#include<iostream>
#include<vector>
using std::vector;

class Solution {
private:
    int partition(vector<int>& a, int left, int right) {
        int pivot = a[left];
        while(left < right) {
            while(left < right && a[right] <= pivot) {
                right--;
            }
            a[left] = a[right];
            while(left < right && a[left] >= pivot) {
                left++;
            }
            a[right] = a[left];
        }
        a[left] = pivot;
        return left;
    }
    int quickSort(vector<int>& a, int left, int right, int targetIndex) {
        int index = partition(a, left, right);
        if(index == targetIndex) {
            return index;
        } else if(index > targetIndex) {
            return quickSort(a, left, index - 1, targetIndex);
        } else {
            return quickSort(a, index + 1, right , targetIndex);
        } 
    }
public:
    int findKth(vector<int> a, int n, int K) {
        return a[quickSort(a, 0, a.size() - 1, K - 1)];
    }
};


int main(){
    return 0; 
}