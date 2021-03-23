#include<iostream>
#include<vector>
using std::vector;

class Solution {
private: 
    //最大的在root， 大根
    void sink(vector<int>& v, int targetIndex) {
        while(targetIndex * 2 <= v.size() - 1) {
            int childNode = targetIndex * 2;
            if(childNode + 1 <= v.size() - 1) 
                if(v[childNode + 1] > v[childNode])
                    childNode = childNode + 1;
            if(v[targetIndex] < v[childNode]) {
                std::swap(v[targetIndex], v[childNode]);
                targetIndex = childNode;
            } else {
                break;
            }
        }
    }
    // 最大的在root
    void swim(vector<int>& v, int targetIndex) {
        while(targetIndex / 2 >= 1) {
            int parentIndex = targetIndex / 2;
            if(v[targetIndex] > v[parentIndex]){
                std::swap(v[targetIndex], v[parentIndex]);
                targetIndex = parentIndex;
            } else {
                break;
            }
        }
    }
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size()) return {};
        vector<int> result;
        result.push_back(-1);  // index 0 不会用到
        for(int i = 0; i < input.size(); i++) {
            if(i < k) {
                result.push_back(input[i]);
                swim(result, i + 1);
            } else {
                if(input[i] < result[1]) {
                    result[1] = input[i];
                    sink(result, 1);
                }
            }
        }
        result.erase(result.begin());
        return result;
    }
};


int main(){
    Solution s;
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(7);
    v.push_back(3);
    v.push_back(8);
    vector<int> result = s.GetLeastNumbers_Solution(v, 4);
    for(auto& value : result) {
        std::cout << value << std::endl;
    }

    return 0;
}