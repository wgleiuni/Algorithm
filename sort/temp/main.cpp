#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        vector<int> QuickSort(vector<int>&);
        void subSort(vector<int>&,int,int);
};

void Solution::subSort(vector<int>& nums,int low,int high) {
    if (low>=high) return;
    int priot=nums[low+(high-low)/2];
    int left=low,right=high;
    while (left<=right) {
        while (left<=high && nums[left]<priot) left++;
        while (low<=right && nums[right]>priot) right--;
        if (left<=right) {
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    if (left-1>low) subSort(nums,low,left-1);
    if (left<high) subSort(nums,left,high);
    return;
}

vector<int> Solution::QuickSort(vector<int>& nums) {
    if (nums.size()<2) return nums;
    subSort(nums,0,nums.size()-1);
    return nums;
}


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums {9,8,7,65,5,43,543,5,34,5,45,4,543,5,4,35,5,45,45,43,654,6,56,5,4,3,2,1};
    auto out=sol.QuickSort(nums);
    for (int i=0;i<out.size();i++) {
        std::cout << out[i] << std::endl;
    }
    return 0;
}
