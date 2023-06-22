https://www.codingninjas.com/codestudio/problems/920552?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

int fn(TreeNode<int> *root, int& diam){
    if(root==NULL) return 0;

    int lh= fn(root->left,diam);
    int rh= fn(root->right,diam);
  
    diam= max(diam, lh+rh);
   
    return 1+max(lh,rh); //fn returns the maximum of ht of left and right subtree
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diam=0;
    fn(root, diam);
    return diam;
}
