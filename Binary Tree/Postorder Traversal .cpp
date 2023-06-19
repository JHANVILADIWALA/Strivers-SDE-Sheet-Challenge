https://www.codingninjas.com/codestudio/problems/postorder-traversal_3839614?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

void postorder(TreeNode *root, vector<int>&ans ){
    if(root==NULL)return;

    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
     vector<int>ans;
     postorder(root,ans);
     return ans;
}
