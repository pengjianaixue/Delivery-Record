#include "stdafx.h"
#include "XmlReader.h"

XmlReader::XmlReader(QObject *parent)
	: QObject(parent)
{

	
}

XmlReader::~XmlReader()
{
	
}

bool XmlReader::openFile(const QString& FileName)
{
	m_PugiXmlDocument.reset();
	pugi::xml_parse_result res = m_PugiXmlDocument.load_file(FileName.toStdString().c_str(), pugi::parse_default, pugi::encoding_utf8);
	if (res)
	{
		m_currentNode = m_PugiXmlDocument.first_child(); //m_PugiXmlDocument.child(m_strRootName.toStdString().c_str());
	}
	return res;
}
void XmlReader::setCurrentNode(const QString &nodeName)
{
	m_currentNode = m_PugiXmlDocument.child(nodeName.toStdString().c_str());
	return;
}

/*

Ref:read an category special child  data 
Author:jian peng
Date:2019/9/2
Param:categoryName<QString>			- name of category name
Param:childName<QString>			- name of category child
Param:attriNameList<QStringList>	- child's attribute name list
Param:valueList<QList<QList<std::pair<QString,QString>>> &>		
- save the each child's attribute name and value to the list
Return:bool
*/
bool XmlReader::getAnSpecialCategoryValue(const QString	&categoryName, const QString  &childName, const QStringList &attriNameList, QList<QList<std::pair<QString,QString>>> &valueList)
{
	//pugi::xml_node nodeRoot = m_PugiXmlDocument.child(m_strRootName.toStdString().c_str());
	pugi::xml_node nodechild = m_currentNode.child(categoryName.toStdString().c_str());
	for (pugi::xml_node node = nodechild.first_child(); node; node = node.next_sibling())
	{
		QList<std::pair<QString, QString>>  attriValue;
		if (childName != node.name())
		{
			continue;
		}
		for (auto &item: attriNameList)
		{
			attriValue.append({ item,node.attribute(item.toStdString().c_str()).value() });
		}
		valueList.append(attriValue);
		attriValue.clear();
	}
	return true;
}
