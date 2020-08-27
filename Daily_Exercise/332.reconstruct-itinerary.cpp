/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution
{
    int total;
    unordered_map<string, vector<string>> airline;
    // Method 2: construct a hash map for fast insert/delete at certain pos.
    // unordered_map<string,unordered_map<int,string>> airline_new;
    vector<string> ans;

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // construct the map
        total = tickets.size();
        for (int i = 0; i < total; i++)
        {
            if (airline.find(tickets[i][0]) == airline.end())
                airline[tickets[i][0]] = vector(1, tickets[i][1]);
            else
                airline[tickets[i][0]].push_back(tickets[i][1]);
        }
        for (auto it = airline.begin(); it != airline.end(); it++)
        {
            sort(it->second.begin(), it->second.end(), [](string a, string b) { return a > b; }); // pop_back use constant time, so we reverse the order
        }

        // Method 2: construct a hash map for fast insert/delete at certain pos.
        // for (auto it = airline.begin(); it != airline.end(); it++)
        // {
        //     for (int i = 0; i < it->second.size(); i++)
        //     {
        //         airline_new[it->first][i] = it->second[i];
        //     }
        // }

        ans.push_back("JFK");
        dfs("JFK");
        return ans;
    }

    bool dfs(string curr)
    {
        if (ans.size() == total)
        {
            ans.push_back(airline[curr][0]);
            return true;
        }
        if (airline.find(curr) == airline.end() || airline[curr].size() == 0)
            return false;
        for (int i = airline[curr].size() - 1; i >= 0; i--)
        {
            string next = airline[curr][i];
            ans.push_back(next);
            airline[curr].erase(airline[curr].begin() + i);
            if (dfs(next)) // end
                return true;
            airline[curr].insert(airline[curr].begin() + i, next); // backtrack invariant
            ans.pop_back();
        }
        return false; // for this iteration it failed
    }

    // Method 2: construct a hash map for fast insert/delete at certain pos.
    // bool dfs(string curr)
    // {
    //     if (ans.size() == total)
    //     {
    //         // unordered_map does not guarantee begin() to be the rest element
    //         for (int i = 0; i < airline[curr].size(); i++)
    //         {
    //             if(airline_new[curr].find(i) != airline_new[curr].end())
    //             {
    //                 ans.push_back(airline_new[curr][i]);
    //                 return true;
    //             }
    //         }

    //         // ans.push_back(airline_new[curr][pos]);
    //         // return true;
    //     }
    //     if (airline_new.find(curr) == airline_new.end() || airline_new[curr].size() == 0)
    //         return false;
    //     for (int i = airline[curr].size() - 1; i >= 0; i--)
    //     {
    //         // can not iterate through airline_new[curr].size(), because unordered_map is not sequential and not all elements are within size()
    //         // as a result, although such optimization reduce the time for insert / delete element at certain position, we need more time for iteration and the whole program get even higher time complexity
    //         if(airline_new[curr].find(i) == airline_new[curr].end())
    //             continue;
    //         string next = airline_new[curr][i];
    //         ans.push_back(next);
    //         airline_new[curr].erase(i);
    //         if (dfs(next)) // end
    //             return true;
    //         airline_new[curr][i] = next; // backtrack invariant
    //         ans.pop_back();
    //     }
    //     return false; // for this iteration it failed
    // }
};
// @lc code=end
