#include "stdafx.h"
#include "deliveryrecord.h"

DeliveryRecord::DeliveryRecord(QWidget *parent)
	: QMainWindow(parent), configurUi(new dialog_UserConfigure(this))
{
	ui.setupUi(this);
	init();
}

DeliveryRecord::~DeliveryRecord()
{
	delete configurUi;
	m_pyCallProcess->terminateProcess();
	m_pyRunThread.terminate();
}

void DeliveryRecord::resizeEvent(QResizeEvent *event)
{ 
	
}

bool DeliveryRecord::eventFilter(QObject * target, QEvent * event)
{
	if (target == this->ui.tablewideget_deliverytable && event->type() == QEvent::Leave)
	{
		this->ui.tablewideget_deliverytable->unsetCursor();
		this->ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		return true;//will 
	}
	else
	{
		return QWidget::eventFilter(target, event);
	}
	return false;
}

void DeliveryRecord::initUI()
{
	ui.progressBar_update->hide();
	this->ui.progressBar_update->setRange(0, 100);
	this->ui.progressBar_update->setStyle(QStyleFactory::create("WindowsVista"));
	this->configurUi->hide();
	this->ui.widget_displayinfor->hide();
	ui.horizontalLayout_2->insertSpacerItem(1,new QSpacerItem(20, 20, QSizePolicy::Expanding));
	IniFileProcesser initIniReader("./RecordTemp.ini");
	QStringList deliveryKeyWords;
	QStringList deliveryInfoWords;
	XmlReader::VALUEPAIRLIST deliveryInfo;
	m_XmlReader->openFile(m_strXmlFilePath);
	m_XmlReader->setRootName();
	m_XmlReader->getAnSpecialCategoryValue("Delivery_Infor", "DliveryInfo", QStringList("Value"), deliveryInfo);
	int count = initIniReader.getGroupKeycount("Dilivery_table_configure");
	for (int i = 0;i < count;++i)
	{
		QString keyword = "Word_" + QString(std::to_string(i+1).c_str());
		QStringList temp = initIniReader.fetchSpecGroupAndKeyValue("Dilivery_table_configure", keyword).split("@=");

		deliveryKeyWords.append(temp[0]);
		i<deliveryInfo.length() ? deliveryInfoWords.append(deliveryInfo[i][0].second) : deliveryInfoWords.append("");
	}
	ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tablewideget_deliverytable->setColumnCount(1);
	ui.tablewideget_deliverytable->setRowCount(deliveryKeyWords.size());
	ui.tablewideget_deliverytable->setVerticalHeaderLabels(deliveryKeyWords);
	ui.tablewideget_deliverytable->horizontalHeader()->setVisible(true);
	ui.tablewideget_deliverytable->setHorizontalHeaderLabels(QStringList(""));
	ui.tablewideget_deliverytable->verticalHeader()->setVisible(true); 
	ui.tablewideget_deliverytable->setItemDelegateForColumn(0, m_pInputTextEditorDelegate.get());
	ui.tablewideget_deliverytable->horizontalHeader()->setStretchLastSection(true);
	ui.tablewideget_deliverytable->verticalHeader()->setStretchLastSection(true);
	for (size_t i = 0; i < deliveryInfoWords.length(); i++)
	{
		QTableWidgetItem *item = new QTableWidgetItem();
		item->setText(deliveryInfoWords[i]);
		ui.tablewideget_deliverytable->setItem(i, 0, item);
	}
	connectSlots();

}
void DeliveryRecord::init()
{
	this->ui.tablewideget_deliverytable->installEventFilter(this);
	m_strXmlFilePath = QApplication::applicationDirPath() + "/DeliveryInfor.xml";
	m_pyCallProcess->moveToThread(&m_pyRunThread);
	m_pyRunThread.start();
	initUI();
}
bool DeliveryRecord::saveTableContents()
{
	QStringList valueList;
	QList<QStringList> valueStringList;
	for (size_t i = 0; i < ui.tablewideget_deliverytable->rowCount(); i++)
	{
		valueList.append(ui.tablewideget_deliverytable->item(i, 0)->text());
		valueStringList.append(valueList);
		valueList.clear();
	}
	if (!m_XmlWirter->loadXmlFile(QApplication::applicationDirPath() + "/DeliveryInfor.xml"))
	{
		m_XmlWirter->emptyXmlDoc();
		m_XmlWirter->fileStructInit("root");
	}
	m_XmlWirter->setCurrentNode("root");
	m_XmlWirter->removeChild("Delivery_Infor");
	m_XmlWirter->writeAncategoryData("Delivery_Infor", "DliveryInfo", QStringList("Value"), valueStringList);
	QList<QString> cmdStringList;
	if (m_XmlWirter->saveToFile(m_strXmlFilePath))
	{

		cmdStringList.append(R"(")" + QApplication::applicationDirPath() + R"(")" + "/Delivery_note_record.exe");
		callUpdateWikiPyScript();
		emit s_runCallPyScriptSolt(cmdStringList);
		ui.progressBar_update->show();
	}
	else
	{
		QMessageBox::critical(this, "save file error", "save delivery information to file faild");
		return false;
	}
	return true;
}
void DeliveryRecord::openConfigurDialog(bool open)
{
	this->configurUi->show();
}

