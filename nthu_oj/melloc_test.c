#include<stdio.h>
#include<stdlib.h>
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned*** ans = (unsigned***)malloc(n*sizeof(unsigned**));
    unsigned** second = (unsigned**)malloc(n*m*sizeof(unsigned*));
    unsigned* third = (unsigned*)malloc(n*m*k*sizeof(unsigned));
    for(int i=0;i<n;i++){
        ans[i]=second+i*m;
        for(int j=0;j<m;j++){
            ans[i][j] = third + (i*m+j)*k;
        }
    }
    return ans;
}
void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}

int main(){
    int **a;
    int n,m;
    scanf("%d %d", &n, &m);
    a = (int **) malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        *(a+i) = (int *) malloc(m*sizeof(int));
    }
    printf("%p %p %p",a+1,*(a+1)+2,&a[1][2]);
}