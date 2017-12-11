import itchat
import requests
from itchat.content import *

'''
2017.12.08
照着itchat的官方demo，做了一个简单的微信自动回复机器人，
调用了腾讯的图灵机器人，已经尝试过打包运行，暂时没有问题
'''


L=[]
#KEY = '71f28bf79c820df10d39b4074345ef8c'
KEY = 'fc85cfe4f39f4f64b89ecd8cc31d7a71' #方面包
remind_flag = True
def get_responses(msg):
    '''
    向腾讯图灵机器人发送请求，调用小机器人
    '''
    apiUrl = 'http://www.tuling123.com/openapi/api'
    data = {
        'key'    :KEY,
        'info'   :msg,
        'userid' :'wechat-robot',
    }
    try:
        r = requests.post(apiUrl, data = data).json()
        return r.get('text')
    except:
        return

@itchat.msg_register(TEXT)
def tuling_reply(msg):
    '''
    微信自动回复
    '''
    defaultReply = 'I receive:' + msg['Text']
    reply = get_responses(msg['Text'])
    global remind_flag
##    if remind_flag:
##        if msg['Text'] == '1':
##            remind_flag = False
##            L.append(msg['FromUserName'])
##            itchat.send(u'小机器人来和你玩耍耍了',msg['FromUserName'])
##            #itchat.send(u'小面包来和你玩耍耍了',toUserName='filehelper')
##        else:
##            itchat.send(u'用户不在，请稍后联系,或者与小机器人玩耍,请按1'
##                    ,msg['FromUserName'])
####            itchat.send(u'用户不在，请稍后联系,或者与小机器人玩耍,请按1'
####                    ,toUserName='filehelper')
##
##    else:
##
##        itchat.send(u'小面包说'+ (reply or defaultReply),toUserName='filehelper')
    if msg['FromUserName'] in L:
        itchat.send(reply or defaultReply,msg['FromUserName'])
    elif msg['FromUserName'] not in L:
        if msg['Text'] == '1':
            L.append(msg['FromUserName'])
            itchat.send(u'小机器人来和你玩耍耍了',msg['FromUserName'])
        else:
            itchat.send(u'用户不在，请稍后联系,或者与小机器人玩耍,请按1'
                    ,msg['FromUserName'])


itchat.auto_login(hotReload = True)
itchat.run()
