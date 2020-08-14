/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> set;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (set.find(key) == set.end())
            set[key] = 1;
    }
    
    void remove(int key) {
        auto it = set.find(key);
        if (it != set.end())
            set.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return (set.find(key) != set.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

