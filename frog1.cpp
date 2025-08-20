#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> h(N);
    for(int i=0;i<N;i++)cin>>h[i];
    vector<int> dp(N);//dp[i] = minimum cost of jumping from stone 1 to stone i
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    for(int i=2;i<N;i++){
        dp[i] = min(abs(h[i]-h[i-1])+dp[i-1], abs(h[i]-h[i-2])+dp[i-2]);
    }
    cout<<dp[N-1];
}