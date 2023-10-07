#include<stdio.h>
#include<string.h>
int max(int a,int b){
	if(a>b)return a;
	else return b;
}
int solve(char s[10005],int len){
	int ans=0, temp=1;
	for(int i=0;i<len;i++){
		for(int j=1;i+j<=len&&i-j>=0;j++){
			if(s[i-j]==s[i+j]){
				temp+=2;
			}else{
				break;
			}
		}
		ans = max(ans, temp);
		temp=1;
	}
	ans = max(ans, temp);
	temp =0;
	for(int i=0;i<len;i++){
		for(int j=0;i+j+1<len&&i-j>=0;j++){
			if(s[i+j+1]==s[i-j])temp+=2;
			else break;
		}
		ans = max(ans, temp);
		temp=0;
	}
	ans = max(ans, temp);
	return ans;
}
int main(){
	char s[10005];
	while(scanf("%s", s)!=EOF){
		int len = strlen(s);
		int ans = solve(s,len);
		printf("%d\n", ans);
	}
}
