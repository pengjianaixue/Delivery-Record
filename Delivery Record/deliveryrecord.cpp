#include "stdafx.h"
#include "deliveryrecord.h"

DeliveryRecord::DeliveryRecord(QWidget *parent)
	: QMainWindow(parent), configurUi(new UserConfigureDialog(this))
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
		//this->ui.tablewideget_deliverytable->unsetCursor();
		if (this->ui.tablewideget_deliverytable->currentRow()== this->ui.tablewideget_deliverytable->rowCount()-1)
		{
			this->ui.tablewideget_deliverytable->setRowHeight(this->ui.tablewideget_deliverytable->currentRow(), 50);
		}
		this->ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		//return true;//will 
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
	this->ui.pushButton_sendemail->hide();
	this->ui.progressBar_update->setRange(0, 100);
	this->ui.progressBar_update->setStyle(QStyleFactory::create("WindowsVista"));
	this->configurUi->hide();
	this->ui.widget_displayinfor->hide();
	ui.horizontalLayout_2->insertSpacerItem(1,new QSpacerItem(20, 20, QSizePolicy::Expanding));
	DeliveryTableInfor deliveryTableInfor;
	QFileInfo fileInfo(m_deliveryInformationXmlfileName);
	if (fileInfo.isFile())
	{
		deliveryTableInfor = loadInformationFromXml(m_deliveryInformationXmlfileName);
	}
	else
	{
		deliveryTableInfor = loadInformationofLegacy(m_strXmlFilePath);
	}
	ui.tablewideget_deliverytable->setStyle(QStyleFactory::create("windowsvista"));
	ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tablewideget_deliverytable->setColumnCount(1);
	ui.tablewideget_deliverytable->setRowCount(deliveryTableInfor.size());
	ui.tablewideget_deliverytable->horizontalHeader()->setVisible(false);
	ui.tablewideget_deliverytable->setHorizontalHeaderLabels(QStringList(""));
	ui.tablewideget_deliverytable->verticalHeader()->setVisible(true);
	ui.tablewideget_deliverytable->setItemDelegateForColumn(0, m_pInputTextEditorDelegate.get());
	ui.tablewideget_deliverytable->horizontalHeader()->setStretchLastSection(true);
	ui.tablewideget_deliverytable->verticalHeader()->setStretchLastSection(true);
	QStringList deliveryHeaderLabel;
	for (size_t i = 0; i < deliveryTableInfor.length(); i++)
	{
		deliveryHeaderLabel << deliveryTableInfor.at(i).first;
		QTableWidgetItem *item = new QTableWidgetItem();
		item->setText(deliveryTableInfor.at(i).second);
		ui.tablewideget_deliverytable->setItem(i, 0, item);
	}
	ui.tablewideget_deliverytable->setVerticalHeaderLabels(deliveryHeaderLabel);
	QTableWidgetItem * header = ui.tablewideget_deliverytable->verticalHeaderItem(deliveryHeaderLabel.size() - 1);
	if (header && header->text() == "* External DB" || header->text() == "External DB")
	{
		if (!header->text().startsWith("* "))
		{
			header->setText("* " + header->text());
		}
		header->setForeground(QBrush(QColor(204, 51, 51)));
		ui.tablewideget_deliverytable->setVerticalHeaderItem(deliveryHeaderLabel.size() - 1, header);
	}
	else
	{
		QMessageBox::critical(this, "information loss", "the delivery table must contain External DB item,please add this item");
		exit(0);
	}
	connectSlots();

}
void DeliveryRecord::init()
{
	m_deliveryInformationXmlfileName = QApplication::applicationDirPath() + "/DeliveryInformation.xml";
	this->setStyleSheet("QMainWindow:{background-color: #1464A0;}");
	this->ui.tablewideget_deliverytable->installEventFilter(this);
	m_strXmlFilePath = QApplication::applicationDirPath() + "/DeliveryInfor.xml";
	m_pyCallProcess->moveToThread(&m_pyRunThread);
	m_pyRunThread.start();
	initUI();
}
bool DeliveryRecord::saveTableContents()
{
	if (this->ui.pushButton_update->text()=="Give up send email")
	{
		this->ui.pushButton_update->setText("Update");
		this->ui.pushButton_update->setIcon(QIcon(":/DeliveryRecord/Resources/update.png"));
		this->ui.pushButton_sendemail->hide();
		this->ui.progressBar_update->setValue(100);
		this->ui.progressBar_update->setFormat("Update done");
		return true;
	}
	/*QStringList valueList;
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
	if (m_XmlWirter->saveToFile(m_strXmlFilePath))
	{

		
	}*/
	if (saveToFile())
	{
		QList<QString> cmdStringList;
		cmdStringList.append(R"(")" + QApplication::applicationDirPath() + R"(")" + "/Delivery_note_record.exe");
		callUpdateWikiPyScript();
		emit s_runCallPyScriptSolt(cmdStringList);
		this->ui.pushButton_update->setEnabled(false);
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
	connect(this->ui.pushButton_sendemail, &QPushButton::clicked, this, &DeliveryRecord::sendEmail);
	connect(this->ui.tablewideget_deliverytable, &QTableWidget::itemChanged, this, [&] {this->ui.progressBar_update->hide(); });
	connect(this->ui.actionsave, &QAction::triggered, this, [&] {this->saveToFile(); });
	connect(this->ui.actionHelp, &QAction::triggered, this, &DeliveryRecord::helpFileOpen);
	connect(this->ui.actionVersion, &QAction::triggered, this, &DeliveryRecord::versionDialog);
	

}

bool DeliveryRecord::callUpdateWikiPyScript()
{
	this->ui.progressBar_update->reset();
	this->ui.progressBar_update->resetFormat();
	this->ui.progressBar_update->setValue(27);
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
	//contentjuedement: 
		if (this->ui.textBrowser_updateInfor->toPlainText().contains(QStringRef(&QString("Update success"))))
		{
			IniFileProcesser initIniReader("./RecordTemp.ini");
			QString pageinfo  = initIniReader.fetchSpecGroupAndKeyValue("wikipage_configure", "loginjumptopage");
			this->ui.progressBar_update->setValue(74);
			//if (configurUi->isEnableEmail())
			//{

			//	/*this->ui.progressBar_update->setValue(ui.progressBar_update->value() + 50);
			//	cmdStringList.append(R"(")" + QApplication::applicationDirPath() + R"(")" + "/Delivery_Record_Notify_EmailSend.exe");
			//	emit s_runCallPyScriptSolt(cmdStringList);*/
			//}
			//else
			//{
			//	this->ui.progressBar_update->setValue(100);
			//	this->ui.progressBar_update->setFormat("Update done");
			//}
			this->ui.pushButton_sendemail->show();
			this->ui.pushButton_update->setText("Give up send email");
			this->ui.pushButton_update->setIcon(QIcon(":/DeliveryRecord/Resources/give-up.png"));
			this->ui.pushButton_sendemail->setEnabled(true);
			QDesktopServices::openUrl(QUrl("https://lte-wiki.rnd.ki.sw.ericsson.se/w/index.php?title=" + pageinfo));
		}
		else
		{
			/*QTime dieTime = QTime::currentTime().addMSecs(1000);
			while (QTime::currentTime() < dieTime)
				QCoreApplication::processEvents(QEventLoop::AllEvents, 100);*/
			QMessageBox::critical(this, "update error", "update the wiki website failed,please contact administrator");
		
			this->ui.progressBar_update->reset();
			this->ui.progressBar_update->hide();
		}
		this->ui.pushButton_update->setEnabled(true);
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
			this->ui.progressBar_update->reset();
			this->ui.progressBar_update->hide();
		}
		this->ui.pushButton_update->setEnabled(true);
		this->ui.pushButton_update->setText("Update");
		this->ui.pushButton_update->setIcon(QIcon(":/DeliveryRecord/Resources/update.png"));
		this->ui.pushButton_sendemail->hide();
	}
	
}

