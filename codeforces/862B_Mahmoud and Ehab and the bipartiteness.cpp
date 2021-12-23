//code for fun
#include<iostream>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
long long up_cnt=0,down_cnt=0;
bool up;
vector<int> adj[100001];
vector <bool> used(100001);
void dfs(int start){
    used[start]=1;
    for(int i=0;i<adj[start].size();i++){
    	int temp=adj[start][i];
        if(used[temp]==0){
        	    if(up){
      			  	up_cnt+=1;
        			up=0;
  				}
    			else{
        			down_cnt+=1;
     				up=1;
   				}
            dfs(temp);
        }
    }
	up=!up;
    return;
}
int main(){
    int n;
    cin>>n;
    int a,b;
    long long edge_cnt=0;
    while(cin>>a>>b){
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge_cnt+=1;
    }
    dfs(1);
    up_cnt+=1;
    long long all=(long long)up_cnt*down_cnt;
    long long ans=all-edge_cnt;
    cout<<ans;
}
