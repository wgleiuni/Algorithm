#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
    public:
        std::vector<int> countBits(int);
};

std::vector<int> Solution::countBits(int num) {
    vector<int> out;
    return out;
}

void func() {
    static int x=0;
    cout << x << endl;
    x=x+1;
}

int main(int argc, char *argv[])
{
    Solution sol;
    int num=10;
    auto out=sol.countBits(num);
    for (int i=0;i<out.size();i++) {
        std::cout << out[i] << std::endl;
    }
    func();
    func();
    func();
    return 0;
}
