学习笔记
1.139多数元素：隐含条件：只要大于n/2的元素必然是个数最多的元素；unordered_map<int,int>counts中是自动添加的个数，所以一边找最大值，一边找统计每遇到的点数的个数。使用的counts中的[]可以插入元素。
知识点：
map： map内部实现了一个红黑树（红黑树是非严格平衡二叉搜索树，而AVL是严格平衡二叉搜索树），红黑树具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素。因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行的操作。map中的元素是按照二叉搜索树（又名二叉查找树、二叉排序树，特点就是左子树上所有节点的键值都小于根节点的键值，右子树所有节点的键值都大于根节点的键值）存储的，使用中序遍历可将键值按照从小到大遍历出来。
unordered_map: unordered_map内部实现了一个哈希表（也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用）。因此，其元素的排列顺序是无序的。
2.874模拟行走机器人
程序表示：二维数组确定行走方向；用哈希表建立障碍
顺序执行：每次查找遇到障碍原地不动，同时计算欧氏距离，同时查找哈希表确定当前点是否是个障碍点
3.455分发饼干
抽象为两个数组：胃口数组和饼干大小数组，然后排序比大小。做最适合的匹配；数学上两条不同斜率的线相交的问题。

知识点：
搜索
遍历搜索

每个节点都要访问一次
每个节点仅访问一次
深度优先搜索 (DFS， Depth First Search)
代码模板:

递归写法
visited = set()

def dfs(node, visited)
    if node in visited:
        return

    visited.add(node)

    # process current node
    ...

    for next_node in node.children():
        if not next_node in visited:
            dfs(next_node, visited)
循环写法 手动维护一个栈
def dfs(self, tree):
    if tree.root is None:
        return []

    visited, stack = [], [tree.root]

    while stack:
        node=stack.pop()
        visited.add(node)

        process(node)
        nodes = generate_relatex_nodes(node)
        stack.push(nodes)

广度优先搜索 (BFS, Breadth First Search)
一层一层的往下遍历

代码模板:

使用队列

def bfs(graph, start, end):
    queue = []
    queue.appedn({start})
    visited.add(start)

    while queue:
        node = queue.pop()
        visited.add(node)

        process(node)
        nodes = generate_related_nodes(node)
        queue.push(nodes)

优先级优先搜索
启发搜索
贪心算法
在每一步选择中都采取在当前状态下最好活最优的选择，从而希望到时结果是全局最好或最优的算法

适用场景
一旦一个问题可以使用贪心算法，那么贪心算法一般是解决这个问题的最好办法

解决一些最优化的问题
最小生成树
哈夫曼编码
用作辅助算法
解决一些结果要求不特别精确的问题
能分解成子问题的问题，子问题的最优解能递推到最终问题的最优解(子问题最优解被称为最优子结构)
与动态规划的区别
贪心
对每个子问题的解决方案都做出选择
不能回退
动态规划
保存以前的运算结果，并根据以前的结果对当前进行选择
有回退功能
二分查找
代码模板：

left, right = 0, len(arry)-1
while left <= right
    mid = (left+right)/2
    if array[mid] == target:
        break or return result
    elif array[mid] < target:
        left=mid+1
    else:
        right=mid-1
前提条件
目标函数单调性(单调递增或递减)
存在上下界
能够通过索引访问


