'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-12-14 14:10:08
LastEditors: lxp
LastEditTime: 2021-12-14 14:10:09
'''
import psutil
battery = psutil.sensors_battery()
plugged = battery.power_plugged
percent = str(battery.percent)
if plugged==False: plugged="Not Plugged In"
else: plugged="Plugged In"
print(percent+'% | '+plugged)