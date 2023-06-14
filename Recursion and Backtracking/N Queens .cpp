https://www.codingninjas.com/codestudio/problems/759332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

//BRUTE FORCE:
//using 3 while loops for checking left upper diag,lower diag, same roww
// O(N)*3 
//that is for checking safe or not 
//TC : (N! * N) trying all ways
//SC : O(N^2)

//OPTIMISED
//optimising safe fn
//using hashing,maintaining list
// lower diag => i+j
// upper diag => n-1+col-row
// TC : O(N! * N)
// SC: O(N)

void solve(int col,vector<vector<int>>&board,vector<vector<vector<int>>>&res, vector<int>&leftr,vector<int>&upperdiag,vector<int>&lowerdiag,int n)
{ //when reached last col means found a sequence
  //so push and return
  if(col==n){
      res.push_back(board);
      return;
  }
   
  //traversing on all rows 
  for(int row=0;row<n;row++){
      //checking if safe to put
      if(leftr[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0 ){
          //means safe
          //put it
          board[row][col]=1;
          leftr[row]=1;
          upperdiag[n-1+col-row]=1;
          lowerdiag[row+col]=1;

          //move to next column after putting
          solve(col+1,board,res,leftr,upperdiag,lowerdiag,n);

          //after completing
          //remove it from there
          board[row][col]=0;
          leftr[row]=0;
          upperdiag[n-1+col-row]=0;
          lowerdiag[row+col]=0;

      }
  }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>>ans; //for returning

    //we will getting res as ans but have to convert every board
    //to single vector afterwards 
    vector<vector<vector<int>>>res;
     vector<vector<int>>board(n,vector<int>(n,0));
      
    
    vector<int>leftr(n,0), upperdiag(2*n-1,0),lowerdiag(2*n-1,0);
    solve(0,board,res,leftr,upperdiag,lowerdiag,n);
    
    //converting boards to single vectors
    for(int i=0;i<res.size();i++){
        vector<int>r;
        for(int j=0;j<n;j++){
           for(int k=0;k<n;k++){
                r.push_back( res[i][j][k] );
           }
        }
        ans.push_back(r);
    }
    return ans;
}
