// https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07
// 2523. Closest Prime Numbers in Range


class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<bool> sieve(right + 1, true);
            sieve[0] = sieve[1] = false;
            
            for (int i = 2; i * i <= right; ++i) {
                if (sieve[i]) {
                    for (int j = i * i; j <= right; j += i) {
                        sieve[j] = false;
                    }
                }
            }
            
            vector<int> primes;
            for (int i = left; i <= right; ++i) {
                if (sieve[i]) {
                    primes.push_back(i);
                }
            }
            
            if (primes.size() < 2) {
                return {-1, -1};
            }
            
            int min_gap = INT_MAX;
            vector<int> result = {-1, -1};
            
            for (int i = 1; i < primes.size(); ++i) {
                int gap = primes[i] - primes[i - 1];
                if (gap < min_gap) {
                    min_gap = gap;
                    result = {primes[i - 1], primes[i]};
                }
            }
            
            return result;
        }
    };