// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/submissions/1458445714/?envType=daily-question&envId=2024-11-20
// Take k of each character from left and right


class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int n = s.size();
        int arr[3] = {0};
        for (char ch : s) arr[ch - 'a']++;
        if (any_of(arr, arr + 3, [k](int f){ return f < k;})) return -1;
        int result = n;

        for (int l = 0, r = 0; r < n; r++) {
            int x = s[r] - 'a';
            arr[x]--;
            while (l <= r && any_of(arr, arr + 3, [k](int f){ return f < k;})) {
                arr[s[l] - 'a']++;
                l++;
            }
            result = min(result, n - (r - l + 1));
        }
        return result;
    }
};