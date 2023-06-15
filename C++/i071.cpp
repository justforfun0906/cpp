#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,pos;
	cin>>a>>pos;
	int arr[a+1];
	for(int i=1;i<=a;i++){
		cin>>arr[i];
	}
	int my_h=arr[pos], right_max=0, left_max=0, cnt=0;
	if(pos!=a)for(int i=pos+1;i<=a;i++){
		if(arr[i]>right_max&&arr[i]>my_h){
			right_max=arr[i];
			cnt++;
		}
	}
	if(pos!=1)for(int i=pos-1;i>=1;i--){
		if(arr[i]>left_max&&arr[i]>my_h){
			left_max=arr[i];
			cnt++;
		}
	}
	cout<<cnt;
}
