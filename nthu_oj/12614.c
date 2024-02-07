#include<stdio.h>
int main(){
    int game_num, bill_num;
    scanf("%d %d", &game_num, &bill_num);
    int game[game_num+5], bill[bill_num+5];
    int now_bill = 0, game_cnt = 0;
    for(int i=0;i<game_num;i++) scanf("%d", &game[i]);
    for(int i=0;i<bill_num;i++) scanf("%d", &bill[i]); 
    for(int i=0;i<game_num;i++){
        if(game[i]<=bill[now_bill]){
            game_cnt++;
            now_bill++;
        }
        if(now_bill==bill_num) break;
    }
    printf("%d\n", game_cnt);
}