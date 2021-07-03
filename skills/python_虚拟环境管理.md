<!--
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-07-03 12:11:16
 * @LastEditors: lxp
 * @LastEditTime: 2021-07-03 12:21:57
-->
virtualenv venv
.\Scripts\activate.bat  #  C:\Users\lxp\dl_lxp
deactivate  # 退出环境
rmvirtualenv venv 删除环境

pip freeze #查看当前安装库版本
#创建 requirements.txt 文件，其中包含了当前环境中所有包及 各自的版本的简单列表
#保持部署相同，一键安装所有包
pip install -r requirements.txt
pip freeze > requirements.txt 
lsvirtualenv    #列举所有的环境
cdvirtualenv    #导航到当前激活的虚拟环境的目录中，相当于pushd 目录
cdsitepackages   # 和上面的类似，直接进入到 site-packages 目录
lssitepackages     #显示 site-packages 目录中的内容