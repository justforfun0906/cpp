#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,target=0;
    cin>>n;
    int g[n+5][n+5];
    for(int i=1;i<=n;i++){//input
        target+=(1<<(i-1));
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    cout<<"target= "<<target<<'\n';
    int dp[(1<<(n+1))+5][n+5];//dp[set(binary)][end]

    for(int i=0;i<=(1<<(n+1));i++){//init
        for(int j=0;j<=n+5;j++){
            dp[i][j]=1e9;
        }
    }
    for(int i=1;i<=n;i++){
        dp[1<<(i-1)][i]=0;
    }

    for(int i=1;i<(1<<n);i++){//don't know what the fuck is this
        vector<int> posible_end;
        vector<int> not_end;
        int temp=i, cnt=1;

        while(temp){//finding what numbers are in the set and what numbers are not
            if(temp&1){
                posible_end.push_back(cnt);
            }
            else{
                not_end.push_back(cnt);
            }
            temp>>=1;
            cnt++;
        }

        for(int j=0;j<posible_end.size();j++){
            int x=posible_end[j];
            for(int o=0;o<not_end.size();o++){
                int y=not_end[o]; //x=end, y=added number
                dp[i+(1<<(y-1))][y] = min( dp[i+(1<<(y-1))][y], (dp[i][x]+g[x][y]));

                cout<<"i= "<<i<<" x= "<<x<<" y= "<<y;
                cout<<"  dp"<<i+(1<<(y-1))<<' '<<y<<" = "<<dp[i+(1<<(y-1))][y];
                cout<<'\n';

            }
        }

        /*cout<<"i= "<<i<<"  ";
        cout<<"element= "; for(auto x:posible_end)cout<<x<<" ";
        cout<<"not elements= "; for(auto x:not_end)cout<<x<<' ';
        cout<<endl;*/

    }
    cout<<'\n';
    //cout<<dp[5][1];
}