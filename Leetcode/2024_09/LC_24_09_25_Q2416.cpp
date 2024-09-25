// Link - https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/?envType=daily-question&envId=2024-09-25
// Sum of Prefix Scores of Strings


class TrieNode {
public:
    int count;
    TrieNode* children[26];

    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert the word into the Trie and update the count for each prefix
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->count++; // Count the occurrence of this prefix
        }
    }

    // Get the sum of prefix scores for the given word
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                break; // This prefix does not exist
            }
            node = node->children[idx];
            score += node->count;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> result(n, 0);
        Trie trie;

        // Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }

        // Calculate the prefix scores for each word
        for (int i = 0; i < n; i++) {
            result[i] = trie.getPrefixScore(words[i]);
        }

        return result;
    }
};



// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
//         int n = words.size();
//         vector<int> result(n, 0);
//         unordered_map<string, int> mpp;

//         for (int i = 0; i < n; i++) {
//             string check = ""; 
//             for (char ch : words[i]) {  
//                 check += ch;
//                 mpp[check]++;
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             string check = ""; 
//             for (char ch : words[i]) {
//                 check += ch;
//                 result[i] += mpp[check];
//             }
//         }

//         return result;
//     }
// };