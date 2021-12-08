#include<iostream>
using namespace std;
bool full(int a,int k[]){
	bool ans=1;
	for(int i=0;i<a;i++){
		if(k[i]==0){
			ans=0;
		}
	}
	return ans;
}
bool palin(int a,int k[]){
	bool ans=1;
	for(int i=0;i<a;i++){
		if(k[i]!=k[a-i-1]){
			ans=0;
		}
	}
	return ans;
}
void insert(int a,int k[]){
	for(int i=0;i<a;i++){
		if(k[i]==0){
			k[i]=1;
			break;
		}
	}
}
void reverse(int a,int k[]){
	int ans[a];
	for(int i=0;i<a;i++){
		ans[i]=k[a-1-i];
	}
	for(int i=0;i<a;i++){
		k[i]=ans[i];
	}
}
int main(){
	int n;
	cin>>n;
	for(int cn=0;cn<n;cn++){
		int a;
		cin>>a;
		int k[a];
		for(int i=0;i<n;i++){
			cin>>k[i];
		}
		bool turn=0;
		int alice=0;
		int bob=0;
		while(!full){
			if(palin(a,k)){
				if(turn==0){
					alice+=1;
					insert(a,k);
					turn=!turn;
				}
				else{
					bob+=1;
					insert(a,k);
					turn=!turn;
				}
			}
			else{
				reverse(a,k);
				turn=!turn;
			} 
		}
		if(alice>bob){
			cout<<"ALICE"<<endl;
		}
		else if(bob>alice){
			cout<<"BOB"<<endl;
		}
		else{
			cout<<"DRAW"<<endl;
		}
	}
}
