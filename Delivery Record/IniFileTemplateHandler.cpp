#include "stdafx.h"
#include "IniFileTemplateHandler.h"


IniFileTemplateHandler::IniFileTemplateHandler(QString iniFilePath)
{
	m_SettingsFile = std::make_shared<QSettings>(iniFilePath, QSettings::IniFormat);
}

IniFileTemplateHandler::~IniFileTemplateHandler()
{
}

bool IniFileTemplateHandler::writeValueDictToIni(VALUELISTDIC valueDict)
{
	return false;
}

QString IniFileTemplateHandler::fetchSpecGroupAndKeyValue(QString group, QString key)
{
	m_SettingsFile->beginGroup(group);
	QString value = m_SettingsFile->value(key).toString();
	m_SettingsFile->endGroup();
	return value;
}

int IniFileTemplateHandler::fetchAnGroupValue(QString group)
{
	m_SettingsFile->beginGroup(group);
	QStringList  valuelist;
	Q_FOREACH(QString item, m_SettingsFile->childKeys())
	{
		valuelist.append(m_SettingsFile->value(item).toString());
	}
	m_SettingsFile->endGroup();
	return 0;
}

IniFileTemplateHandler::VALUELISTDIC IniFileTemplateHandler::fetchValueDictFromIni()
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
