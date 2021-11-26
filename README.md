LeetCode每日一题个人刷题记录,C++解题,始于2021.11.19

刷题过程中总结的一句话trick:

- [859-亲密字符串](https://github.com/Meow-2/LeetCode-Everyday/blob/main/design/859-亲密字符串.cpp):`set`里的元素是唯一的，可以用于字符串快速去重，`set<char>(s.begin(),s.end())`，通过比较去重后的size()还可以得到字符串是否有重复字符

- [423-从英文中重建数字](https://github.com/Meow-2/LeetCode-Everyday/blob/main/math/423-%E4%BB%8E%E8%8B%B1%E6%96%87%E4%B8%AD%E9%87%8D%E5%BB%BA%E6%95%B0%E5%AD%97.cpp):`unordered_map<char,int>`哈希表可以用一个int数组代替，前提数组的范围要能容纳下字符的ASCII码;`unordered_map<int,int>`也是，但前提是int数组的范围要能容纳下第一个int的范围

- [594-最长和谐子序列](https://github.com/Meow-2/LeetCode-Everyday/blob/main/hash-table/594-%E6%9C%80%E9%95%BF%E5%92%8C%E8%B0%90%E5%AD%90%E5%BA%8F%E5%88%97.cpp):`unordered_map<int,int>`可以用于快速查找序列中已遍历过的数，和该数在序列中已出现的次数，查找的时间复杂度为O(1)

- [700-二叉搜索树中的搜索](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/700-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%90%9C%E7%B4%A2.cpp):对于并列关系的if语句，如果判断的条件单一，执行的语句形式也相似，可以尝试使用三元式替换:
    `search(root->val<val?root->right:root->left,val)`

- [559-N 叉树的最大深度](https://github.com/Meow-2/LeetCode-Everyday/blob/main/Unknown/559-N%20%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E6%B7%B1%E5%BA%A6.cpp):选取一个for循环中最大的数，使用`maxdepth = max(maxdepth,1 + maxDepth(child))`来替换掉`if(depth > maxdepth)`

刷题过程中的常用api:
