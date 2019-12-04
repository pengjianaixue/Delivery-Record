from xml.etree import ElementTree as ET
from xml.dom import minidom
class XmlReader(object):
    """Read and parse Xml file"""

    def __init__(self, XmlName=''):
        self.XmlName = XmlName
        self.Tree = ET.parse(self.XmlName)
        self.XmlRoot = self.Tree.getroot()
        pass

    def GetElementAllSiblingattrib(self, ElementName,AttribName=[]):
        ElmentItemList = []
        for Elementitem in self.XmlRoot.iter(ElementName):
            attribtuple = []
            for AttribItem in AttribName:
                attribtuple.append(Elementitem.attrib[AttribItem])
            pass
            ElmentItemList.append(tuple(attribtuple))
        return ElmentItemList
        pass
    pass
def getAnSpecialCategoryValue(XmlName='',categoryName = '',AttribName = []):
    XmlReaderInstance = XmlReader(XmlName)
    return XmlReaderInstance.GetElementAllSiblingattrib(categoryName,AttribName)
    pass