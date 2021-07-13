#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;


int32_t main()
{
    int m;
    cin>>m;
    int mon[]={1,3,4};
    int minm[m+1];
    minm[0]=0;
    minm[1]=1;

    for(int i=2;i<=m;i++){
        
        minm[i]=10000;
        for(int x:mon)
            if(i>=x){
                minm[i]=min(minm[i],minm[i-x]+1);
                
            }
    
                
    }

    cout<<minm[m];
  return 0;
}