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
class Node {
    public:
        int val;
        bool mark;
        vector<Node*> children;
        Node(int x) : val(x), mark(false), children(vector<Node*> ()) {}
        void add(Node* child) {children.push_back(child);};
};

class Solution {
    public:
        vector<int> TopologicalSort(int,vector<pair<int,int>>&);
        bool dfs(Node*,vector<int>&,unordered_set<int>&);
};

bool Solution::dfs(Node* cur,vector<int>& out,unordered_set<int>& visited) {
    if (visited.count(cur->val)) return false;
    visited.emplace(cur->val);
    for (auto i:cur->children) {
        if (i->mark) continue;
        if (!dfs(i,out,visited)) return false;
    }
    cur->mark=true;
    out.push_back(cur->val);
    return true;
}

vector<int> Solution::TopologicalSort(int n,vector<pair<int,int>>& rqst) {
    vector<int> out;
    if (n==0) return out;
    if (n==1) return vector<int> {0};
    vector<Node*> node;
    for (int i=0;i<n;i++) node.push_back(new Node(i));
    for (auto i:rqst) {
        node[i.first]->add(node[i.second]);
    }
    for (int i=0;i<n;i++) {
        if (node[i]->mark) continue;
        unordered_set<int> visited;
        if (!dfs(node[i],out,visited)) return vector<int> ();
    }
    return out;
}

int main(int argc, char *argv[])
{
    Solution obj;
    int n=3;
    vector<pair<int,int>> rqst {{0,1},{0,2},{1,2}};
    auto out=obj.TopologicalSort(n,rqst);
    for (auto i:out) cout << i << " ";
    cout << endl;
    return 0;
}
