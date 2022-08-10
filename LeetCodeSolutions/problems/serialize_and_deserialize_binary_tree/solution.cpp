/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::istringstream in(data);
        return decode(in);
    }
    
private: 
    
    void encode(TreeNode *root, std::ostringstream &out) {
        if(root == nullptr) {
            out << "N ";
            return;
        } else {
            out << root->val << " ";
        }
        encode(root->left, out);
        encode(root->right, out);
    }
    
    TreeNode* decode(std::istringstream &in) {
        string curVal = "";
        in >> curVal;
        
        if (curVal == "N") return nullptr;
        
        TreeNode * root = new TreeNode(std::stoi(curVal));
        
        root->left = decode(in);
        root->right = decode(in);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));