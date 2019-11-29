import requests
from  PageInfoFecth import *
from  Configruation import *
import random
import copy
import os
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
            wpLoginToken   =   getInputTagVaule(Response.text,'wpLoginToken')
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
            paramEdit = {
                'title': loginjumptopage,
                'action': 'edit',
                'section': EDITSECTION
            }
            # turn to the Delivery Note page
            Response = requestsSession.get(LOGINURL,params=paramEdit)
            # fetch the Request payload	word
            # wordList = []
            # wordValueList = []
            # wordList.append('wpUnicodeCheck')
            # wordList.append('wpAntispam')
            # wordList.append('editingStatsId')
            # wordList.append('wpSection')
            # wordList.append('wpStarttime')
            # wordList.append('wpEdittime')
            # wordList.append('editRevId')
            # wordList.append('wpScrolltop')
            # wordList.append('wpAutoSummary')
            # wordList.append('oldid')
            # wordList.append('parentRevId')
            # wordList.append('format')
            # wordList.append('model')
            # wordList.append('wpTextbox1')
            # wordList.append('wpSummary')
            # wordList.append('wpWatchthis')
            # wordList.append('wpSave')
            # wordList.append('wpEditToken')
            # wordList.append('mode')
            # wordList.append('wpUltimateParam')
            wpUnicodeCheck = getHtmlTagValue(Response.text,'input','wpUnicodeCheck')
            wpAntispam = getHtmlTagValue(Response.text,'input','wpAntispam')
            editingStatsId = getHtmlTagValue(Response.text, 'input', 'editingStatsId')
            wpSection = getHtmlTagValue(Response.text, 'input', 'wpSection')
            wpStarttime = getHtmlTagValue(Response.text, 'input', 'wpStarttime')
            wpEdittime = getHtmlTagValue(Response.text, 'input', 'wpEdittime')
            editRevId = getHtmlTagValue(Response.text, 'input', 'editRevId')
            wpScrolltop = getHtmlTagValue(Response.text, 'input', 'wpScrolltop')
            if wpScrolltop ==None:
                wpScrolltop = '0'
            wpAutoSummary = getHtmlTagValue(Response.text, 'input', 'wpAutoSummary')
            oldid = getHtmlTagValue(Response.text, 'input', 'oldid')
            parentRevId = getHtmlTagValue(Response.text, 'input', 'parentRevId')
            format = getHtmlTagValue(Response.text, 'input', 'format')
            model = getHtmlTagValue(Response.text, 'input', 'model')
            wpSummary = getHtmlTagValue(Response.text, 'input', 'wpSummary')
            wpWatchthis = getHtmlTagValue(Response.text, 'input', 'wpWatchthis')
            wpSave = getHtmlTagValue(Response.text, 'input', 'wpSave')
            wpEditToken = getHtmlTagValue(Response.text, 'input', 'wpEditToken')
            mode = getHtmlTagValue(Response.text, 'input', 'mode')
            wpUltimateParam = getHtmlTagValue(Response.text, 'input', 'wpUltimateParam')
            wpTextbox1 = getHtmlTableData(Response.text,'wpTextbox1')
            # wordValueList.append(wpUnicodeCheck)
            # wordValueList.append(wpAntispam)
            # wordValueList.append(editingStatsId)
            # wordValueList.append(wpSection)
            # wordValueList.append(wpStarttime)
            # wordValueList.append(wpEdittime)
            # wordValueList.append(editRevId)
            # wordValueList.append(wpScrolltop)
            # wordValueList.append(wpAutoSummary)
            # wordValueList.append(oldid)
            # wordValueList.append(parentRevId)
            # wordValueList.append(format)
            # wordValueList.append(model)

            # Edit Delivery Note Table
            # boundarysy = '-----------------------------' + ''.join(str(random.choice(range(10))) for i in range(14))
            # wordlistHead = copy.deepcopy(wordList[0:13])
            # wordlistTail = copy.deepcopy(wordList[13:])
            # # wordValuelistHead = copy.deepcopy(wordValueList[0:12])
            # # wordValuelistTail = copy.deepcopy(wordValueList[13:])
            # RequestFormBody = combinationRequestFormData(wordlistHead,wordValueList,boundarysy,True)
            try:
                with open('./Delivery_Note_Template.txt','r') as  DeliveryContentFile:
                    DeliveryContent = DeliveryContentFile.read()
                    ContentList  = DeliveryContent.split('@|')[1:]
                    if len(ContentList) != int(CONTENTCOLUMNLIMT):
                        print('the Delivery content column in Delivery_Note_Template.txt is max than for the limit ,please check column or format ')
                        os.system("pause")
                        exit(-1)
                    wpTextbox1 = appendContentTotheTable(ContentList,wpTextbox1)
                    # wordValueList.append(wpTextbox1)
            except Exception as e:
                print('open Delivery_Note_Template.txt File Fail:'+ e.args)

            # wordValueList.append(wpSummary)
            # wordValueList.append(wpWatchthis)
            # wordValueList.append(wpSave)
            # wordValueList.append(wpEditToken)
            # wordValueList.append(mode)
            # wordValueList.append(wpUltimateParam)
            # RequestFormBody = RequestFormBody + combinationRequestFormData(wordlistTail,wordValueList[13:],boundarysy,False)
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
               'format'        :format,
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
            # RequestHeaders  = {
            #     'Accept':r'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
            #     'Accept-Encoding':r'gzip, deflate, br',
            #     'Accept-Language':r'Accept-Language',
            #     'Connection': r'keep-alive',
            #     'Content-Type': r'multipart/form-data; boundary='+boundarysy,
            # }
            Response = requestsSession.post(LOGINURL, data=RequestFormBody, params=paramEditSubmit )
            if Response.status_code ==200:
                print('Update Success.......')
    except requests.RequestException as e:
        print('detect request exception')
        print('Requset response info:' + e.response)
        print('Requset Except info:'+ e.with_traceback())
        pass