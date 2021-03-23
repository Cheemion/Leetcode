#include<iostream>
#include<string>
#include<cstring>
using std::string;
class Solution {

private:
    int& get(int* dp, int i, int j, int width) {
        return dp[i * width + j];
    }

public:

    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        int str1Length = str1.size();
        int str2Length = str2.size();
        int* dp = new int[str1Length * str2Length];
        int maxIndex = 0;
        int maxLength = 0;
        std::memset(dp, 0, sizeof(int) * str1Length * str2Length);
        for(int i = 0; i < str1Length; i++) {
            for(int j = 0; j < str2Length; j++) {
                if(str1[i] == str2[j]) {
                    if(i == 0 || j == 0) {
                       get(dp, i, j, str2Length) = 1; 
                    } else {
                        get(dp, i, j, str2Length) = get(dp, i - 1, j - 1, str2Length) + 1;
                    }
                    if(get(dp, i, j, str2Length) > maxLength) {
                        maxLength = get(dp, i, j, str2Length);
                        maxIndex = i;
                    }
                }
            }
        }
        delete[] dp;
        std::string s = str1.substr(maxIndex - (maxLength - 1), maxLength);
        return s;
    }
};

int main(){
    Solution s;
    std::string s1 = "12322";
    std::string s2 = "2221331232233";
    std::string ss =  s.LCS(s1, s2);
    std::cout << ss << std::endl;
    return 0;
}