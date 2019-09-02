#pragma once

#include <QObject>
#include <pugixml.hpp>
class XmlWirter : public QObject
{
	Q_OBJECT
	
public:
	XmlWirter(QObject *parent);
	~XmlWirter();
	//API
	bool emptyXmlDoc();
	void fileStructInit(const QString &rootname);
	bool writeAncategoryData(const QString &categoryName, const QString &childName, const QStringList &attriNameList, const QStringList &valueList);
	bool saveToFile(const QString& FilePath);
private:
	pugi::xml_document	m_PugiXmlDocument;
	pugi::xml_node      m_RootNode;
	QString				m_strRootName;
};
