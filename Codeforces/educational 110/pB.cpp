#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int count(int a){
	int temp=2;
	int cnt=0;
	while(temp<=a){
		if(a%temp==0){
			a=a/temp;
			cnt+=1;
		}
		else{
			temp+=1; 
		}
	}
	return cnt;
}
bool cmp(int a,int b){
	return (a%2)<(b%2);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int k,cnt=0;
		cin>>k;
		int a[k];
		for(int j=0;j<k;j++){
			cin>>a[j];
		}
		sort(a,a+k,cmp);
		for(int j=0;j<k-1;j++){
			for(int m=j+1;m<k;m++){
				if(__gcd(a[j],2*a[m])>1){
				cnt+=1;
				}
			} 
		}
		cout<<cnt<<endl;
	}

}
