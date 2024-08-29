// Link - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/?envType=daily-question&envId=2024-08-29
// Most stones removed with same row or column


class Solution {
private:
    int count = 0;

    int findRep(int el, vector<int>& setRep) {
        if (setRep[el] ==  0) {
            setRep[el] = el;
            count++;
        }
        return setRep[el] == el ? el : (setRep[el] = findRep(setRep[el], setRep));
    }

    void merge(int a, int b, vector<int>& setRep) {
        int repA = findRep(a, setRep);
        int repB = findRep(b, setRep);
        if (repA != repB) {
            setRep[repB] = repA;
            count--;
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> setRep(20003, 0);
        for (const auto& it : stones) {
            merge(it[0] + 1, it[1] + 10002, setRep);
        }
        return stones.size() - count;
    }
};