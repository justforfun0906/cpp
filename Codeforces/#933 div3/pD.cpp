#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void check(vector<bool> pos, int n){
    for(int i=1;i<=n;i++){
        cout<<pos[i]<<' ';
    }
    cout<<'\n';
}
void solve(){
    int n,m,x; cin>>n>>m>>x;
    vector<bool> posib(n+5,0);
    posib[x]= 1;
    int temp_x = x;
    for(int i=0;i<m;i++){
        int dis; cin>>dis;
        dis%=n;
        char dir; cin>>dir;
        for(int j=1;j<=n;j++){
            if(posib[j]){
                temp_x = j;
                if(dir=='0'){//clockwise
                    int pass = (temp_x+dis)%(n+1);
                    if(pass == 0) pass = n;
                    posib[j]=0;
                    posib[pass] = 1;
                }else if(dir=='1'){//counter-clockwise
                    int pass = (temp_x-dis+n)%(n+1);
                    if(pass == 0) pass = n;
                    posib[j] = 0;
                    posib[pass] = 1;
                }else{//don't know
                    int pass1 = (temp_x+dis)%(n+1), pass2 = (temp_x-dis+n)%(n+1);
                    posib[j] = 0;
                    posib[pass1] = 1;
                    posib[pass2] = 1;
                    cout<<"pass1="<<pass1<<" pass2="<<pass2<<'\n';
                }
            }
        }
        cout<<"now m ="<<i<<"dir = "<<dir<<'\n';
        check(posib, n);
    }
    cout<<"ans ";
    for(int i=1;i<=n;i++){
        if(posib[i])cout<<i<<' ';
    }
    cout<<'\n';
}
int main(){
    //fastio
    int t; cin>>t;
    while(t--){
        solve();
    }
}