#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
class Solution {
    public:
        std::vector<int> countBits(int);
};

std::vector<int> Solution::countBits(int num) {
    return out;
}

int main(int argc, char *argv[])
{
    Solution sol;
    int num=10;
    std::string test="wefe";
    auto out=sol.countBits(num);
    for (int i=0;i<out.size();i++) {
        std::cout << out[i] << std::endl;
    }
    return 0;
}
