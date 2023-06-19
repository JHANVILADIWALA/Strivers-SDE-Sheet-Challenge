https://www.codingninjas.com/codestudio/problems/inorder-traversal_3839605?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

void inorder(TreeNode *root, vector<int>&ans){
    if(root==NULL)return ;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
     vector<int>ans;
     inorder(root,ans);
     return ans;
}
