LeetCode每日一题个人刷题记录,C++解题,始于2021.11.19

刷题过程中总结的一句话trick:

- [859-亲密字符串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/design/859-亲密字符串.cpp):`set`里的元素是唯一的，可以用于字符串快速去重，`set<char>(s.begin(),s.end())`，通过比较去重后的size()还可以得到字符串是否有重复字符

- [423-从英文中重建数字](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/423-从英文中重建数字.cpp):`unordered_map<char,int>`哈希表可以用一个int数组代替，前提数组的范围要能容纳下字符的ASCII码(对于包含所有小写字母，大小为26的数组，可以用`int hashmap[c - 'a']`来寻址);`unordered_map<int,int>`也是，但前提是int数组的范围要能容纳下第一个int的范围

- [594-最长和谐子序列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/594-最长和谐子序列.cpp):`unordered_map<int,int>`可以用于快速查找序列中已遍历过的数，和该数在序列中已出现的次数，查找的时间复杂度为O(1)

- [700-二叉搜索树中的搜索](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/700-二叉搜索树中的搜索.cpp):对于并列关系的if语句，如果判断的条件单一，执行的语句形式也相似，可以尝试使用三元式替换:
    `search(root->val<val?root->right:root->left,val)`

- [559-N叉树的最大深度](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/559-N叉树的最大深度.cpp):选取一个for循环中最大的数，使用`maxdepth = max(maxdepth,1 + maxDepth(child))`来替换掉`if(depth > maxdepth)`

- [400-第N位数字](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/400-第N位数字.cpp):当需要累加特别大的数字时，要考虑int溢出的问题，对于将累加数和参照值比较的问题可以这样转换:用参照值减去各个阶段的累加数，将其差值与下一个阶段的累加值进行比较，从而确定多少次累加才能达到参照值，即参照值在那个累加区间内

- [786-第K个最小的素数分数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/786-第K个最小的素数分数.cpp):
对于几个有序序列的排序，可以使用多路归并的方式，每一路用最大（最小）堆取出最大（最小）值归并

刷题过程中的常用api:

- [458-可怜的小猪](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/458-可怜的小猪.cpp):Cpp标准库没有提供自定义底数的log函数，需要时可以这样代替`loga(b) = log2(b)/log2(a);`

- [594-最长和谐子序列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/594-最长和谐子序列.cpp):从小到大排序`#include <algorithm> std::sort(iterator &begin,iterator &end)`;

- [786-第K个最小的素数分数](https://github.com/Meow-2/LeetCode-Everyday/blob/main/binary-search/786-第K个最小的素数分数.cpp):
    - 优先队列`priority_queue<pair<double,pair<int,int>>>q`,`q.push(pair<double,pair<int,int>>)压入`,`q.pop()弹出`;
    - 自定义排序
    `vec<pair<int,int>> sort(vec.begin(), vec.end(), [&](const auto& x, const auto& y) {return x.first * y.second < x.second * y.first;});`
