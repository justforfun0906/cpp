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
    pair<int, pair<int, int> > dp [(1<<(n+1))+5][n+5];//dp[set(binary)][end]

    for(int i=0;i<=(1<<(n+1));i++){//init
        for(int j=0;j<=n+5;j++){
            dp[i][j].first=1e9;
            dp[i][j].second.first=0;
            dp[i][j].second.second=0;
        }
    }
    for(int i=1;i<=n;i++){
        dp[1<<(i-1)][i].first=0;
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
                if(dp[i+(1<<(y-1))][y].first>dp[i][x].first+g[x][y]){
                    dp[i+(1<<(y-1))][y].first=dp[i][x].first+g[x][y];
                    dp[i+(1<<(y-1))][y].second.first=i;
                    dp[i+(1<<(y-1))][y].second.second=x;
                }

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
    pair<int,pair<int,int>> min_e;min_e.first=1e9;
    for(int i=1;i<=n;i++){
        if(min_e.first>=dp[target][i].first){
            min_e=dp[target][i];
        }
    }
    cout<<min_e.first<<'\n';
    deque<int> ans;
    set<int> fuck;
    fuck.clear();
    pair<int,int> t=min_e.second;
    ans.push_front(min_e.second.second);
    fuck.insert(min_e.second.second);
    while(t!=make_pair(0,0)){
        int tx=t.first;
        int ty=t.second;
        ans.push_front(dp[tx][ty].second.second);
        fuck.insert(dp[tx][ty].second.second);
        t=dp[tx][ty].second;
    }
    while(!ans.empty()){
        if(ans.front()!=0)cout<<ans.front()<<' ';
        ans.pop_front();
    }
    for(int i=1;i<=n;i++){
        if(fuck.count(i)==0)cout<<i;
    }
    cout<<'\n';
}