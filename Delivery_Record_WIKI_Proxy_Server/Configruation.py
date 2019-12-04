import glob
import configparser
import  base64
import XmlReader
configurationFile =  glob.glob(pathname = './DeliveryInformation.xml')
cf = configparser.ConfigParser()
LOGINURL = 'https://lte-wiki.rnd.ki.sw.ericsson.se/w/index.php'
USERNAME =''
USERPASSWORD=''
EDITSECTION=''
LOGINJUMPTOPAGE = ''
CONTENTCOLUMNLIMT=''
if len(configurationFile)>0:
    userInformation = XmlReader.getAnSpecialCategoryValue('./DeliveryInformation.xml','Delivery_configure_Infor',['Item','Value'])
    # cf.read('./RecordTemp.ini', encoding='utf-8')
    # Filed name
    for informationItem in userInformation:
        if informationItem.index(0) == 'username':
            USERNAME = informationItem.index(1)
        elif informationItem.index(0) == 'password':
            USERPASSWORD = base64.b64decode(informationItem.index(1))
        elif informationItem.index(0) == 'editsection':
            EDITSECTION = informationItem.index(1)
        elif informationItem.index(0) == 'emailsubject':
            EMAILSUJECT = informationItem.index(1)
        elif informationItem.index(0) == 'emailsender':
            EMAILSENDER = informationItem.index(1)
    # USERNAME = cf.get('user_configure', 'username')
    # USERPASSWORD = base64.b64decode(cf.get('user_configure', 'password'))
    # EDITSECTION = cf.get('user_configure', 'editsection')
    # EMAILSUJECT = cf.get('user_configure', 'emailcomments')
    # EMAILSENDER = cf.get('user_configure', 'emailsender')
    EMAILRECVIERS = []
    DELIVERY_TABLE_HEAD = []
    emailReceiverInformation = XmlReader.getAnSpecialCategoryValue('./DeliveryInformation.xml', 'Delivery_EmailReceiver_Infor',
                                                          ['Receiver_Number', 'Receiver_Address'])
    # items = cf.options('user_configure')
    # recviercount = len(items) - 5
    for reveiver in emailReceiverInformation:
        EMAILRECVIERS.append(reveiver.index(1))
    wikiInformation = XmlReader.getAnSpecialCategoryValue('./DeliveryInformation.xml',
                                                                   'Wiki_Infor',
                                                                   ['Item', 'Value'])
    for wikiItem in wikiInformation:
        if wikiItem.index(0)  == 'loginjumptopage':
            LOGINJUMPTOPAGE = wikiItem.index(1)
        elif wikiItem.index(0) == 'tablecolumnlimt':
            CONTENTCOLUMNLIMT = wikiItem.index(1)
    deliveryTableInformation = XmlReader.getAnSpecialCategoryValue('./DeliveryInformation.xml',
                                                          'Delivery_Infor',
                                                          ['ItemTitle', 'Value'])
    for deliveryTableItem in deliveryTableInformation:
        DELIVERY_TABLE_HEAD.append(deliveryTableItem[0])


    # for i in range(recviercount):
    #     EMAILRECVIERS.append(cf.get('user_configure', 'recvier_'+str(i)))
    # items = cf.options('Dilivery_table_configure')
    # for item in items:
    #     DELIVERY_TABLE_HEAD.append(cf.get('Dilivery_table_configure',item))
    # CONTENTCOLUMNLIMT = cf.get('wikipage_configure', 'tablecolumnlimt')
    # LOGINJUMPTOPAGE = cf.get('wikipage_configure', 'loginjumptopage')

else:
    raise NotADirectoryError('can not find the configuration.ini file')