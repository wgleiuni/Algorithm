#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Codec {
    public:
        std::string serialize(TreeNode*);
        TreeNode* deserialize(std::string);
};

std::string Codec::serialize(TreeNode* root) {
    std::string out;
    if (root==NULL) {
        out="null";
        return out;
    }
    std::queue<TreeNode*> Q;
    Q.push(root);

    while (!Q.empty()) {
        TreeNode* temp=Q.front();
        Q.pop();
        if (temp) {
            out+=std::to_string(temp->val)+",";
            Q.push(temp->left);
            Q.push(temp->right);
        }
        else out+="null,";
    }

    out.pop_back();
    return out;
}

TreeNode* Codec::deserialize(std::string data) {
    if (data.empty()) return NULL;
    std::queue<TreeNode*> Q;
    size_t p2=data.find_first_of(","),p1=0;
    std::string temps=data.substr(p1,p2-p1);
    if (temps=="null") return NULL;
    TreeNode* root=new TreeNode(std::stoi(temps));
    Q.push(root);
    if (p2==std::string::npos) return root;
    p1=p2+1;
    p2=data.find_first_of(",",p1);
    while (p1!=std::string::npos) {
        TreeNode* temp=Q.front();
        Q.pop();
        std::string temps=data.substr(p1,p2-p1);
        if (temps!="null") {
            temp->left=new TreeNode(std::stoi(temps));
            Q.push(temp->left);
        }
        if (p2==std::string::npos) break;
        p1=p2+1;
        p2=data.find_first_of(",",p1);
        temps=data.substr(p1,p2-p1);
        if (temps!="null") {
            temp->right=new TreeNode(std::stoi(temps));
            Q.push(temp->right);
        }
        if (p2==std::string::npos) break;
        p1=p2+1;
        p2=data.find_first_of(",",p1);
    }
    return root;
}
