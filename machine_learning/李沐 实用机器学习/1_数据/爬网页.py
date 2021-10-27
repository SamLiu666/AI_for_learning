'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-10-27 20:01:28
LastEditors: lxp
LastEditTime: 2021-10-27 20:03:57
'''
from selenium import webdriver
chrome_optimes = webdriver.ChromOptions()
chrome_optimes.headless = False  # 是否显示图形化界面
chrome = webdriver.Chrome(chrome_options=chrome_optimes)

url = "www.baidu.com"
page = chrome.get(url)
