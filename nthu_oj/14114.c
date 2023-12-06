#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 500
char content[MAX_SIZE];
char input[MAX_SIZE];
int main(){
    fgets(input,MAX_SIZE, stdin);
    char temp[MAX_SIZE];
    int cursor=0;//cursor of content;
    for(int i=0;i<MAX_SIZE;i++){
        if(input[i]=='/'){
            if(input[i+1]=='b'){//backspace
                i+=9;
                if(cursor!=0){
                    strcpy(temp,&content[cursor]);//copy the whole content from the cursor pos and post it to temp
                    cursor--;//go back 1 block and paste it back in order to delete a char
                    strcpy(&content[cursor], temp); // pasting it back.

                }
            }
            else if(input[i+1]=='n'){//newline
                i+=7;//copy the whole content from cursor paste it to temp;
                //then insert a '\n' at the cursor pos and paste the original content back start from next cursor pos
                strcpy(temp, &content[cursor]);
                content[cursor]='\n';
                strcpy(&content[cursor+1],temp);
                cursor++;

            }else if(input[i+1]=='l'){//left
                i+=4;
                if(cursor!=0){
                    cursor--;
                }
            }else if(input[i+1]=='r'){//right
                i+=5;
                if(content[cursor]!=0){//hasn't reached the end of the string
                    cursor++;
                }
            }
        }else if(isalpha(input[i])||input[i]==' '){
            strcpy(temp,&content[cursor]);
            strcpy(&content[cursor+1],temp);
            content[cursor]=input[i];
            cursor++;
        }
    }
    printf("%s",content);
}