#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sum(int x, int y){
    return x+y;
}
void sort(int a[], int n){
    
}
int main(){
    int a[5] = {1 , 3, 2, 5, 4};
    sort(a, a+5);
    for(int i = 0;i<5;i++){
        cout<<a[i]<<' ';
    }
}
//n = 班上人數
//n個數字分別代表每個人的考試分數
//請你找到不及格的最高分 跟 及格的最低分 分別是多少