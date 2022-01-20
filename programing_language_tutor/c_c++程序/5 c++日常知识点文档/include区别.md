<!--
 * @Author: [lxp]
 * @Date: 2022-01-18 20:05:20
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-01-18 20:05:21
 * @Description: 
-->
 #include <> 和 #include "" 都会在实现定义的位置查找文件，并将其包含。

区别是若 #include "" 查找成功，则遮蔽 #include <> 所能找到的同名文件；否则再按照 #include <> 的方式查找文件。另外标准库头文件都放在 #include <> 所查找的位置。

一般来说 #include <> 的查找位置是标准库头文件所在目录， #include "" 的查找位置是当前源文件所在目录。不过这些都可由编译器调用参数等配置更改。