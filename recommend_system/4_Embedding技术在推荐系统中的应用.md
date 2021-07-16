<!--
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-07-16 16:30:21
 * @LastEditors: lxp
 * @LastEditTime: 2021-07-16 17:05:09
-->
1. Embedding

概念：用一个低维稠密向量表示一个对象

重要性：表征能力更强

2. 经典的Embedding方法

2.1 Word2Vec

2.1.1 CBOW -- 利用周围词去预测中心词

2.1.2 Skip-Gram -- 利用中心词去预测周围词

训练：负采样--转为二分类问题

2.2 Item2vec 

双塔模型

3. Graph Embedding -- 引入更多结构信息的图嵌入技术

3.1 DeepWalk -- 基础的 Graph Embedding

3.2 Node2vec -- 同质性和结构性的权衡

3.3 EGES 

4. Youtube 推荐系统召回层模型

4.2 局部敏感哈西

召回搜索：物品总数为n，k维的Embedding空间，遍历计算用户与物品相似度时间复杂度为O(kn)，物品总数为几百万量级的推荐系统，这样做会导致服务过程的延迟

K-dTree

ANN ： 未提及