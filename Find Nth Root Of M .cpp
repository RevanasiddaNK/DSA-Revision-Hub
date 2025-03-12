#include<bits/stdc++.h>
using namespace std;

int nthExp(int n, int mid, int m){
  long long temp = 1;
  for(int i=0; i<n; i++){
    temp *= mid;
    if(temp > m)
      return INT_MAX;
  }
  return temp;
}

int NthRoot(int n, int m) {
  int s=1,e=m;
  int ans = -1;
  while(s <= e){
    int mid = s+(e-s)/2;
    int nthExpVal = nthExp(n,mid,m);
    if( nthExpVal == m  ){
      return mid;
    }
    else if( nthExpVal < m){
      s = mid+1;
    }
    else{
      e = mid-1;
    }
  }

  return -1;
}
