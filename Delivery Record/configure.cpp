#include "stdafx.h"
#include "configure.h"

UserConfigureDialog::UserConfigureDialog(QWidget *parent)
	: QDialog(parent), m_pInputTextEditorDelegate(new QTextEditDelegate(this))
{
	ui.setupUi(this);
	initUi();
}

UserConfigureDialog::~UserConfigureDialog()
{
	if (!m_lineEditEmialRecvierAdd)
	{
		delete m_lineEditEmialRecvierAdd;
		m_lineEditEmialRecvierAdd = nullptr;
	}
	ui.tableWidget_emailcontents->clearContents();
}

bool UserConfigureDialog::isEnableEmail() const
{
	return m_isSendEmail;
}

void UserConfigureDialog::showEvent(QShowEvent *showevent)
{

	if (!m_emailContentsList.isEmpty())
	{
		int rowconunter = 0;
		int colcounter = 0;
		for (auto &item : m_emailContentsList)
		{
			for (auto &childitem : item)
			{
				this->ui.tableWidget_emailcontents->setItem(rowconunter, colcounter, new QTableWidgetItem(childitem.second));
				++colcounter;
			}
			++rowconunter;
			colcounter = 0;
		}
	}
	ui.lineEdit_username->setText(m_editSubmitContentsMap["username"]);
	QString passwordDecodestr = m_editSubmitContentsMap["password"];
	passwordDecodeProcess(passwordDecodestr);
	ui.lineEdit_password->setText(passwordDecodestr);
	ui.lineEdit_editsection->setText(m_editSubmitContentsMap["editsection"]);
	ui.lineEdit_emailsubject->setText(m_editSubmitContentsMap["emailsubject"]);
	ui.lineEdit_emailsender->setText(m_editSubmitContentsMap["emailsender"]);
	ui.lineEdit_username->setText(m_editSubmitContentsMap["username"]);

}

bool UserConfigureDialog::eventFilter(QObject *target, QEvent *event)
{
	if (target == this->ui.tableWidget_emailcontents && event->type() == QEvent::Leave)
	{
		this->ui.tableWidget_emailcontents->unsetCursor();
		this->ui.tableWidget_emailcontents->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		return true;//will 
	}
	else if (target == this->ui.tableWidget_emailcontents && event->type() == QEvent::Enter)
	{
		setEditRowWidth();
	}
	else
	{
		return QDialog::eventFilter(target, event);
	}
	return false;
}

bool UserConfigureDialog::connectslots()
{
	return this->connect(this->ui.okButton, &QPushButton::clicked, this, &UserConfigureDialog::submitButtonClick)
		&& this->connect(this->ui.cancelButton, &QPushButton::clicked, this, &UserConfigureDialog::cancelButtonClick)
		&& this->connect(this->ui.pushButton_removeEmailRecvier, &QPushButton::clicked, this, &UserConfigureDialog::removeEmailRecvier)
		&& this->connect(this->ui.pushButton_addEmailRecvier, &QPushButton::clicked, this, &UserConfigureDialog::addEmailRecvier)
		//this->connect(this->ui.radioButton_enableSendEmail, &QRadioButton::clicked, this, &UserConfigureDialog::emialRadioPushbuttonCliked);
		&& this->connect(this->ui.tableWidget_emailcontents, &QTableWidget::itemClicked, this, &UserConfigureDialog::setEditRowWidth)
		&& this->connect(this->ui.tableWidget_emailcontents, &QTableWidget::cellChanged, this, &UserConfigureDialog::rowAdd)
		&& this->connect(this->ui.pushButton_Loadfromfile,&QPushButton::clicked,this,&UserConfigureDialog::loadEmailAddressFromFile)
		;
	//this->connect(this->ui.tableWidget_emailcontents, &QTableWidget::customContextMenuRequested, this, &UserConfigureDialog::rowOperationMenu);
	
}

