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
