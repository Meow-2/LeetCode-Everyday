/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <array>
#include <memory>
#include <string>
using namespace std;
// @lc code=start
struct TrieNode
{
    bool                            isWordEnd{false};
    array<unique_ptr<TrieNode>, 26> child;
    TrieNode(bool isWordEnd_ = false) : isWordEnd(isWordEnd_) {}
};
class Trie
{
public:
    unique_ptr<TrieNode> root;
    Trie() : root(make_unique<TrieNode>()) {}

    void insert(string const& word)
    {
        auto ptr = root.get();
        for (auto ch : word) {
            if (!ptr->child[ch - 'a'])
                ptr->child[ch - 'a'] = make_unique<TrieNode>();
            ptr = ptr->child[ch - 'a'].get();
        }
        ptr->isWordEnd = true;
    }

    bool search(string const& word)
    {
        auto ptr = root.get();
        for (auto ch : word) {
            if (!ptr->child[ch - 'a'])
                return false;
            ptr = ptr->child[ch - 'a'].get();
        }
        return ptr->isWordEnd ? true : false;
    }

    bool startsWith(string const& prefix)
    {
        auto ptr = root.get();
        for (auto ch : prefix) {
            if (!ptr->child[ch - 'a'])
                return false;
            ptr = ptr->child[ch - 'a'].get();
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