void UserConfigureDialog::submitButtonClick()
{
	
	if (!m_xmlWirter.loadXmlFile(m_deliveryInformationXmlfileName))
	{
		m_xmlWirter.emptyXmlDoc();
		m_xmlWirter.fileStructInit("root");
	}
	m_xmlWirter.setCurrentNode("root");
	QStringList attruiItemList;
	attruiItemList << "Title" <<"Contents";
	QList<QStringList> vauleList;
	m_emailContentsList.clear();
	for (size_t i = 0; i < ui.tableWidget_emailcontents->rowCount(); i++)
	{
		if (ui.tableWidget_emailcontents->item(i,0) 
			&& ui.tableWidget_emailcontents->item(i, 1)
			&& !ui.tableWidget_emailcontents->item(i, 0)->text().isEmpty()  
			&& !ui.tableWidget_emailcontents->item(i, 1)->text().isEmpty()
			)
		{
			QStringList itemtext;
			itemtext << ui.tableWidget_emailcontents->item(i, 0)->text();
			itemtext << ui.tableWidget_emailcontents->item(i, 1)->text();
			QList<std::pair<QString, QString>> contentspair;
			contentspair.append({"Title",itemtext[0]});
			m_emailContentsList.append(contentspair);
			m_emailContentsList.clear();
			contentspair.append({"Contents",itemtext[1] });
			m_emailContentsList.append(contentspair);
			vauleList.append(itemtext);
		}
	}
	m_xmlWirter.removeChild("Delivery_Email_Infor");
	m_xmlWirter.writeAncategoryData("Delivery_Email_Infor","Delivery_Email_Content", attruiItemList, vauleList);
	m_editSubmitContentsMap.clear();
	m_editSubmitContentsMap.insert({ "username",ui.lineEdit_username->text() });
	QString passwordEncStr = ui.lineEdit_password->text();
	passwordEncryptionProcess(passwordEncStr);
	m_editSubmitContentsMap.insert({ "password",passwordEncStr });
	m_editSubmitContentsMap.insert({ "editsection",ui.lineEdit_editsection->text() });
	m_editSubmitContentsMap.insert({ "emailsubject",ui.lineEdit_emailsubject->text() });
	m_editSubmitContentsMap.insert({ "emailsender",ui.lineEdit_emailsender->text() });
#ifdef _DEBUG
	qDebug() << ui.comboBox_emailrecviers->count();
#endif // _DEBUG
	for (size_t i = 0; i < ui.comboBox_emailrecviers->count(); i++)
	{

#ifdef _DEBUG
		qDebug() << ui.comboBox_emailrecviers->count();
#endif // _DEBUG
		m_editSubmitContentsMap.insert({ QString("recvier_") + QString::number(i),ui.comboBox_emailrecviers->itemText(i) });
	}
	vauleList.clear();
	for (const auto &item: m_editSubmitContentsMap)
	{
		if (!item.first.startsWith("recvier_"))
		{
			vauleList.append(QStringList() << item.first << item.second);
		}
	}
	m_xmlWirter.removeChild("Delivery_configure_Infor");
	m_xmlWirter.writeAncategoryData("Delivery_configure_Infor","Delivery_Configure_Item", QStringList() << "Item" << "Value", vauleList);
	vauleList.clear();
	for (const auto &item : m_editSubmitContentsMap)
	{
		if (item.first.startsWith("recvier_"))
		{
			vauleList.append(QStringList() << item.first << item.second);
		}
	}
	m_xmlWirter.removeChild("Delivery_EmailReceiver_Infor");
	m_xmlWirter.writeAncategoryData("Delivery_EmailReceiver_Infor", "Delivery_Receiver_Item",
		QStringList() << "Receiver_Number" << "Receiver_Address", vauleList);
	m_xmlWirter.saveToFile(m_deliveryInformationXmlfileName);
//	m_editSubmitContentsMap.clear();
//	m_editSubmitContentsMap.insert({ "username",ui.lineEdit_username->text()});
//	QString passwordEncStr = ui.lineEdit_password->text();
//	passwordEncryptionProcess(passwordEncStr);
//	m_editSubmitContentsMap.insert({ "password",passwordEncStr});
//	m_editSubmitContentsMap.insert({ "editsection",ui.lineEdit_editsection->text() });
//	m_editSubmitContentsMap.insert({"emailcomments",ui.lineEdit_emailcomments->text()});
//	m_editSubmitContentsMap.insert({ "emailsender",ui.lineEdit_emailsender->text() });
//#ifdef _DEBUG
//	qDebug() << ui.comboBox_emailrecviers->count();
//#endif // _DEBUG
//	for (size_t i = 0; i < ui.comboBox_emailrecviers->count(); i++)
//	{
//
//#ifdef _DEBUG
//		qDebug() << ui.comboBox_emailrecviers->count();
//#endif // _DEBUG
//		m_editSubmitContentsMap.insert({QString("recvier_")+ QString::number(i),ui.comboBox_emailrecviers->itemText(i)});
//	}
//	QList<std::pair<QString, QString>> iniList;
//	for (auto  &item : m_editSubmitContentsMap)
//	{
//		iniList.append({ item.first ,item.second });
//	}
//	IniFileProcesser iniFileWirter("./RecordTemp.ini");
//	iniFileWirter.deleteGroupContents("user_configure");
//	iniFileWirter.writeGroupValueToIni("user_configure", iniList);
	this->close();
}

