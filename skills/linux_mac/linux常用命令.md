<!--
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-06-01 22:17:16
 * @LastEditors: lxp
 * @LastEditTime: 2021-06-01 22:18:55
-->
```sh
# conda 操作
conda activate lxp_torch  # 激活虚拟环境
conda activate /home/kgcode/anaconda3/envs/lxp_torch
conda create -n py37 python=3.7  # 创建名为py37的虚拟环境
conda env list #查看虚拟环境
conda deactivate # 退出虚拟环境
```

```sh
# 解压、压缩操作
 unzip text.zip  # 压缩文件text.zip在当前目录下解压缩
 tar -xvzf # 解压缩
 ```

 ```sh
# 常用命令
free -m  # 查看内存使用情况
top  # 查看CPU使用情况
nvidia-smi # 查看显卡使用情况
df -h  # 查看磁盘使用情况
du -h --max-depth=1 filedir/  # 查看某个文件夹
 ```