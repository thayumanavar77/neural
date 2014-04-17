#include <iostream>
#include <algorithm>
using namespace std;
long long k[403][950003];
bool sols[403][950001];
#define N 10003
int solveK(int n, int w, int *wa, int *v, bool *out)
{

//  int k[n+1][w+1]; bool sols[n+1][w+1];

  for(int j=0;j<=w;j++)
    k[0][j]= 0;

  for(int i= 1; i <= n; i++)
  {
    for(int j= 0; j <= w; j++)
    {
      if (wa[i] <= j && (v[i] + k[i-1][j-wa[i]]) >= k[i-1][j]) {
        k[i][j]= v[i] + k[i-1][j-wa[i]];
        sols[i][j]= true;
      }
      else {
        k[i][j]= k[i-1][j];
        sols[i][j]= false;
    }
  }
  }
  int j= w;
  cout<<k[n][w]<<" "<<0<<endl;
  for(int i= n; i>0; i--) {
    if (sols[i][j]) {
       out[i]= true;
       j= j - wa[i];
    }
  }
  cout<<out[1]?1:0;
  for(int i=2;i<=n;i++)
    cout<<"  "<<out[i]?1:0;
  cout<<endl;
  return k[n][w];
}

int
main(int arg,char **argv)
{
  int n,w;
  int v[n+1],wa[n+1];
  bool out[n+1];
  cin>>n>>w;
  //cout<<n<<"  "<<w<<endl;
  for(int i= 1; i <= n; i++) {
    cin>>v[i]>>wa[i];
    out[i]= false;
    //cout<<v[i]<<"   "<<wa[i]<<endl;
  }
 (void)solveK(n,w,wa,v,out);
}
