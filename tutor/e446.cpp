#include<bits/stdc++.h>
using namespace std;
void print_perm(vector<int>& used_nums, vector<int>temp_ans, int remain_length){
    if(remain_length == 0){
        for(int i=0;i<temp_ans.size();i++){
            cout<<temp_ans[i]<<" ";
        }
        cout<<endl;
        return; 
    }
    for(int i=1;i<used_nums.size();i++){
        if(used_nums[i] == 0){
            used_nums[i] = 1; // Mark this number as used
            temp_ans.push_back(i); // Add it to the current permutation
            print_perm(used_nums, temp_ans, remain_length-1); // Recur with one less number to place
            temp_ans.pop_back(); // Backtrack: remove the last added number
            used_nums[i] = 0; // Unmark this number as used
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> used_nums(n+1,0);
    vector<int> ans;
    print_perm(used_nums, ans, n);
}