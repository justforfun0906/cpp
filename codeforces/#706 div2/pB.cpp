#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		vector<int> k;
		for(int j=0;j<a;j++){
			int temp;
			cin>>temp;
			k.push_back(temp);
		}
		sort(k.begin(),k.end());
		for(int j=0;j<b;j++){
			int mex=k.size(),max,add;
			for(int q=0;q<k.size();q++){
				if(k[q]!=q){
					mex=q;
					break;
				}
			}
			max=k.back();
			if((mex+max)%2!=0){
				add=((mex+max)/2)+1;
			}
			else{
				add=(mex+max)/2;
			}
			k.push_back(add);
			sort(k.begin(),k.end());;
		}
		int count=0;
		for(int j=0;j<k.size();j++){
			if(k[j]!=k[j+1]){
				count++;
			}
		}
		cout<<count<<endl;
	}
}
