#include <iostream>
#include <limits.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool isMatch(string,string);
};

bool Solution::isMatch(string s,string p) {
    vector<vector<bool>> dp (s.size()+1,vector<bool> (p.size()+1,false));
    dp[0][0]=true;
    for (int i=0;i<dp.size();i++) {
        for (int j=1;j<dp[0].size();j++) {
            if (p[j-1]!='.' && p[j-1]!='*') {
                if (i>0 && s[i-1]==p[j-1]) dp[i][j]=dp[i-1][j-1];
            }
            else if (p[j-1]=='.') {
                if (i>0) dp[i][j]=dp[i-1][j-1];
            }
            else {
                if (j>1 && dp[i][j-2]) dp[i][j]=true;
                else if (j>0 && dp[i][j-1]) dp[i][j]=true;
                else if (i>0 && dp[i-1][j] && j>1 && (p[j-2]=='.' || s[i-1]==p[j-2])) dp[i][j]=true;
            }
        }
    }
    return dp.back().back();
}

int main(int argc, char *argv[])
{
    Solution sol;
    std::string s="aab";
    std::string p="c*a*b";
    auto out=sol.isMatch(s,p);
    std::cout << out << std::endl;
    return 0;
}
