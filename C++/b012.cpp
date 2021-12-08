#include<iostream>
using namespace std;
char a[100];
int roman_to_int(char a[]){
	int ans=0;
	for(int i=0;i<sizeof(a);i++){
		if(a[i]=='M'){
			ans+=1000;
		}
		if(a[i]=='D'){
			ans+=500;
		}
		if(a[i]=='C'){
			if(a[i+1]=='D'||a[i+1]=='M'){
				ans-=100;
			}
			else{
				ans+=100;
			}
		}
		if(a[i]=='L'){
			ans+=50;
		}
		if(a[i]=='X'){
			if(a[i+1]=='L'||a[i+1]=='C'){
				ans-=10;
			}
			else{
				ans+=10;
			}
		}
		if(a[i]=='V'){
			ans+=5;
		}
		if(a[i]=='I'){
			if(a[i+1]=='V'||a[i+1]=='X'){
				ans-=1;
			}
			else{
				ans+=1; 
			}
		}
	}
	return ans;
}
int main(){
	cin>>a;
	cout<<roman_to_int(a);
} 
