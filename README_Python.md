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

Python 中的哈希集合是 set

```python
hashset = set()
```

Python 中用于计数的哈希表

```python
def majorityElement(self, nums: List[int]) -> int:
    counts = collections.Counter(nums)
    return max(counts.keys(), key=counts.get)
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

可以使用 max 函数来求字典里的最大值
max(d), 求最大的 key
max(d, key=d.get), 求最大的 value

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

Python 中的最小堆和最大堆

```python
# heapq相当与在list上操作
# 使用heapq实现最大堆和最小堆
# https://blog.csdn.net/a284365/article/details/123592517

def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
    if not k:
        return []
    hp = []
    for i, e in enumerate(arr):
        if i < k:
            # heapq默认是最小堆, 所以这里 e越大, 越排在前面
            heapq.heappush(hp, (-e, e))
        elif e < hp[0][1]: # 取堆的第一个元素
            heapq.heappushpop(hp, (-e, e))
    return [x for _, x in hp]
```

### Python 函数

函数的内部可以创建函数

1. Python 中字符串、元组、数值类型都是按值传参的
   如果想要字符串按引用传递, 只能通过传 list 再将 list 转为 str 的方式实现
   如果想要数值类型按引用传递, 在函数内声明 `nonlocal idx`
2. Python 中字典和列表都是按引用传参的

### Python 作用域

python if 和 for 里面的变量可以在 if 和 for 外面使用, python 是没有 python 是没有块级别的作用域的
python 的作用域一共有四层：
局部作用域 L (Local)-->闭包函数外的函数中 E ( Enclosing ) -->全局作用域 G ( Global ) --> 内建作用域 B (Built-in)。记成 LEGB。
Python 以 L –> E –> G –>B 的规则查找变量

## 剑指 Offer

- [[4-二维数组中的查找](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/04-%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.py)]:
  [Z 字查找图解](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/)

- [[6-从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/06-%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.py)]:
  [递归解法](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solution/mian-shi-ti-06-cong-wei-dao-tou-da-yin-lian-biao-d/)

- [[7-重建二叉树](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/07-%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91.py)]:
  在 inorder 列表中查找 root 的过程其实是很耗时的, 可以先用哈希表建立一个 pre 到 ord 的一一映射
  但是这样的话就要改函数传入参数, 改成 list 的左右 index 的范围, 而不能只用切片了
  https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-by-leetcode-s/

- [[10-I.斐波那契数列](https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/10-I-%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97.py)]:
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

- [[11-旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/11-%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97.py)]:
  https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
  https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-by-leetcode-s/

- [[19-正则表达式匹配](https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-s3jgn/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/19-%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%E5%8C%B9%E9%85%8D.py)]:
  写一个函数进行字符的匹配, 方便匹配'.', 创建二维 dp 数组时需要注意, 不要把每一行搞成引用了, 状态转移需要考虑周围的每个状态

- [[27-二叉树的镜像](https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/27-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%95%9C%E5%83%8F.py)]:
  先考虑特殊情况, 比如 A 为 None, B 为 None

- [[29-顺时针打印矩阵](https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/29-%E9%A1%BA%E6%97%B6%E9%92%88%E6%89%93%E5%8D%B0%E7%9F%A9%E9%98%B5.py)]:
  注意, 在逐层打印的时候, 如果 lengthX 或 lengthY==1 的话, 有些 for 循环是要去除的, 要考虑那一层只有一行或只有一列的情况

- [[31-栈的压入、弹出序列](https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/31-%E6%A0%88%E7%9A%84%E5%8E%8B%E5%85%A5%E3%80%81%E5%BC%B9%E5%87%BA%E5%BA%8F%E5%88%97.py)]:
  外层循环的条件不太好找, 需要注意, 对于每一个 poped 中的元素(这就是一个 for 循环), 如果模拟栈的栈顶不是该元素, 则要一直压栈, 压到不能压了, 就返回 False, 如果是该元素就出栈, 判断下一个 poped 中的元素, 直到 poped 中的元素都判断成功就返回 True

- [[32-I-从上到下打印二叉树](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/32-I-%E4%BB%8E%E4%B8%8A%E5%88%B0%E4%B8%8B%E6%89%93%E5%8D%B0%E4%BA%8C%E5%8F%89%E6%A0%91.py)]:
  https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/solution/mian-shi-ti-32-i-cong-shang-dao-xia-da-yin-er-ch-4/
  deque 的用法和 list 比较相似

- [[33-二叉搜索树的后序遍历序列](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/33-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97.py)]:
  后序遍历的特点就是最后一个节点是根节点, 然后根据二叉搜索树的特性划分左右子树, 然后递归实现
  备注:中序遍历+前(后)序遍历可以确定唯一的一颗二叉树, 这里单后序遍历是不可以确定二叉树形状的, 但是我们可以依据后续遍历构造可能的二叉搜索树

- [[34-二叉树中和为某一值的路径](https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/34-%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%92%8C%E4%B8%BA%E6%9F%90%E4%B8%80%E5%80%BC%E7%9A%84%E8%B7%AF%E5%BE%84.py)]:
  dfs 模板题, 但是需要主要 python 里列表传递默认是按引用传递, 所以`res.append(path[:])`要写成切片形式

- [[37-序列化二叉树](https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/37-%E5%BA%8F%E5%88%97%E5%8C%96%E4%BA%8C%E5%8F%89%E6%A0%91.py)]:
  记得用`,`隔开各个节点

- [[41-数据流中的中位数](https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/41-%E6%95%B0%E6%8D%AE%E6%B5%81%E4%B8%AD%E7%9A%84%E4%B8%AD%E4%BD%8D%E6%95%B0.py)]:
  使用两个堆, 最大堆 A, 最小堆 B, A 里放小于中位数的数, B 里放大于中位数的数, 一个堆里放大于中位数的数, 维护这两个堆, 使他们的 size 之差永远<=1

  1. 当两个堆的数目相等时, 将这个数放进 A 里, 然后将 A 的堆顶移入 B, A、B 的定义依旧满足, 之后 B 比 A 的元素个数多一
  2. 当两个堆的数目不相等时, 也就是 B 里的元素多 1 时, 将这个数放进 B 里, 然后将 B 的堆顶移入 A, A、B 的定义依旧满足, 之后 B 比 A 的元素个数多一
     这里的精髓就在于 A、B 堆顶的互相移动, 这样就无需在意要放的数是大于中位数还是小于中位数了

- [[43-1~n 整数中 1 出现的次数](https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/43-1%EF%BD%9En%E6%95%B4%E6%95%B0%E4%B8%AD1%E5%87%BA%E7%8E%B0%E7%9A%84%E6%AC%A1%E6%95%B0.py)]:
  https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
- [[44-数字序列中某一位的数字](https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/44-%E6%95%B0%E5%AD%97%E5%BA%8F%E5%88%97%E4%B8%AD%E6%9F%90%E4%B8%80%E4%BD%8D%E7%9A%84%E6%95%B0%E5%AD%97.py)]:
  https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/mian-shi-ti-44-shu-zi-xu-lie-zhong-mou-yi-wei-de-6/
- [[46-把数字翻译成字符串](https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/46-%E6%8A%8A%E6%95%B0%E5%AD%97%E7%BF%BB%E8%AF%91%E6%88%90%E5%AD%97%E7%AC%A6%E4%B8%B2.py)]:
  动态规划, 和青蛙跳台阶差不多, 但是需要注意"06"是不可以被当作"6"来被翻译的, 此外 int 转 str, 直接用 str()就可以, 然后可以用切片访问字符串

- [[49-丑数](https://leetcode.cn/problems/chou-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/49-%E4%B8%91%E6%95%B0.py)]:
  最小堆

- [[51-数组中的逆序对](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/51-%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%80%86%E5%BA%8F%E5%AF%B9.py)]:
  在归并排序的过程中记录逆序对的数量, 因为 O(n^2)的算法肯定过不了, 所以考虑 O(nlogn)的算法

- [[53-I-在排序数组中查找数字 I](https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/53-I-%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E6%95%B0%E5%AD%97I.py)]:
  已排好序的数组, 且数组可以按一定规律分成两段, 考虑二分法, 另外, 先 return len(nums) = 0 的情况
  整个数组, 对于最左边的 target, 它左边的元素都小于 target, 右边的元素都大于等于 target;
  整个数组, 对于最右边的 target, 它左边的元素都小于等于 target, 右边的元素都大于 target;

- [[53-II-0 ～ n-1 中缺失的数字](https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/53-II-0~n-1%E4%B8%AD%E7%BC%BA%E5%A4%B1%E7%9A%84%E6%95%B0%E5%AD%97.py)]:
  1. 二分法, 对于缺失的那一个数的 idx, 他左边的数都满足 i = nums[i], 对于他右边的数都满足 i > nums[i]
  2. 位运算, 相同为 0, 不同为 1, 对整个数组异或[0, n-1]的每一个数
  ```python
  def solution(nums):
    xor = 0
    for i, n in enumerate(nums):
        xor^=i^n
    return xor^len(nums)
  ```
- [[54-二叉搜索树的第 k 大节点](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/54-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E7%AC%ACk%E5%A4%A7%E8%8A%82%E7%82%B9.py)]:
  中序遍历二叉树

  1. 对于函数内部定义的函数, 要操作一个外面的变量, 可以通过 nonlocal 的方式声明, 也可以将外部变量写成类成员变量
  2. 递归可以提前返回, 只需要提前判断条件是否满足即可, 满足就直接 return, 这样回溯的时候就不会继续递归了

- [[55-I-二叉树的深度](https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/55-I-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%B7%B1%E5%BA%A6.py)]:
  其实是后序遍历二叉树
