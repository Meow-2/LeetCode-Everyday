LeetCode每日一题个人刷题记录,C++解题,始于2021.11.19

个人快速回顾使用，所以许多地方是经过大量省略的，甚至是只有我自己才能理解的说法，如果觉得有错误或不明白，请参考正确解答

## One Line Trick：

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

## Forgetfulness Cpp Api：

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
- [125-验证回文串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/125-%E9%AA%8C%E8%AF%81%E5%9B%9E%E6%96%87%E4%B8%B2.cpp)：`isalnum(char)`判断一个字符是否是数字或字母，反转字符串str `string reverse_string(str.rbegin(),str.rend())`, rbegin()的类型是reverse_iterator
- [76-最小覆盖子串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/sliding-window/76-%E6%9C%80%E5%B0%8F%E8%A6%86%E7%9B%96%E5%AD%90%E4%B8%B2.cpp)：unordered_map使用count(key)的方式检查表内是否含有某个key，如果含有返回1，如果不含有返回0

  ```
  unordered_map<char,int> a;
  if(a.count('c')){}
  ```
- [349-两个数组的交集](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/349-%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.cpp)、[350-两个数组的交集2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/350-%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86%20II.cpp)：

  ```
  set<int> a;
  map<int,int> b;	   //在map中，key不插入默认是不存在的，find(key)也只会返回end(),但是b[key]会对不存在的key进行创建，且默认value为0
  int key;
  if(a.count(key))   //返回set中对应key的个数，可用于判断key是否存在
  a.insert(key);     //插入key 
  a.erase(key);      //删除key 
  a.find(key);       //查找key,返回迭代器，如果是end()就说明没找到
  b.insert(key);     //插入key 
  b.erase(key);      //删除key
  b.find(key);       //查找key,返回迭代器，如果是end()就说明没找到
  ```
- [451-根据字符出现频率排序](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/451-%E6%A0%B9%E6%8D%AE%E5%AD%97%E7%AC%A6%E5%87%BA%E7%8E%B0%E9%A2%91%E7%8E%87%E6%8E%92%E5%BA%8F.cpp)

  ```
  sort(temp.begin(), temp.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
  ```

---

## Array-数组：

1. 数组题目一般都可以使用**双指针**的解法,三路快排就是一个很典型的双指针加二分递归
2. 双指针根据指针起点和移动方式的不同，可以分为快慢指针和对撞指针和**滑动窗口**

   ```
   int slow = 0,fast = 0 //快慢指针,[0,slow)维护一个题目要求的数组
   int left = 0,right = arr.size()-1 //对撞指针，当 i = j 或 i < j 时停止循环
   ```
3. 快慢指针，两个指针起点相同同向移动，速度不同；对撞指针，两个指针一头一尾，相向移动；滑动窗口，两个指针构成一个区间，在数组内滑动
4. 在搜索时考虑使用二分法

   ```
   int i = 0,j = arr.size() - 1;//[i,j]，在二分查找中，i = j 时，相当于[i]，仍旧需要对 i 进行一次判断
   while(i<=j){
     mid = i+(j - i )/2; 	//防止溢出
     ...
   }
   ```
5. 写不出来就暴力，但有可能会超时，超时也可以试着用if来筛选一些明显不可能的情况

- [11-盛水最多的容器](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/11-%E7%9B%9B%E6%9C%80%E5%A4%9A%E6%B0%B4%E7%9A%84%E5%AE%B9%E5%99%A8.cpp)： 这题使用暴力解法会超时（除非用在第二层循环前用 if 过滤掉不可能的情况），使用对撞指针时，应将两个指针想象成容器的两边，若想让当前的容器盛更多的水，那么只有将短的那一边向内部移动才有可能
- [167-两数之和 2 输入有序数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/167-%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C%20II%20-%20%E8%BE%93%E5%85%A5%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.cpp)：对撞指针，从比较指针和与target的大小，从而决s定如何逼近两个指针
- [26-删除有序数组的重复项](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/26-%E5%88%A0%E9%99%A4%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9.cpp)：快慢指针，慢指针维护题目要求的数组，快指针每扫到一个数，就将该数与慢指针数组的最后一位进行比较
- [80-删除有序数组中的重复项2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/80-%E5%88%A0%E9%99%A4%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9%20II.cpp)：快慢指针，同上，但快指针应与慢指针数组的最后倒数第二位进行比较
- [75-颜色分类](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/75-%E9%A2%9C%E8%89%B2%E5%88%86%E7%B1%BB.cpp)：一个快指针两个慢指针，和快速排序相似
- [27-移除元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/27-%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.cpp)、[283-移动零](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/283-%E7%A7%BB%E5%8A%A8%E9%9B%B6.cpp)：快慢指针
- [88-合并两个有序数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/88-%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.cpp)：归并排序的合并方法，开个新数组
- [215-数组的第K个最大元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/divide-and-conquer/215-%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E7%AC%ACK%E4%B8%AA%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0.cpp)：二分法+快排partition；或者建堆，最小堆O（nlogk），最大堆O（klogn）;记住找准循环不变量，在while外面先将循环不变量定义好，循环不变量就是指在循环中性质不变的量
- [209-长度最小的子数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/209-%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.cpp)：滑动窗口，两个指针的移动是并非每次移动一步，而是在没达到条件前一直移动，使用while嵌套

