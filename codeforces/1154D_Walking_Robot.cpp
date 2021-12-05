//code for fun
#include<iostream>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int main(){
	int len,batt,acu;
	cin>>len>>batt>>acu;
	int ful_batt=batt, ful_acu=acu;
	bool path[len];
	int cnt=0;
	for(int i=0;i<len;i++){
		cin>>path[i];
	}
	for(int i=0;i<len;i++){
		if(batt==0&&acu==0){//robot die
			cout<<cnt;
			break;
		}
		if(path[i]==true){//exposed
			if(acu==ful_acu){
				acu--;
				//cout<<"condition1 ";
			}
			else{
				if(batt==0){
					acu--;
					//cout<<"condition2 ";
				}
				else{
					batt--;
					acu++;
					//cout<<"condition3 ";
				}
			}
		}
		else if(path[i]==false){//not exposed
			if(acu){
				acu--;
				//cout<<"condition4 ";
			}
			else{
				batt--;
				//cout<<"condition5 ";
			}
		}
		cnt++;
	}
	if(cnt==len){
		cout<<cnt;
	}
}

