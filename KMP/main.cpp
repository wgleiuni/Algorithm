#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        vector<int> KMP (string&,string&);
};

vector<int> Solution::KMP (string& s1,string& s2) {
    vector<int> out;
    if (s2.empty() || s1.size()<s2.size()) return out;
    vector<int> b (s2.size()+1,-1);
    int j=-1;
    for (int i=0;i<s2.size();i++) {
        while (j>=0 && s2[i]!=s2[j]) j=b[j];
        b[i+1]=++j;
    }
    j=0;
    for (int i=0;i<s1.size();i++) {
        while (j>=0 && s1[i]!=s2[j]) j=b[j];
        j++;
        if (j==s2.size()) {
            out.push_back(i+1-j);
            j=b[j];
        }
    }
    return out;
}

int main(int argc, char *argv[])
{
    Solution sol;
    string s1="abcabcabcabcabcabcjabcaabcabcabcabcabhcabcabcab";
    string s2="abcabcabc";
    auto out=sol.KMP(s1,s2);
    for (int i=0;i<out.size();i++) {
        std::cout << out[i] << std::endl;
    }
    return 0;
}
