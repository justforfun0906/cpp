#include<string.h>
#include<stdio.h>
char order[26];
char input[105][7];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s", order);
	for(int i=0;i<n;i++){
		scanf("%s", input[i]);
	}
}
