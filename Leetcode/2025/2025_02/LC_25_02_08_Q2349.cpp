// https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08
// 2349. Design a Number Container System


class NumberContainers {
public:
    unordered_map<int, int> indToNum;
    unordered_map<int, set<int>> numToInd;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indToNum.count(index)) {
            int old = indToNum[index];
            numToInd[old].erase(index);
            if (numToInd[old].empty()) numToInd.erase(old);
        }
        indToNum[index] = number;
        numToInd[number].insert(index);
    }
    
    int find(int number) {
        if (numToInd.count(number) && !numToInd[number].empty()) {
            return *numToInd[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */