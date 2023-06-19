https://www.codingninjas.com/codestudio/problems/inorder-traversal_3839605?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>ans ;
    TreeNode *curr=root;
    TreeNode *prev;
    while(curr!=NULL){
        
        //left subtree
        if(curr->left ==NULL ){ //have no left subtree
            ans.push_back(curr->data);
            curr=curr->right; //move to right subtree
        }
        
        else{
            //find the rightmost node of leftsubtree
             prev= curr->left; //looking for left subtree
            //finding rightmost child
            while(prev->right!=NULL && prev->right!=curr){
              prev=prev->right;
            }
            
        //if rightmost child of left subtree
        //is NULL
        if(prev->right==NULL){
            prev->right=curr; //point it to curr
            curr=curr->left;  //further traverse left subtree
        }
        else{
        //is NOT NULL
            prev->right=NULL;
            ans.push_back(curr->data);
            curr=curr->right;
           }
        }
    } 
    return ans;
}
