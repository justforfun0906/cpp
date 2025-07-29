#include<iostream>
#include<vector>
using namespace std;

int main(){
    int L, W;
    cin >> L >> W;
    
    // 創建L×L的網格，初始化為空格
    vector<vector<char>> grid(L, vector<char>(L, ' '));
    
    // 方向：右(0)、下(1)、左(2)、上(3)
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int direction = 0; // 從向右開始
    
    int x = 0, y = 0; // 起始位置：左上角
    
    // 檢查下一個位置是否可用
    auto canMove = [&](int nx, int ny) -> bool {
        if(W == 1) {
            if(nx < 0 || nx >= L || ny < 0 || ny >= L) return false;
            return grid[nx][ny] == ' ';
        } else { // W == 2
            if(nx < 0 || nx + 1 >= L || ny < 0 || ny + 1 >= L) return false;
            return grid[nx][ny] == ' ' && grid[nx+1][ny] == ' ' && 
                   grid[nx][ny+1] == ' ' && grid[nx+1][ny+1] == ' ';
        }
    };
    
    // 填充當前位置
    auto fill = [&](int cx, int cy) {
        if(W == 1) {
            grid[cx][cy] = '*';
        } else { // W == 2
            grid[cx][cy] = '*';
            grid[cx+1][cy] = '*';
            grid[cx][cy+1] = '*';
            grid[cx+1][cy+1] = '*';
        }
    };
    
    // 開始繪製
    fill(x, y); // 填充起始位置
    
    while(true) {
        // 嘗試向當前方向移動
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        
        if(canMove(nx, ny)) {
            // 可以移動，繼續當前方向
            x = nx;
            y = ny;
            fill(x, y);
        } else {
            // 不能向當前方向移動，嘗試轉彎
            direction = (direction + 1) % 4; // 順時鐘轉90度
            nx = x + dx[direction];
            ny = y + dy[direction];
            
            if(canMove(nx, ny)) {
                // 轉彎後可以移動
                x = nx;
                y = ny;
                fill(x, y);
            } else {
                // 轉彎後也不能移動，停止繪製
                break;
            }
        }
    }
    
    // 輸出結果
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < L; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
