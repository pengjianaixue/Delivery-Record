#pragma once
#include "qobject.h"
#include <QFile>
#include <memory>
class IniFileTemplateHandler :public QObject
{
	Q_OBJECT
public:
	using VALUELISTDIC = QMap<QString, std::list<std::pair<QString, QString>>>;
public:
	IniFileTemplateHandler(QString iniFilePath = "./Template.ini");
	~IniFileTemplateHandler();
	VALUELISTDIC fetchValueDictFromIni();
	bool writeValueDictToIni(VALUELISTDIC valueDict);
	QString fetchSpecGroupAndKeyValue(QString group, QString key);
	int  fetchAnGroupValue(QString group);
	
private:
	std::shared_ptr<QSettings>  m_SettingsFile = {nullptr};
	  
};

