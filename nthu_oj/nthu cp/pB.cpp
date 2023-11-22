#include<iostream>
using namespace std;
int main(){
    int n,m;
    int w_cnt = 0, b_cnt = 0;
    cin>>n>>m;
    char map[n+5][m+5];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    int status=0; //1 = white, -1 = black, 0 = *
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='W'){
                if(status!=1){
                    w_cnt++;
                    status = 1;
                }
            }else if(map[i][j]=='B'){
                
            }else if(map[i][j]=='G'){
                if(map[i][j-1]!='G'){
                    if(status==1){
                        b_cnt++;
                    }else{
                        
                    }
                }

            }else{

            }
        }
    }
}