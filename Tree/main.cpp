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
#include "TreeNode.h"
using namespace std;

class Transverse {
	public:
		Transverse(TreeNode* root) {_root=root;};
		void inorder_iter();
		void postorder_iter();
		vector<int> _trans;
	private:
		TreeNode* _root;
};

void Transverse::inorder_iter() {
	_trans.clear();
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
            _trans.push_back(cur->val);
            cur=cur->right;
        }
	}
	return;
}

void Transverse::postorder_iter() {
	_trans.clear();
	if (!_root) return;
	stack<TreeNode*> st;
	TreeNode* last=NULL,*cur=_root;
	while (!st.empty() || cur) {
        if (cur) {
            st.push(cur);
            cur=cur->left;
        }
        else {
            TreeNode* pcur=st.top();
            if (pcur->right==last || !pcur->right) {
                _trans.push_back(pcur->val);
                last=pcur;
                st.pop();
            }
            else {
                cur=pcur->right;
            }
        }
	}
	return;
}

int main(int argc, char *argv[])
{
    Codec Tree;
    TreeNode* root=Tree.deserialize("1,2,3,4,5,6,7");
    Transverse obj(root);
    obj.postorder_iter();
    for (auto i:obj._trans) cout << i << " ";
    cout << endl;
    obj.inorder_iter();
    for (auto i:obj._trans) cout << i << " ";
    cout << endl;
	return 0;
}