void DeliveryRecord::setEditRowWidth()
{
	this->ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Custom);
	for (size_t i = 0; i < this->ui.tablewideget_deliverytable->rowCount(); i++)
	{
		this->ui.tablewideget_deliverytable->setRowHeight(i, 50);
	}
	this->ui.tablewideget_deliverytable->resizeRowToContents(this->ui.tablewideget_deliverytable->currentRow());
}

void DeliveryRecord::sendEmail()
{
	this->ui.pushButton_sendemail->setEnabled(false);
	this->ui.pushButton_update->setEnabled(false);
	QList<QString> cmdStringList;
	cmdStringList.append(R"(")" + QApplication::applicationDirPath() + R"(")" + "/Delivery_Record_Notify_EmailSend.exe");
	emit s_runCallPyScriptSolt(cmdStringList);

}

bool DeliveryRecord::saveToFile()
{
	QStringList valueList;
	QList<QStringList> valueStringList;
	for (size_t i = 0; i < ui.tablewideget_deliverytable->rowCount(); i++)
	{
		valueList.append(ui.tablewideget_deliverytable->verticalHeaderItem(i)->text());
		valueList.append(ui.tablewideget_deliverytable->item(i, 0)->text());
		valueStringList.append(valueList);
		valueList.clear();
	}
	if (!m_XmlWirter->loadXmlFile(m_deliveryInformationXmlfileName))
	{
		m_XmlWirter->emptyXmlDoc();
		m_XmlWirter->fileStructInit("root");
		
	}
	m_XmlWirter->setCurrentNode("root");
	writeWikiLinkAndColumnLimit();
	m_XmlWirter->removeChild("Delivery_Infor");
	m_XmlWirter->writeAncategoryData("Delivery_Infor", "DliveryInfo", QStringList()<<"ItemTitle"<<"Value", valueStringList);
	if (!m_XmlWirter->saveToFile(m_deliveryInformationXmlfileName))
	{
		QMessageBox::critical(this, "save information", "save to file failed!");
		return false;
	}
	return true;

}

