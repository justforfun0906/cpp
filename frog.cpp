#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int N, K;
    cin>>N>>K;
    vector<int> h(N);
    for(int i=0;i<N;i++)cin>>h[i];
    vector<int> dp(N);//dp[i] = minimum cost of jumping from stone 1 to stone i
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    for(int i=2;i<N;i++){
        int m = 1e9;
        for(int j = max(0,i-K);j<i;j++){
            m = min(m, abs(h[i]-h[j])+dp[j]);
        }
        dp[i] = m;
    }
    cout<<dp[N-1];
}