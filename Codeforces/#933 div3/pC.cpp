#include<iostream>
#include<vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> p_front_cnt(n+5,0), e_cnt(n+5,0), m_cnt(n+5,0), p_back_cnt(n+5,0);
    if(s[0]=='p') p_front_cnt[0] = 1;
    else if(s[0]=='m') m_cnt[0] = 1;
    for(int i=1;i<n;i++){
        if(s[i]=='p') p_front_cnt[i] = p_front_cnt[i-1]+1;
        else if(s[i]=='m') m_cnt[i] = m_cnt[i-1]+1;
        else{
            p_front_cnt[i] = 0;
            m_cnt[i] = 0;
        }
    }
    for(int i = n-1;i>=0;i--){
        if(s[i]=='e') e_cnt[i] = e_cnt[i+1]+1;
        else if(s[i]=='p') p_back_cnt[i] = p_back_cnt[i+1]+1;
        else{
            e_cnt[i] = 0;
            p_back_cnt[i] = 0;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(p_back_cnt[i+1]>0){
                if(m_cnt[i-1]>0){
                    int p_cnt = p_back_cnt[i+1];
                    if(s[i+p_cnt+1]=='i'&&s[i+p_cnt+2]=='e'){
                        if(p_back_cnt[i+1]<m_cnt[i-1]+e_cnt[i+2+p_cnt]){
                            ans+=p_back_cnt[i+1];
                            p_front_cnt[i+p_cnt] = 0;
                            i+=p_back_cnt[i+1]+1;
                            continue;
                            //cout<<"special\n";
                        }
                    }
                }
            }
            ans+=min(p_back_cnt[i+1],m_cnt[i-1]);
        }else if(s[i]=='i'){
            ans+=min(p_front_cnt[i-1],e_cnt[i+1]);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}