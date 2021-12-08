#include<iostream>
using namespace std;
string a[13]={"1w","9w","1s","9s","1t","9t","east","south","west","north","white","redmid","facai"};
int zerocnt(int k[]){
	int ans=0;
	for(int i=0;i<13;i++){
		if(k[i]==0){
			ans+=1;
		}
	}
	return ans;
}
int onecnt(int k[]){
	int ans=0;
	for(int i=0;i<13;i++){
		if(k[i]==1){
			ans+=1;
		}
	}
	return ans;
}
void facai(){
	int k[13];
	for(int i=0;i<13;i++){
		k[i]=0;
	}
	for(int i=0;i<13;i++){
		string temp;
		cin>>temp;
		for(int j=0;j<13;j++){
			if(temp==a[j]){
				k[j]+=1;
			}
		}
	}
	if(zerocnt(k)==0&&onecnt(k)==13){
		cout<<"Thirteen orphans OuO!"<<endl;
	}
	else if(zerocnt(k)==1&&onecnt(k)==11){
		cout<<"Thirteen orphans!"<<endl;
	}
	else{
		cout<<"QAQ!"<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		facai();
	}
}