void UserConfigureDialog::cancelButtonClick()
{
	this->close();
}

bool UserConfigureDialog::passwordEncryptionProcess(QString &paswordstr)
{
	QByteArray passwordbyte  = paswordstr.toUtf8();
	paswordstr = QString(passwordbyte.toBase64());
	return true;
}

bool UserConfigureDialog::passwordDecodeProcess(QString &paswordstr)
{

	QByteArray passwordbyte = QByteArray::fromBase64(paswordstr.toUtf8());
	paswordstr = QString(passwordbyte);
	return true;
}

void UserConfigureDialog::removeEmailRecvier()
{
	ui.comboBox_emailrecviers->removeItem(ui.comboBox_emailrecviers->currentIndex());
	ui.comboBox_emailrecviers->update();
}

void UserConfigureDialog::addEmailRecvier()
{
	if (!ui.comboBox_emailrecviers->lineEdit()->text().isEmpty())
	{
		for (size_t i = 0; i < ui.comboBox_emailrecviers->count(); i++)
		{
			if (ui.comboBox_emailrecviers->itemText(i) == ui.comboBox_emailrecviers->lineEdit()->text())
			{
				QMessageBox::warning(this, "add warning", QString("The email address %1 have exist in the list ,please don't repeat add the email address").arg(ui.comboBox_emailrecviers->lineEdit()->text()));
				return;
			}
		}
		ui.comboBox_emailrecviers->addItem(ui.comboBox_emailrecviers->lineEdit()->text());
		ui.comboBox_emailrecviers->update();
		//ui.comboBox_emailrecviers->lineEdit()->setText(QString());
	}
	else
	{
		QMessageBox::warning(this, "add warning", "can't add empty content,please input email address");
	}
}


void UserConfigureDialog::emialRadioPushbuttonCliked()
{
	//if (ui.radioButton_enableSendEmail->isChecked())
	//{
	//	m_isSendEmail = true;
	//	this->resize(900, 700);
	//	QRect rect = (static_cast<QWidget*>(parent()))->geometry();
	//	int x = rect.x() + rect.width() / 2 - this->width() / 2;
	//	int y = rect.y() + rect.height() / 2 - this->height()/2;
	//	this->move(x,y);
	//	ui.widget_email->show();
	//	
	//}
	//else
	//{
	//	m_isSendEmail = false;
	//	ui.widget_email->hide();
	//	this->resize(300, 50);
	//	//QRect emailFrame;
	//	//emailFrame.setHeight(50);
	//	//emailFrame.setWidth(300);
	//	//this->setGeometry(emailFrame);
	//	QRect rect = (static_cast<QWidget*>(parent()))->geometry();
	//	int x = rect.x() + rect.width() / 2 - this->width() / 2;
	//	int y = rect.y() + rect.height() / 2 - this->height() / 2;
	//	this->move(x, y);
	//}
}

