#include<iostream>
#include<vector>
#include<unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    /**
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        if(arr.size() < 2)
            return arr.size();
        int i = 0;
        int j = 0;
        int res = 0;
        std::unordered_set<int> set;
        while(j < arr.size()) {
            if(set.find(arr[j]) != set.end()) { // include
                set.erase(arr[i]);
                i++;
            } else {
                set.insert(arr[j]);
                j++;
            }
            res = std::max(res, j - i);
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> ints = {1, 2, 3, 4, 1, 2, 2};
    std::cout << s.maxLength(ints) << std::endl;
    return 0;
}