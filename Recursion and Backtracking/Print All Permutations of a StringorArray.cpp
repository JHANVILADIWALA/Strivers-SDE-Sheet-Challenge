https://www.codingninjas.com/codestudio/problems/758958?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 

void fn(int ind, string &s,vector<string>&ans ){
    //reached end so return
  if(ind==s.size()){
      ans.push_back(s);
      return ;
  }
  for(int i=ind;i<s.size();i++){
      //swap
      swap(s[ind],s[i]);
      //recursive call
      fn(ind+1,s,ans);
      //backtrack
      swap(s[ind],s[i]);
  }
}
vector<string> findPermutations(string &s) {
    vector<string>ans; 
    fn(0,s,ans);
    return ans;
}
