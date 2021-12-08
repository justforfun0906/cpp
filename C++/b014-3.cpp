#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long sum(string s){
	long long ans = 0;
	int temp = 0;
	for(int i=0;i<s.size();++i){
		if(s[i]!=' '){
			temp=temp*10;
			temp+=s[i]-'0';
			if(i==s.size()-1){
				ans+= temp;
			}
		}
		else{
			ans+= temp;
			temp = 0;
		}
		//cout<<"temp = "<<temp<<endl;
	}
	//cout<<"ans = "<<ans<<endl;
	return ans;
}
int main(){
	string s1,s2,s3;
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);
	int val[3]={sum(s1),sum(s2),sum(s3)};
	cout<<max_element(val,val+3)-val+1<<' '<<*max_element(val,val+3);
} 
