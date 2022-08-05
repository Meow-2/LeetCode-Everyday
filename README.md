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

  - 优先队列, 优先自然是大的在前

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

  // map 按Key从大到小排序, map默认是按key从小到大排
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

- [136-只出现一次的数字](https://github.com/Meow-2/LeetCode-Everyday/blob/main/bit-manipulation/136-%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97.cpp):

    cpp的异或运算符`^`

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

- [108-将有序数组转换为二叉搜索树](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/108-%E5%B0%86%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.cpp):

    递归分解为子问题

- [450-删除二叉搜索树中的节点](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/450-%E5%88%A0%E9%99%A4%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.cpp):

    经典模板, TreeNode* dfs(TreeNode* root, int key)返回删除key后的二叉搜索树的根节点

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

- [105-从前序与中序遍历序列构造二叉树](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/105-%E4%BB%8E%E5%89%8D%E5%BA%8F%E4%B8%8E%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.cpp):

    递归构造

    ```
    [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]

    [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
    ```

- [114-二叉树展开为链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/114-%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%95%E5%BC%80%E4%B8%BA%E9%93%BE%E8%A1%A8.cpp):

    递归分解问题, 空间复杂度为O(1);或者dfs构造一条链表, 然后让root指向新构造的链表

- [121-买卖股票的最佳时机](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/121-%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA.cpp):

    求一个值右边最大的值, 可以用dp, dp[i]表示i右边最大的值, 从右往左遍历一遍即可, 然后从左往右遍历一遍, 记录下最大盈利

    本题也可以用单调栈, 单调栈的性质和特点(单调递增栈):

    1. 每个值都会被push
    2. 栈顶的值为当前值左边第一个小于当前值的值, 如果不是, 在push当前值前要pop, 直到满足
    3. 可以用来求数组里元素间的最大差值

- [124-二叉树中的最大路径和](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/124-%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%AF%E5%BE%84%E5%92%8C.cpp):

    递归分解子问题, 同时计算多种情况, 多返回值

    对于以任意节点N为根的树都有一条最大路径, 根据路径所在位置的不同, 以N为子节点的根M的最大路径与N的最大路径的关系也不同, 所以为了涵盖所有的情况, 需要在递归求解的时候同时返回以当前根为端点的最大路径(可以和父节点连接)和不以当前根为端点的最大路径(不可以和父节点连接)

- [128-最长连续序列(哈希表解法)](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/128-%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E5%BA%8F%E5%88%97.cpp)、[128-最长连续序列(并查集解法)](https://github.com/Meow-2/LeetCode-Everyday/blob/main/union-find/128-%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E5%BA%8F%E5%88%97.cpp):
    
    本题中重复的数是累赘, 可以先去重, 或者遇到重复的数字直接跳过
 
    哈希表解法很容易想到, 即用一个哈希表存储每个值的最长连续序列长度, 但是维护这个哈希表需要的时间复杂度也是O(n)级别, 所以需要优化, 实际上, 一个连续序列中, 真正有作用的只有其两个端点在哈希表里的值, 所以只需要维护每个序列的两个端点即可;

    另外, 哈希表也有另一种用法: 遍历数组, 以每个数 i 为起点, 检查i+1、i+2、i+3 ...的长度, 这样的时间复杂度是O(n^2)级别, 所以也可以用哈希表优化, 先用哈希表存储整个数组, 然后遍历数组,对每个数i, 先用哈希表检查 i - 1 是否存在于数组中, 如果存在则跳过i , 因为以i为起点的序列一定被以i-1为起点序列所包含了, 然后再检查i+1、i+2、i+3 ...是否在哈希表中
    
    并查集解法需要自己实现并查集, 并查集由两个unordered_map uf,sz组成, uf是<元素,元素所在集合的根>, sz是<根,根所在集合的大小>

    这两个集合有如下特点:

    1. 对于根元素root: `uf[root] = root`
    2. 对于非根元素ele: `uf[ele] = root_of_ele`
    3. 对于sz中的元素, 只有sz[root]是有效的

    并查集需要定义两个必要的函数find和merge:

    ```cpp
    // union-found, 只有当uf[i] = i 时, i 才是根
    unordered_map<int, int> uf;
    // union-found, 只有当sz[i] = i 时, size才有效, 才表示 union-found 的大小
    unordered_map<int, int> sz;

    // 返回根
    int find(int x)
    {
        // 这里本可以直接写`uf[x] == x ? x : find(uf[x])` , 之所以这么写是为了优化路径
        return uf[x] == x ? x : uf[x] = find(uf[x]);
    }

    //返回合并后集合的大小
    int merge(int x, int y)
    {
        x = find(x), y = find(y);
        // 如果根相同, 则什么也不做
        if (x == y)
            return sz[x];
        uf[y] = x;
        sz[x] = sz[x] + sz[y];
        return sz[x];
    }
    ```

- [139-单词拆分](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/139-%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86.cpp):

    dp, dp[i]表示s的前i个字符能否被字典表示

    dfs, 超时, 需要加入记忆化, 记忆化就是用一个unordered_map存储dfs参数和其返回值, 当再次遇到相同问题时直接查表得出结果

- [136-只出现一次的数字](https://github.com/Meow-2/LeetCode-Everyday/blob/main/bit-manipulation/136-%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97.cpp):

    对数组里所以数做异或运算(相同为0,不同为1,且满足交换律和结合律), 最后出现两次的数字都变成了0, 只出现一次的数字会和0进行异或, 得到他自己

- [142-环形链表 II](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/142-%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8%20II.cpp):

    环形链表求环, 如果只需要判断有无环, 仅用slow和fast两个指针即可, 如何需要求环的入口, 则还需要ptr = head指针, 当slow和fast指针相遇后, 同时向后以步长为1移动 ptr 和 slow, 当 slow == ptr 时, ptr 即为环入口, 求环长也只需要沿着环走一遍即可

    <img src="https://s2.loli.net/2022/07/21/85rPeMG6XZ2sqkS.png" alt="" width="250">

    fast == slow 时, 有 `2(a + b) = a + n(b + c) + b`, 故 `a = nb + nc - b = c + (n - 1)(b + c)` , 所以此时让 ptr 和 slow 一起前进, 他们会在环入口相遇

- [146-LRU缓存](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/152-%E4%B9%98%E7%A7%AF%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84.cpp):

    本想用按值排序的map, 但是发现map不支持自定义按值排序, 想要按值排序, 只能把map取出来放到vector里用sort排序

    双向链表+哈希表, 链表头放最常访问的key, 哈希表存储key和key对应的链表地址, 单向链表不方便修改, 所以使用双向链表, 使修改的时间复杂度也降为O(1)

    双向链表注意维护pre, 另外为了防止经常改动head和tail, 可以在首尾加入两个dummyNode, 使用unique_ptr和裸指针的组合防止内存泄漏

- [148-排序链表](https://github.com/Meow-2/LeetCode-Everyday/blob/main/sort/148-%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8.cpp):

    归并!归并!归并!链表排序用归并!记住在分成子链表的时候, 要断开, 然后merge两个断开的链表!

- [152-乘积最大子数组](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/152-%E4%B9%98%E7%A7%AF%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84.cpp):

    二维dp, dp[i][j]代表nums[i,...,j]的乘积, 最后两个用例超时

    一维dp, dp[i]代表以nums[i]结尾的不包含0的子序列的最大乘积, 需要分多重情况讨论, 当nums[i]>=0时比较简单求, 对于nums[i]<0的情况:
    1. 以nums[i]结尾到最近的0(默认往数组最开头添加一个0)有奇数个负数
    2. 以nums[i]结尾到最近的0有偶数个负数

    最简单的方法是用dp_min[i],dp_max[i]分别记录以nums[i]结尾的子序列的最小乘积和最大乘积, 因为当nums[i]<0时,dp_max[i]可能等于dp_min[i]*nums[i], 可以使用if语句在分情况更新dp_min[i]和dp_max[i], 也可以简单粗暴一点:

    ```cpp
    for (int i = 1; i < n; i++) {
        dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
        dp_min[i] = min(nums[i], min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
    }
    ```

- [155-最小栈](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/155-%E6%9C%80%E5%B0%8F%E6%A0%88.cpp):

    最小栈, 用两个同步的栈, 一个栈存值, 另一个栈存每个值对应的栈内的最小值, 我最开始用了一个multiset来排序, 额...面试应该不会给过吧, 另外有一种不需要辅助栈的解法, 即栈里存元素与最小值的差值, 非常巧妙[无额外空间解法](https://leetcode.cn/problems/min-stack/solution/zui-xiao-zhan-by-leetcode-solution/531353/)

- [[160-相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/linked-list/160-%E7%9B%B8%E4%BA%A4%E9%93%BE%E8%A1%A8.cpp)]:

    哈希表, 如果要求O(1)的空间复杂度, 可以先求两条链表的长度, 然后长的先走到一样长, 再开始遍历

- [[169-多数元素](https://leetcode.cn/problems/majority-element/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/260dcfdad8c1ad63e749289ff120c5203b020099/bit-manipulation/169-%E5%A4%9A%E6%95%B0%E5%85%83%E7%B4%A0.cpp)]:

    位运算, 如果要用O(1)的时间复杂度, 意味这要用常数的空间保存之前遍历过的值的信息, 那么一种思路是对之前的进行某种运算, 保存运算的结果, 如此以来便容易想到位运算:

    int的长度是32位, 每一位都是由0和1组成, 针对每一位, 统计数组里那一位上 1 的数量, 如果数量大于一半, 则说明 res 的那一位上的是1, 反之为零
    
    位运算技巧: 

    1. 取i的第n位:`i & (1 << n)`
    2. 设i的第n位为1: `i | (1 << n)`
    3. 设i的第n位为0: `i & (~(1 << n))`

    摩尔投票法: 
    ```cpp
    int votes     = 0;
    int candidate = 0;
    for (auto i : nums) {
        if (!votes)
            candidate = i;
        votes = i == candidate ? votes + 1 : votes - 1;
    }
    ```
    其核心就是对拼消耗, 想象有一个没有相同元素的数组, 那么candidate会轮流当选, 因为每一个candidate都会被后一数消耗掉, 而对于"数组中的大多数数", 它可以消耗掉任何其他数的当选, 而且还余下一个给自己当选
        
- [[198-打家劫舍](https://leetcode.cn/problems/house-robber/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/198-%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D.cpp)]:
    
    dp[i]表示以nums[i]结尾的最大盗窃序列和

- [[200-岛屿数量](https://leetcode.cn/problems/number-of-islands/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/union-find/200-%E5%B2%9B%E5%B1%BF%E6%95%B0%E9%87%8F.cpp)]:

    并查集, 哈希表的key用string表示, 即grid[i][j]对应的key为"ij"

    DFS解岛屿问题: [岛屿类问题的通用解法、DFS 遍历框架](https://leetcode.cn/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/), Tips: dfs先判断当前是不是1, 不是就return, 对于遍历过的地方可以设置为2, 这样就不会重复遍历

- [[207-课程表](https://leetcode.cn/problems/course-schedule/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/depth-first-search/207-%E8%AF%BE%E7%A8%8B%E8%A1%A8.cpp)]:
    
    本题因为要经常访问课程表, 所以要先将其存储在能快速访问的数据结构中, 起初我用的是 `unordered_map<int, unordered_set<int>>`, 其实用`vector<vector<int>>`就好了, 也就是一个"拓扑排序"建图的过程, 因为其实只需要遍历图, 而不需要快速查找节点后面有没有哪一个节点, 所以用`vector`就行, 也更加快速
 
    另外要表示一个节点有没有被访问过, 在数据量小, 且节点能表示成下标的情况下用数组是最快的, 用`unordered_set`需要计算hash值, 是比较慢的, 本题需要存储整个过程已经访问的节点, 和当前dfs已经访问的节点, 用`unordered_set`的话, 就需要两个`unordered_set hasSearch,curPath`, 用`vector<int>`的话, 只需要用两种不同的int值来表示这两种状态就好了
    
 
- [[208-实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/design/208-%E5%AE%9E%E7%8E%B0%20Trie%20(%E5%89%8D%E7%BC%80%E6%A0%91).cpp)]:

    每个节点存储一个bool值和一个数组(哈希表), bool值表示当前节点是不是一个字符串的结尾, 数组的下标从'a'到'z', 指向下一个字母节点

    <img src="https://s2.loli.net/2022/07/24/HgrvmuJYOkcfAQM.png" alt="" width="250">

    另外在实现的过程中遇到了一个小问题: C++中一个引用指向的地址不会改变，改变的是指向地址的内容，然而java中引用指向的地址在变, 所以老老实实用指针迭代而不要用引用迭代

- [[215-数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/heap/215-%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E7%AC%ACK%E4%B8%AA%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0.cpp)]:

    STL里的优先队列默认是最大堆, 毕竟是"优先"嘛, map和set是默认小的key在前

    对于本题, 可以用一个大小为k的最小堆来存储, 这样的话, 时间复杂度就是O(nlogk), 用最大堆的话就需要O(nlogn), 一个自定义的heap需要有一下几个部分:

    1. 一个数组, 数组下标表示节点序号(从0到n), 通过序号可以求子节点和父节点
        
        1. 对于从1开始的下标i的父节点为i/2, 子节点为2*i、2*i+1
        2. 对于从0开始的下标i的父节点为(i/2+1)-1 , 子节点为2*i+1、2*i+2

    2. shiftUp()、shiftDown()
    3. push()、pop()

    使用容量为k的最小堆的话, 先用前k个元素建成最小堆, 然后遇到比堆顶小的nums[i]就不管, 比堆顶大的nums[i]替换掉堆顶然后shiftDown()

- [[221-最大正方形](https://leetcode.cn/problems/maximal-square/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/221-%E6%9C%80%E5%A4%A7%E6%AD%A3%E6%96%B9%E5%BD%A2.cpp)]:

    dp, dp[i][j]表示以matrix[i][j]为右下角的最大面积正方形的边长

- [[226-翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/238-%E9%99%A4%E8%87%AA%E8%BA%AB%E4%BB%A5%E5%A4%96%E6%95%B0%E7%BB%84%E7%9A%84%E4%B9%98%E7%A7%AF.cpp)]:

    递归求解

- [[234-回文链表](https://leetcode.cn/problems/palindrome-linked-list/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/234-%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8.cpp)]:

    快慢指针找中间点(先移动快指针再移动慢指针, 根据链表长度的奇偶(isOdd)分情况讨论), 同时慢指针翻转链表, 然后从中间向两端遍历

- [[236-二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/236-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.cpp)]:

    递归求解(注意子树存在p, 自己是q的情况), 或者回溯找出到结点的两条路径, 然后找最后一个相同点

- [[238-除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/238-%E9%99%A4%E8%87%AA%E8%BA%AB%E4%BB%A5%E5%A4%96%E6%95%B0%E7%BB%84%E7%9A%84%E4%B9%98%E7%A7%AF.cpp)]:

    从前往后遍历, 从后往前遍历, 同时累积

- [[239-滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/heap/239-%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.cpp)]:

    用一个优先队列存放滑动窗口中的数(存放一个val和pos构成的pair), 当窗口右移时, push新数, 检查堆顶, 如果堆顶元素的pos不属于当前窗口,则pop它, 直到堆顶的pos属于当前窗口, 以后有时间可以看看双向队列O(n)的解法

- [[240-搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix-ii/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/240-%E6%90%9C%E7%B4%A2%E4%BA%8C%E7%BB%B4%E7%9F%A9%E9%98%B5%20II.cpp)]:

    用了非常low的递归算法, 然后当target在三个角落里会超时, 可能是代码bug, 不想调了, 本来就感觉这个递归写的还不如直接遍历...答案是分行二分查找, 用了标准库的算法`lower_bound(row.begin(), row.end(), target)`, 以后有时间可以看看Z形查找

- [[279-完全平方数](https://leetcode.cn/problems/perfect-squares/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/279-%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.cpp)]:

    dp[i]表示i的完全平方数的最少数量(即题目所求), 在遍历过程中提前将所有的完全平方数的dp值设为1, 当遍历到这些数时, 将其压入vector, vector里存储的即为i之前所有的完全平方数, 对于非完全平方数的, 则遍历vector中每个元素j, dp[i] = min(dp[i-j]+1)

    或者找到每个 i 之前的每个完全平方数, 然后广度优先遍历

    后记: 好吧其实不用那么麻烦
    ```cpp
    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
    ```

- [[283-移动零](https://leetcode.cn/problems/move-zeroes/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/283-%E7%A7%BB%E5%8A%A8%E9%9B%B6.cpp)]:

    标记非零元素和零的分界线, 每当遇到非零元素就将其与分界线后的第一个零元素交换

- [[287-寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/two-pointers/287-%E5%AF%BB%E6%89%BE%E9%87%8D%E5%A4%8D%E6%95%B0.cpp)]:

    本题的解法虽然很, 但每种都过于巧妙, 不是很容易想出来

    1. 二分查找, target的范围是[1, n], 可以对这个区间进行二分查找, `left=1,right=n,mid=left+(right-left)>>1`, 但二分查找的前提能根据mid来确定下一个[left, right], 这一点很难想到解决办法, 可以定义 cnt[i] 表示 nums 数组中小于等于 i 的数有多少个，[1, target−1]里的所有数满足 cnt[i]≤i，[target, n] 里的所有数满足 cnt[i]>i，从而就可以知道当前的mid在target的左边还是右边, 进而进行二分查找, 这里还需要关注停止条件, 当 left>right 时会停止(且一定是因为right = mid - 1), 此时上一个 [left, right] 的 mid 即为 target
    2. 位运算, 求 target 的每一位, 那么nums的第i位上共有 x 个 1 ,设 [1, n] 的第i位上共有 y 个 1, 只有当 x > y 时, target的第 i 位上才可能是1
    3. 快慢指针, 将数组抽象成环型链表, target 就是环的入口; 快指针和慢指针一定会在环上相遇, 相遇后, 令一个 ptr 从链表头开始走, 当slow和 ptr 相遇时, 相遇的节点就是环的入口; 有疑惑可以参见这个评论[i=nums[i]怎么跳出去](https://leetcode.cn/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/1356666)
     
- [[297-二叉数的序列化与反序列化](https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/297-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%BA%8F%E5%88%97%E5%8C%96%E4%B8%8E%E5%8F%8D%E5%BA%8F%E5%88%97%E5%8C%96.cpp)]:

    序列化成层序遍历有些麻烦, 直接序列化成先序遍历就好了, 使用istringsteam, 用空格分隔每个字符串, nullptr 用 # 表示, 反序列化时可以方便地从 istringsteam 中取出当初放进去的每个 string

- [[300-最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)|[解答]()]:

    动态规划, dp[i] 表示以 nums[i] 结尾的最长子序列, 需要 O(n^2) 的时间复杂度, 因为对于每个 dp[i] 要比较 i 之前所以小于 nums[i] 的数

    还有一种贪心+二分搜索的办法, 实在不想看了, 附链接吧[贪心+二分搜索](https://leetcode.cn/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/)

- [[301-删除无效的括号](https://leetcode.cn/problems/remove-invalid-parentheses/)|[解答]()]:

    暴力搜索所有的正确的最长解(删除最少的括号意味着剩余的字符串是最长的合法字符串), 那么如何判断一个解是否正确呢?

    1. 左右括号的数量是相等的
    2. 用score记录左括号的数量, 如果是'(', score++, 如果是')', score--
    3. 对于一个子串, score=0 的话就是合格的
   
    我们使用一个set<string>来存储题目的答案, 用string res来记录当前判断的字符串, 可以这样看, res最开始时是"", 对于字符串s的每一个字符ch, 我们只有两种选择, 将ch加入res, 舍弃res, 因而可以依此来进行dfs或回溯

    优化: 加入枝剪, score的最大值为s中'('和')'数量的最小值, 当score超过了这个值, 就舍弃

    C++代码参考: [【宫水三叶】将括号的「是否合法」转化为「数学判定」](https://leetcode.cn/problems/remove-invalid-parentheses/solution/yi-fen-zhong-nei-kan-dong-jiang-gua-hao-aya6k/1199550)

- [[309-最佳买卖股票时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/309-%E6%9C%80%E4%BD%B3%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E6%97%B6%E6%9C%BA%E5%90%AB%E5%86%B7%E5%86%BB%E6%9C%9F.cpp)]:

    分状态dp , dp[i]表示第i天**结束后**的状态, 是第i天结束后最大的累积收益, 这个最大收益跟第i天的操作相关, 但是这么简单的dp定义并不能让我们写出状态转移方程, 尝试让dp状态携带更多信息:

    1. dp[i][0] 第i天结束后持有股票-> 可能是第i天买的, 也可是之前买的
        dp[i][0] = max(dp[i-1][2] - price[i], dp[i-1][0])
    2. dp[i][1] 第i天结束后不持有股票, 且处于冷冻期, 说明是第i天卖的, 第i+1天处于冷冻期
        dp[i][1] = dp[i-1][0] + price[i]
    3. dp[i][2] 第i天结束后不持有股票, 且不处于冷冻期, 第i天结束后不处于冷冻期, 所以第i天可以是冷冻期, 也就是第i-1天结束后处于冷冻期    
        dp[i][2] = max(dp[i-1][2], dp[i-1][1])
    
    分这三种情况后, dp状态就可以覆盖股票买卖的所有情况了,同时收益可以这样看待, 最开始收益是r = 0, 当买入股票时, 收益r = r - price0,当卖出股票时, 收益r = r + price1, dp[prices.size()-1][1]就是最大收益

- [[312-戳气球](https://leetcode.cn/problems/burst-balloons/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/312-%E6%88%B3%E6%B0%94%E7%90%83.cpp)]:

    回溯法, 每次选一个气球戳破, 这样回溯的话, 子问题之间不是相互独立的, 做记忆化的代码也不是很会写, 因为nums会变化, 每个nums对应一个最大值解的话, 就需要对nums数组进行哈希编码, 可能有些麻烦, 所以逆向思考, 把问题转化成易于记忆化的, 相互独立的子问题

    可以向数组两端插入两个哨兵气球, nums[-1] = 1, nums[n] = 1, 假设最后一个被戳破的气球的下标为k, 那么就可以变成(-1,k)和(k,n)的两个子问题, 然后就可以使用回溯或区间dp来解, 就是说dp[i][j] = dp[i][k] + nums[i]*nums[k]*nums[j] + dp[k][j]

- [[322-零钱兑换](https://leetcode.cn/problems/coin-change/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/322-%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2.cpp)]:

    dp, dp[i]表示凑齐i块钱需要的最少硬币数量, 对于每一个dp[i], 遍历数组coins, dp[i] = min(dp[i-j] + 1)

    bfs + 记忆化, 队列里存的是当前积累的总数和当前层数的pair, 为了防止溢出, 可以用 long long 存当前积累的总数, 或者使用减法, 即队列里存当前剩余需要凑的数量和当前层数的pair

    ```cpp
    unordered_map<long long, int> m;
    queue<pair<long long, int>>   q;
    q.push({0, 0});
    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            auto f = q.front();
            q.pop();
            for (auto i : coins) {
                long long temp  = f.first + i;
                int  layer = f.second + 1;
                if (m.count(temp) && m[temp] <= layer)
                    continue;
                if (temp == amount)
                    return f.second + 1;
                if (temp < amount) {
                    q.push({temp, layer});
                    m[temp] = layer;
                }
            }
        }
    }
    ```

- [[337-打家劫舍III](https://leetcode.cn/problems/house-robber-iii/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/depth-first-search/337-%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D%20III.cpp)]:

    递归函数返回一个pair, pair<打劫当前节点的最大值, 不打劫当前节点的最大值>, 另外可以发现, 每一个节点都对应一个返回值, 故也可以不用返回值的方式, 使用两个 unordered_map<TreeNode*,int> 来存储每个节点的返回值

    注意当不打劫当前节点时, 可以选择不打劫左子树和右子树的根节点, 而去选择更优的策略

- [[338-比特位计数](https://leetcode.cn/problems/counting-bits/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/bit-manipulation/338-%E6%AF%94%E7%89%B9%E4%BD%8D%E8%AE%A1%E6%95%B0.cpp)]:

    取n的第i位: n & (1 << i)

- [[347-前K个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/347-%E5%89%8D%20K%20%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.cpp)]:

    哈希表计数, 然后用 size = k 最小堆来筛选前 k 大的元素

- [[394-字符串解码](https://leetcode.cn/problems/decode-string/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/394-%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%A7%A3%E7%A0%81.cpp)]:

    简单栈, 栈可以直接用 string 代替, 可以省去复制的开销

- [[399-除法求值](https://leetcode.cn/problems/evaluate-division/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/union-find/399-%E9%99%A4%E6%B3%95%E6%B1%82%E5%80%BC.cpp)]:

    带权并查集, 重点在于find的时候更新权值

    两个哈希表, uf<string, string>, weight<string, double>, uf代表string和其父亲的映射, weight代表string和father_string/string的映射 , 对于 a/b = 3, uf[b] = a, uf[a] = a, weight[b] = 3, weight[a] = 1
    
- [[406-根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/)|[解答]()]:

- [[416-分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/416-%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.cpp)]:

    先将问题转换成, 能否在 nums 里凑出nums数字总和 sum 的一半 target

    dfs记忆化, dfs有两种思路, 一种把选取过程完全看作01背包问题, 对于每个数都有选和不选两种情况, 另一种思路是每次选择只能在有限的集合中选一个下标作为开始, 每次选择的下标只能比上一次选择的下标更大, 具体看代码

    二维dp, dp[i][j]表示nums[0,i]能否凑出j

- [[437-路径总和III](https://leetcode.cn/problems/path-sum-iii/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/437-%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C%20III.cpp)]:

    在dfs基础上以每个节点为root进行dfs, 为了防止溢出使用long long

- [[448-找到所有数组中消失的数字](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/448-%E6%89%BE%E5%88%B0%E6%89%80%E6%9C%89%E6%95%B0%E7%BB%84%E4%B8%AD%E6%B6%88%E5%A4%B1%E7%9A%84%E6%95%B0%E5%AD%97.cpp)]:

    遍历数组, 用一个哈希表记录每个值的存在情况, 然后从[1,n]看每个值是否存于哈希表, 为了优化空间复杂度, 可以将nums数组用作哈希表, 为了在用做哈希表的过程中, 不影响取值, 可以使用`+n`、取模的方式来分别表示某数存在和还原该index的原值

- [[461-汉明距离](https://leetcode.cn/problems/hamming-distance/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/bit-manipulation/461-%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB.cpp)]:

    位运算, (x & (1 << i)) ^ (y & (1 << i))

- [[494-目标和](https://leetcode.cn/problems/target-sum/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/depth-first-search/494-%E7%9B%AE%E6%A0%87%E5%92%8C.cpp)]:

    dfs记忆化, 哈希表存储string和int, string 为pos和target的编码

- [[538-把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/538-%E6%8A%8A%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E8%BD%AC%E6%8D%A2%E4%B8%BA%E7%B4%AF%E5%8A%A0%E6%A0%91.cpp)]:
    
    优先右子树的中序遍历

- [[543-二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/543-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%9B%B4%E5%BE%84.cpp)]:

    多种思路: 
        1. DFS遍历每个节点, 计算过每个节点的最大直径, 用一个公共遍历ans保存最大直径, 即在求高的过程中算出该点的直径并与ans比较
        2. 递归求解子问题, 用tuple<过根的最大直径, 不过根的最大直径, 高>来返回子问题的解

- [[560-和为k的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/560-%E5%92%8C%E4%B8%BA%20K%20%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.cpp)]:

    前缀和, 即用一个哈希表存储nums[0,i)的和pre和pre的个数, 时间复杂度为O(n), 我们寻找以nums[i]结尾的, 和为target的子数组, 如果哈希表内存在pre = sum[i] - k, 则res += pre的个数

- [[581-最短无序连续子数组](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/array/581-%E6%9C%80%E7%9F%AD%E6%97%A0%E5%BA%8F%E8%BF%9E%E7%BB%AD%E5%AD%90%E6%95%B0%E7%BB%84.cpp)]:

    单调栈, 遇到小的值就pop, 记录下pop的最小的下标就是左边界, 单调栈里只需要记录元素的下标就可以了

- [[617-合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/tree/617-%E5%90%88%E5%B9%B6%E4%BA%8C%E5%8F%89%E6%A0%91.cpp)]:
 
    递归构造二叉树

- [[621-任务调度器](https://leetcode.cn/problems/task-scheduler/)|[解答]()]:

- [[647-回文子串](https://leetcode.cn/problems/palindromic-substrings/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/dynamic-programming/647-%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.cpp)]:

    区间dp
 
- [[739-每日温度](https://leetcode.cn/problems/daily-temperatures/)|[解答](https://github.com/Meow-2/LeetCode-Everyday/blob/main/stack/739-%E6%AF%8F%E6%97%A5%E6%B8%A9%E5%BA%A6.cpp)]:

    单调递减栈, 当遇到更高温时, 弹栈, 并计算天数
