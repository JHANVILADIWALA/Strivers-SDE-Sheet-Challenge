https://www.codingninjas.com/codestudio/problems/920519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

void fn(TreeNode<int> *root,int level,vector<int>&ans){
    if(root==NULL)return;

    if(level==ans.size())ans.push_back(root->data);
    fn(root->left,level+1,ans);
    fn(root->right,level+1,ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    int level=0;
    vector<int>ans;
    fn(root,level,ans);
    return ans;
}
