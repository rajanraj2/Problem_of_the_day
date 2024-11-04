// Link - https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04
// String Compression III


class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1, n = word.size();
        char ch = word[0];
        for(int i=1;i<n;i++){
            if(word[i] == ch && cnt < 9)cnt++;
            else{
                comp.push_back(cnt+'0');
                comp.push_back(ch);
                ch = word[i];
                cnt = 1;
            }
        }
        comp.push_back(cnt+'0');
        comp.push_back(ch);
        return comp;
    }
};




// class Solution {
// public:
//     string compressedString(string word) {
//         // int i = 0;
//         string result = "";
//         int count = 1;
//         for (int i = 1; i < word.size(); i++) {
//             if (count == 9) {
//                 result += "9";
//                 result += word[i - 1];
//                 count = 1;

//             }
//             if (word[i] == word[i - 1]) {
//                 count++;
//             }
//             else {
//                 if (i == word.size() - 1) {
//                     result += "1";
//                     result += word[i]; mn    
//                 }
//                 result += to_string(count);
//                 result += word[i - 1];
//                 count = 1;
//             }
//         }
//         return result;
//     }
// };