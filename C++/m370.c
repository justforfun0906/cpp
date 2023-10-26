#include<stdio.h>
int main(){
    int pos, n;
    scanf("%d %d", &pos, &n);
    int right_max= pos, left_min = pos, right_cnt = 0, left_cnt = 0;
    for(int i=0;i<n;i++){
        int temp; scanf("%d", &temp);
        if(temp>pos){
            right_cnt++;
            if(temp>right_max)right_max = temp;
        }else{
            left_cnt++;
            if(temp<left_min) left_min = temp;
        }
    }
    if(left_cnt>right_cnt){
        printf("%d %d\n", left_cnt, left_min);
    }else{
        printf("%d %d\n", right_cnt, right_max);
    }
}