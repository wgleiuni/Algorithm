#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>

using namespace std;
class TreeNode {
    public:
        string val;
        TreeNode *left,*right;
        TreeNode(string x): val(x), left(NULL), right(NULL) {}
        virtual string eval(string a,string b) {return "";};
};

class TreeNode_p : public TreeNode {
    public:
        TreeNode_p(string x) : TreeNode(x) {}
        string eval(string a,string b) {return to_string(stoll(a)+stoll(b));};
};

class TreeNode_m : public TreeNode {
    public:
        TreeNode_m(string x) : TreeNode(x) {}
        string eval(string a,string b) {return to_string(stoll(a)-stoll(b));};
};

class TreeNode_t : public TreeNode {
    public:
        TreeNode_t(string x) : TreeNode(x) {}
        string eval(string a,string b) {return to_string(stoll(a)*stoll(b));};
};

class TreeNode_d : public TreeNode {
    public:
        TreeNode_d(string x) : TreeNode(x) {}
        string eval(string a,string b) {return to_string(stoll(a)/stoll(b));};
};

class Calculator {
    public:
        Calculator();
        string evaluate(string);
    private:
        bool CheckInput();
        void ToPostfix();
        void ToExpressionTree();
        string ETeval(TreeNode*);
        string _infix;
        vector<string> _postfix;
        unordered_map<string,int> _dict;
        TreeNode* _root;
};

Calculator::Calculator() {
    _dict["+"]=3;
    _dict["-"]=3;
    _dict["*"]=2;
    _dict["/"]=2;
    return;
}

bool Calculator::CheckInput() {
    if (_infix.empty()) return false;
    for (int i=0;i<_infix.size();i++) {
        if (_infix[i]==' ') {
            _infix.erase(_infix.begin()+i--);
        }
    }
    return _infix.find_first_of("0123456789")!=string::npos;
}

void Calculator::ToPostfix() {
    _postfix.clear();
    stack<string> st;
    for (int i=0;i<_infix.size();i++) {
        if (_infix[i]=='+' || _infix[i]=='-' || _infix[i]=='*' || _infix[i]=='/') {
            if (st.empty()) {
                st.push(_infix.substr(i,1));
                continue;
            }
            while (!st.empty() && st.top()!="(" && _dict[st.top()]<=_dict[_infix.substr(i,1)]) {
                _postfix.push_back(st.top());
                st.pop();
            }
            st.push(_infix.substr(i,1));
        }
        else if (_infix[i]=='(') {
            st.push(_infix.substr(i,1));
        }
        else if (_infix[i]==')') {
            while (st.top()!="(") {
                _postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else {
            size_t p=_infix.find_first_of("+-*/()",i);
            _postfix.push_back(_infix.substr(i,p-i));
            i=p-1;
        }
    }
    while (!st.empty()) {
        _postfix.push_back(st.top());
        st.pop();
    }
    return;
}

void Calculator::ToExpressionTree() {
    stack<TreeNode*> st;
    for (auto s:_postfix) {
        if (s=="+" || s=="-" || s=="*" || s=="/") {
            TreeNode *cur;
            if (s=="+") cur=new TreeNode_p(s);
            else if (s=="-") cur=new TreeNode_m(s);
            else if (s=="*") cur=new TreeNode_t(s);
            else if (s=="/") cur=new TreeNode_d(s);
            cur->right=st.top();
            st.pop();
            cur->left=st.top();
            st.pop();
            st.push(cur);
        }
        else st.push(new TreeNode(s));
    }
    _root=st.top();
    return;
}

string Calculator::ETeval(TreeNode* root) {
    if (root->val!="+" && root->val!="-" && root->val!="*" && root->val!="/") {
        return root->val;
    }
    string left=ETeval(root->left);
    string right=ETeval(root->right);
    return root->eval(left,right);
}

string Calculator::evaluate(string s) {
    _infix=s;
    if (!CheckInput()) return "";
    ToPostfix();
    ToExpressionTree();
    return ETeval(_root);
}

int main(int argc, char *argv[])
{
    Calculator obj;
    string s="1+(2+3*4)/5*5";
    auto out=obj.evaluate(s);
    std::cout << out << std::endl;
    return 0;
}
