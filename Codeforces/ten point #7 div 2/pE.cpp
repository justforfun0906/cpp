#include<iostream>
#include<vector>
using namespace std;
int main(){
	long long n;
	cin>>n;
	vector<char> a;
	for(long long i=0;i<n;i++){
		string temp;
		cin>>temp;
		if(temp=="WA"){
			a.push_back('W');
		}
		else{
			a.push_back('A');
		}
	}
	vector<long long> A;
	vector<long long> W;
	for(long i=0;i<n;i++){
		if(a[i]=='W'){
			W.push_back(i);
		}
		else if(a[i]=='A'){
			A.push_back(i);
		}
	}
	long long ind=0;
	long long cnt=W.size();
	if(A.empty()==1){
		cout<<cnt;
		return 0;
	}
	for(long long i=0;i<A.size();i++){
			if(A[i]>W[ind]){
				cnt=cnt-1;
				ind+=1;
			}
	}
	cout<<cnt;
}

