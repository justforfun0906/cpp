#include<iostream>
using namespace std;
bool check(int n, int goal, int a[], int len){
	int cnt=0;
	int sum=0;
    for(int i=0;i<len;i++){
        sum += a[i];
        if(sum>n){
            sum = a[i];
            cnt++;
        }
    }
	return cnt<=goal;
}
int search(int left, int right, int goal, int a[], int len){
	int mid=(left+right)/2;
	if(left==right)return right;
	else if(check(mid, goal, a,len))return search(left,mid,goal,a,len);
	else return search(mid+1,right,goal,a,len);
}
int main(){
	int len,heavy;
	if(len==0&&heavy==0)return 0;
	while(cin>>len>>heavy){
		int a[len];
		for(int i=0;i<len;i++){
			cin>>a[i];
		}
		cout<<search(a[len-1],1002*1002,heavy,a,len)<<'\n';
	}
}
