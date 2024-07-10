// Link - https://leetcode.com/problems/crawler-log-folder/?envType=daily-question&envId=2024-07-10
// Crawler Log Folder


class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                step = max(0, step - 1);
            }
            else if (logs[i] != "./") {
                step++;
            }
        }
        return step;
    }
};