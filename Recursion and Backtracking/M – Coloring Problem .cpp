https://www.codingninjas.com/codestudio/problems/981273?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
//TC: O( N^M)
//SC: O( N )

// check possibility to color 
bool safe(int n, int node,vector<vector<int>> &mat,
int col,int color[]){
    for(int k=0;k<n;k++){//checking for all nodes
//    not itself   edge exists(is neighbour)  colored        
       if(k!=node && mat[k][node]==1 && color[k]==col)
       return false;
    }
    return true;
}

//recursive fn
bool solve(int node, int n,int m, vector<vector<int>> &mat,
int color[]){
    if(node==n){//end
    return true;
    }
    //trying all possible colors on that node
    for(int i=1;i<=m;i++){
       if(safe(n,node,mat,i,color)){ //safe to color it
           color[node]=i;
           //call recursively
           //if any returns true means we got answe
           if(solve(node+1,n,m,mat,color)){
               return true;
           }
           color[node]=0; //backtrack
       }
    }
    //none of them were safe
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
     int n= mat.size(); //number of nodes
     int color[n]={0}; //color array
     if(solve(0,n,m,mat,color) ==true)return "YES";
     return "NO";
}
