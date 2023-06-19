https://www.codingninjas.com/codestudio/problems/799401?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

vector<int> getTopView(TreeNode<int> *root) {
     vector<int>ans;
     if(root==NULL)return ans;

     queue<pair< TreeNode<int> *, int>>q;
     q.push({root,0});
     map<int,int>m;

     while(!q.empty()){
         auto it= q.front();
         q.pop();
         TreeNode<int> * node= it.first;
         int line= it.second;

         //if its NOT already present
         //THEN ONLY STORE IT
         if(m.find(line)==m.end()) m[line]=node->val;

         //left
         if(node->left!=NULL){
             q.push({node->left, line-1});
         }
         //right
         if(node->right!=NULL){
             q.push({node->right, line+1});
         }
     }
     for(auto it: m){
         ans.push_back(it.second);
     }
     return ans;
}