void UserConfigureDialog::setEditRowWidth()
{
	this->ui.tableWidget_emailcontents->verticalHeader()->setSectionResizeMode(QHeaderView::Custom);
	for (size_t i = 0; i < this->ui.tableWidget_emailcontents->rowCount(); i++)
	{
		this->ui.tableWidget_emailcontents->setRowHeight(i, 40);
	}
	/*this->ui.tableWidget_emailcontents->setRowHeight(this->ui.tableWidget_emailcontents->currentRow(), 100);*/
	this->ui.tableWidget_emailcontents->resizeRowToContents(this->ui.tableWidget_emailcontents->currentRow());

}

void UserConfigureDialog::rowAdd(int row, int cloumu)
{
	if (row == this->ui.tableWidget_emailcontents->rowCount()-1)
	{
		this->ui.tableWidget_emailcontents->insertRow(row+1);
	}
}

void UserConfigureDialog::rowOperationMenu(const QPoint &pos)
{
	int row = this->ui.tableWidget_emailcontents->indexAt(pos).row();
	int column = this->ui.tableWidget_emailcontents->indexAt(pos).column();
	QMenu  popMenu(this->ui.tableWidget_emailcontents);
	QList<QAction*> actionlist;
	if (row < this->ui.tableWidget_emailcontents->rowCount() && row != -1 && column == 1)
	{

		QAction *addTable = new QAction(tr("Add a table"));
		addTable->setProperty("row", row);
		addTable->setIcon(QIcon(":/DeliveryRecord/Resources/table.png"));
		connect(addTable, &QAction::triggered, this, &UserConfigureDialog::addTableInCell);
		actionlist.append(addTable);
		popMenu.addActions(actionlist);
		popMenu.exec(QCursor::pos());
		return;
	}
}

void UserConfigureDialog::addTableInCell()
{
	/*QAction *act = qobject_cast<QAction*>(QObject::sender());
	int row = act->property("row").toInt();
	QTableView *emailContentsTable = new QTableView(this->ui.tableWidget_emailcontents);
	QStandardItemModel *emailContentsTableModel = new QStandardItemModel(this->ui.tableWidget_emailcontents);
	emailContentsTable->setModel(emailContentsTableModel);
	emailContentsTableModel->setColumnCount(3);
	emailContentsTableModel->setRowCount(5);
	emailContentsTable->setWindowTitle("Email Internal Table Editor");
	emailContentsTable->show();*/
}

void UserConfigureDialog::loadInformationFromXml(const QString &fileName)
{
	if (!m_xmlReader.openFile(fileName))
	{
		return;
	}
	m_emailContentsList.clear();
	m_xmlReader.getAnSpecialCategoryValue("Delivery_Email_Infor", "Delivery_Email_Content",
		QStringList() << "Title" << "Contents", m_emailContentsList);
	XmlReader::VALUEPAIRLIST InforList;
	InforList.clear();
	m_xmlReader.getAnSpecialCategoryValue("Delivery_configure_Infor", "Delivery_Configure_Item",
		QStringList() << "Item" << "Value", InforList);
	if ((!InforList.isEmpty()))
	{
		for (auto &item : InforList)
		{
			QString  key;
			QString  value;
			for (auto &childitem : item)
			{
				if (childitem.first == "Item")
				{
					key = childitem.second;
				}
				else if (childitem.first == "Value")
				{
					value = childitem.second;
				}
			}
			if (!(key.isEmpty() || value.isEmpty()))
			{
				m_editSubmitContentsMap[key] = value;
			}
		}
	}
	InforList.clear();
	//m_xmlReader.setCurrentNode("Delivery_configure_Infor");
	m_xmlReader.getAnSpecialCategoryValue("Delivery_EmailReceiver_Infor", "Delivery_Receiver_Item",
		QStringList() << "Receiver_Number" << "Receiver_Address", InforList);
	if ((!InforList.isEmpty()))
	{
		for (auto &item : InforList)
		{
			for (auto &childitem : item)
			{
				if (childitem.first == "Receiver_Address")
				{
					ui.comboBox_emailrecviers->addItem(childitem.second);
				}
			}
		}
	}
	m_xmlReader.setCurrentNode("root");
	return;
}

