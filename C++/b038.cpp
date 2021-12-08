#include<iostream>
using namespace std;
int solution[100];
bool used[9];
void backtrack(int m,int dim){
	if(dim==m){
		for(int i=0;i<m;i++){
			cout<<solution[i];
		}
		cout<<endl;
		return;
	}	
	for(int i=0;i<m;i++){
		if(!used[i]){
			used[i]=true;
			solution[dim]=i+1;
			backtrack(m,dim+1);
			used[i]=false;
		}
	}
}
int main(){
	int m;
	cin>>m;
	backtrack(m,0);
} 
