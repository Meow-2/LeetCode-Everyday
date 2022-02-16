LeetCode每日一题个人刷题记录,C++解题,始于2021.11.19

个人复习使用，许多地方并没有完全写清楚，如果觉得有错误或不明白，请参考正确解答

## A line trick:

- [859-亲密字符串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/design/859-亲密字符串.cpp)：`set`里的元素是唯一的，可以用于字符串快速去重，`set<char>(s.begin(),s.end())`，通过比较去重后的size()还可以得到字符串是否有重复字符
- [423-从英文中重建数字](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/423-从英文中重建数字.cpp)：`unordered_map<char,int>`哈希表可以用一个int数组代替，前提数组的范围要能容纳下字符的ASCII码(对于包含所有小写字母，大小为26的数组，可以用 `int hashmap[c - 'a']`来寻址);`unordered_map<int,int>`也是，但前提是int数组的范围要能容纳下第一个int的范围
- [594-最长和谐子序列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/594-最长和谐子序列.cpp)：`unordered_map<int,int>`可以用于快速查找序列中已遍历过的数，和该数在序列中已出现的次数，查找的时间复杂度为O(1)
- [700-二叉搜索树中的搜索](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/700-二叉搜索树中的搜索.cpp)：对于并列关系的if语句，如果判断的条件单一，执行的语句形式也相似，可以尝试使用三元式替换:
  `search(root->val<val?root->right:root->left,val)`
- [559-N叉树的最大深度](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/559-N叉树的最大深度.cpp)：选取一个for循环中最大的数，使用 `maxdepth = max(maxdepth,1 + maxDepth(child))`来替换掉 `if(depth > maxdepth)`
- [400-第N位数字](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/400-第N位数字.cpp)：当需要累加特别大的数字时，要考虑int溢出的问题，对于将累加数和参照值比较的问题可以这样转换:用参照值减去各个阶段的累加数，将其差值与下一个阶段的累加值进行比较，从而确定多少次累加才能达到参照值，即参照值在那个累加区间内
- [786-第K个最小的素数分数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/786-第K个最小的素数分数.cpp)：
  对于几个有序序列的排序，可以使用多路归并的方式，每一路用最大（最小）堆取出最大（最小）值归并
- [372-超级次方.cpp](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/372-超级次方.cpp)：

  - (x*y)%k = (x%k*y%k)%k;
  - (a `<sup>`b `</sup>`)%k = ((a%k)`<sup>`b `</sup>`)%k;
  - **a `<sup>`1234 `</sup>`%k** = ((**a `<sup>`123 `</sup>`%k**)`<sup>`10 `</sup>`%k * a `<sup>`4 `</sup>`%k)%k
  - 定义一个函数powMod(int a,int b) = a `<sup>`b `</sup>`%k ;(0<=k<10)

## Forgetfulness Cpp Api:

- [458-可怜的小猪](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/458-可怜的小猪.cpp)：Cpp标准库没有提供自定义底数的log函数，需要时可以这样代替 `loga(b) = log2(b)/log2(a);`
- [594-最长和谐子序列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/594-最长和谐子序列.cpp)：从小到大排序 `#include <algorithm> std::sort(iterator &begin,iterator &end)`;
- [786-第K个最小的素数分数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/786-第K个最小的素数分数.cpp):

  - 优先队列

  ```
  priority_queue<pair<double,pair<int,int>>>q;
  q.push({1*1.0/3,{1,3}});
  q.pop();
  ```

  - 自定义排序

  ```
  vector<pair<int, int>> vec;
  sort(vec.begin(), vec.end(), [&](const auto& x, const auto& y) {
          return x.first * y.second < x.second * y.first;
      });
  ```
- [1816-截断句子](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/1816-截断句子.cpp)：删除字符串从index i到末尾的所有字符 `s.erase(i)`

---

## Array-数组:

1. 数组题目一般都可以使用双指针的解法,三路快排就是一个很典型的双指针加二分递归
2. 双指针根据指针起点的不同，可以分为快慢指针和对撞指针

   ```
   int slow = 0,fast = 0 //快慢指针,[0,slow)维护一个题目要求的数组
   int left = 0,right = arr.size()-1 //对撞指针，当 i = j 或 i < j 时停止循环
   ```
3. 在搜索时考虑使用二分法

   ```cpp
   int i = 0,j = arr.size() - 1;//[i,j]，在二分查找中，i = j 时，相当于[i]，仍旧需要对 i 进行一次判断
   while(i<=j){
       mid = i+(j - i )/2; 	//防止溢出
       ...
   }
   ```
4. 写不出来就暴力，但有可能会超时，超时也可以试着用if来筛选一些明显不可能的情况

- [11-盛水最多的容器](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/11-%E7%9B%9B%E6%9C%80%E5%A4%9A%E6%B0%B4%E7%9A%84%E5%AE%B9%E5%99%A8.cpp)： 这题使用暴力解法会超时（除非用在第二层循环前用 if 过滤掉不可能的情况），使用对撞指针时，应将两个指针想象成容器的两边，若想让当前的容器盛更多的水，那么只有将短的那一边向内部移动才有可能
- [167-两数之和 2 输入有序数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/167-%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C%20II%20-%20%E8%BE%93%E5%85%A5%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.cpp)：对撞指针，从比较指针和与target的大小，从而决s定如何逼近两个指针
- [26-删除有序数组的重复项](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/26-%E5%88%A0%E9%99%A4%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9.cpp)：快慢指针，慢指针维护题目要求的数组，快指针每扫到一个数，就将该数与慢指针数组的最后一位进行比较
- [80-删除有序数组中的重复项2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/80-%E5%88%A0%E9%99%A4%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9%20II.cpp)：快慢指针，同上，但快指针应与慢指针数组的最后倒数第二位进行比较
- [75-颜色分类](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/75-%E9%A2%9C%E8%89%B2%E5%88%86%E7%B1%BB.cpp)：一个快指针两个慢指针，和快速排序相似
- [27-移除元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/27-%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.cpp)、[283-移动零](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/283-%E7%A7%BB%E5%8A%A8%E9%9B%B6.cpp)：快慢指针
- [88-合并两个有序数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/88-%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.cpp)：归并排序的合并方法，开个新数组
- [215-数组的第K个最大元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/divide-and-conquer/215-%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E7%AC%ACK%E4%B8%AA%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0.cpp)：二分法+快排partition；或者建堆，最小堆O（nlogk），最大堆O（klogn）;记住找准循环不变量，在while外面先将循环不变量定义好，循环不变量就是指在循环中性质不变的量tl

## String-字符串

1.回文、反转字符串问题可以尝试用双指针解决

2.判断一个字符是否是数字、字母、大小写可借助 ASCII 码，或者使用cpp api

- [125-验证回文串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/125-%E9%AA%8C%E8%AF%81%E5%9B%9E%E6%96%87%E4%B8%B2.cpp)：`isalnum(char)`判断一个字符是否是数字或字母，反转字符串str `string reverse_string(str.rbegin(),str.rend())`, rbegin()的类型是reverse_iterator
- [344-反转字符串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/344-%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.cpp)、[345-反转字符串中的元音字母](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/345-%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%85%83%E9%9F%B3%E5%AD%97%E6%AF%8D.cpp)：对撞指针
