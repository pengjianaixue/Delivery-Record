#include "stdafx.h"
#include "IniFileTemplateHandler.h"


IniFileProcesser::IniFileProcesser(QString iniFilePath)
{
	m_SettingsFile = std::make_shared<QSettings>(iniFilePath, QSettings::IniFormat);
}

IniFileProcesser::~IniFileProcesser()
{
}

bool IniFileProcesser::writeDictValueToIni(const VALUELISTDIC &valueDict)
{

	return false;
}

bool IniFileProcesser::writeGroupValueToIni(const QString &groupName, const QStringList &valueAndKeyList, const QString &SplitSymbol)
{
	m_SettingsFile->beginWriteArray(groupName);
	for (auto &item: valueAndKeyList)
	{
		QStringList keyvaule = item.split(SplitSymbol);
		m_SettingsFile->setValue(keyvaule[0], keyvaule[1]);
	}
	m_SettingsFile->endArray();
	return true;
}

QString IniFileProcesser::fetchSpecGroupAndKeyValue(const QString &group, const QString &key)
{
	m_SettingsFile->beginGroup(group);
	QString value = m_SettingsFile->value(key).toString();
	m_SettingsFile->endGroup();
	return value;
}

int IniFileProcesser::getGroupKeycount(const QString &group)
{
	m_SettingsFile->beginGroup(group);
	int keynum = m_SettingsFile->childKeys().length();
	m_SettingsFile->endGroup();
	return keynum;
}

QStringList IniFileProcesser::fetchAnGroupValue(const QString &group)
{
	m_SettingsFile->beginGroup(group);
	QStringList  valuelist;
	Q_FOREACH(QString item, m_SettingsFile->childKeys())
	{
		valuelist.append(m_SettingsFile->value(item).toString());
	}
	m_SettingsFile->endGroup();
	return valuelist;
}

IniFileProcesser::VALUELISTDIC IniFileProcesser::fetchValueDictFromIni()
{
	VALUELISTDIC vaulelistdict;
	QStringList Grounps  = m_SettingsFile->childGroups();
	std::list<std::pair<QString, QString>> grounpvaulelist;
	Q_FOREACH(QString grounpitem, Grounps)
	{
		m_SettingsFile->beginGroup(grounpitem);                             
		QStringList KeyList = m_SettingsFile->childKeys();
		Q_FOREACH(QString item, KeyList)
		{
			grounpvaulelist.push_back({item,m_SettingsFile ->value(item).toString()});
		}
		vaulelistdict.insert(grounpitem, grounpvaulelist);
		grounpvaulelist.clear();
		m_SettingsFile->endGroup();
	}
	return vaulelistdict;
}
