https://www.codingninjas.com/codestudio/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

void preorder( TreeNode *root, vector<int>&ans){
    if(root==NULL) return ;

    ans.push_back(root->data);
    preorder(root->left , ans);
    preorder(root->right , ans );
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    preorder(root, ans);
    return ans;
}
