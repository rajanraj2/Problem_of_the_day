// Link - https://leetcode.com/problems/number-of-atoms/?envType=daily-question&envId=2024-07-14
// Number of Atoms


class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCount;
        stack<map<string, int>> stack;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stack.push(atomCount);
                atomCount.clear();
                i++;
            }
            else if (formula[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier;
                if (start == i) {
                    multiplier = 1;
                }
                else {
                    multiplier = stoi(formula.substr(start, i - start));
                }

                if (!stack.empty()) {
                    auto topMap = stack.top();
                    stack.pop();
                    for (const auto& pair : atomCount) {
                        topMap[pair.first] += pair.second * multiplier;
                    }
                    atomCount = topMap;
                }
            }
            else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string element = formula.substr(start, i - start);

                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count;
                if (start == i) {
                    count = 1;
                }
                else {
                    count = stoi(formula.substr(start, i - start));
                }
                atomCount[element] += count;
            }
        }

        string result;
        for (const auto& pair : atomCount) {
            result += pair.first;
            if (pair.second > 1) result += to_string(pair.second);
        }

        return result;
    }
};