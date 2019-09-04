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
	m_RootNode = m_PugiXmlDocument.append_child(rootname.toStdString().c_str());
	pugi::xml_node pre = m_PugiXmlDocument.prepend_child(pugi::node_declaration);
	pre.append_attribute("version") = "1.0";
	pre.append_attribute("encoding") = "utf-8";
}

/*

Ref:wirte an category data to xml file
Author:jian peng
Date:2019/9/2
Param:categoryName<QString>			- name of category name
Param:childName<QString>			- name of category child
Param:attriNameList<QStringList>	- child's attribute name list
Param:valueList<QStringList>		- attribute vaule list,  the each attribute item vaule combile with "/"
Return:bool 
*/
bool XmlWirter::writeAncategoryData(const QString &categoryName, const QString &childName, const QStringList &attriNameList, const QList<QStringList> &valueList)
{

	pugi::xml_node nodeCommentBooks = m_RootNode.append_child(pugi::node_comment);
	nodeCommentBooks.set_value(categoryName.toStdString().c_str());
	pugi::xml_node node = m_RootNode.append_child(categoryName.toStdString().c_str());
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

bool XmlWirter::saveToFile(const QString& FilePath)
{
	return m_PugiXmlDocument.save_file(FilePath.toStdWString().c_str(), "\t", 1U, pugi::encoding_utf8);
}


