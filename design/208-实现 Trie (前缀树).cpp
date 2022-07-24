/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
struct TrieNode
{
    unordered_map<char, unique_ptr<TrieNode>> child;
};
class Trie
{
public:
    unordered_set<string> isExistString;
    unique_ptr<TrieNode>  root;
    Trie() : root(make_unique<TrieNode>()) {}

    void insert(string const& word)
    {
        // c++中一个引用指向的地址不会改变，改变的是指向地址的内容，然而java中引用指向的地址在变
        // 老老实实用指针迭代而不要用引用迭代;
        if (isExistString.count(word))
            return;
        isExistString.insert(word);
        auto ptr = root.get();
        for (auto ch : word) {
            if (!ptr->child.count(ch))
                ptr->child[ch] = make_unique<TrieNode>();
            ptr = ptr->child[ch].get();
        }
    }

    bool search(string const& word) { return isExistString.count(word); }

    bool startsWith(string const& prefix)
    {

        auto ptr = root.get();
        for (auto ch : prefix) {
            if (!ptr->child.count(ch))
                return false;
            ptr = ptr->child[ch].get();
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
