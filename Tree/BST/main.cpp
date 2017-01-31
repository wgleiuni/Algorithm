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

class TreeNode {
    public:
        int val;
        TreeNode *left,*right;
        TreeNode(int x) {val=x,left=NULL,right=NULL;};
};

class BST {
    public:
        bool check(int);
        void add(int);
        void del(int);
    private:
        void inorder_iter();
        TreeNode* _root=NULL;
        TreeNode* mycheck(int);
};

TreeNode* BST::mycheck(int x) {
    if (!_root || _root->val==x) return _root;
    TreeNode* cur=_root;
    while (cur->left || cur->right) {
        if (cur->left && cur->left->val==x) return cur;
        if (cur->right && cur->right->val==x) return cur;
        if (cur->val>x) {
            if (!cur->left) return cur;
            else cur=cur->left;
        }
        else {
            if (!cur->right) return cur;
            else cur=cur->right;
        }
    }
    return cur;
}

bool BST::check(int x) {
    TreeNode* res=mycheck(x);
    if (!res) return false;
    if (res->val==x || (res->left && res->left->val==x) || (res->right && res->right->val==x)) return true;
    return false;
}

void BST::add(int x) {
    TreeNode* res=mycheck(x);
    if (!res) {
        _root=new TreeNode(x);
        inorder_iter();
        return;
    }
    if (res->val==x || (res->left && res->left->val==x) || (res->right && res->right->val==x)) return;
    if (res->val>x) res->left=new TreeNode(x);
    else res->right=new TreeNode(x);
    inorder_iter();
    return;
}

void BST::del(int x) {
    TreeNode* res=mycheck(x);
    if (!res) return;
    if (res->val==x) delete [] res;
    if (res->left && res->left->val==x) {
        TreeNode* cur=res->left->right;
        if (!cur) {
            cur=res->left->left;
            delete [] res->left;
            res->left=cur;
        }
        else {
            while (cur->left) cur=cur->left;
            TreeNode* temp=res->left->right;
            cur->left=res->left->left;
            delete [] res->left;
            res->left=temp;
        }
    }
    if (res->right && res->right->val==x) {
        TreeNode* cur=res->right->right;
        if (!cur) {
            cur=res->right->left;
            delete [] res->right;
            res->right=cur;
        }
        else {
            while (cur->left) cur=cur->left;
            TreeNode* temp=res->right->right;
            cur->left=res->right->left;
            delete [] res->right;
            res->right=temp;
        }
    }
    inorder_iter();
    return;
}

void BST::inorder_iter() {
    vector<int> trans;
    if (!_root) return;
    stack<TreeNode*> st;
    TreeNode *cur=_root;
    while (!st.empty() || cur) {
        if (cur) {
            st.push(cur);
            cur=cur->left;
        }
        else {
            cur=st.top();
            st.pop();
            trans.push_back(cur->val);
            cur=cur->right;
        }
    }
    for (auto i:trans) cout << i << " ";
    cout << endl;
    return;
}

int main(int argc, char *argv[])
{
    BST obj;
    for (int i=0;i<100;i++) obj.add(i);
    obj.del(50);
    obj.del(5);
    obj.del(13);
    obj.del(82);
    obj.del(93);
    return 0;
}
