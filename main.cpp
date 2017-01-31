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
class Base {
    public:
        void foo() {cout << "base foo()" << endl;};
        virtual void bar() {cout << "base bar()" << endl;}
};

class Solution : public Base {
    public:
        void foo() {cout << "derived foo()" << endl;};
        void bar() {cout << "derived bar()" << endl;};
};

int main(int argc, char *argv[])
{
    Base *obj=new Solution();
    obj->foo();
    obj->bar();
    return 0;
}
