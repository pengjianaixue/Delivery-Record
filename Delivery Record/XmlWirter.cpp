#include "stdafx.h"
#include "XmlWirter.h"

XmlWirter::XmlWirter(QObject *parent)
	: QObject(parent)
{
	
}

XmlWirter::~XmlWirter()
{

}

bool XmlWirter::emptyXmlDoc()
{
	m_PugiXmlDocument.reset();
	return true;
}

void XmlWirter::fileStructInit(const QString &rootname)
{
	m_currentNode = m_PugiXmlDocument.append_child(rootname.toStdString().c_str());
	pugi::xml_node pre = m_PugiXmlDocument.prepend_child(pugi::node_declaration);
	pre.append_attribute("version") = "1.0";
	pre.append_attribute("encoding") = "utf-8";
}

bool XmlWirter::setCurrentNode(const QString &nodeName)
{
	m_currentNode = m_PugiXmlDocument.child(nodeName.toStdString().c_str());
	//m_currentNode = m_PugiXmlDocument.find_child([&](const pugi::xml_node &node) {if (node.name() != nodeName.toStdString().c_str()) { return false; } return true; });
	if (m_currentNode.empty())
	{
		return false;
	}
	return true;
}

/*

Ref:wirte an category data to xml file
Author:jian peng
Date:2019/9/2
Param:categoryName<QString>			- name of category name
Param:childName<QString>			- name of category child
Param:attriNameList<QStringList>	- child's attribute name list
Param:valueList<QStringList>		- attribute string list of vaule list, the each QStringList.length() is eq to the attriNameList.length()
Return:bool 
*/
bool XmlWirter::writeAncategoryData(const QString &categoryName, const QString &childName, const QStringList &attriNameList, const QList<QStringList> &valueList)
{
	pugi::xml_node nodeCommentBooks = m_currentNode.append_child(pugi::node_comment);
	nodeCommentBooks.set_value(categoryName.toStdString().c_str());
	pugi::xml_node node = m_currentNode.append_child(categoryName.toStdString().c_str());
	for (auto &valueitem:valueList)
	{
		pugi::xml_node childnode = node.append_child(childName.toStdString().c_str());
		if (valueitem.length()!= attriNameList.length())
		{
			continue;
		}
		for (size_t i = 0; i < attriNameList.length(); i++)
		{
			childnode.append_attribute(attriNameList[i].toStdString().c_str()).set_value(valueitem[i].toStdString().c_str());
		}
	}
	return true;
}

bool XmlWirter::saveToFile(const QString &FilePath)
{
	return m_PugiXmlDocument.save_file(FilePath.toStdWString().c_str(), "\t", 1U, pugi::encoding_utf8);
}

bool XmlWirter::loadXmlFile(const QString &FilePath)
{
	m_PugiXmlDocument.reset();
	pugi::xml_parse_result res = m_PugiXmlDocument.load_file(FilePath.toStdString().c_str(), pugi::parse_default, pugi::encoding_utf8);
	return res;
}

bool XmlWirter::removeChild(const QString & childName)
{
	return m_currentNode.remove_child(childName.toStdString().c_str());;
}


