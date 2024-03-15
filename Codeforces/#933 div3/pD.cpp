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
    vector<bool> temp_posib(n+5,0);
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
                    int pass = (temp_x+dis)%n;
                    if(pass == 0) pass = n;
                    posib[j]=0;
                    temp_posib[pass] = 1;
                }else if(dir=='1'){//counter-clockwise
                    int pass = (temp_x-dis+n)%n;
                    if(pass == 0) pass = n;
                    posib[j] = 0;
                    temp_posib[pass] = 1;
                }else{//don't know
                    int pass1 = (temp_x+dis)%n, pass2 = (temp_x-dis+n)%n;
                    posib[j] = 0;
                    if(pass1==0) pass1 = n;
                    if(pass2==0) pass2 = n;
                    temp_posib[pass1] = 1;
                    temp_posib[pass2] = 1;
                    //cout<<"pass1="<<pass1<<" pass2="<<pass2<<'\n';
                }
            }
        }
        for(int i=1;i<=n;i++){
            posib[i] = temp_posib[i];
            temp_posib[i] = 0;
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(posib[i])cnt++;
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++){
        if(posib[i])cout<<i<<' ';
    }
    cout<<'\n';
}
int main(){
    fastio
    int t; cin>>t;
    while(t--){
        solve();
    }
}