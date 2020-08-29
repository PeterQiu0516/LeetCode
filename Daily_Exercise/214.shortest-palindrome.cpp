/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
// manacher algorithm
// class Manacher {
//     public:
//     Manacher(const std::string &s) {
//         construct(s);
//     };

// 	void getLongestPalindromeString(int &position, int &length) {
// 		// 找到最长的回文子串的位置与长度。
//         position = -1, length = -1;
//         for(int i = 0; i < len.size(); i++) {
//             if(len[i] > length) {
//                 length = len[i];
//                 position = i;
//             }
//         }
//         // 映射到原始字符串中的位置。
//         position = position/2 - length/4;
//         length = length/2;
//         return;
//     }

//     // s[L:R] 是否是回文的
//     bool isPalindrome(int L, int R) {
//         L = L*2 + 1;
//         R = R*2 + 1;
//         int mid = (L+R)/2;
//         if(0 <= mid && mid < len.size() && R-L+1 <= len[mid]) {
//             return true;
//         }
//         return false;
//     }

//     private:
//     vector<int> len;

//     void construct(const std::string &s) {
//         vector<char> vec;
//         // 用 0 作为分隔符
//         vec.resize(s.size()*2+1);
//         for(int i = 0; i < s.size(); i++) {
//             vec[i<<1|1] = s[i];
//         }

//         int L = 0, R = -1;
//         len.resize(vec.size());

//         for(int i = 0, n = vec.size(); i < n; i++) {
//             if(i <= R) { // 被覆盖了，尝试加速
//                 len[i] = min((R-i)*2+1, len[L+R-i]);
//             } else { // 未被覆盖，那就没办法加速了，从 1 开始。
//                 len[i] = 1;
//             }
//             // 尝试继续探测
//             int l = i - len[i]/2 - 1;
//             int r = i + len[i]/2 + 1;
//             while(0 <= l && r < vec.size() && vec[l] == vec[r]) {
//                 --l;
//                 ++r;
//             }
//             // 更新
//             len[i] = r-l-1;
//             if(r > R) {
//                 L = l+1;
//                 R = r-1;
//             }
//         }
//     }
// };

// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         if(s.size() <= 0) {
//             return s;
//         }
//         Manacher manacher(s);
//         for(int i = s.size()-1; i >= 0; i--) {
//             if(manacher.isPalindrome(0, i)) {
//                 auto str = s.substr(i+1);
//                 reverse(str.begin(), str.end());
//                 return str + s;
//             }
//         }
//         // will not happen
//         return "";
//     }
// };

// kmp
class Solution
{
public:
    int commpute_next(string pattern)
    {
        vector<int> next(pattern.size() + 1, 0);
        next[0] = -1;
        next[1] = 0;
        int i = 2; // i: index for next
        int j = 0; // j: index for pattern
        while (i < next.size())
        {
            if (pattern[i - 1] == pattern[j])
            {
                next[i] = j + 1;
                j = next[i];
                ++i;
            }
            else if (j == 0)
            {
                next[i] = 0;
                ++i;
            }
            else // move searcher in pattern
            {
                j = next[j];
            }
        }
        return next[next.size() - 1];
    }

    string shortestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }
        string reverse;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            reverse += s[i];
        }

        string pattern = s + '#' + reverse;
        int max_len = commpute_next(pattern); // max_len Palindrome in s

        return reverse.substr(0, reverse.size() - max_len) + s;
    }
};

// O(n^2), reverse
// class Solution
// {
// public:
//     string shortestPalindrome(string s)
//     {
//         if (s.empty())
//         {
//             return "";
//         }
//         string reverse;
//         for (int i = s.size() - 1; i >= 0; --i)
//         {
//             reverse += s[i];
//         }

//         if (s == reverse)
//             return s;
//         int len = s.size() - 1; // abade - edaba aba = aba; abad != daba
//         while (len >= 1)        // will always end for the first element
//         {
//             if (s.substr(0, len) == reverse.substr(s.size() - len))
//                 return reverse.substr(0, s.size() - len) + s;
//             len--;
//         }
//         // will not happen
//         return "";
//     }
// };

// @lc code=end
