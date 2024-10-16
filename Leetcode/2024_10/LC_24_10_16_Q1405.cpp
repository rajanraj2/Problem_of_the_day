// Link - https://leetcode.com/problems/longest-happy-string/?envType=daily-question&envId=2024-10-16
// Longest Happy String


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        int n = a + b + c;
        char maxi, smaxi;
        for (int i = 0; i < n; i++) {
            if (c >= b & c >= a & c > 0) {
                maxi = 'c';
                if (b >= a & b > 0) smaxi = 'b';
                else if (a > 0) smaxi = 'a';
                else smaxi = '1';
            }
            else if (b >= a & b >= c & b > 0) {
                maxi = 'b';
                if (c >= a & c > 0) smaxi = 'c';
                else if (a > 0) smaxi = 'a';
                else smaxi = '1';
            }
            else if (a >= c & a >= b & a > 0) {
                maxi = 'a';
                if (b >= c & b > 0) smaxi = 'b'; 
                else if (c > 0) smaxi = 'c';
                else smaxi = '1';
            }
            else maxi = '0';
            
            int s = result.size();
            if (s >= 2) {
                if (result[s - 1] == result[s - 2] & result[s - 1] == maxi) maxi = smaxi;
            } 
            
            if (maxi == 'a' | maxi == 'b' | maxi == 'c') {
                result += maxi;
                if (maxi == 'c') c--;
                else if (maxi == 'b') b--;
                else if (maxi == 'a') a--;
            }
            else break;
        }

        return result;
    }
};


// 1. initialise empty string result
// 2. find max from a, b, c
// 3. add it to the result 
// 4. check if the previous 2 chars were same
//    4.1 then add the max from the other two chars
// 5. repeat from step 2 to 4 till possible 
// 6. return the string