#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <utility>
using namespace std;

template<typename T>
void add(T& h,int n) {
    auto p=h.begin();
    for (p;p!=h.end();p++) {
        if (*p>n) break;
    }
    h.insert(p,n);
    return;
}

int main(int argc, char *argv[])
{
    if (argc!=3) return -1;
    string container(argv[1]);
    int N=atoi(argv[2]);
    srand(time(NULL));
    if (container=="vector") {
        vector<int> res;
        for (int i=0;i<N;i++) {
            add(res,rand());
        }
        for (auto i:res) cout << i << " ";
        cout << endl;
    }
    else {
        list<int> res;
        for (int i=0;i<N;i++) {
            add(res,rand());
        }
        for (auto i:res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
