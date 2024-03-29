# 多源BFS

一般，广度优先搜索都是从一个源点出发。

![单源BFS.gif](https://pic.leetcode-cn.com/a3f28eeb94837d510ad7360e756881059e65ca78489d4d9bae6973884b9870bb-%E5%8D%95%E6%BA%90BFS.gif)

多源广度优先搜索长这样。

![多源BFS.gif](https://pic.leetcode-cn.com/be6bdff2b8d983d2135e5d2675b4dae750fef16104c904e462d9b1d64ef6d8ed-%E5%A4%9A%E6%BA%90BFS.gif)


如何证明理解多源点BFS的正确性？其实可以通过添加超级源点方式来思考。添加超级源点可以使多源BFS退化成单源BFS。

首先让我们用离散数学中图的概念来描述这张地图：

1、海洋和陆地都是图中的结点。
2、相邻网格的对应结点之间有一条无向边。
这样地图中的网格及其相邻关系构成了一张无向无权图。 如下图示：

![图.png](https://pic.leetcode-cn.com/3d08b7302e78bc926042856191ea0ffce1312b16c10ecdc08df12c1502ef7c37-%E5%9B%BE.png)

我们向图中加入一个超级源点，并在超级源点与每个陆地结点之间建立一条边。如下图示：

![超级源点.png](https://pic.leetcode-cn.com/5d4d1debe4c272fc248d67b9eeda8f2f8e530bc35a38c286bf3e6b8285e85859-%E8%B6%85%E7%BA%A7%E6%BA%90%E7%82%B9.png)


现在我们从超级源点开始做单源BFS，发现原先的多个源点只不过是BFS的第二层而已~。
所以多源BFS没有改变BFS的本质，不会影响结果的正确性。

作者：Time-Limit
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/zhen-liang-yan-sou-huan-neng-duo-yuan-kan-wan-miao/



