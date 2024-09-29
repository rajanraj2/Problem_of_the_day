// Link - https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29
// All O`one Data Structure


class AllOne {
public:
    unordered_map<string, int> freq;
    set<pair<int,string>> st;
    AllOne() {
        // nothing to do here
    }
    
    void inc(string key) {
        st.erase({freq[key],key});
        freq[key]++;

        st.insert({freq[key], key});
    }
    
    void dec(string key) {
        st.erase({freq[key],key});
        freq[key]--;

        if(freq[key] > 0){
            st.insert({freq[key], key});
        }
    }
    
    string getMaxKey() {
        if(st.size()==0){return "";}
        string ans = prev(st.end())->second;
        return ans;
    }
    
    string getMinKey() {
        if(st.size()==0){return "";}
        string ans = st.begin()->second;
        return ans;
    }
};