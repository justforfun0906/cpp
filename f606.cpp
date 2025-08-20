#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,q[55][55],server_loc[55],city[55][55];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>q[i][j];
        }
    }
    int ans = 1e9;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++)cin>>server_loc[j];
        int cnt = 0;
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                city[j][k] = 0;
            } 
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                city[server_loc[j]][k] += q[j][k];
            }
        }
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j == k){
                    cnt += city[j][k];
                }else{
                    if(city[j][k]>1000){
                        cnt += 2* (city[j][k]-1000)+ 3000;
                    }else{
                        cnt += 3* city[j][k];
                    }
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout<<ans;
}