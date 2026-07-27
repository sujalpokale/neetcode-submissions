/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void preorder(TreeNode* root,string &s){
        if(root == NULL){
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        preorder(root->left,s);
        preorder(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
            string s;
            preorder(root,s);
            return s;
    }

    TreeNode* build(stringstream &ss){
         string value;
        
        getline(ss,value,',');

        if(value == "N")
            return NULL;

        TreeNode* root =new TreeNode(stoi(value));

        root->left = build(ss);

        root->right = build(ss);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       stringstream ss(data);
       return build(ss);
    }
};
