#ifndef FUNCTION_H
#define FUNCTION_H
#include<ctype.h>
#include<string.h>
int solver(int **ptr, int *sum, char *s){
    int size = strlen(s);
    int ans = 0;
    int temp = -1;
    int neg = 0;
    for(int i=0;i<size;i++){
        if(s[i]=='-'){
            if(temp>-1){
                if(neg==1){
                    *sum-=temp/10;
                    *(ptr[ans])=-temp/10;
                }else{
                    *sum+=temp/10;
                    *(ptr[ans])=temp/10;
                }
                ans++;
            }
            neg=1;
            temp = -1;
        }
        else if(s[i]>='0'&&s[i]<='9'){
            if(temp==-1){
                temp = 0;
            }
            temp+=s[i]-'0';
            temp*=10;
        }
        else{
            //printf("%c",s[i]);
            if(temp>-1){
                if(neg==1){
                    *sum-=temp/10;
                    *(ptr[ans])=-temp/10;
                }else{
                    *sum+=temp/10;
                    *(ptr[ans])=temp/10;
                }
                //printf("%d ",temp/10);
                ans++;
                neg=0,temp=-1;
            }
            
        }
    }
    if(temp>-1){
        if(neg==1){
            *sum-=temp/10;
            *(ptr[ans])=-temp/10;
        }else{
            *sum+=temp/10;
            *(ptr[ans])=temp/10;
        }
        //printf("%d ",temp/10);
        ans++;
    }
    //printf("\n");
    return ans;
}
#endif