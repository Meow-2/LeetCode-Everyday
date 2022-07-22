/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;
// @lc code=start
class LRUCache;
ostream& operator<<(ostream& x, LRUCache const& y);
struct MyListNode
{
    unique_ptr<MyListNode> next;
    MyListNode*            pre{nullptr};
    int                    val{0};
    int                    key{0};
    MyListNode(int val_, int key_) : val(val_), key(key_) {}
    MyListNode(unique_ptr<MyListNode>&& next_, MyListNode* pre_, int val_, int key_)
        : next(std::move(next_)), pre(pre_), val(val_), key(key_)
    {}
};
class LRUCache
{
public:
    LRUCache(int capacity_) : capacity(capacity_)
    {
        // 两个dummyNode, 这样就不需要频繁地更改head和tail了
        head       = make_unique<MyListNode>(-1, -1);
        head->next = make_unique<MyListNode>(nullptr, head.get(), -1, -1);
        tail       = head->next.get();
    }

    int get(int key)
    {
        if (cache.count(key)) {
            moveToHead(key);
            return cache[key]->val;
        }
        // cout << *this;
        return -1;
    }
    void put(int key, int value)
    {
        if (!cache.count(key)) {
            addNodeToHead(key, value);
            // cout << *this;
            return;
        }
        moveToHead(key);
        cache[key]->val = value;
        // cout << *this;
    }
    void removeLRUNode()
    {
        cache.erase(tail->pre->key);
        auto tailPrePre  = tail->pre->pre;
        tailPrePre->next = std::move(tail->pre->next);
        tail->pre        = tailPrePre;
    }
    void addNodeToHead(int key, int value)
    {
        // 最近访问的Key加入到链表头(dummyNode之后)
        head->next = make_unique<MyListNode>(std::move(head->next), head.get(), value, key);
        head->next->next->pre = head->next.get();
        // 加入哈希表
        cache[key] = head->next.get();
        if (++count > capacity)
            removeLRUNode();
    }
    void moveToHead(int key)
    {
        auto curPtr = cache[key];
        // 最近访问的Key移动到链表头(dummyNode之后)
        auto prePtr        = curPtr->pre;
        auto tempPtr       = std::move(prePtr->next);
        prePtr->next       = std::move(tempPtr->next);
        prePtr->next->pre  = prePtr;
        tempPtr->next      = std::move(head->next);
        tempPtr->next->pre = curPtr;
        head->next         = std::move(tempPtr);
        head->next->pre    = head.get();
    }
    auto getHead() const { return head.get(); }
    auto getTail() const { return tail; }

private:
    unordered_map<int, MyListNode*> cache;
    unique_ptr<MyListNode>          head;
    MyListNode*                     tail;
    int                             capacity{0};
    int                             count{0};
};

ostream& operator<<(ostream& x, LRUCache const& y)
{
    auto head = y.getHead();
    head      = head->next.get();
    auto tail = y.getTail();
    x << '{';
    while (head != tail) {
        x << "[key: " << head->key << " value: " << head->val << "] ";
        head = head->next.get();
    }
    x << "}\n";
    return x;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
