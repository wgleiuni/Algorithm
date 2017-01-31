#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
    public:
        int OptimalPath(vector<vector<int>>&,pair<int,int>,pair<int,int>);
};

int Solution::OptimalPath(vector<vector<int>>& board,pair<int,int> start,pair<int,int> end) {
    if (board.empty() || board[0].empty()) return 0;
    unordered_map<int,pair<int,int>> path;
    multimap<int,int> rec;
    int _m=board.size(),_n=board[0].size();
    int s=start.first*_n+start.second,e=end.first*_n+end.second;
    path[s]=make_pair(0,s);
    rec.emplace(make_pair(0,s));
    vector<int> dx {-1,1,0,0};
    vector<int> dy {0,0,1,-1};
    int min_fuel=INT_MAX;
    while (!path.count(e) || (path.count(e) && min_fuel>rec.begin()->first)) {
        int cur=rec.begin()->second;
        int cur_fuel=rec.begin()->first;
        rec.erase(rec.begin());
        if (path.count(cur) && path[cur].first<cur_fuel) continue;
        for (int i=0;i<4;i++) {
            int x=cur/_n+dx[i],y=cur%_n+dy[i];
            if (x<0 || x>=_m || y<0 || y>=_n) continue;
            int fuel=cur_fuel+abs(board[cur/_n][cur%_n]-board[x][y])*10+1;
            if (path.count(x*_n+y)) {
                if (fuel<path[x*_n+y].first) {
                    path[x*_n+y].first=fuel;
                    path[x*_n+y].second=cur;
                    rec.emplace(make_pair(fuel,x*_n+y));
                }
            }
            else {
                path[x*_n+y]=make_pair(fuel,cur);
                rec.emplace(make_pair(fuel,x*_n+y));
            }
            if (x*_n+y==e) {
                min_fuel=min(fuel,min_fuel);
            }
        }
    }
    return min_fuel;
}

int main(int argc, char *argv[])
{
    Solution obj;
    vector<vector<int>> board {
        {3,2,1,2,1,1,1,2,3},
        {2,1,1,1,1,3,1,1,2},
        {1,1,2,2,3,2,2,2,1},
        {1,2,2,3,4,5,3,2,1},
        {1,2,2,3,4,6,3,2,1},
        {1,1,2,2,3,3,5,3,1},
        {1,1,2,1,1,1,3,2,1},
        {1,1,1,1,2,1,2,1,1},
        {1,1,1,1,1,1,1,1,1}
    };
    pair<int,int> start {4,0}, end {4,8};
    auto out=obj.OptimalPath(board,start,end);
    cout << out << endl;
    return 0;
}
