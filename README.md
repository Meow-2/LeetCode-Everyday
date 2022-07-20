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
  - (a <sup>b </sup>)%k = ((a%k)<sup>b </sup>)%k;
  - **a <sup>1234 </sup>%k** = ((**a <sup>123 </sup>%k**)<sup>10 </sup>%k * a <sup>4 </sup>%k)%k
  - 定义一个函数powMod(int a,int b) = a <sup>b </sup>%k ;(0<=k<10)

## Some Tips：

**不要使用`for(int i= -1;i<vec.size();i++)`，(int) -1 > (unsigned int) size()**

- [458-可怜的小猪](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/458-可怜的小猪.cpp)：Cpp标准库没有提供自定义底数的log函数，需要时可以这样代替 `loga(b) = log2(b)/log2(a);`
- [594-最长和谐子序列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/594-最长和谐子序列.cpp)：从小到大排序 `#include <algorithm> std::sort(iterator &begin,iterator &end)`;
- [786-第K个最小的素数分数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/786-第K个最小的素数分数.cpp)、[23-合并K个排序链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/heap/23-%E5%90%88%E5%B9%B6K%E4%B8%AA%E5%8D%87%E5%BA%8F%E9%93%BE%E8%A1%A8.cpp)、[347-前K个高频元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/heap/347-%E5%89%8D%20K%20%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.cpp):

  - 优先队列

  ```cpp
  priority_queue<pair<double,pair<int,int>>>q;
  q.push({1*1.0/3,{1,3}});
  q.pop();

  //23-合并K个排序链表
  struct node
  {
    int       val;
    ListNode* nodeAdress;
    node(int a, ListNode* b) : val(a), nodeAdress(b)
    {}
    //优先队列，所以默认是小的在后，而题目里需要小的在前，所以return的时候是大于号
    bool operator<(const node& a) const
    {
        return this->val < a.val;
    }
  };
  priority_queue<node> q;
  ```

  - 自定义排序

  ```cpp
  vector<pair<int, int>> vec;
  sort(vec.begin(), vec.end(), [&](const auto& x, const auto& y) {
          return x.first * y.second < x.second * y.first;
      });

  // map 按Key从大到小排序
  map<int,int,great<int>> mapp;

  // 使用lambda表达式的最小堆, 优先队列默认是最大堆, 比较函子是 a < b 为 true , 所以 a 在 b 的下面,
  // 为了变成最小堆, 让大的在下面就需要为 true 时, 大的在前面
  auto cmp = [](const ListNode* a, const ListNode* b) { return a->val > b->val; };
  priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
  ```

- [1816-截断句子](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/1816-截断句子.cpp)：删除字符串从index i到末尾的所有字符 `s.erase(i)`
- [125-验证回文串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/125-%E9%AA%8C%E8%AF%81%E5%9B%9E%E6%96%87%E4%B8%B2.cpp)：`isalnum(char)`判断一个字符是否是数字或字母，反转字符串str `string reverse_string(str.rbegin(),str.rend())`, rbegin()的类型是reverse_iterator
- [76-最小覆盖子串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/sliding-window/76-%E6%9C%80%E5%B0%8F%E8%A6%86%E7%9B%96%E5%AD%90%E4%B8%B2.cpp)：unordered_map使用count(key)的方式检查表内是否含有某个key，如果含有返回1，如果不含有返回0

  ```cpp
  unordered_map<char,int> a;
  if(a.count('c')){}
  ```
