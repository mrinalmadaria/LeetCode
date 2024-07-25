#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftArray(n1);
        vector<int> rightArray(n2);
        
        for (int i = 0; i < n1; ++i)
            leftArray[i] = nums[left + i];
        for (int i = 0; i < n2; ++i)
            rightArray[i] = nums[mid + 1 + i];
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                nums[k++] = leftArray[i++];
            } else {
                nums[k++] = rightArray[j++];
            }
        }
        
        while (i < n1) {
            nums[k++] = leftArray[i++];
        }
        
        while (j < n2) {
            nums[k++] = rightArray[j++];
        }
    }
};
