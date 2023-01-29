## Python 基本语法

### 函数类型后置

```python
from typing import List
def findRepeatNumber(self, nums: List[int]) -> int:
def findRepeatNumber(self, nums: Dict[int, int]) -> int:
```

Python 里的自定义类型首字母一般要大写, 这是约定俗成的
看源码就可以知道, List 只是 list 的别名而已

### Python set

Python 中的哈希表是 set

```python
hashset = set()
```

### Python list

1. 交换 list 中的元素

```python
# a,b=c,d 操作的原理是先暂存元组 (c,d) ，然后 “按左右顺序” 赋值给 a 和 b 。
# 如果 a,b 两个值互相影响, 如 a 改动后 b 也会改动, 则要先写 b 再写 a
# 写成 nums[i], nums[nums[i]] = nums[nums[i]], nums[i] 是不对的
# 因为nums[i] 一旦发生变化后, nums[nums[i]] 的值就变了, 所以 nums[nums[i]] 要写在前面
nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
```

2. list 反转

```python
a = [1, 2, 3, 4]
a = a[::-1]
a.reverse() # 直接在原列表上修改, 不会返回新列表
```

3. list 拼接

```python
a = [1, 2, 3, 4]
b = [1, 2, 3, 4]
c = a + b
```

4. 创建 list

```python
# 长度为20的全零数组
a = [0]*10
```

5. 创建二维 list

```python
# 不可以写成 a = [[0]*10]*5, 这样每一行会变成引用
a = [[0]*10 for _ in range(5)]
```

### Python 二分查找 API

```python
idx = bisect.bisect_left(row, target)

bisect.bisect_left(nums, target, lo=0, hi=len(a))
# 在nums中找到target的合适插入点, 以保证有序
# 如果找到一个数等于target, 则在这个数的左边插入, 那么返回的索引就是target的索引
# idx 返回的是[0, len(nums)]的一个索引, 需要做如下判断
if idx < len(nums) and nums[idx]==target:
```

### Python str

python 的字符串是不可变的, 不可以同过下标访问的方式来进行修改
要修改字符串可以通过切片、或转成列表的方式

1. 切片访问

```python
s = "hollo"
s = s[:1] +'e'+ s[2:]
print(s) # hello
```

2. 转成 list

```python
s = list(s)
# 转回去需要使用空字符串join, 直接转会把list的括号也转过去
s = ''.join(s)
```

### Python dict

python 中的 dict 不支持索引访问
即使当 dict 的 key 是 int 类型时, 也不能使用 dict[数字]的方式访问

### Python queue

```python
import queue

q = queue.Queue()
q.put()
q.get()
# 一定要使用 empty 来判断是否为空, 不能使用 while not q:
while not q.empty():
```

[各种 Python 队列](https://blog.csdn.net/brucewong0516/article/details/84025027): queue、deque、PriorityQueue

Python 中使用 collections 中的双端队列 deque() ，其 popleft() 方法可达到 O(1) 时间复杂度；列表 list 的 pop(0) 方法时间复杂度为
O(N), deque 的 api 用法和 list 比较相似, 也可以使用 `while q:` 来判断 deque 是否为空, 所以推荐使用 deque

### Python 函数

函数的内部可以创建函数

## 剑指 Offer

- [[4-二维数组中的查找](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/04-%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.py)]:
  [Z 字查找图解](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/)

- [[6-从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/06-%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.py)]:
  [递归解法](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solution/mian-shi-ti-06-cong-wei-dao-tou-da-yin-lian-biao-d/)

- [[7-重建二叉树](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)|[解答]()]:
  在 inorder 列表中查找 root 的过程其实是很耗时的, 可以先用哈希表建立一个 pre 到 ord 的一一映射
  但是这样的话就要改函数传入参数, 改成 list 的左右 index 的范围, 而不能只用切片了
  https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-by-leetcode-s/

- [[10-I.斐波那契数列](https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/)|[解答]()]:
  滚动数组, 其实总共只需要记录三个变量就行了, 然后这三个变量间滚动
  https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/solution/mian-shi-ti-10-i-fei-bo-na-qi-shu-lie-dong-tai-gui/

- [[10-II.青蛙跳台阶问题](https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)|[解答](https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/solution/mian-shi-ti-10-ii-qing-wa-tiao-tai-jie-wen-ti-dong/)]:

  1. 单独列出 n=1, n=2 的特殊情况 return
  2. 构造 dp 数组
  3. 返回 dp[n]
     一定要注意题目的输入范围, 很多时候 list 越界都是输入范围有特例的问题
     不用特意追求最优解法, 滚动数组就算了, 普通的 dp 会一点就行
     滚动数组的 range 范围可以看下面这个, 一般都是先确定 range 再确定 a, b, c 的初始值
     https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/solution/jian-zhi-offer-10-ii-qing-wa-tiao-tai-ji-aq1j/
     https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/solution/mian-shi-ti-10-ii-qing-wa-tiao-tai-jie-wen-ti-dong/

- [[11-旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)|[解答]()]:
  https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
  https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-by-leetcode-s/

- [[19-正则表达式匹配](https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-s3jgn/)|[解答]()]:
  写一个函数进行字符的匹配, 方便匹配'.', 创建二维 dp 数组时需要注意, 不要把每一行搞成引用了, 状态转移需要考虑周围的每个状态

- [[27-二叉树的镜像](https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/)|[解答]()]:
  先考虑特殊情况, 比如 A 为 None, B 为 None

- [[29-顺时针打印矩阵](https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)|[解答]()]:
  注意, 在逐层打印的时候, 如果 lengthX 或 lengthY==1 的话, 有些 for 循环是要去除的, 要考虑那一层只有一行或只有一列的情况

- [[31-栈的压入、弹出序列](https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)|[解答]()]:
  外层循环的条件不太好找, 需要注意, 对于每一个 poped 中的元素(这就是一个 for 循环), 如果模拟栈的栈顶不是该元素, 则要一直压栈, 压到不能压了, 就返回 False, 如果是该元素就出栈, 判断下一个 poped 中的元素, 直到 poped 中的元素都判断成功就返回 True

- [[32-I-从上到下打印二叉树](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)|[解答]()]:
  https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/solution/mian-shi-ti-32-i-cong-shang-dao-xia-da-yin-er-ch-4/
  deque 的用法和 list 比较相似

- [[33-二叉搜索树的后序遍历序列](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)|[解答]()]:
  后序遍历的特点就是最后一个节点是根节点, 然后根据二叉搜索树的特性划分左右子树, 然后递归实现
  备注:中序遍历+前(后)序遍历可以确定唯一的一颗二叉树, 这里单后序遍历是不可以确定二叉树形状的, 但是我们可以依据后续遍历构造可能的二叉搜索树

- [[34-二叉树中和为某一值的路径](https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)|[解答]()]:
  dfs 模板题, 但是需要主要 python 里列表传递默认是按引用传递, 所以`res.append(path[:])`要写成切片形式
