#include<bits/stdc++.h>
using namespace std;
int M,N;
int main(){
    cin>>M>>N;
    vector<int> job_set[M+5];
    for(int i=1;i<=M;i++){
        int k; cin>>k;
        job_set[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>job_set[i][j];
        }
    }
    map<int, queue<int> > job_type;
    for(int i=0;i<N;i++){
        int k; cin>>k;
        job_type[k].push(i);
    }
    vector<int> winner_of_jobs(N+5);
    for(int i=1;i<=M;i++){
        for(int x:job_set[i]){
            winner_of_jobs[job_type[x].front()] = i;
            job_type[x].pop();
        }
    }
    for(int i=0;i<N;i++){
        cout<<winner_of_jobs[i]<<'\n';
    }
}