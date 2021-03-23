#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        sort(arr, 0, arr.size() - 1);
        return arr;
    }

private:
    int partition(vector<int>& arr, int start, int end) {
       int pivot = arr[start];
       int left = start;
       int right = end;
       while(left < right) {
           while(right > left && arr[right] >= pivot) {
               right--;
           }
           arr[left] = arr[right];
           while(right > left && arr[left] <= pivot) {
               left++;
           }
           arr[right] = arr[left];
       }
       arr[left] = pivot;
       return left;
    }
    void sort(vector<int>& arr, int start, int end) {
       if(start >= end) return;
       int index = partition(arr, start, end);
       sort(arr, start, index - 1);
       sort(arr, index + 1, end);
    }
};

int main(int, char**) {
    
    std::cout << "Hello, world!\n";
    return 0;
}
