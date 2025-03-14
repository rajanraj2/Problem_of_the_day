// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/?envType=daily-question&envId=2025-03-14
// 2226. Maximum Candies Allocated to K Children


class Solution {
    private:
        bool check(vector<int>& candies, long long mid, long long k) {
            long long count = 0;
            for (auto it : candies) {
                count += it / mid; 
                if (count >= k) return true;
            }
            return false;
        }
    
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            long long left = 1, right = *max_element(candies.begin(), candies.end()), result = 0;
    
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                if (check(candies, mid, k)) {
                    result = mid;
                    left = mid + 1;
                }
                else right = mid - 1; 
            }
            return (int)result;
        }
    };