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
    //cout<<"target= "<<target<<'\n';
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
        set<int>fuck;
        vector<int> not_end;
        int temp=i, cnt=1;

        while(temp){//finding what numbers are in the set and what numbers are not
            if(temp&1){
                posible_end.push_back(cnt);
                fuck.insert(cnt);
            }
            temp>>=1;
            cnt++;
        }
        for(int j=1;j<=n;j++){
            if(fuck.count(j)==0){
                not_end.push_back(j);
            }
        }
        //cout<<"i="<<i;
        for(int j=0;j<posible_end.size();j++){
            int x=posible_end[j];
            //cout<<" x="<<x;
            for(int k=0;k<not_end.size();k++){
                int y=not_end[k]; //x=end, y=added number
                dp[i+(1<<(y-1))][y] = min( dp[i+(1<<(y-1))][y], (dp[i][x]+g[x][y]));

                /*cout<<" y="<<y;
                cout<<"  dp"<<i+(1<<(y-1))<<' '<<y<<" = "<<dp[i+(1<<(y-1))][y];
                cout<<'\n';*/

            }
        }

        /*cout<<"i= "<<i<<"  ";
        cout<<"element= "; for(auto x:posible_end)cout<<x<<" ";
        cout<<"not elements= "; for(auto x:not_end)cout<<x<<' ';
        cout<<endl;*/

    }
    int min_e=1e9;
    for(int i=1;i<=n;i++){
        min_e=min(min_e,dp[target][i]);
    }
    cout<<min_e<<'\n';
}