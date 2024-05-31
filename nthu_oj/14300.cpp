#include<bits/stdc++.h>
using namespace std;
int M,N;
void print(vector<int> &v){
    for(auto i:v){
        cout<<i<<'\n';
    }
}
int find_job(map<int, queue<int>> &ma, int target){
    if(ma.count(target)){//has a queue for target job type
        int ret_val = ma[target].front();
        ma[target].pop();
        if(ma[target].empty()){//take the last one
            ma.erase(target);
        }
        return ret_val;
    }else{
        return -1;//not found
    }
}
int main(){
    cin>>M>>N;
    vector<int> job_set[M+5];
    for(int i=0;i<M;i++){
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
    vector<int> winner_of_jobs(N);
    for(int i=0;i<M;i++){
        vector<int> job_taken_list;
        for(int x:job_set[i]){
            int ind = find_job(job_type, x);
            if(ind==-1){//cry
                print(winner_of_jobs);
                /*
                without using job_taken_list
                a littlecute who can't get all jobs that it want
                might eventually getting a portion of it's job set
                however, it should get non of them.
                by adding a job_taken_list, we can ensure that only those little cutes
                who don't cry, can get the jobs in their job set.
                */
                return 0;
            }else{
                job_taken_list.push_back(ind);
            }
        }
        for(auto x:job_taken_list){
            winner_of_jobs[x] = i+1;
        }
    }
    print(winner_of_jobs);
}