bool UserConfigureDialog::loadEmailAddressFromFile()
{
	bool loadFlag = false;
	QByteArray btyeAddress;
	QFile emailAddressFile(m_emailAddressFile);
	emailAddressFile.open(QFile::OpenModeFlag::ReadOnly);
	if (emailAddressFile.isOpen())
	{
		btyeAddress = emailAddressFile.readAll();
	}
	QString emialAddress(btyeAddress);
	QStringList emaillist =  emialAddress.split(";");
	QRegularExpression emialPattern(R"(^[\w|\s]+<(.*@.*)>[\w|\s]?$)");
	Q_FOREACH(QString emialItem ,emaillist)
	{
		QRegularExpressionMatch matchres =  emialPattern.match(emialItem);
		if (matchres.hasMatch())
		{
			this->ui.comboBox_emailrecviers->addItem(matchres.captured(matchres.lastCapturedIndex()));
			loadFlag = true;
		}
	}
	if (loadFlag)
	{
		QMessageBox::information(this, "Load Information", "Load email address success !");
	}
	return true;
}

void UserConfigureDialog::loadEmailContentsfromOldXml()
{
	m_emailContentsList.clear();
	if (m_xmlReader.openFile(QApplication::applicationDirPath() + "/DeliveryInfor.xml"))
	{
		//m_xmlReader.setRootName();
		m_xmlReader.getAnSpecialCategoryValue("Delivery_Email_Infor", "Delivery_Email_Content",
			QStringList() << "Title" << "Contents", m_emailContentsList);
		return;
	}
}

void UserConfigureDialog::initUi()
{
	m_emailAddressFile = QApplication::applicationDirPath() + "/Email address configure.txt";
	m_deliveryInformationXmlfileName = QApplication::applicationDirPath() + "/DeliveryInformation.xml";
	this->setModal(true);
	this->ui.tableWidget_emailcontents->setStyle(QStyleFactory::create("windowsvista"));
	this->ui.tableWidget_emailcontents->installEventFilter(this);
	this->ui.tableWidget_emailcontents->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.splitter->setStretchFactor(0,1);
	ui.splitter->setStretchFactor(1, 9);
	ui.comboBox_emailrecviers->setEditable(true);
	ui.lineEdit_password->setEchoMode(QLineEdit::Password);
	ui.lineEdit_password->setPlaceholderText("please input password");
	ui.lineEdit_username->setPlaceholderText("please input username");
	ui.lineEdit_editsection->setPlaceholderText("please input table name");
	this->ui.tableWidget_emailcontents->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->ui.tableWidget_emailcontents->setColumnCount(2);
	QStringList horizontalHeader;
	horizontalHeader << "Email Title" << "Email Contents";
	this->ui.tableWidget_emailcontents->setRowCount(10);
	this->ui.tableWidget_emailcontents->setRowHeight(1, 10);
	this->ui.tableWidget_emailcontents->setHorizontalHeaderLabels(horizontalHeader);
	this->ui.tableWidget_emailcontents->horizontalHeader()->setStretchLastSection(true);
	this->ui.tableWidget_emailcontents->setItemDelegateForColumn(1, m_pInputTextEditorDelegate);
	this->ui.tableWidget_emailcontents->setItem(1, 1, new QTableWidgetItem());
	// Change all the information save to xml file.
	QFileInfo fileInfo(m_deliveryInformationXmlfileName);
	if (fileInfo.isFile())
	{
		loadInformationFromXml(m_deliveryInformationXmlfileName);
	}
	else
	{
		IniFileProcesser initIniReader("./RecordTemp.ini");
		IniFileProcesser::VALUELISTDIC iniFileValue = initIniReader.fetchValueDictFromIni();
		for (auto &item : iniFileValue["user_configure"])
		{
			m_editSubmitContentsMap.insert({ item.first,item.second });
		}
		for (size_t i = 0; i < (m_editSubmitContentsMap.size() - 5); i++)
		{
			ui.comboBox_emailrecviers->addItem(m_editSubmitContentsMap[QString("recvier_") + QString::number(i)]);
		}
		loadEmailContentsfromOldXml();
	}
	showEvent(nullptr);
	if (!connectslots())
	{
		QMessageBox::critical(this, "internal Error", "Connect slots fail");
		exit(-1);
	}
	
}
