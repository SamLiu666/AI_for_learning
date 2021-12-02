'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-12-02 13:39:55
LastEditors: lxp
LastEditTime: 2021-12-02 14:52:44
'''
import tkinter as tk
from PIL import Image, ImageTk
import tkinter.messagebox
from Learning_interval import Learning
"""https://zhuanlan.zhihu.com/p/81429343"""


class Learning_Window(tk.Tk):
    def __init__(self, freq=1, music=False, interval=1):
        super(Learning_Window, self).__init__()
        self.freq = freq  # 默认至少设定两次学习
        self.music = music
        self.action_time = interval
        self.action_name = "学习"
        self.action_time = 1
        self.play_music = True

    def main_run(self):
        # 顺序会按程序顺序执行
        self.create_window()  # 1.创建窗口
        self.show_picture()  # 2.显示图片
        self.button_design()  # 3.学习按钮 单击启动学习
        self.get_int()  # 4.获取学习设定次数
        self.mainloop()

    # 1. 窗口外观尺寸设计
    def create_window(self):
        self.geometry('300x600')
        self.title(" Action ")

    # 2. 窗口 按钮设计
    def button_design(self):

        # 设定行为和时间
        tk.Label(self, text="输入行为：如学习").pack()
        self.action_name = tk.Entry(self, textvariable=tk.StringVar()).pack()
        tk.Label(self, text="输入间隔：如45").pack()
        self.action_time = tk.Entry(self, textvariable=tk.StringVar()).pack()

        # 提前结束按钮
        self.btn3 = tk.Button(master=self, text="退出",
                              command=self.exit_window).pack(padx=0, pady=20)

    # 4.学习主循环
    def get_int(self):
        try:
            print('设定action为：', self.action_name,
                  " 时间" + str(self.action_time) + "分钟/次：")
            tk.messagebox.showinfo(
                "提示",
                "已确定学习: " + str(self.action_time) + " 分钟/次\n" + "请点击开始学习按钮")
            self.start_learning()
        except:
            print('设定action为：', self.action_name,
                  " 时间" + str(self.action_time) + "分钟/次：")
            tk.messagebox.showwarning("警告", "请输入整数")

    # 3. 窗口 实现功能： 单击开始学习，获取学习次数，提前结束学习，记录学习次数
    def start_learning(self):
        learning_bool = tkinter.messagebox.askyesno(
            '提示', '确定要开始学习吗')  # 是/否，返回值true/false
        # count = 0
        if learning_bool == True:
            s = Learning(counts=self.freq,
                         interval=self.action_time)  # 设定 学习次数，学习时长
            s.music = self.music  # 是否播放音乐 bool
            print("学习中。。。")
            s.start_()
            count = s.freq
            print("此次学习设定{}次，已完成{}次".format(self.freq, count))
        else:
            print("学习已取消")

    # 5. 窗口放入图片
    def show_picture(self):
        im = Image.open(r"Projects\学习间隙记录器\window\picture\test.jpg")
        # im = Image.open("picture/test.jpg")
        global img
        img = ImageTk.PhotoImage(im)
        imLabel = tk.Label(self, image=img).pack()  # 全局变量

    # 6、确认播放音乐
    def play_music(self):
        self.music = tkinter.messagebox.askyesno(
            '提示', '学习结束播放音乐吗？\n 确定后点击开始学习按钮')  # 是/否，返回值true/false

    # 7、结束退出程序
    def exit_window(self):
        self.destroy()
        print("已退出学习")


if __name__ == '__main__':

    win = Learning_Window()
    win.main_run()
