#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char order[26];
char input[105][7];
void srt(int n){
	for(int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			if(input[n][j]!=input[n][j+1]){
				int ia,ib;
				for(int k=0;k<26;k++){
					if(order[k]==input[n][j])ia = k;
					if(order[k]==input[n][j+1])ib = k;
				}
				if(ia>ib){
					int temp = input[n][j];
					input[n][j]=input[n][j+1];
					input[n][j+1]=temp;
				}
			}
		}
	}
}
int cmp1(const void* a, const void* b){
	int ia=0, ib=0;
	for(int i=0;i<26;i++){
		if(*(char*)a==order[i])ia = i;
		if(*(char*)b==order[i])ib = i;
	}
	if(ia>ib)return 1;
	else return -1;
}
int cmp2(char a[], char b[]){
	int flag = strcmp(a,b);
	return flag;
}
int main(){
	int n;
	int ans[105];
	scanf("%d",&n);
	scanf("%s", order);
	for(int i=0;i<n;i++){
		ans[i]=i;
		scanf("%s", input[i]);
		srt(i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(cmp2(input[ans[j]],input[ans[j+1]])>0){
				int temp = ans[j];
				ans[j]=ans[j+1];
				ans[j+1] = temp;
			}
		}
	}
	printf("%s",input[ans[0]]);
	for(int i=1;i<n;i++){
		printf(" %s",input[ans[i]]);
	}
	printf("\n");
}