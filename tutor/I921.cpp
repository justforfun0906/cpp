#include<iostream>
using namespace std;
int main(){
    int R, N;
    cin>>R>>N;
    char m[2*R+5][2*R+5];
    for(int i=0;i<=2*R;i++){
        for(int j=0;j<=2*R;j++){
            m[i][j] = '#';
        }
    }
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        x = x * 2;
        y = y * 2;
        m[x][y]='&';
    }
    for(int i=0;i<=2*R;i++){
        for(int j=0;j<=2*R;j++){
            if(i>0&&i<2*R && j>0&&j<2*R){
                if(m[i-1][j-1] == '&' && m[i+1][j-1] == '&' && m[i+1][j+1] == '&' && m[i-1][j+1] == '&'){
                    m[i][j] = 'X';
                }else if(m[i-1][j-1] == '&' && m[i+1][j+1] == '&'){
                    m[i][j] = '\\';
                }else if(m[i-1][j+1] == '&' && m[i+1][j-1] == '&'){
                    m[i][j] = '/';
                }
            }
            if(i>0 && i<2*R && m[i][j] == '#'){
                if(m[i-1][j] == '&' && m[i+1][j] == '&'){
                    m[i][j] = '|';
                }
            }
            if(j>0 && j<2*R && m[i][j] == '#'){
                if(m[i][j+1] == '&' && m[i][j-1] == '&'){
                    m[i][j] = '-';
                }
            }
        }
    }
    for(int i=0;i<2*R-1;i++){
        for(int j=0;j<2*R-1;j++){
            cout<<m[i][j];
        }
        cout<<'\n';
    }
}