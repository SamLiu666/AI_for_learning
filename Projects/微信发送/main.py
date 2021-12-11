'''
Description: 微信 定时发送消息
Version: 2.0
Autor: lxp
Date: 2021-12-06 12:28:18
LastEditors: lxp
LastEditTime: 2021-12-06 12:40:30
'''
# 导入模块
from wxpy import *
# 初始化机器人，扫码登陆
bot = Bot()

# 搜索名称含有 "游否" 的男性深圳好友
my_friend = bot.friends().search('文件传输助手')[0]

# 发送文本给好友
my_friend.send('Hello WeChat!')
# 发送图片
my_friend.send_image('my_picture.jpg')

print("Done")