bool DeliveryRecord::versionDialog()
{
	QMessageBox::about(this, "About", QString("© 2019 Ericcson\nVersion:%1\nAuthor: jian.peng@ericsson.com\r\n\r\nBuild with Qt").arg(Version));
	return true;
}

bool DeliveryRecord::helpFileOpen()
{
	QString GuideFileDir = QCoreApplication::applicationDirPath() + "/Delivery Record Tool Guide.chm";
	return QDesktopServices::openUrl(QUrl::fromLocalFile(GuideFileDir));
}

bool DeliveryRecord::writeWikiLinkAndColumnLimit()
{
	QList<QStringList> valueStringList;
	valueStringList.append(QStringList() << "tablecolumnlimt" <<  QString::number(this->ui.tablewideget_deliverytable->verticalHeader()->count()));
	valueStringList.append(QStringList() << "loginjumptopage" << "RA_Radio/release-note");
	m_XmlWirter->removeChild("Wiki_Infor");
	m_XmlWirter->writeAncategoryData("Wiki_Infor", "WikiInfor", QStringList() << "Item" << "Value", valueStringList);
	return false;
}

DeliveryRecord::DeliveryTableInfor DeliveryRecord::loadInformationFromXml(const QString &fileName)
{
	DeliveryTableInfor tableinfor;
	XmlReader::VALUEPAIRLIST deliveryInfo;
	m_XmlReader->openFile(fileName);
	//m_XmlReader->setRootName();
	m_XmlReader->getAnSpecialCategoryValue("Delivery_Infor", "DliveryInfo", QStringList()<<"ItemTitle"<<"Value", deliveryInfo);
	for (const auto &item: deliveryInfo)
	{
		QString ItemTitle;
		QString Value;
		for (const auto &attributeitem : item)
		{
			if (attributeitem.first == "ItemTitle")
			{
				ItemTitle = attributeitem.second;
			}
			else if (attributeitem.first == "Value")
			{
				Value = attributeitem.second;
			}
		}
		tableinfor.append({ ItemTitle ,Value });
	}
	return tableinfor;

}

DeliveryRecord::DeliveryTableInfor DeliveryRecord::loadInformationofLegacy(const QString &fileName)
{
	DeliveryTableInfor tableinfor;
	IniFileProcesser initIniReader("./RecordTemp.ini");
	QStringList deliveryKeyWords;
	QStringList deliveryInfoWords;
	XmlReader::VALUEPAIRLIST deliveryInfo;
	m_XmlReader->openFile(fileName);
	//m_XmlReader->setRootName();
	m_XmlReader->getAnSpecialCategoryValue("Delivery_Infor", "DliveryInfo", QStringList("Value"), deliveryInfo);
	int count = initIniReader.getGroupKeycount("Dilivery_table_configure");
	for (int i = 0; i < count; ++i)
	{
		QString keyword = "Word_" + QString(std::to_string(i + 1).c_str());
		QStringList temp = initIniReader.fetchSpecGroupAndKeyValue("Dilivery_table_configure", keyword).split("@=");
		deliveryKeyWords.append(temp[0]);
		/*i < deliveryInfo.length() ? deliveryInfoWords.append(deliveryInfo[i][0].second) : deliveryInfoWords.append("");*/
		i < deliveryInfo.length() ? tableinfor.append({ temp[0], deliveryInfo[i][0].second }): tableinfor.append({ temp[0], "" });
		
	}
	return tableinfor;
	
}


