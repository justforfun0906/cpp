#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int num;
	cin>>num;
	for(int i=0;i<num;i++){
		string a;
		cin>>a;
		vector <int> arr;
		for(int j=0;j<a.length();j++){
			if(a[j]>='a')arr.push_back(a[j]-'a');
			else arr.push_back(a[j]-'A');
		}
		int min=min_element(arr.begin(),arr.end())-arr.begin();
		bool Y=1;
		if(a.length()>26)Y=0;
		if(arr[min]!=0)Y=0;
		int left=min,right=min+1;
		int temp=arr[min];
		for(int j=0;j<a.length();j++){
				if(left>=0&&arr[left]==temp){
					temp++;
					left--;
				}
				else if(right<arr.size()&&arr[right]==temp){
					temp++;
					right++;
				}
				else{
					Y=0;
					break;
				}
		}
		if(Y==1)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}

