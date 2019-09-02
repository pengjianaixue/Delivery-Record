#pragma once
#include "qobject.h"
#include <QFile>
#include <memory>
class IniFileProcesser :public QObject
{
	Q_OBJECT
public:
	using VALUELISTDIC = QMap<QString, std::list<std::pair<QString, QString>>>;
public:
	IniFileProcesser(QString iniFilePath = "./Template.ini");
	~IniFileProcesser();
	VALUELISTDIC fetchValueDictFromIni();
	bool writeDictValueToIni(const VALUELISTDIC &valueDict);
	bool writeGroupValueToIni(const QString &groupName, const QStringList &valueAndKeyList , const QString &SplitSymbol);
	QString fetchSpecGroupAndKeyValue(const QString &group, const QString &key);
	QStringList  fetchAnGroupValue(const QString &group);
	int			 getGroupKeycount(const QString &group);
	
private:
	std::shared_ptr<QSettings>  m_SettingsFile = {nullptr};
	  
};