void DeliveryRecord::connectSlots()
{
	connect(this->ui.actionconfiguration, &QAction::triggered, this, &DeliveryRecord::openConfigurDialog);
	connect(this->ui.pushButton_update, &QPushButton::clicked, this, &DeliveryRecord::saveTableContents);
	connect(this->m_pyCallProcess.get(), &subProcessRunner::s_processMsgReaded, this, &DeliveryRecord::readPyScriptOutputToDisplay);
	connect(this, &DeliveryRecord::s_runCallPyScriptSolt, this->m_pyCallProcess.get(), &subProcessRunner::run);
	connect(this->ui.pushButton_logview, &QPushButton::clicked, this, [&] {this->ui.widget_displayinfor->show(); this->ui.pushButton_logview->hide(); });
	connect(this->ui.pushButton_hidedispaly, &QPushButton::clicked, this, &DeliveryRecord::hideDisplayTextBrowse);
	connect(this->ui.actionclean_contents, &QAction::triggered, this, &DeliveryRecord::cleanTableContents);
	connect(this->m_pyCallProcess.get(), &subProcessRunner::s_runFinished, this, &DeliveryRecord::fetchPyScriptRunResult);
	connect(this->ui.tablewideget_deliverytable, &QTableWidget::itemClicked, this, &DeliveryRecord::setEditRowWidth);
}

bool DeliveryRecord::callUpdateWikiPyScript()
{
	this->ui.textBrowser_updateInfor->clear();
	this->ui.textBrowser_updateInfor->insertPlainText("Start run python script...\r\n");
	return true;
}


void DeliveryRecord::readPyScriptOutputToDisplay(QString cmdProcessMsg)
{
	
	this->ui.textBrowser_updateInfor->insertPlainText(cmdProcessMsg);
}

void DeliveryRecord::hideDisplayTextBrowse()
{

	this->ui.widget_displayinfor->hide();
	this->ui.pushButton_logview->show();
}

void DeliveryRecord::cleanTableContents()
{
	for (size_t i = 0; i < this->ui.tablewideget_deliverytable->rowCount(); i++)
	{
		this->ui.tablewideget_deliverytable->item(i, 0)->setText("");
	}
}

void DeliveryRecord::fetchPyScriptRunResult(const QString &cmditem)
{
	
	if (cmditem.contains(QStringRef(&QString("Delivery_note_record.exe"))))
	{
		if (this->ui.textBrowser_updateInfor->toPlainText().contains(QStringRef(&QString("Update success"))))
		{
			QList<QString> cmdStringList;
			if (configurUi->isEnableEmail())
			{
				this->ui.progressBar_update->setValue(ui.progressBar_update->value() + 50);
				cmdStringList.append(R"(")" + QApplication::applicationDirPath() + R"(")" + "/Delivery_Record_Notify_EmailSend.exe");
				emit s_runCallPyScriptSolt(cmdStringList);
			}
			else
			{
				this->ui.progressBar_update->setValue(100);
				this->ui.progressBar_update->setFormat("Update done");
			}
		}
		else
		{
			QMessageBox::critical(this, "update error", "update the wiki website failed,please contact administrator");
			this->ui.progressBar_update->hide();
		}
	}
	if (cmditem.contains(QStringRef(&QString("Delivery_Record_Notify_EmailSend.exe"))))
	{
		if (this->ui.textBrowser_updateInfor->toPlainText().contains(QStringRef(&QString("mail send success"))))
		{
			this->ui.progressBar_update->setValue(100);
			this->ui.progressBar_update->setFormat("Update done");

		}
		else
		{
			QMessageBox::critical(this, "update error", "send email failed,please contact administrator");
			this->ui.progressBar_update->hide();
		}
	}
	
}

void DeliveryRecord::setEditRowWidth()
{
	this->ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Custom);
	for (size_t i = 0; i < this->ui.tablewideget_deliverytable->rowCount(); i++)
	{
		this->ui.tablewideget_deliverytable->setRowHeight(i, 50);
	}
	this->ui.tablewideget_deliverytable->setRowHeight(this->ui.tablewideget_deliverytable->currentRow(), 150);
}


