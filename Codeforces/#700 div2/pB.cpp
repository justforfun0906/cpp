#include<iostream>
using namespace std;
struct monster{
	int num;
	long long atk;
	long long hp;
};
bool game(){
	long long atk,hp,n;
	//write
	cin>>atk>>hp>>n;
	monster mon[n];
	for(int i=0;i<n;i++){
		mon[i].num=i;
		cin>>mon[i].atk;
	} 
	for(int i=0;i<n;i++){
		cin>>mon[i].hp;
	} 
	//operate
	for(int i=0;i<n;i++){
		//t:atk turns
		int herot=mon[i].hp/atk;
		int monstert=hp/mon[i].atk;
		//adjust
		if(herot==0){
			herot=1;
		}
		if(monstert==0){
			monstert=1;
		}
		//final fight
		hp=hp-(herot*mon[i].atk);
		if(hp<=0){
			if(i+1==n){
				if(herot==monstert){
					if(mon[i].hp-(herot*atk)>0){
						return 0;
					}
					else{
						return 1;
					}
				}
			}
			else{
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		if(game()==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	} 
}
