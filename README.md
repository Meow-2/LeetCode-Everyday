LeetCode每日一题个人刷题记录,C++解题,始于2021.11.19

刷题过程中总结的一句话trick:

- 859-亲密字符串:set里的元素是唯一的，可以用于字符串快速去重，set<char>(s.begin(),s.end())，通过比较去重后的size()还可以得到字符串是否有重复字符

- 423-从英文中重建数字:unordered_map<char,int>哈希表可以用一个int数组代替，前提数组的范围要能容纳下字符的ASCII码;unordered_map<int,int>也是，但前提是int数组的范围要能容纳下第一个int的范围

- 594-最长和谐子序列:unordered_map<int,int>可以用于快速查找序列中已遍历过的数，和该数在序列中已出现的次数，查找的时间复杂度为O(1)

刷题过程中的常用api:
