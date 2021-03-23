#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型-
     */
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int middle = 0;
        while(start <= end) {
            middle = start + (end - start) / 2;
            if(nums[middle] == target) {
                while((middle - 1) >= 0 && nums[middle - 1] == target) {
                    middle = middle - 1;
                }
                return middle;
            } else if(nums[middle] > target) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        } 
        return -1;
    }
};



int main(){
    Solution s;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(5);
    std::cout << s.search(vec, 4) << std::endl;
    return 0;
}