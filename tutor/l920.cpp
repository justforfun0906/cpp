#include<iostream>
#include<vector>
using namespace std;

int main(){
    string S;
    cin >> S;
    int n = S.length();
    
    // 模擬骨牌效應直到穩定
    while(true){
        string nextS = S;
        bool changed = false;
        
        // 對每個X建築物檢查是否會倒塌
        for(int i = 0; i < n; i++){
            if(S[i] == 'X'){
                bool leftPush = false, rightPush = false;
                
                // 檢查左邊是否有R推過來
                if(i > 0 && S[i-1] == 'R'){
                    leftPush = true;
                }
                
                // 檢查右邊是否有L推過來
                if(i < n-1 && S[i+1] == 'L'){
                    rightPush = true;
                }
                
                // 決定這個建築物的命運
                if(leftPush && rightPush){
                    // 兩邊都推，保持平衡，變成穩定狀態
                    // 在這個問題中，我們可以用不同的字符表示平衡
                    // 但題目暗示平衡後不再變化，所以可能還是X
                    nextS[i] = 'X'; // 保持不變
                } else if(leftPush){
                    // 只有左邊推，向右倒
                    nextS[i] = 'R';
                    changed = true;
                } else if(rightPush){
                    // 只有右邊推，向左倒
                    nextS[i] = 'L';
                    changed = true;
                }
            }
        }
        
        S = nextS;
        
        // 如果沒有變化，模擬結束
        if(!changed){
            break;
        }
    }
    
    cout << S << endl;
    return 0;
}