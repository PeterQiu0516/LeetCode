/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary
{
public:
    // iterating against all members is too slow, we sort them by size
    // vector<string> dict;
    unordered_map<int, vector<string>> dict;
    /** Initialize your data structure here. */
    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        dict[word.size()].push_back(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        for (string str : dict[word.size()])
        {
            bool check = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] == '.')
                    continue;
                if (word[i] != str[i])
                {
                    check = false;
                    break;
                }
            }
            if (check)
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
