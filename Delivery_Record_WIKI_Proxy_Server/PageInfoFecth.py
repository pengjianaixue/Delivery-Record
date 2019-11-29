import re
import bs4
# def combinationRequestFormData(wordname = [''],wordvaule=[''],splitword='',isTableHead=False):
#     WordHead = ''
#     if len(wordname) != len(wordvaule):
#         return  None
#     if isTableHead:
#         WordHead = splitword + '\n'
#     for i in range(len(wordname)):
#         if i == len(wordname)-1:
#             splitword = splitword + '--'+'\n'
#         WordHead = WordHead + 'Content-Disposition: form-data; name="{0}"\r\n\r\n{1}\r\n{2}\n'.format(wordname[i],wordvaule[i],splitword)
#     return WordHead
def appendContentTotheTable(ContentList = [],TableContent=''):
    newDeliveryContent = ''
    newDeliveryTable = ''
    for i in range(len(ContentList)):
        print('delivery content item:{0}'.format(ContentList[i]),flush=True)
        splitstr = '|{0}\n'
        if i == len(ContentList) -1:
            splitstr ='|{0}'
        newDeliveryContent = newDeliveryContent + '|{0}\n'.format(str(ContentList[i]).replace('\n','<br>'))
        # newDeliveryContent = newDeliveryContent + '|{0}'.format(str(i))
    splitstrlist = re.split('\|-',TableContent)
    if len(splitstrlist)>0:
        newDeliveryTable =  splitstrlist[0].replace('&lt;','<')   #re.split('|}$','',TableContent)
        newDeliveryTable = newDeliveryTable + '|-\n'+ newDeliveryContent
    else:
        splitstrlist = re.split(r'(\|)}$', TableContent)
        if len(splitstrlist)>0:
            newDeliveryTable = splitstrlist[0].replace('&lt;', '<')
            newDeliveryTable = newDeliveryTable + '|-\n' + newDeliveryContent + '\n|}'
            return newDeliveryTable
            pass
        else:
            raise Exception("slpit table content error")
    for item in range(len(splitstrlist)):
        if item ==0:
            continue
        newDeliveryTable =  newDeliveryTable + '|-' + str(splitstrlist[item]).replace('&lt;','<')
    return newDeliveryTable
    pass

# def getHtmlTableData(PageContent = '',tagname=''):
#     """
#     :param PageContent:
#     :param tagname:
#     :return:
#     """
#     pattern = r'<textarea(.*"{0}"[\S\s]*)textarea>'.format(tagname)
#     findlist = re.findall(pattern, PageContent)
#     if len(findlist) > 0:
#         vaulelist = re.findall(r'(===[\S\s]*?\})', findlist[0])
#         if len(vaulelist) > 0:
#             return vaulelist[0]
#     pass
def getHtmlTagValue(PageContent = '', tagtype = '',tagname='',getvaulename = 'value'):
    """
    :param getvaulename:
    :param PageContent:
    :param tagtype:
    :param tagname:
    :return:tagname value
    """
    return getInputTagVauleUseBsLib(PageContent,tagtype,{'name':tagname},getvaulename);
    # pattern = r'<{0}([\S ][^<]+?name=["\']{1}["|\'].*?)/>'.format(tagtype,tagname)
    # findlist = re.findall(pattern, PageContent)
    # if len(findlist)>0:
    #     vaulelist = re.findall(r'value=["|\'](.*?)["|\']',findlist[0])
    #     if  len(vaulelist)>0:
    #         # vaulelist = re.findall(r'".*"',vaulelist[0])
    #         # if len(vaulelist)>0:
    #             return vaulelist[0]
    pass
def getInputTagVaule(PageContent = '', tagname=''):
    """
    :param PageContent:
    :param tagname:
    :return:tagname value
    """
    return getInputTagVauleWithBslib(PageContent,'input',{'name':tagname},'value')
    # findlist = re.findall(tagname+ r'.*[/>\|>]',PageContent)
    # if len(findlist)>0:
    #     vaulelist = re.findall(r'value="([\S| ^=]+?)"',findlist[0])
    #     if  len(vaulelist)>0:
    #         # vaulelist = re.findall(r'".*"',vaulelist[0])
    #         # if len(vaulelist)>0:
    #             return vaulelist[0]
    pass
def getInputTagVauleWithBslib(PageContent , tagname,attrs={},getvaulename=''):
    response = bs4.BeautifulSoup(PageContent, 'html.parser')
    tagcontent = response.find_all(tagname, attrs)
    if len(tagcontent) > 0:
        return tagcontent[0].attrs[getvaulename]
    pass

def getInputTagVauleUseBsLib(PageContent, tagname,attrs={}, getvaulename = ''):

    """
    :param getvaulename:
    :param PageContent:
    :param tagname: tagname:str
    :param attrs: attrs dict:dict
    :return:
    """
    response = bs4.BeautifulSoup(PageContent, 'html.parser')
    tagcontent=  response.find_all(tagname,attrs)
    if len(tagcontent) > 0 :
        if getvaulename == 'text':
            return tagcontent[0].text
        else:
            return dict(tagcontent[0].attrs).get(getvaulename)
    pass