#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char order[26];
char input[105][7];
void srt(int n){
	for(int i=0;i<5;i++){
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
	int ia, ib;
	int flag = -1;
	for(int i=0;i<6;i++){
		if(a[i]!=b[i]){
			for(int j=0;j<26;j++){
				if(order[j]==a[i])ia = j;
				if(order[j]==b[i])ib = j;
			}
			if(ia>ib){
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s", order);
	for(int i=0;i<n;i++){
		scanf("%s", input[i]);
		srt(i);
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(cmp2(input[j],input[j+1])){
				char temp[10];
				strcpy(temp,input[i]);
				strcpy(input[i],input[i+1]);
				strcpy(input[i+1],temp);
			}
		}
	}
	printf("%s",input[0]);
	for(int i=1;i<n;i++){
		printf(" %s",input[i]);
	}
	printf("\n");
}