- [349-两个数组的交集](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/349-%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.cpp)、[350-两个数组的交集2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/350-%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86%20II.cpp)：

  ```cpp
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
- [451-根据字符出现频率排序](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/451-%E6%A0%B9%E6%8D%AE%E5%AD%97%E7%AC%A6%E5%87%BA%E7%8E%B0%E9%A2%91%E7%8E%87%E6%8E%92%E5%BA%8F.cpp)：

  ```cpp
  sort(temp.begin(), temp.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
  ```
- [149-直线上最多的点数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/149-%E7%9B%B4%E7%BA%BF%E4%B8%8A%E6%9C%80%E5%A4%9A%E7%9A%84%E7%82%B9%E6%95%B0.cpp)：将 float 保留10位小数转化为 string，借助ostringstream

  ```cpp
  #include <sstream>
  ostringstream s;
  s<<setiosflags(ios::fixed) << setprecision(10)<<3.21;
  ```
- [220-存在重复元素3](https://github.com/Meow-2/LeetCode-Everyday/blob/main/ordered-map/220-%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0%20III.cpp)：

  ```cpp
  int key;
  set<int> windowNums;
  auto it = windowNums.lower_bound(key);//返回不小于key的第一个元素的迭代器
  it = windowNums.upper_bound(key);//返回大于key的第一个元素的迭代器
  ```
- [150-逆波兰表达式求值](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/150-%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.cpp)：Lambda表达式
  ```cpp
  unordered_map<string, function<int(int, int)>> map = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}};
  int op1 = stack.top();
  stack.pop();
  int op2 = stack.top();
  stack.pop();
  stack.push(map[s](op2, op1));
  ```
 
- [46-全排列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/backtracking/46-%E5%85%A8%E6%8E%92%E5%88%97.cpp):


    erase(pos)	删除 vector 容器中 pos 迭代器指定位置处的元素，并返回指向被删除元素下一个位置元素的迭代器。该容器的大小（size）会减 1，但容量（capacity）不会发生改变。

    iterator insert(pos,n,elem)	在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器

---

## Array-数组：

1. 数组题目一般都可以使用**双指针**的解法,三路快排就是一个很典型的双指针加二分递归
2. 双指针根据指针起点和移动方式的不同，可以分为快慢指针和对撞指针和**滑动窗口**

   ```cpp
   int slow = 0,fast = 0 //快慢指针,[0,slow)维护一个题目要求的数组
   int left = 0,right = arr.size()-1 //对撞指针，当 i = j 或 i < j 时停止循环
   ```
3. 快慢指针，两个指针起点相同同向移动，速度不同；对撞指针，两个指针一头一尾，相向移动；滑动窗口，两个指针构成一个区间，在数组内滑动
4. 在搜索时考虑使用二分法

   ```cpp
   int i = 0,j = arr.size() - 1;//[i,j]，在二分查找中，i = j 时，相当于[i]，仍旧需要对 i 进行一次判断
   while(i<=j){
     mid = i+(j - i )/2; 	//防止溢出
     ...
   }
   ```
5. 写不出来就暴力，但有可能会超时，超时也可以试着用if来筛选一些明显不可能的情况

- [11-盛水最多的容器](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/11-%E7%9B%9B%E6%9C%80%E5%A4%9A%E6%B0%B4%E7%9A%84%E5%AE%B9%E5%99%A8.cpp)： 这题使用暴力解法会超时（除非用在第二层循环前用 if 过滤掉不可能的情况），使用对撞指针时，应将两个指针想象成容器的两边，若想让当前的容器盛更多的水，那么只有将短的那一边向内部移动才有可能
- [167-两数之和 2 输入有序数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/167-%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C%20II%20-%20%E8%BE%93%E5%85%A5%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.cpp)：对撞指针，从比较指针和与target的大小，从而决定如何逼近两个指针
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

    ```cpp
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
- [15-三数之和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/15-%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.cpp)：

    三数之和可以降维为二数之和，不用哈希表，而是用排序数组加对撞指针的方式, 这里需要注意去重的问题:

    1. 如果 num[i] == nums[i-1] 继续, i++
    2. 如果nums[left]前一个值和它一样, 那么说明已经统计过了, 就不统计, 但是如果同时还满足 left = i + 1, 那么是没有统计过的

- [18-四数之和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/18-%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.cpp)：四数之和也是一样的降维，同时需要注意整型溢出的问题，在比较 target 时用减法
- [454-四数相加2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/454-%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0%20II.cpp)：如果使用暴力解法，将nums4存在哈希表里，那么时间复杂度是O(n^3)，可以先求出num1、num2所有可能的值存在哈希表里，再遍历num3、num4，那么时间复杂度是O(n^2)
- [49-字母异位词分组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/49-%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D%E5%88%86%E7%BB%84.cpp)：异位词哈希编码，可以使用排序好的异位词作为key,或者使用每个字母出现的次数的字符串sts表示作为key
  ` string sts = string(26, '0') ; //在字母的对应位上计数`
- [447-回旋镖的数量](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/447-%E5%9B%9E%E6%97%8B%E9%95%96%E7%9A%84%E6%95%B0%E9%87%8F.cpp)：使用hashmap记录每次循环中已遍历的点与选定镖尖点的距离从而将时间复杂度降到O(n^2)
- [149-直线上最多的点数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/149-%E7%9B%B4%E7%BA%BF%E4%B8%8A%E6%9C%80%E5%A4%9A%E7%9A%84%E7%82%B9%E6%95%B0.cpp)：这题主要考察如何用哈希表存储斜率

  - 如果将key设为浮点数，那么就面临浮点数精度不一定够的情况，可以借助 `<sstream>`将浮点数转为保留10位小数的string:

    ```cpp
    ostringstream s;
    s<<setiosflags(ios::fixed) << setprecision(10)
    ```

    但是这样就需要注意，斜率为0和分子为0的情况，这时一个斜率可能代表很多直线，或者斜率不存在无法用浮点数表示

  - 或者使用分母分子形式的string来作为key,那么就一定要是最简形式的分子分母,"分子_分母",这就需要求最大公约数，使用辗转相除法：

    ```cpp
    int gcd(int a, int b)   //最大公约数
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    ```

