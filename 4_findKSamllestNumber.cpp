#include<iostream>
#include<vector>
#include<queue>
using std::vector;

class Solution {
private:
    void quickSort(vector<int>& input,int left, int right, int targetIndex) {
       int index = partition(input, left, right);
       if(index == targetIndex) {
           return;
       } else if(index > targetIndex) {
          quickSort(input, left, index - 1, targetIndex); 
       } else {
           quickSort(input, index + 1, right, targetIndex);
       }
    }
    int partition(vector<int>& input, int left, int right) {
        int pivot = input[left];
        while(left < right) {
            while(input[right] > pivot && left < right) {
                right--;
            }
            input[left] = input[right];
            while(input[left] < pivot && left < right) {
                left++;
            }
            input[right] = input[left];
        }
        input[left] = pivot;
        return left;
    }
public:
    vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
        vector<int> result;
        if(input.size() < k)
            return result;
        quickSort(input, 0, input.size() - 1, k - 1);
        for(int i = 0; i < k; i++)
            result.push_back(input[i]);
        return result;
    }

    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
        vector<int> result;
        if(input.size() < k)
            return result;
        std::priority_queue<int> pq;
        for(const auto& i : input) {
            if(pq.size() < k) {
                pq.push(i);
            } else {
                if(pq.top() > i) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }

    
};


int main(){
    Solution s;
    vector<int> input;
    input.push_back(4);
    input.push_back(5);
    input.push_back(1);
    input.push_back(6);
    input.push_back(2);
    input.push_back(7);
    input.push_back(3);
    input.push_back(8);
    auto result = s.GetLeastNumbers_Solution(input, 4);
    for(auto& i : result) {
        std::cout << i << std::endl;
    }
    return 0;
}