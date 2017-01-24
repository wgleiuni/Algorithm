#include <iostream>
#include <limits.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<int> quicksort(vector<int>&);
        void mysolve(vector<int>&,int,int);
};

void Solution::mysolve(vector<int>& nums,int low,int high) {
    if (low>=high) return;
    int pivot=nums[(low+high)/2];
    int left=low,right=high;
    while (left<=right) {
        while (left<=high && nums[left]<pivot) left++;
        while (right>=low && nums[right]>pivot) right--;

        if (left<=right) {
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    if (low<left-1) mysolve(nums,low,left-1);
    if (high>left) mysolve(nums,left,high);
    return;
}

vector<int> Solution::quicksort(vector<int>& nums) {
    if (nums.size()<2) return nums;
    mysolve(nums,0,nums.size()-1);
    return nums;
}

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums {1,2,9,5,3,5,652,213,243,4,5,6,32,9,3,1,321,4,4234,5};
    auto out=sol.quicksort(nums);
    for (int i=0;i<out.size();i++) {
        std::cout << out[i] << std::endl;
    }
    return 0;
}
