int scene_A(int deposit, double rate){
    double money = deposit;
    int cnt = 0;
    while(money <= deposit*2){
        money *= rate;
        cnt++;
    }
    return cnt;
}
int scene_B(int deposit, double rate, int year){
    int money = deposit;
    int cnt = 0;
    do{
        money *= rate;
        cnt++;
    }while (cnt < year);
    return money;
}