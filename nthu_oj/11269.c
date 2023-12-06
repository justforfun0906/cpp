#include<stdio.h>
#include<string.h>
#define MAX_LEN 1005
char key[MAX_LEN];
char ans[MAX_LEN];
int max_cnt=0;
char input[100005];
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s\n",key);
    while(n--){
        fgets(input,MAX_LEN, stdin);
        char untouched[100005];
        char *d = " ,?!.";
        strcpy(untouched,input);
        char *start;
        int i;
        for(i=0;i<strlen(input);i++){
            if(input[i]==':'){
                start=&input[i];
                break;
            }
        }
        char sentence[100005];
        strncpy(sentence,start,strlen(input)-i);
        printf("sentence: %s",)
        char *end=strtok(sentence,d);
        start = end;
        int temp_cnt = 0;
        while(end!=NULL){
            //printf("%s\n",end);
            end = strtok(NULL, d);
            /*for(int i=0;i<end-start;i++){
                printf("%c",*(start+i));
            }
            printf("\n");*/
            if(strncasecmp(key,start,end - start)==0)temp_cnt++;
            start = end;
        }
        printf("count = %d\n",temp_cnt);
        if(temp_cnt>max_cnt){
            max_cnt=temp_cnt;
            strcpy(ans,untouched);
        }
    }
    for(int i=0;i<strlen(ans);i++){
        printf("%c",ans[i]);
        if(ans[i]==':'){
            printf(" ");
        }
    }
}