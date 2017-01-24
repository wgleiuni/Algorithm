#include <iostream>
#include <limits.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<int> mergesort(vector<int>&);
        void subsort(vector<int>&,int,int);
        void merge(vector<int>&,int,int,int);
    private:
        vector<int> rec;
};

void Solution::merge(vector<int>& nums,int low,int mid,int high) {
    for (int i=low;i<=high;i++) {
        rec[i]=nums[i];
    }
    int p1=low,p2=mid,cur=low;
    for (;p1<mid && p2<=high;) {
        if (rec[p1]<=rec[p2]) {
            nums[cur]=rec[p1];
            p1++;
        }
        else {
            nums[cur]=rec[p2];
            p2++;
        }
        cur++;
    }
    for (int i=0;i<mid-p1;i++) {
        nums[cur+i]=rec[p1+i];
    }
    return;
}

void Solution::subsort(vector<int>& nums,int low,int high) {
    if (low>=high) return;
    subsort(nums,low,(low+high)/2);
    subsort(nums,(low+high)/2+1,high);
    merge(nums,low,(low+high)/2+1,high);
    return;
}

vector<int> Solution::mergesort(vector<int>& nums) {
    if (nums.size()<2) return nums;
    rec=vector<int> (nums.size(),0);
    subsort(nums,0,nums.size()-1);
    return nums;
}

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums {1,2,4,5,6,32,9,3,1,321,4,4234,5};
    auto out=sol.mergesort(nums);
    for (int i=0;i<out.size();i++) {
        std::cout << out[i] << std::endl;
    }
    return 0;
}
