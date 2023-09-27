#include<stdio.h>
int main(){
    int n, m;
    int arr[1005], pos[1005];
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        arr[i]=i;
        pos[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        int temp_pos = pos[a];
        pos[a] = pos[b];
        pos[b] = temp_pos;
        arr[pos[a]]=a;
        arr[pos[b]]=b;
    }
    for(int i=1;i<n;i++)printf("%d ", arr[i]);
    printf("%d\n", arr[n]);
}