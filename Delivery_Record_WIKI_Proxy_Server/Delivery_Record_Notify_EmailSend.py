# import  sys
import Configruation
import   XmlReader
from email.mime.text import MIMEText
from email.utils import formataddr
from email.header import Header
# from email.mime.application import MIMEApplication
# from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
import smtplib
account =  Configruation.USERNAME + '@ericsson.com'
sender = Configruation.EMAILSENDER #'jian.peng@ericsson.com'
receivers = Configruation.EMAILRECVIERS
passwd = str(Configruation.USERPASSWORD,'utf-8')
mailcontents = Configruation.EMAILCOMMENTS
mailserver = 'se-smtp.ericsson.se'
sub = 'Product Delivery Update Notify'
try:
    msg = MIMEMultipart('related')
    print('mail sender is :' + str(sender))
    msg['From'] = formataddr(["sender", sender])
    print('mail recvier list:'+ ','.join(receivers))
    msg['To'] =  Header(",".join(receivers)) #formataddr(["receiver", receive])
    msg['Subject'] = mailcontents
    print('mail Subject is :' + str(mailcontents))
    #contents information
    # msg.attach(txt)
    # txt = MIMEText(Configruation.LOGINURL+'?title='+Configruation.LOGINJUMPTOPAGE, 'plain', 'utf-8')
    # msg.attach(txt)
    #attach file
    # attach = MIMEApplication(open("D:\xx\\tool\pycharm\\1.csv").read())
    # attach.add_header('Content-Disposition', 'attachment', filename='1.csv')
    # msg.attach(attach)
    tableHeadTemplate = ' <td style= "color:white" align="center">{0}</td>'
    tableContentsTemplate = '<td align="center">{0}</td>'
    tableContentsLinkTemplate = '<a href = {0}> {1} </a>'
    emailCommentsTemplate = '<h4 id ="155" font > <strong> {0} </strong> </h4> <p style="text-indent:1em">{1}</p>'
    # emailCommentsContentsTemplate = '<p style="text-indent:1em;" class="comments" >{0}</p>'
    tableContents = ''
    tableHeads = ''
    emailComments = ''
    wikiLink = tableContentsLinkTemplate.format(Configruation.LOGINURL+'?title='+Configruation.LOGINJUMPTOPAGE,'The Delivery Note Wiki Link')
    for head in Configruation.DELIVERY_TABLE_HEAD:
        tableHeads = tableHeads + tableHeadTemplate.format(head)
    tableContents = ''
    contentList = XmlReader.getAnSpecialCategoryValue('./DeliveryInfor.xml', 'DliveryInfo','Value')
    for contentitem in contentList:
        contentitem = str(contentitem).replace('\n','<br>')
        if '[' in contentitem:
            contentitemlinklist =  contentitem.split(']')
            for contentitemlink in contentitemlinklist:
                if '[' in contentitemlink:
                    contentlist = contentitemlink.replace('[','').replace(']','').split(' ')
                    tablecellcontents = ''.join(contentlist[1:])
                    contentitem = tableContentsLinkTemplate.format(contentlist[0],tablecellcontents)
        tableContents = tableContents + tableContentsTemplate.format(contentitem)
    emailCommentsTitleList = XmlReader.getAnSpecialCategoryValue('./DeliveryInfor.xml', 'Delivery_Email_Content','Title')
    emailCommentsContentList = XmlReader.getAnSpecialCategoryValue('./DeliveryInfor.xml', 'Delivery_Email_Content', 'Contents')
    for i in range(len(emailCommentsTitleList)):
        emailComments = emailComments + emailCommentsTemplate.format(str(emailCommentsTitleList[i]).replace('\n', '<br>') ,
                                                                     str(emailCommentsContentList[i]).replace('\n','<br>&nbsp&nbsp'))
        # commentsContentsSpilt = str(emailCommentsContentList[i]).replace('\n','<br>')
        # commentsContents = ''
        # for row in emailCommentsContentList[i].split('\n'):
        #     commentsContents = commentsContents + emailCommentsContentsTemplate.format(row)
        # emailComments = emailComments+ commentsContents
    body = """
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Delivery Contents</title>
        <style type="text/css">
        p.comments{0}
        </style>
    </head>
    <body>
        {1}
        <table border="0" cellpadding="2">
           <tr id="125" bgcolor="#4682B4">
                {2}
            </tr>
            <tr bgcolor="#7fffd4">
                {3}
            </tr>
        </table>
        {4}
        <h5 id="135">  <br> <br> This page auto generate by delivery record program <br> </h5>
        <script>
            document.getElementById("135").innerHTML += Date()
        </script>
    </body>
    </html>
    """.format('{line-height: 5px;}',wikiLink,tableHeads,tableContents,emailComments)
    text = MIMEText(body, 'html', 'utf-8')
    # f = open('D:\xx\pip.png', 'rb')
    # pic = MIMEImage(f.read())
    # f.close()
    # pic.add_header('Content-ID', '<image>')
    msg.attach(text)
    server = smtplib.SMTP(mailserver, 587)
    # server.set_debuglevel(1)
    server.ehlo()
    server.starttls()
    try:
        server.login(sender, passwd)
    except Exception as e:
        try:
            server.login(account, passwd)
        except Exception as e:
            print('mail login  failed' + str(e.with_traceback()))
        pass
    print('mail server login success')
    server.sendmail(sender, receivers, msg.as_string())
    print('mail send...')
    print('mail send success')
    server.quit()
    print('mail server quit')
except Exception as e:
        print('mail script run error' + str(e.with_traceback()))