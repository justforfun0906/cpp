#include<stdio.h>
#include<string.h>
int main(){
    char str[1010];
    scanf("%s", str);
    int cnt = 0, n = strlen(str);
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            int left = i-j, right = i+j;
            if(left<0||right>=n) break;
            else{
                if(str[left]==str[right]){
                    cnt++;
                    //for(int m=left; m<=right; m++){
                    //    printf("%c", str[m]);
                    //}
                    //printf("\n");    
                }
            }
        }
    }
    printf("%d\n", cnt);
}