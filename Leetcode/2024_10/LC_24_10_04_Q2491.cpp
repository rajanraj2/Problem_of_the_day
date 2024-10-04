// Link - https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/?envType=daily-question&envId=2024-10-04
// Divide Players into Teams of Equal Skill


class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int l = 0, r = n - 1;
        if (n < 2) return -1;
        long long result = skill[l] * skill[r];
        long long sum = skill[l++] + skill[r--];
        while (l < r) {
            if (skill[l] + skill[r] != sum) return -1;
            else {
                result += skill[l++] * skill[r--];
            }
        }
        return result;
    }
};