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
#include <list>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
    public:
        vector<int> TopologicalSort(int,vector<pair<int,int>>&);
};

vector<int> Solution::TopologicalSort(int n,vector<pair<int,int>>& rqst) {
    vector<int> out;
    if (n==0) return out;
    if (n==1) return vector<int> {0};
    unordered_set<int> fnode;
    for (int i=0;i<n;i++) fnode.emplace(i);
    unordered_map<int,unordered_set<int>> rec1,rec2;
    for (auto i:rqst) {
        if (fnode.count(i.first)) fnode.erase(i.first);
        rec1[i.first].emplace(i.second);
        rec2[i.second].emplace(i.first);
    }
    while (!fnode.empty()) {
        unordered_set<int> next;
        for (auto i:fnode) {
            if (rec2.count(i)) {
                for (auto j:rec2[i]) {
                    if (rec1[j].size()==1) {
                        next.emplace(j);
                        rec1.erase(j);
                    }
                    else rec1[j].erase(i);
                }
                rec2.erase(i);
            }
            out.push_back(i);
        }
        fnode=next;
    }
    if (out.size()<n) return vector<int> {};
    return out;
}

int main(int argc, char *argv[])
{
    Solution obj;
    int n=4;
    vector<pair<int,int>> rqst {{1,0},{2,0},{3,1},{3,2}};
    auto out=obj.TopologicalSort(n,rqst);
    for (auto i:out) cout << i << " ";
    cout << endl;
    return 0;
}
