#include<string.h>
#include<stdio.h>
int main(){
    int n;
    char key_words[1005],ans_s[100005],ans_n[100005];
    int max_cnt = 0;
    scanf("%d %s\n",&n, key_words);
    while(n--){
        char s[100005];
        int temp_cnt = 0;
        fgets(s,100005,stdin);
        char name[100005],sentence[100005],pure_sentence[100005];
        char *d = ":", *temp;
        temp = strtok(s,d);
        strcpy(name,temp);
        //printf("name :%s\n",name);
        while(temp!=NULL){
            strcpy(sentence,temp);
            temp = strtok(NULL, d);
        }
        //printf("sentence: %s\n",sentence);
        char *new_d=" ,.?!";
        strcpy(pure_sentence,sentence);
        temp = strtok(sentence,new_d);
        while(temp!=NULL){
            //printf("temp :%s",temp);
            if(strcasecmp(temp,key_words)==0)temp_cnt++;
            temp = strtok(NULL,new_d);
        }
        if(temp_cnt > max_cnt){
            max_cnt = temp_cnt;
            strcpy(ans_n, name);
            strcpy(ans_s,pure_sentence);
        }
    }
    printf("%s: %s",ans_n, ans_s);
}