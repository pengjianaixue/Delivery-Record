import requests
from   PageInfoFecth import *
from   Configruation import *
from   XmlReader import  *
import  sys
if __name__ == '__main__':
    loginURL = LOGINURL
    loginjumptopage = LOGINJUMPTOPAGE
    requestsSession = requests.Session()
    # Step 1: Retrieve a login token
    paramPageRequest = {
        "title": "Special:UserLogin",
        "returnto": loginjumptopage,
    }
    try:
        Response = requestsSession.get(url=loginURL, params=paramPageRequest)
        if Response.status_code ==200 and Response.content:
            wpName     = USERNAME
            wpPassword = USERPASSWORD
            '''
            Get the login token
            '''
            wpLoginToken   =   getInputTagVaule(Response.text,'wpLoginToken')#getInputTagVauleWithBslib(Response.text,'input',{'name':'wpLoginToken'},'value')
            wpEditToken    =   getInputTagVaule(Response.text,'wpEditToken')
            authAction     =   getInputTagVaule(Response.text,'authAction')
            wploginattempt =   getInputTagVaule(Response.text,'wploginattempt')
            wpRemember = '1'
            paramLogin = {
                "title": "Special:UserLogin",
                "returnto": loginjumptopage,
            }
            loginData = {
                'authAction': authAction,
                'force': '',
                'title': 'Special: UserLogin',
                'wpEditToken':wpEditToken,
                'wploginattempt': wploginattempt,
                'wpLoginToken': wpLoginToken,
                'wpName': wpName,
                'wpPassword': wpPassword,
                'wpRemember': wpRemember
            }
            # login
            Response = requestsSession.post(LOGINURL, data=loginData,params=paramPageRequest)
            if Response.status_code == 200:
                print('user login success')
            else:
                print('user login failed, pealse check your username and password')
                exit(-1)
            EDITSECTION = EDITSECTION.replace('"','')
            editsection =  getInputTagVauleUseBsLib(Response.text,'a',{'title':'Edit section: {0}'.format(EDITSECTION)},'href')
            loginurl = 'https://' + str(list(dict((requestsSession.cookies._cookies)).keys())[0]) + editsection
            # turn to the Delivery Note page
            Response = requestsSession.get(loginurl)
            # fetch the Request payload	word
            wpUnicodeCheck = getHtmlTagValue(Response.text,'input','wpUnicodeCheck')
            wpAntispam = getHtmlTagValue(Response.text,'input','wpAntispam')
            editingStatsId = getHtmlTagValue(Response.text, 'input', 'editingStatsId')
            wpSection = getHtmlTagValue(Response.text, 'input', 'wpSection')
            wpStarttime = getHtmlTagValue(Response.text, 'input', 'wpStarttime')
            wpEdittime = getHtmlTagValue(Response.text, 'input', 'wpEdittime')
            editRevId = getHtmlTagValue(Response.text, 'input', 'editRevId')
            wpScrolltop = getHtmlTagValue(Response.text, 'input', 'wpScrolltop')
            if wpScrolltop is None:
                wpScrolltop = '0'
            wpAutoSummary = getHtmlTagValue(Response.text, 'input', 'wpAutoSummary')
            oldid = getHtmlTagValue(Response.text, 'input', 'oldid')
            parentRevId = getHtmlTagValue(Response.text, 'input', 'parentRevId')
            textformat = getHtmlTagValue(Response.text, 'input', 'format')
            model = getHtmlTagValue(Response.text, 'input', 'model')
            wpSummary = getHtmlTagValue(Response.text, 'input', 'wpSummary')
            wpWatchthis = getHtmlTagValue(Response.text, 'input', 'wpWatchthis')
            wpSave = getHtmlTagValue(Response.text, 'input', 'wpSave')
            wpEditToken = getHtmlTagValue(Response.text, 'input', 'wpEditToken')
            mode = getHtmlTagValue(Response.text, 'input', 'mode')
            wpUltimateParam = getHtmlTagValue(Response.text, 'input', 'wpUltimateParam')
            # wpTextbox1 = getHtmlTableData(Response.text,'wpTextbox1')
            #change html element fetch use bs4 lib
            wpTextbox1 = getHtmlTagValue(Response.text, 'textarea', 'wpTextbox1','text')
            try:
                ContentList = getAnSpecialCategoryValue('./DeliveryInformation.xml', 'DliveryInfo',['Value'])
                if len(ContentList) != int(CONTENTCOLUMNLIMT):
                    print('the Delivery content column in Delivery_Note_Template.txt is max than for the limit ,please check column or format ')
                    raise Exception('the Delivery content column in Delivery_Note_Template.txt is max than for the limit ,please check column or format')
                    exit(-1)
                wpTextbox1 = appendContentTotheTable(ContentList,wpTextbox1)
            except Exception as e:
                print('open Delivery_Note_Template.txt File Fail:'+ e.args,flush=True)
            RequestFormBody = {
               'wpUnicodeCheck':wpUnicodeCheck,
               'wpAntispam'    :wpAntispam,
               'editingStatsId':editingStatsId,
               'wpSection'     :wpSection,
               'wpStarttime'   :wpStarttime,
               'wpEdittime'    :wpEdittime,
               'editRevId'     :editRevId,
               'wpScrolltop'   :wpScrolltop,
               'wpAutoSummary' :wpAutoSummary,
               'oldid'         :oldid,
               'parentRevId'   :parentRevId,
               'format'        :textformat,
               'model'         :model,
               'wpTextbox1'    :wpTextbox1,
               'wpSummary'     :wpSummary,
               'wpWatchthis'   :wpWatchthis,
               'wpSave'        :wpSave,
               'wpEditToken'    :wpEditToken,
               'mode'           :mode,
               'wpUltimateParam':wpUltimateParam
            }
            paramEditSubmit = {
                'action':'submit',
                'title': loginjumptopage,
            }
            Response = requestsSession.post(LOGINURL, data=RequestFormBody, params=paramEditSubmit )
            if Response.status_code == 200:
                print('Update success.......',flush=True)
    except requests.RequestException as e:
        print('detect request exception')
        print('Requset response info:' + e.response)
        print('Requset Except info:'+ e.with_traceback())
        pass