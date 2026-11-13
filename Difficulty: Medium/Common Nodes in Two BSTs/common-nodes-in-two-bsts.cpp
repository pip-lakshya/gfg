/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void rec1(Node* root,unordered_map<int,int> &mp){
        if(!root) return ;
        mp[root->data]++;
        rec1(root->left,mp);
        rec1(root->right,mp);
    }
    void rec2(Node*root,unordered_map<int,int> &mp,vector<int>&ans){
        if(!root) return;
        if(mp.count(root->data)){
            ans.push_back(root->data);
        }
        rec2(root->left,mp,ans);
        rec2(root->right,mp,ans);
    }
    vector<int> findCommon(Node* r1, Node* r2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        rec1(r1,mp);
        rec2(r2,mp,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};