#include<stdio.h>
#include<stdlib.h>
int used[15]={0};
int arr[15];
int N,M;
int ans[300][15];
int ans_cnt;
int now = 0;
int cmp(const void* a, const void* b){
    return(*(int*)a- *(int*)b);
}
void store_ans(){
    int temp = 0;
    for(int i=0;i<N;i++){
        if(used[i]==1){
            ans[now][temp]=arr[i];
            temp ++;
        }
    }
    now++;
}
int unique(int a, int output[300][15]){
    int flag = 1;
    for(int i=0;i<ans_cnt;i++){
        if(i!=a){
            int same = 1;
            for(int j=0;j<M;j++){
                if(output[i][j]!=ans[a][j]) same = 0;
            }
            if(same == 1) flag = 0;
        }
    }
    return flag;
}
void solve(int n, int m, int k, int last){
    if(k==0&&m<=0){
        store_ans();
        return;
    }else if(m<=0){
        return;
    }
    for(int i=last+1;i<N;i++){
        if(used[i]==0&&arr[i]<=k){
            used[i]=1;
            solve(n,m-1,k-arr[i],i);
            used[i]=0;
        }
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ans_cnt = 0;
        now = 0;
        for(int i=0;i<15;i++) used[i]=0;
        int k;
        scanf("%d %d %d", &N, &M, &k);
        for(int i=0;i<N;i++) scanf("%d", &arr[i]);
        qsort(arr,N,sizeof(int),cmp);
        solve(N,M,k,-1);
        int output[300][15];
        for(int i=0;i<now;i++){
            if(unique(i, output)){
                for(int j=0;j<M;j++){
                    printf("%d ", ans[i][j]);
                    output[ans_cnt][j]=ans[i][j];
                }
                ans_cnt++;
                printf("\n");
            }
        }
    }
}