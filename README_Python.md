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

6. 对 list 进行排序

```python
list1 = sorted(list1)
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

### Python 整数表示

```python
print(hex(1)) # = 0x1 补码
print(hex(-1)) # = -0x1 负号 + 原码 （ Python 特色，Java 会直接输出补码）

print(hex(1 & 0xffffffff)) # = 0x1 正数补码
print(hex(-1 & 0xffffffff)) # = 0xffffffff 负数补码

print(-1 & 0xffffffff) # = 4294967295 （ Python 将其认为正数）
```

计算机里的负数使用补码的形式存储, 以 32 位 int 为例

负数的补码=其绝对值取反+1

可以通过最高位来判断 32 位 int 数字的正负

```
  0 : 0000 0000 0000 0000 0000 0000 0000 0001
  1 : 0000 0000 0000 0000 0000 0000 0000 0001
 -1 : 1111 1111 1111 1111 1111 1111 1111 1111
+max: 0111 1111 1111 1111 1111 1111 1111 1111(2147483647)
-max: 1000 0000 0000 0000 0000 0000 0000 0000(-2147483648)
```

python 没有 int 和 long 的区别, python 的 int 是无限长不会溢出的
所以题目中如果限定了 32 位整数, 那么使用 python 解题时要对数字进行转换:

#### 计算 32 位整型加法

1. 32 位整数的范围在[-2147483648, 2147483647], 所以题目的输入一定是这个范围的,
   对于这个范围的数，python int 的后 32 位和 C++ 的 int32 相同，但是前面是不同的，
   对于[0, 2147483647], python 的前面全为 0
   对于[-2147483648, -1], python 的前面全为 1
2. 为了仿照 32 位 int 加法来处理，需要对 python 整数的后 32 位进行截断

```
x = 0xffffffff
a, b = a & x, b & x
```

3. 截断后的数, 相当于前面的位都是 0，在输出时就会出现问题，因为 python 会将其认定为正数
4. 对于 int32 里应当是负数的数, 应当转换成 python 的表示形式, 即将前面的位全部变成 1
5. 要将前面的位全部变成 1，可以对后 32 位取反，在对整个数取反
   `res^x`, 相同为 0，不同为 1，可对 res 的后 32 位取反, 前面的位依然保持 0

```
return res if res < 0x7fffffff else ~(res^x)
```

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

- [[56-I-数组中数字出现的次数](https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/56-I-%E6%95%B0%E7%BB%84%E4%B8%AD%E6%95%B0%E5%AD%97%E5%87%BA%E7%8E%B0%E7%9A%84%E6%AC%A1%E6%95%B0.py)]:

  1. 对 nums 所有数进行异或, 求解 target1 xor target2 的值
  2. target1 和 target2 不是相同的数, 这他们必定有某一位不同, 那么这一位上 xor 的结果为 1, 设这一位为 m
  3. 将 nums 分为两个部分, 一个只包含 target1, 一个只包含 target2, 且这两个部分都满足只有 target 没有相同的数

  - 可以依据 m 来对数组进行划分, 第 m 位为 0 的划分为 1 组, 第 m 位为 1 的划分为一组
  - 这样, 这两组就一个只包含 target1, 一个只包含 target2, 而且对于每个组除 target 以外的元素而言, 和他们相同的元素一定在同一个组, 因为他们的第 m 位一定是相同的

  4. 对这两个组进行异或即可求出 target1, target2

- [[56-II-数组中数字出现的次数 II.py](https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/56-II-%E6%95%B0%E7%BB%84%E4%B8%AD%E6%95%B0%E5%AD%97%E5%87%BA%E7%8E%B0%E7%9A%84%E6%AC%A1%E6%95%B0II.py)]:
  把数组中所有数字的二进制表示的每一位加起来，如果某一位的和可以被 3 整除，那么那个只出现一次的数字二进制表示中对应的那一位是 0，否则是 1

  分别考虑数的每一位:

  - 如果 target 的那一位为 0, 那么整个数组的那一位的和一定是三的倍数
  - 如果 target 的那一位为 1, 那么整个数组的那一位的和除以 3 的余数一定是 1

- [[57-和为 s 的两个数字](https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/57-%E5%92%8C%E4%B8%BAs%E7%9A%84%E4%B8%A4%E4%B8%AA%E6%95%B0%E5%AD%97.py)]:
  对于已排好序的数组, 可以双指针求两数之和

- [[57-II-和为 s 的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/57-II-%E5%92%8C%E4%B8%BAs%E7%9A%84%E8%BF%9E%E7%BB%AD%E6%AD%A3%E6%95%B0%E5%BA%8F%E5%88%97.py)]:
  看到连续子数组两个字就可以往滑动窗口的方向想了

- [[58-I-翻转单词顺序](https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/58-I-%E7%BF%BB%E8%BD%AC%E5%8D%95%E8%AF%8D%E9%A1%BA%E5%BA%8F.py)]:
  python 使用 str api 一行流, `' '.join(s.strip().split()[::-1])`, 这里要使用`split()`, 而不能使用`split(" ")`, 后者无法区分多个空格连在一起的情况

- [[59-I-滑动窗口的最大值](https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/59-I-%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC.py)]:
  https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-i-hua-dong-chuang-kou-de-zui-da-1-6/
  双端队列可以不看, 但是滑动窗口+堆一定要会, 堆中存储的是(-nums[i], i), 窗口收缩时, 如果堆顶的 i 在 r-k+1 之前, 就说明堆顶的元素是不在滑动窗口范围内的, 这时候就要出堆

- [[60-n 个骰子的点数](https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/60-n%E4%B8%AA%E9%AA%B0%E5%AD%90%E7%9A%84%E7%82%B9%E6%95%B0.py)]:
  https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/solution/jian-zhi-offer-60-n-ge-tou-zi-de-dian-sh-z36d/
  二维 dp, dp[i][j] 表示前 i 个骰子和为 j 的概率, `dp[1] = [1/6]*6`, 因此可以递推出 dp[2]的值,到最后返回 dp[n]的值即可

- [[62-圆圈中最后剩下的数字](https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/?favorite=xb9nqhhg)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/62-%E5%9C%86%E5%9C%88%E4%B8%AD%E6%9C%80%E5%90%8E%E5%89%A9%E4%B8%8B%E7%9A%84%E6%95%B0%E5%AD%97.py)]:
  [动态规划](https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/jian-zhi-offer-62-yuan-quan-zhong-zui-ho-dcow/)
  约瑟夫环问题, 动态规划可解, 设置该问题为(n, m)问题, 其解为 f(n), 当 m 固定时, f(n)可以由 f(n-1)推导得来

  1. (n, m)问题在删除一个数后得到一个长度为 n-1 的序列，这个序列可以和(n-1, m)的序列完成一个一一映射, (n-1, m)的解为 f(n-1), 这个解映射到(n, m)删除一个数后的 n-1 序列就是 f(n)
  2. 映射关系如下

  ```
   f(n-1)
      0    1    2    3    4   ...   n-3    n-2
   设 t = m % n, (n, m) 第一个要删除的数是 (m - 1) % n, t 即为下一个循环开头的数
      t   t+1  t+2  t+3  t+4  ...   t-3    t-2
   f(n) = (f(n-1) + t)%n
  ```

  3. f(0) = 0, 迭代即可解

- [[63-股票最大利润](https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/63-%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E5%A4%A7%E5%88%A9%E6%B6%A6.py)]:
  动态规划，dp[i]表示在 prices[i]处卖出的最大收益，所以 `dp[i] = max(0, dp[i-1]+prices[i] - prices[i-1])`

- [[64-求 1+2+…+n](https://leetcode.cn/problems/qiu-12n-lcof/?favorite=xb9nqhhg)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/64-%E6%B1%821%2B2%2Bn.py)]:
  使用递归来代替循环, 利用 and 来制造递归出口和返回 0
  ```python
  class Solution:
    def sumNums(self, n: int) -> int:
        return n > 0 and (self.sumNums(n-1) + n)
  ```
- [[65-不用加减乘除做加法](https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/)|[解答]()]:
  [位运算做加法](https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/)
  使用位运算可解, 注意 python 的数字存储格式, 加法可转化为非进位和与进位和的加法, 直到进位和为 0

  1. 两个数的加法可以转变为两个数的非进位和+两个数的进位和
  2. 这又是一个加法, 而这个加法又可以这样转换, 直到两个数的进位和为 0
  3. 两个数的非进位和就等于 `a ^ b`, 两个数的进位和就等于`(a & b ) << 1`

  ```
  s = a + b = n + c = ... = n' + 0
  ```

- [[1-整数除法](https://leetcode.cn/problems/xoh6Oh/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/01-%E6%95%B4%E6%95%B0%E9%99%A4%E6%B3%95.py)]:

  1. 注意符号
  2. 注意溢出
  3. 使用慢启动的思想加速

- [[2-二进制加法](https://leetcode.cn/problems/JFETK5/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/02-%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%8A%A0%E6%B3%95.py)]:
  二进制加法其实可以转化为两个位运算之和, 使用循环求解

  ```python
    class Solution:
        def addBinary(self, a, b) -> str:
            x, y = int(a, 2), int(b, 2)
            while y:
                answer = x ^ y
                carry = (x & y) << 1
                x, y = answer, carry
            return bin(x)[2:]
  ```

- [[3-数组中重复的数字](https://leetcode.cn/problems/w3tCBm/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/03-%E5%89%8Dn%E4%B8%AA%E6%95%B0%E5%AD%97%E4%BA%8C%E8%BF%9B%E5%88%B6%E4%B8%AD1%E7%9A%84%E4%B8%AA%E6%95%B0.py)]:
  动态规划

  1. 对于奇数 x，其 1 的个数比上一个数多 1
  2. 对于偶数 x，其 1 的个数等于 x//2 中 1 的个数，因为 x//2 变成 x 需要左移 1 位，末尾补零，1 的个数不变

- [[4-只出现一次的数字](https://leetcode.cn/problems/WGki4K/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/04-%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97.py)]:
  1. 如果不存在这个数, 那么每一位上 1 的个数之和都应当是 3 的倍数
  2. 注意 python 的整数表示，如果第 32 位上是 1，那么 python 的前面所有位都应该是 1，0xFFFFFFFF 的亦或运算可以用来对低 32 位取反，然后整体取反就可以得到 python 正确的整数表示
