#pragma once

#include <QObject>
#include <pugixml.hpp>
#include <sstream>
class XmlReader : public QObject
{
	Q_OBJECT
	
public:
	XmlReader(QObject *parent);
	~XmlReader();
	//API
	bool openFile(const QString	&FileName);
	bool setRootName(const QString &RootName);
	bool getAnSpecialCategoryValue(const QString	&categoryName, const QString  &childName, const QStringList &attriNameList, QList<QList<std::pair<QString, QString>>> &valueList);
private:
	pugi::xml_document	m_PugiXmlDocument;
	QString				m_strRootName;
};
