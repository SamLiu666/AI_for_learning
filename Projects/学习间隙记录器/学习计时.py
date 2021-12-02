import time
import webbrowser
import xlrd
import xlwt
import datetime
import pygame
from xlutils.copy import copy
from selenium import webdriver


class Action(object):
    def __init__(self):
        self.action_name = '学习'  # 默认操作为学习
        self.action_time = 45  # 默认45分钟操作
        self.music = True  # 默认记时结束播放music
        self.FLAG = True  # 默认持续一整天，按q退出
        self.intervalMin = 1
        self.musicPath = "Projects\学习间隙记录器\data\骄傲的少年.mp3"
        self.now_time_start = datetime.datetime.now()
        self.now_time_end = datetime.datetime.now()

    def main(self):
        "主程序运行"
        while self.FLAG:
            self.getActionTime()
            if not self.FLAG:
                break
            self.now_time_start = datetime.datetime.now()
            self.learning()
            self.now_time_end = datetime.datetime.now()
            self.hintSome()
            self.playMusic()
            self.writeExcel()
            self.writeDB()
        print("Done")

    def getActionTime(self):
        "用户输入行为和时间"
        temp = input("输入行为名称和时间min(空格分隔，回车结束，q直接退出): ")
        if temp == 'q':
            print("学习已完成，记录并退出")
            self.FLAG = False
            return
        try:
            temp = temp.split()
            self.action_name = temp[0]
            self.action_time = int(temp[1]) * self.intervalMin
            print("已设定", self.action_name, "时长", self.action_time, "min")
        except:
            self.FLAG = False
            print("请核对输入格式是否正确")

    def learning(self):
        "学习"
        time.sleep(self.action_time)

    def playMusic(self):
        "学习结束播放音乐--本地音乐"
        # musicWeb = "https://music.163.com/#/discover/recommend/taste"
        # browser = webdriver.Chrome()  # 打开浏览器
        # browser.get(musicWeb)  # 获取网页
        # playButtun = browser.find_element_by_xpath(
        #     '//*[@id="g_player"]/div[1]/a[2]')
        # playButtun.click()

        pygame.mixer.init()
        # 设置 要播放音乐的绝对路径,绝对路径
        pygame.mixer.music.load(self.musicPath)
        # while True:
        if pygame.mixer.music.get_busy() == False:
            pygame.mixer.music.play()

    def hintSome(self):
        "待补充"
        messageInfo = self.action_name + "时长" + str(
            self.action_time) + "min" + "请查看命令行决定是否继续"
        # tkinter.messagebox.showinfo(messageInfo)
        print(messageInfo)

    def writeExcel(self):
        "写入excel进行记录"
        try:
            exfPath = r'Projects\学习间隙记录器\data\record.xls'
            # workbook = xlwt.Workbook()  # 新建一个工作簿
            # sheet = workbook.add_sheet('记录')  # 在工作簿中新建一个表格
            # workbook.save(exfPath)  # 保存工作簿

            workbook = xlrd.open_workbook(exfPath)  # 打开工作簿
            sheets = workbook.sheet_names()  # 获取工作簿中所有表格
            worksheet = workbook.sheet_by_name(sheets[0])  # 获取工作簿所有表格中第一个表格
            rows_old = worksheet.nrows  # 获取表格中已存在的行数
            new_workbook = copy(workbook)  # 将xlrd对象拷贝转化为xlwt对象
            new_worksheet = new_workbook.get_sheet(0)  # 获取转化后的工作簿第一个表格
            # 写入数据
            new_worksheet.write(rows_old, 0, self.action_name)
            new_worksheet.write(rows_old, 1, self.action_time)
            new_worksheet.write(
                rows_old, 2, self.now_time_start.strftime('%Y-%m-%d %H:%M:%S'))
            new_worksheet.write(
                rows_old, 3, self.now_time_end.strftime('%Y-%m-%d %H:%M:%S'))
            new_workbook.save(exfPath)
            print("已追加写入excel")
        except:
            print("记录时打开excel查看会发生错误")

    def writeDB(self):
        "写入数据库"
        print("writeDB")


if __name__ == '__main__':
    ac = Action()
    ac.main()