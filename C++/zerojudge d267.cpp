#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int input;
	cin>>input;
	int alphabet[26];
	string sentence;
	for(int i=0;i<=input;i++){
		getline(cin,sentence);
		for(int k=0;k<26;k++){
			alphabet[k]=0;
		}
		for(int j=0;j<sentence.size();j++){
			if(sentence[j]>='A'&&sentence[j]<='z'){
				if(sentence[j]>='a'){
					alphabet[sentence[j]-'a']++;
				}
				else{
					alphabet[sentence[j]-'A']++;	
				}
			}
		}
	}
	int num=*max_element(alphabet,alphabet+26);
	for(int i=0;i<26;i++){
		if(alphabet[i]==num){
			cout<<char('a'+i);
		}
	}
} 
