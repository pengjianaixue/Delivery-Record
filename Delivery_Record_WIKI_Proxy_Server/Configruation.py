import glob
import configparser
import  base64
configurationFile =  glob.glob(pathname = './RecordTemp.ini')
cf = configparser.ConfigParser()
LOGINURL = 'https://lte-wiki.rnd.ki.sw.ericsson.se/w/index.php'
USERNAME =''
USERPASSWORD=''
EDITSECTION=''
LOGINJUMPTOPAGE = ''
CONTENTCOLUMNLIMT=''
if len(configurationFile)>0:
    cf.read('./RecordTemp.ini', encoding='utf-8')
    # Filed name
    USERNAME =cf.get('user_configure', 'username')
    USERPASSWORD = base64.b64decode(cf.get('user_configure', 'password'))
    EDITSECTION = cf.get('user_configure', 'editsection')
    EMAILCOMMENTS = cf.get('user_configure','emailcomments')
    EMAILSENDER = cf.get('user_configure', 'emailsender')
    EMAILRECVIERS = []
    DELIVERY_TABLE_HEAD = []
    items = cf.options('user_configure')
    recviercount = len(items) - 5
    for i in range(recviercount):
        EMAILRECVIERS.append(cf.get('user_configure', 'recvier_'+str(i)))
    items = cf.options('Dilivery_table_configure')
    for item in items:
        DELIVERY_TABLE_HEAD.append(cf.get('Dilivery_table_configure',item))
    CONTENTCOLUMNLIMT = cf.get('wikipage_configure', 'tablecolumnlimt')
    LOGINJUMPTOPAGE = cf.get('wikipage_configure', 'loginjumptopage')

else:
    raise NotADirectoryError('can not find the configuration.ini file')