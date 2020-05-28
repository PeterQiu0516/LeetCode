/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        // const int maxn = 2e6;
        // int isPrime[maxn + 1];
        // int tot_primes = 0;
        // int Primes[maxn + 1];
        // for (int i = 2; i < maxn + 1; i++)
        //     isPrime[i] = 1;

        // for (int i = 2; i <= maxn; i++)
        // {
        //     //cout << i << endl;
        //     //cout << i << "prime? :" << isPrime[i] << endl;

        //     if (isPrime[i])
        //         Primes[tot_primes++] = i;
        //     for (int j = 0; j < tot_primes; j++)
        //     {
        //         if (i * Primes[j] >= maxn)
        //             break;
        //         isPrime[i * Primes[j]] = 0;
        //         if (i % Primes[j] == 0)
        //             break;
        //     }
        // }

        // int ans = 0;
        // for (int i = 0; i < n; i++)
        //     ans += isPrime[i];
        // return ans;

        vector<bool> isPrime(n + 1, true);
        vector<int> Primes;

        int tot_primes = 0;
        // create a table
        // const int n = ~(1 << 31) - 1;
        // const int n = 1e5;
        // int isPrime[n + 1];
        // int Primes[n + 1];
        // for (int i = 2; i < n + 1; i++)
        //     isPrime[i] = 1;

        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
                Primes.push_back(i);
            for (int j = 0; j < Primes.size(); j++)
            {
                if (i * Primes[j] > n)
                    break;
                isPrime[i * Primes[j]] = 0;
                if (i % Primes[j] == 0)
                    break;
            }
        }
        return Primes.size();
    }
};
// @lc code=end