- [220-存在重复元素3](https://github.com/Meow-2/LeetCode-Everyday/blob/main/ordered-map/220-%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0%20III.cpp)：使用滑动窗口来解决 k 的问题，然后在滑动窗口内解决 t 的问题，每新加一个数 x，检查窗口内的其他数是否在 [ x - t , x + t ]的范围内，使用一个个遍历的方式会超时，故**将窗口中的数存储在一个有序的数据结构中**使用二分查找的方式来降低时间复杂度，查找的数即为第一个不小于 x - t 的数，若存在这个数，且这个数小于 x + t 则返回 true ：

  ```cpp
  set<long> windowNum;
  auto it = windowNum.lower_bound((long)nums[right]-t);
  if (it != windowNum.end() && *it <= (long)nums[right] + t)
      return true;
  ```
  本题需要考虑 x - t 和 x + t 溢出的问题，可以将所有的int改用为long解决，也可以限定[x-t,x+t]的范围如：

  ```cpp
  //nums[right] - t 写成如下形式，其最小值也就是INT_MIN
  max(nums[right],INT_MIN + t) - t;
  //nums[right] + t 写成如下形式，其最大值也就是INT_MAX
  min(num[right],INT_MAX - t) + t;
  ```

## Linked List-链表:
- [206-反转链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/206-%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.cpp)：
考察对链表指针的运用：
  ```cpp
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* n;
        while (cur != nullptr) {
            n         = cur->next;
            cur->next = pre;
            pre       = cur;
            cur       = n;
        }
        return pre;
    }
  ```
- [92-反转链表2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/92-%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8%20II.cpp)：记住，在反转链表时需要用到 pre cur n 三个指针，n只是暂时用来存放 next 指针。在遍历链表的过程中，只有cur 指针指向的 node 的内容会发生改变。
- [86-分隔链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/86-%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8.cpp)、[328-奇偶链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/328-%E5%A5%87%E5%81%B6%E9%93%BE%E8%A1%A8.cpp)：将一个链表拆成两个链表，然后再将两个链表连接起来，需要注意链接后的链表尾部是否指向nullptr
- [2-两数相加](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/2-%E4%B8%A4%E6%95%B0%E7%9B%B8%E5%8A%A0.cpp)：将链表转换成整数会溢出，需要模拟加法的过程直接在两个链表上相加，记得最后的进位。
- [203-移除链表元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/203-%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.cpp)：本题如果使用一个dummyNode作为第一个节点可以省略许多判断，**链表进行删除操作时考虑使用dummy节点** ，注意`while`语句的写法也不同：
  ```cpp
  ListNode* removeElements(ListNode* head, int val)
  {
      ListNode* preHead = new ListNode(0, head);
      ListNode* cur     = preHead;
      while (cur->next) {
          if (cur->next->val == val) {
              ListNode* temp = cur->next;
              cur->next      = cur->next->next;
              delete temp;
          }
          else
              cur = cur->next;
      }
      return preHead->next;
  }
  ```
- [82-删除链表中的重复元素2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/82-%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0%20II.cpp)：**用dummy节点加cur->next进行while判断能省不少事** 。本题因为需要把重复的元素都删除，如果只删除等于下一个节点的节点的话就会留下一个节点，所以使用一个临时量存储当前要删除的节点的值，即当下一个节点的值等于当前节点时，存储这个值,这样一来即使到了最后一个要删除的节点，因为下一个节点的值不等于当前值，所以这个值也不会改变，然后只要当前节点等于这个值就删除当前节点。在dummy节点下,我说的当前节点实际上是指cur->next 这个节点删除的是 cur->next。
- [21-合并两个有序链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/21-%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8.cpp)：**使用dummy节点来处理链表的头**, 链表合并时, 循环的条件可以是(l1&&l2), 如果有一方到头了, 直接把另一方剩下的迁过来即可
- [24-两两交换链表中的节点](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/24-%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.cpp)：**当链表的头可能发生改变时，使用dummy节点** 。
- [25-K个一组翻转链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/25-K%20%E4%B8%AA%E4%B8%80%E7%BB%84%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.cpp)：画一个图就很快能解决了，另外需要注意当count == k 时, 下一个 pre 是 reverseHead 。
- [147-对链表进行插入排序](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/147-%E5%AF%B9%E9%93%BE%E8%A1%A8%E8%BF%9B%E8%A1%8C%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F.cpp)：维护一个已排好序的链表，用下一个将排序的元素与链表尾元素比较，如果小于则进入循环寻找该元素的位置。
- [237-删除链表中的节点](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/237-%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.cpp)：只给出了要删除的节点的指针，所以我们只能删除下一个节点，并将当前节点的值改为下一个节点的值。
- [19-删除链表的倒数第N个节点](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/19-%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%AC%20N%20%E4%B8%AA%E7%BB%93%E7%82%B9.cpp)：可能改动头节点，使用dummy节点。可以遍历两遍链表，也可以使用双指针（固定窗口）的方式：
  ```cpp
  auto*     dummyNode = new ListNode(0, head);
  ListNode* left      = dummyNode;
  ListNode* right     = dummyNode->next;
  int       count     = 1;  // right 和 left 的距离
  while (right) {
      if (count != n + 1) {
          count++;
          right = right->next;
      }
      else {
          right = right->next;
          left  = left->next;
      }
  }
  if (count == n + 1) {
      ListNode* temp = left->next;
      left->next     = left->next->next;
      delete temp;
  }
  ```
- [61-旋转链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/61-%E6%97%8B%E8%BD%AC%E9%93%BE%E8%A1%A8.cpp)：先求出倒数N,然后断开，再连成环。
- [234-回文链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/234-%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8.cpp)：
  - 使用一个额外的数组来存储，然后对撞指针，时间复杂度为O(n),空间复杂度为O(n)。
  - 找到中间指针，反转后面的链表，前后遍历一遍，时间复杂度O(n),空间复杂度为O(n)。**找到中间指针可以用快慢指针**，只需遍历一遍，而计数法需要遍历两遍, 而且使用快慢指针的同时由于慢指针刚好是一个个遍历且在中间停下来，故可以顺便翻转前面的链表。
  ```cpp
  //快指针的速度是慢指针的两倍
  ListNode* pre  = nullptr;
  ListNode* n    = nullptr;
  auto*     slow = head;
  auto*     fast = head->next;
  while (fast && fast->next) {
      n          = slow->next;
      slow->next = pre;
      pre        = slow;
      slow       = n;
      fast       = fast->next->next;
  }
  auto* right = slow->next;
  slow->next  = pre;
  auto* left  = fast ? slow : pre;
  ```
  - 还可以使用哈希法，如果是回文链表的话，正向哈希、反向哈希是一样的，附上一个不太看的明白的 java 解法：
  ```java
  class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode t=head;
		int base = 11, mod = 1000000007;
    	int left = 0, right = 0, mul = 1;
        while(t!=null){
        	left = (int) (((long) left * base + t.val) % mod);
        	right = (int) ((right + (long) mul * t.val) % mod);
            mul = (int) ((long) mul * base % mod);
            t=t.next;
        }
        return left==right;
    }
  }
  ```
- [148-排序链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/148-%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8.cpp)：快排不知道为什么超时了，归并排序AC了,两个都是先拆开链表再递归再合并。
- [143-重排链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/143-%E9%87%8D%E6%8E%92%E9%93%BE%E8%A1%A8.cpp)：快慢指针找中点，倒转后半部分再合并。

## Stack-栈 & Queue 队列
- [20-有效的括号](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/20-%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.cpp)：栈顶元素反应了在嵌套的层次关系中，最近的需要匹配的元素，常用于匹配问题
 
- [150-逆波兰表达式求值](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/150-%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.cpp)：经典的栈，注意栈顶和次栈顶，谁是左操作数？谁是右操作数？
 
- [71-简化路径](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/71-%E7%AE%80%E5%8C%96%E8%B7%AF%E5%BE%84.cpp)：直接在结果字符串上模拟栈，或者先将path分隔，再送栈，再连接。
 
- [144-二叉树的前序遍历](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/144-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86.cpp)、[145-二叉树的中序遍历](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/145-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86.cpp)、[94-二叉树的后序遍历](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/94-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86.cpp)：使用栈完成，前序好写；中序需要将所有的左节点先压栈，然后弹栈，打印，将该节点的右子节点的所有左子节点压栈循环；后序遍历使用双栈, 第一个栈弹出节点，压入左节点，压入右节点，但是弹栈时不打印，而是将值存入第二个栈，第二个栈弹栈打印，又或者可以使用中序遍历的方式，只是每次pop元素时，记录下该元素，当一个元素要pop时，如果上一个pop的是左子树就要压栈右子树，如果上一个pop的是右子树或右子树为空就可以直接pop；或者有一个更通用的方法，使用一个command栈模拟递归函数调用的过程
 
- [102-二叉树的层序遍历](https://github.com/Meow-2/LeetCode-Everyday/blob/main/breadth-first-search/102-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.cpp)：双队列，两个指针指向两个队列，一个放当前层一个放下一层，当前层为空，两个指针交换，两个队列为空结束;广度优先搜索，队列中存放（TreeNode*，层数），子节点层数为父节点层数加一;更进一步优化额外空间，双队列可以优化成一个队列，每次出队前计算当前队列的节点数量，出队那么多数量的节点，**这样可以做到逐层操作**

- [279-完全平方数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/breadth-first-search/279-%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.cpp)：dp或者广度优先搜索（队列实现），dp需要写出状态转移方程，而BFS要在脑海中构建图
 
- [127-单词接龙](https://github.com/Meow-2/LeetCode-Everyday/blob/main/breadth-first-search/127-%E5%8D%95%E8%AF%8D%E6%8E%A5%E9%BE%99.cpp)：广度优先搜索，维护一个已访问节点的链表，对于以访问的节点就不再入队
 
- [126-单词接龙2](https://github.com/Meow-2/LeetCode-Everyday/blob/main/breadth-first-search/126-%E5%8D%95%E8%AF%8D%E6%8E%A5%E9%BE%99%20II.cpp)：BFS找到最优解（使用一个bool来标记是否找到，若找到，则这一层遍历后就结束），用一个hashmap记录每个单词第一次出现的层数，下一层同样的单词就不入队了;BFS结束后DFS回溯路径，所以需要一个hashmap记录string是从哪一个string来的

- [347-前K个高频元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/heap/347-%E5%89%8D%20K%20%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.cpp)：前多少个xx，这类题目基本都可以用堆做，也就是优先队列;也可以直接用按值排序的map，map按值排序可以将其放入`vector<pair<T,T>>`中使用sort + lamdab表达式来做
  - Q：为什么不能直接用sort对map进行排序呢？
  - A：因为sort只能对序列化容器进行排序
  
- [23-合并K个排序链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/heap/23-%E5%90%88%E5%B9%B6K%E4%B8%AA%E5%8D%87%E5%BA%8F%E9%93%BE%E8%A1%A8.cpp)：注意优先队列是大的在前，小的在后，而题目里需要小的在前，所以return的时候是大于号

## Binaray Tree 二叉树 & Recursive 递归

- [111-二叉树的最小深度](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/111-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.cpp):
    
    当子节点有一方为空的时候, 以该节点为根的二叉树的最小深度为1
 
- [222-完全二叉树的节点个数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/111-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.cpp):
    
    先求出二叉树的层数h (从第0层开始计数), 得到可能的取值范围[1<<h , (1<<(h+1)) - 1], 然后可采用二分搜索的方法, 另为在判断某个编号的节点是否位于
树上时, 可以采用位运算的方法, 将该节点转换为二进制( h 层的节点会转化为 h + 1 位二进制数, 其最高位为1 , 其余各位从高到低表示从根节点到第 k 个节点的路径，0 表示移动到左子节点，1 表示移动到右子节点), 然后用一个mask循环与来判断每一位是1还是0, 并从根节点按相应的路径移动, 看是否会到达空节点
 
- [404-左叶子之和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/404-%E5%B7%A6%E5%8F%B6%E5%AD%90%E4%B9%8B%E5%92%8C.cpp):递归最重要的就是找到递归出口

- [257-二叉树所有路径](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/257-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.cpp):深度优先遍历(先序遍历)加字符串存储

- [129-求根节点到叶节点数字之和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/129-%E6%B1%82%E6%A0%B9%E8%8A%82%E7%82%B9%E5%88%B0%E5%8F%B6%E8%8A%82%E7%82%B9%E6%95%B0%E5%AD%97%E4%B9%8B%E5%92%8C.cpp):深度优先遍历(先序遍历)

- [113-路径总和II](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/113-%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C%20II.cpp):

- [437-路径总和III](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/437-%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C%20III.cpp): 双重深度优先遍历, 先对每个结点深度优先遍历, 再将每个结点做为树的根进行深度优先遍历

    深度优先遍历模板:
    ```
    // 注意 dfs 的参数, 带引用的参数和不带引用的参数效果是不同的
    // res带引用, 所以 dfs 中的 res 是全局的
    // path 不带引用, dfs 中的 path 是和 dfs 的函数调用栈相关的, path 参数常用于记录根节点到当前节点的路径
    void dfs(TreeNode* root,int target,T & res, T' path){
        if (!root)
            return;
        //条件判断, 对当前node进行操作
        ...
        dfs(root->left, target, res, path);
        dfs(root->right, target, res, path);
    }
    T solution(TreeNode* root,int target){
        T res;
        T' path;
        dfs(root,target,res,path);
        return res;
    }
    ```
- [230-二叉搜索树中第K小的元素](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/230-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%AC%ACK%E5%B0%8F%E7%9A%84%E5%85%83%E7%B4%A0.cpp):
    
    二叉搜索树的中序遍历序列一定是递增的, 所以中序遍历到第k个返回就可以了

- [235-二叉搜索树的最近公共祖先](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/235-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.cpp)

    `bool dfs(root,p,q)` 如果以root为根的树存在p或q为子节点,则返回true,对于一个root,如果其`dfs(root->left,p,q)`和`dfs(root->right,p,q)`都为true(注意也要考虑root为p,root->left返回q的情况),则记录root为结果

- [236-二叉树的最近公共祖先](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/236-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.cpp):

    dfs或回溯, 记录遍历到q 、p 的路径, 然后返回路径中最后一个相同部分

--- 

## Hot 100

- [4-寻找两个正序数组的中位数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/4-%E5%AF%BB%E6%89%BE%E4%B8%A4%E4%B8%AA%E6%AD%A3%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E4%B8%AD%E4%BD%8D%E6%95%B0.cpp):

    O(log(m+n))的写法就不追求了, 简单归并, 然后取中位数就好, 注意取中位数和`m+n`的奇偶是有关系的

- [5-最长回文子串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/5-%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.cpp):
 
    动态归划的重点就是找到状态转移方程, 然后将所有的状态的值求出来(求dp[n][n]), 之后找到满足题目要求的值, 本题求最大回文子串, 那么我们可以把所有子串作为一个状态, 其值表示是否是回文串, 写状态转移方程时注意边界条件
    ```cpp
    vector<vector<bool> dp{n,vector<bool>{n, false}};
    if (j - i == 0)
        dp[i][j] = true;
    if (j - i == 1)
        dp[i][j] = s[i] == s[j];
    if (j - i > 1)
        dp[i][j] = dp [i+1][j-1] && s[i+1]==s[j-1];
    ```
    `dp[n][n]` 的值是从 `dp[0][0]` 开始一步步求到 `dp[n][n]`, 双重循环, 第一层是 `2 <= j - i + 1 <= n` , 第二层是 `0 <= i < n`

    另外也可以用中心扩展法来解, 但是注意扩展的时候, 字符串并不是只有 n 个可扩展的节点, 而是 n + n - 1 个, 因为两个节点中间也是一个可扩展节点, 或者说扩展本来就是从两个节点开始的(1. 从一个节点扩展相当于从两个相同节点扩展 2. 从相邻两节点扩展)

- [10-正则表达式匹配](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/10-%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%E5%8C%B9%E9%85%8D.cpp):
    
    动态规划, dp[i][j] ( i = s.size() + 1, j = p.size() + 1) 表示 s 的前 i 个字符与 p 的前 j 个字符能否匹配

    注意 base case 的求解:
    1. 当 s 为空串, 若 p 全是带 * 的则也可以匹配
    2. 当 p 为空串, s 非空, 全部不能匹配
    3. dp[0][0] 可匹配
    
    求解完 base case 之后就可以从 i = 1 , j = 1 开始迭代了, 如果 p[j-1] 为 '*' , 则有三种情况可令dp[i][j]为true:
     
    1. dp[i][j-2] 为 true, 则dp[i][j] 为true;
    2. dp[i-1][j-2] 为 true, 且 matches(i, j-1) 为true;
    3. dp[i-1][j] 为 true, 且 matches(i, j-1) 为true;

- [17-电话号码的字母组合](https://github.com/Meow-2/LeetCode-Everyday/blob/main/backtracking/17-%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88.cpp):

    回溯法用于遍历所有情况, 而动态规划往往是遍历所有情况找最优

    回溯法和 dfs 其实是一回事, 但是写法有稍许不同, 两者可以相互转换, 本题提供了回溯和 dfs 两种写法, dfs 相当于把记录 path 的步骤放到了每个递归调用中, 而回溯法在一次递归调用中会多次记录路径, dfs 因此也需要多一个函数参数

    从结构上看, dfs 是对树的节点的遍历, 而回溯则是对树的躯干(层次)的遍历
    在 path 的记录上, dfs 不能使用引用, 而回溯可以

- [22-括号生成](https://github.com/Meow-2/LeetCode-Everyday/blob/main/backtracking/22-%E6%8B%AC%E5%8F%B7%E7%94%9F%E6%88%90.cpp):

    枚举所有的情况用回溯法, 注意分支选择条件

- [31-下一个排列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/31-%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%8E%92%E5%88%97.cpp):

    草稿纸上模拟, 找规律, 注意边界条件, 如比较大小时数字相等的情况, `index = 0` 或 `index == nums.size() - 1` 的情况

    1. 从数组的后面往前找, 找到第一个递增的序列, 设其下标为 `index - 1` 和 `index` , 也就是说从 `index` 开始, 数组都是递减的
     
    2. 再从后往前找, 找到第一个大于`nums[index-1]`的数, 设其下标为 `index1`
     
    3. `swap(nums[index1], nums[index - 1])` 
     
    4. 反转 `index` 到数组最末尾的数

- [32-最长有效括号](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/32-%E6%9C%80%E9%95%BF%E6%9C%89%E6%95%88%E6%8B%AC%E5%8F%B7.cpp):动态规划, 找状态转移方程, 本题只需要 dp[n] 的空间就能解决, 我最开始想的是 dp[n][n], 最后10个用例超时, [LeetCode题解](https://leetcode.cn/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/)

- [33-搜索旋转排序数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/33-%E6%90%9C%E7%B4%A2%E6%97%8B%E8%BD%AC%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84.cpp):

    注意数组有两个部分, 如果`nums[mid]`和`target`在一个部分, 则和普通二分查找没有什么区别, 如果他们不在一个部分, 那么就与普通二分查找不同, 只需要在循环中用两个 if 处理不在一个部分的两种特殊情况即可

- [34-在排序数组中查找元素的第一个和最后一个位置](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/34-%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%92%8C%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E4%BD%8D%E7%BD%AE.cpp):
    
    两遍二叉搜索, 先搜索右边, 再搜索左边, 或者复杂一点把两次搜索写进一个搜索过程里(增加了代码复杂度, 也不便于理解, 不推荐)

- [39-组合总和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/backtracking/39-%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.cpp):

    回溯, 先对数组排序, 然后选择路径, 因为允许重复元素, 所以用一个begin_index来标记可以选择的值, 即下标大于begin_index的都是可选的值, 递归结束条件就设为当path里的数字之和大于target时, 若等于target则压入res数组

- [42-接雨水](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/42-%E6%8E%A5%E9%9B%A8%E6%B0%B4.cpp):

    关键在于弄对雨水面积的求法, 按列求每列的雨水面积, 当前列的雨水面积只与其左边最高列和右边最高列有关, 将其高度h与其左右最高中较矮的那一个h'进行比较, 如果 h >= h' , 则当前行无雨水, 如果 h < h' , 则当前行的雨水为 h' - h, 如此一来, 三次遍历即可解, [接雨水-详细通俗的思路分析，多解法](https://leetcode.cn/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)

- [46-全排列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/backtracking/46-%E5%85%A8%E6%8E%92%E5%88%97.cpp):

    在回溯的过程中, 用一个数组维护路径, 同时可选则的路径也会越来越少, 因此需要对存储可选路径的nums数组进行erase()和insert()

    erase(pos)	删除 vector 容器中 pos 迭代器指定位置处的元素，并返回指向被删除元素下一个位置元素的迭代器。该容器的大小（size）会减 1，但容量（capacity）不会发生改变。

    iterator insert(pos,n,elem)	在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器

- [48-旋转图像](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/48-%E6%97%8B%E8%BD%AC%E5%9B%BE%E5%83%8F.cpp):
 
    从外向内循环, 注意每一层实际上只需要一个临时变量就好了

- [53-最大子数组和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/53-%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C.cpp):

    一维的dp, 很常见的一种描述状态转移方程的方法: dp[i]代表以下标i结尾的最大子序列和


- [55-跳跃游戏](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/55-%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F.cpp):
 
    此题用dfs、dp超时(dp[i]表示dp[i]能否到达), 使用贪心法求解, 遍历数组(直到索引等于最大索引或超出数组范围)用一个变量记录所能到达的最大索引, 如果最大索引大于等于最后一个元素的索引则能够到达

- [56-合并区间](https://github.com/Meow-2/LeetCode-Everyday/blob/main/sort/56-%E5%90%88%E5%B9%B6%E5%8C%BA%E9%97%B4.cpp):

    先对数组进行排序, 再对数组进行合并, 用result数组来存储合并结果, 用left和right两个int变量来存储需要压入result的区间的两端, 只需遍历数组一遍即可完成合并

- [62-不同路径](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/62-%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.cpp):

    使用组合数学的解法或者dp, 对于 mxn 的矩阵, 共需要走 (m - 1 + n - 1) 步, 在其中选 (n - 1) 步向下, 有多少种选法就有多少种路线, 在实现的时候要注意 result 会溢出, 所以使用 long long 来代替 int , 另外不可以使用 `result *= (m - 1 + n - 1 - i) / (i + 1)` 的写法, 这样会导致先计算等号右边的式子, 而右边的式子是无法整除的, 从而导致精度丢失, 应该写成`result = result * (m - 1 + n - 1 - i) / (i + 1)`

- [64-最小路径和](https://github.com/Meow-2/LeetCode-Everyday/tree/main/dynamic-programming):

    dp, dp[i][j] 代表到grid[i][j]的最短路径和, 那么`dp[j][i] = min(dp[j][i - 1] + grid[j][i], dp[j - 1][i] + grid[j][i])`

- [70-爬楼梯](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/70-%E7%88%AC%E6%A5%BC%E6%A2%AF.cpp):

    dp, dp[i] 代表到第i阶楼梯有多少种走法

- [72-编辑距离](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/72-%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.cpp):

    dp, dp[i][j] 代表word1的前i个字母变换到word2的前j个字母所需的最小步骤, dp[0][0]代表空字符串到空字符串, 二维的dp在找上一个状态和下一个状态之间的关系时可以着重关注dp[i][j]周围的的状态, 如dp[i-1][j]、dp[i][j-1]、dp[i-1][j-1]如何到达dp[i][j]

- [75-颜色分类](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/75-%E9%A2%9C%E8%89%B2%E5%88%86%E7%B1%BB.cpp):

    和快排一样的对撞指针
    ```cpp
    // [0,left)为0,(right,nums.size()-1]为2
    int left = 0;
    // 不要使用auto, auto 会把right自动推导成 unsigned int
    int right = nums.size()-1;
    // 注意: nums[i] == 2 时, swap(nums[i],nums[right])后, 需要i--, 因为原本的nums[right]还没有判断
    ```

- [76-最小覆盖子串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/76-%E6%9C%80%E5%B0%8F%E8%A6%86%E7%9B%96%E5%AD%90%E4%B8%B2.cpp):

    滑动窗口，如果没有覆盖就移动right，覆盖就移动left，找到最小覆盖，然后算长度，用minLength、minLeft、minRight 保留最小字串的left和right
    
- [78-子集](https://github.com/Meow-2/LeetCode-Everyday/blob/main/backtracking/78-%E5%AD%90%E9%9B%86.cpp):

    回溯, 每次做选择之前, 把当前的path压入res中即可, 等价于在数组末尾加入了一个空元素, 每一步选择只能选比index大的元素, 每次选完之后, 下一次只能选比这次选的 index 大的元素, 如果选到了空元素, 则压入res

    <img src="https://s2.loli.net/2022/07/17/7av2XW9UHc4SC5q.png" alt="" width="250">

    观察发现所有的path最后都有空, 所以可以事先将path压入, 因而就不需要空元素了

- [79-单词搜索](https://github.com/Meow-2/LeetCode-Everyday/blob/main/backtracking/79-%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2.cpp):
    
    回溯, 这题用 dfs 的话, hasSearch数组一定不能写成引用(此题用dfs有一个用例会超时,就是board是A,而word是AAAAAAAA...B,可能是我的写法有问题), 回溯的话, 相当于一条路走到头, 再撤回所有操作再选一条新的路走

- [84-柱状图中的最大矩形](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/84-%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.cpp):

    二维dp超时, 使用单调栈:

    1. 从左往右遍历, 为每个值记录下小于该值的左边最接近的下标, for循环遍历的同时维护一个单调递增栈
    2. 从右往左遍历, 为每个值记录下小于该值的右边最接近的下标, for循环遍历的同时维护一个单调递增栈
    3. 从左往右遍历, 为每个值求以其为高的矩形的面积,记录下最大的面积
    
    单调栈, 即栈里的所有元素代表的值都是单调的, 当需要求一个数左边/右边 大于/小于自己的第一个数时, 经常使用
    ```cpp
    int n = heights.size();
    // 保存小于heights[i]的左边第一个数的下标
    vector<int> left_low(n, -1);
    vector<int> right_low(n, -1);
    // 栈顶是与当前下标最接近的,小于当前值的下标
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        left_low[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        right_low[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    ```
- [85-最大矩形](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/85-%E6%9C%80%E5%A4%A7%E7%9F%A9%E5%BD%A2.cpp):

    二维dp没解出来, dp[i][j]存的是以(i,j)为右下角的最大面积矩形的左上角坐标, 最后有几个用例答案错误
    
    参照地84题, 这题可以转化为直方图求面积, 即以j = 0为y轴, i = 0...m-1 分别为x轴, 当然了需要先将字符矩阵转化为数字矩阵, 并且将每一行的数字都按上一行是否为1进行累积
    
    <img src="https://s2.loli.net/2022/07/19/PIEGwmxbWjRSnFi.png" alt="" width="250">

- [96-不同的二叉搜索树](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/96-%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.cpp):

    dp , dp[i]表示i个递增的数能组成的二叉搜索树的个数

    dp[i] = f(1) + f(2) + f(3) + ... + f(i) , f(x)表示以x为根, 能组成的二叉搜索树的数量

    f(x) = dp[x-1]*dp[i-x], dp[x-1]表示左子树的个数, dp[i-x]表示右子树的个数

    <img src="https://s2.loli.net/2022/07/19/QvoLnrpE2NDeuRJ.png" alt="" width="250">

- [98-验证二叉搜索树](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/98-%E9%AA%8C%E8%AF%81%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.cpp):

    二叉搜索树的中序遍历序列一定是递增的, 注意本题节点值的范围, lastNode的初始值应当是LONG_LONG_MIN

- [101-对称二叉树](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/101-%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.cpp):

    递归求解, 参考判断两颗二叉树是否相同的解法
