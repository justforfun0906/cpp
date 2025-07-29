#include<iostream>
#include<vector>
using namespace std;
void print_permutation(vector<int> &used_nums, vector<int> &temp_ans, int remained_length){
    if(remained_length ==0){
        print temp_ans;
    }
    for(int i=0;i<used_nums.size();i++){
        if(used_nums[i]==0){
            //push i into temp ans
            //update used nums
            //recursion
            //pop i
            //update used nums
        }
    }
}
int main(){
    vector<int> arr;//empty vector
    vector<int> a(10);//size = 0
    vector<int> b(10, 0);//10 elements are initially 0
    arr.push_back(10);//add a new element to back
    arr.pop_back();//remove the last element
    int ab = arr.size();//get the current size of the vector 
    cout<<arr[0];
    cout<<arr.size();
    int k = 0;
    pass_by_value(k);
    cout<<"in main, k="<<k;
}