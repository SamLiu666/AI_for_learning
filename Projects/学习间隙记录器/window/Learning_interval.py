import time, winsound, pygame, webbrowser
import tkinter


class Learning:
    """学习提醒"""

    def __init__(self,interval=1, web="https://www.baidu.com/", counts=2, music=False, stop = False, freq=0):
        # 初始化
        self.interval = interval*60      # 学习时间* 45 *60
        self.web = web  # 开启网页
        self.counts = counts  # 学习设定一次循环次数，默认至少1次
        self.music = music  # 默认不播放音乐
        self.stop = stop
        self.freq = freq    # 实际学习次数

    def start_(self):
        # 主要部分
        while self.freq < self.counts:
            if self.stop == True:   break   # 强制退出
            time.sleep(self.interval)  # 设定为分钟，参数不要设置和time一样
            webbrowser.open(self.web)
            # 决定是否播放音乐
            if self.music == True:
                self.play_music()
            self.freq += 1
            print("今日已学习 {} 次（{}分钟/次）".format(self.freq, self.interval//60))
            if self.freq == self.counts:
                tkinter.messagebox.showinfo("提示", "设定学习" + str(self.freq) + "次已完成\n" + "如需继续学习，请重新设定学习次数")
                break
            learning_bool = self.Visualization()
            if learning_bool == False: break


    # 播放音乐，两首歌
    def play_music(self):
        j = self.freq   # 选择乐曲
        pygame.mixer.init()
        # 设置 要播放音乐的绝对路径,绝对路径
        # music1 = "Music/骄傲的少年.mp3"
        music1 = "D:\东蒙 人工智能课程\cs learning git\Project\window\Music\骄傲的少年.mp3"
        music2 = "D:\东蒙 人工智能课程\cs learning git\Project\window\Music\句号.mp3"
        if (j == 0):
            pygame.mixer.music.load(music1)
        else:
            pygame.mixer.music.load(music2)
        # while True:
        if pygame.mixer.music.get_busy() == False:
            pygame.mixer.music.play()
        # j = 1 if j == 0 else 0

    def Horn_to_remind(self):
        # 学习时间到，鸣笛，弹窗，休息之后关闭，重新循环
        duration = 600  # millisecond
        freq = 440  # Hz
        winsound.Beep(freq, duration)

    def Visualization(self):
        #easygui.msgbox("学习时间到！\n 若休息好，单击继续学习按钮", title="提示", ok_button=" 继续学习")
        return tkinter.messagebox.askyesno('提示', '已完成学习，是否继续')  # 是/否，返回值true/false
