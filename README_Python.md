## Python 基本语法

函数类型后置

```python
def findRepeatNumber(self, nums: List[int]) -> int:
```

Python 中的哈希表是 set

```python
hashset = set()
```

Python list

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

Python 二分查找 API

```
idx = bisect.bisect_left(row, target)

bisect.bisect_left(nums, target, lo=0, hi=len(a))
# 在nums中找到target的合适插入点, 以保证有序
# 如果找到一个数等于target, 则在这个数的左边插入, 那么返回的索引就是target的索引
# idx 返回的是[0, len(nums)]的一个索引, 需要做如下判断
if idx < len(nums) and nums[idx]==target:
```

Python str
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

## 剑指 Offer

- [[4-二维数组中的查找](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/04-%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.py)]:
  [Z 字查找图解](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/)

- [[6-从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Coding-Interviews/06-%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.py)]:
  [递归解法](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solution/mian-shi-ti-06-cong-wei-dao-tou-da-yin-lian-biao-d/)
