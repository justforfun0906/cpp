#include<stdio.h>
#include<stdbool.h>
int origin[505][505];
int temp[505][505];
int padded[2005][2005];
int mask[505][505];
int conv[2005][2005];
void rotate(int n, int r){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(r==1){
                temp[j][n-1-i]=origin[i][j];
            }else if(r==2){
                temp[n-1-i][n-1-j]=origin[i][j];
            }else if(r==3){
                temp[n-1-j][i]=origin[i][j];
            }
        }
    }
    //printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            origin[i][j]=temp[i][j];
            //printf("%d ", origin[i][j]);
        }
        //printf("\n");
    }
}
void pad(int n,int p){
    int len = n+2*p;
    for(int i=0;i<len;i++) for(int j=0;j<len;j++) padded[i][j]=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) padded[p+i][p+j]=origin[i][j];
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,m,k,r,p,s;
        scanf("%d %d %d %d %d %d", &n, &m, &k, &r, &p, &s);
        r=r%4;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &origin[i][j]);
            }
        }
        if(r!=0) rotate(n,r);
        pad(n,p);
        for(int i=0;i<m;i++) for(int j=0;j<m;j++) scanf("%d", &mask[i][j]);
        int len = (n+2*p-m+1)/s;
        if((n+2*p-m+1)%s!=0) len++;
        //printf("conv:\n");
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                int ans=0;
                for(int x=i*s;x<i*s+m;x++){
                    for(int y=j*s;y<j*s+m;y++){
                        ans+=padded[x][y]*mask[x-(i*s)][y-(j*s)];
                    }
                }
                conv[i][j]=ans;
                //printf("%d ", conv[i][j]);
            }
            //printf("\n");
        }
        int new_len= len/k;
        if(len%k!=0)new_len++;
        for(int i=0;i<new_len;i++){
            for(int j=0;j<new_len;j++){
                int maxx=-1e9;
                for(int x=i*k;x<i*k+k&&x<len;x++){
                    for(int y=j*k;y<j*k+k&&y<len;y++){
                        if(conv[x][y]>maxx) maxx=conv[x][y];
                    }
                }
                printf("%d ", maxx);
            }
            printf("\n");
        }
    }
}