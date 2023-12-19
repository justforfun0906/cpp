#include <stdio.h>
#include <string.h>
char s[11];
char res[11];
int visited[11];
void perm(int pos, int len);
int main(void)
{
    scanf("%s", s);
    perm(0,strlen(s));
}
void perm(int pos, int len)
{
    int i;
    //basis step
    if(pos==len)
    {
        res[pos]='\0';
        printf("%s\n",res);
        return; 
    }
    char head='\0';
    //recursive step
    for(i=0;i<len;i++)
    {
        if(!visited[i])
        {
        if(s[i]!=head) head=s[i];
        else continue;
        res[pos]=s[i];
        visited[i] = 1;
        perm(pos+1,len);
        visited[i] = 0;
        }
    }
}
