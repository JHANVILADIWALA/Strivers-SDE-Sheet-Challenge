https://www.codingninjas.com/codestudio/problems/893110?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


vector<int> bottomView(BinaryTreeNode<int> * root){

     vector<int>ans;
     if(root==NULL) return ans;

     queue<pair< BinaryTreeNode<int> *, int >>q;
     //            node               line
     // line : -2 -1 0 1 2

     q.push({root,0});

     // line lowermostNode
     map<int,int>m;

     while(!q.empty()){
         auto it= q.front();
         q.pop();

        BinaryTreeNode<int> * node= it.first;
        int line= it.second;
        m[line]=node->data; //update lowermost node on that line

        //left  => LINE--
        if(node->left!=NULL){
            q.push({node->left,line-1});
        }

        //right => RIGHT++
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
     }
     for(auto it: m){
         ans.push_back(it.second);
     }
     return ans; 
}
