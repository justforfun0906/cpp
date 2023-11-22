#include<stdio.h>
#include<string.h>
#include<ctype.h>
int a[105], b[105], ans[105];
void reverse(int *a, int n){
    int temp[105];
    for(int i=0;i<n;i++){
        temp[n-1-i]=*(a+i);
    }
    for(int i=0;i<n;i++) *(a+i)=temp[i];
}
int min(int a, int b){
    if(a<b) return a;
    else return b;
}
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
int main(){
    int sa, sb;
    scanf("%d", &sa);
    char temp[105];
    scanf("%s",temp);
    for(int i=0;i<sa;i++){
        a[i]=temp[i]-'0';
    }
    reverse(a,sa);
    scanf("%d", &sb);
    scanf("%s", temp);
    for(int i=0;i<sb;i++) b[i] = temp[i]-'0';
    reverse(b,sb);
    int carry = 0;
    for(int i=0;i<max(sa,sb);i++){
        ans[i]=a[i]+b[i]+carry;
        carry = 0;
        if(ans[i]>9){
            ans[i]=ans[i]%10;
            carry=1;
        }
    }
    int bound = max(sa,sb);
    if(carry==1)ans[bound]=1, bound++;
    reverse(ans, bound);
    for(int i=0;i<bound;i++){
        printf("%d",ans[i]);
    }
}