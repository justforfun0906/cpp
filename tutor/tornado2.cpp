#include<iostream>
#include<vector>
using namespace std;

int main(){
    int L, W;
    cin >> L >> W;
    
    vector<vector<char>> grid(L, vector<char>(L, ' '));
    
    // 方向向量：右、下、左、上
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int dir = 0; // 開始向右
    
    int x = 0, y = 0;
    
    // 填充函數
    auto fill = [&](int r, int c) {
        if(W == 1) {
            grid[r][c] = '*';
        } else {
            grid[r][c] = grid[r+1][c] = grid[r][c+1] = grid[r+1][c+1] = '*';
        }
    };
    
    // 檢查是否可以移動到下一個位置
    auto canGo = [&](int r, int c) {
        if(W == 1) {
            return r >= 0 && r < L && c >= 0 && c < L && grid[r][c] == ' ';
        } else {
            return r >= 0 && r + 1 < L && c >= 0 && c + 1 < L && 
                   grid[r][c] == ' ' && grid[r+1][c] == ' ' && 
                   grid[r][c+1] == ' ' && grid[r+1][c+1] == ' ';
        }
    };
    
    // 填充起始位置
    fill(x, y);
    
    while(true) {
        // 計算下一個位置
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(canGo(nx, ny)) {
            // 可以向前移動
            x = nx;
            y = ny;
            fill(x, y);
        } else {
            // 不能向前，嘗試轉向
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
            
            if(canGo(nx, ny)) {
                // 轉向後可以移動
                x = nx;
                y = ny;
                fill(x, y);
            } else {
                // 轉向後也不能移動，結束
                break;
            }
        }
    }
    
    // 輸出
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < L; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