## String-字符串：

1.回文、反转字符串问题可以尝试用双指针解决

2.判断一个字符是否是数字、字母、大小写可借助 ASCII 码，或者使用cpp api

- [125-验证回文串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/125-%E9%AA%8C%E8%AF%81%E5%9B%9E%E6%96%87%E4%B8%B2.cpp)：`isalnum(char)`判断一个字符是否是数字或字母，反转字符串str `string reverse_string(str.rbegin(),str.rend())`, rbegin()的类型是reverse_iterator
- [344-反转字符串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/344-%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.cpp)、[345-反转字符串中的元音字母](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/345-%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%85%83%E9%9F%B3%E5%AD%97%E6%AF%8D.cpp)：对撞指针
- [3-无重复字符的最长子串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/3-%E6%97%A0%E9%87%8D%E5%A4%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E4%B8%B2.cpp)：
  - 使用滑动窗口求解即可,注意窗口两个边界移动的条件
  - 使用vector `<int>` a(256,-1)来当作字符的哈希表，因为8位ASCII码表只有256个字符
  - 犯的小错1：`int a[256]={-1}`只能将a[0]初始化为-1,其余剩余元素都为0,使用 `vector<int> a(256,-1)`将所有元素都初始化为-1
  - 犯的小错2：`charLocation[s[right++]] = right;`从右往左运算（参照运算符重载的匹配规则，双目运算符先确定右边的数的类型），所以这一行执行完后，right+1；若写成 `charLocation[s[right]] = right++;`则在读取右边时，,right+1,左边的right就变成了加一后的right
- [438-找到字符串中所有字母异位词](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/438-%E6%89%BE%E5%88%B0%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E6%89%80%E6%9C%89%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.cpp)：滑动窗口;不要简单问题复杂化，不要简单问题复杂化，不要简单问题复杂化，直接遍历字符串，将两个hashmap比较即可 ，hashmap的key是字符，value是字符在子串中的个数
- [76-最小覆盖子串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/sliding-window/76-%E6%9C%80%E5%B0%8F%E8%A6%86%E7%9B%96%E5%AD%90%E4%B8%B2.cpp)：
  - 滑动窗口经典题
  - 要比较cur的字符是否覆盖了goal的字符，可以时刻记录cur中value大于goal的key的个数，当个数等于goal的size时，cur 的字符就覆盖了goal，这样比起用循环会快很多
  - ```
    //1.我们在字符串S中使用双指针中的左右指针技巧，初始化left = right = 0，把索引左闭右开区间[left, right)称为一个「窗口」。
    //2、我们先不断地增加right指针扩大窗口[left, right)，直到窗口中的字符串符合要求（包含了T中的所有字符）。
    //3、此时，我们停止增加right，转而不断增加left指针缩小窗口[left, right)，直到窗口中的字符串不再符合要求（不包含T中的所有字符了）。同时，每次增加left，我们都要更新一轮结果。
    //4、重复第 2 和第 3 步，直到right到达字符串S的尽头。
    /* 滑动窗口算法框架 */
    void slidingWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0; 
        while (right < s.size()) {
            // c 是将移入窗口的字符
            char c = s[right];
            // 右移窗口
            right++;
            // 进行窗口内数据的一系列更新
            ...

            /*** debug 输出的位置 ***/
            printf("window: [%d, %d)\n", left, right);
            /********************/

            // 判断左侧窗口是否要收缩
            while (window needs shrink) {
                // d 是将移出窗口的字符
                char d = s[left];
                // 左移窗口
                left++;
                // 进行窗口内数据的一系列更新
                ...
            }
        }
    }
    ```

## Search-查找：

- [349-两个数组的交集](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/349-%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.cpp)、[350-两个数组的交集2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/350-%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86%20II.cpp)：如果数组有序的话，使用二分查找会更好
- [202-快乐数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/202-%E5%BF%AB%E4%B9%90%E6%95%B0.cpp)：要判断一个链表是否有环可以使用快慢指针的方式，如果没有环，慢指针一定赶不上快指针，如果有环，则快指针一定能追上慢指针
- [15-三数之和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/15-%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.cpp)：三数之和可以降维为二数之和，不用哈希表，而是用排序数组加对撞指针的方式
- [18-四数之和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/18-%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.cpp)：四数之和也是一样的降维，同时需要注意整型溢出的问题，再比较 target 时用减法
- [454-四数相加2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/454-%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0%20II.cpp)：如果使用暴力解法，将nums4存在哈希表里，那么时间复杂度是O(n^3)，可以先求出num1、num2所有可能的值存在哈希表里，再遍历num3、num4，那么时间复杂度是O(n^2)
