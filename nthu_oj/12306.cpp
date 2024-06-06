#include<bits/stdc++.h>
using namespace std;
typedef struct player_state{
    int hp;
    int mhp;
    int lv;
    int step;
    player_state(int hp,int mhp,int lv,int step):hp(hp),mhp(mhp),lv(lv),step(step){}
} state;
bool checked[16][301][401];//level, hp, mhp
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int L, HP, MHP, MDMG;
    cin>>L>>HP>>MHP>>MDMG;
    vector<pair<int, int> > lv_table(L+5);
    for(int i=0;i<L;i++){
        cin>>lv_table[i].first>>lv_table[i].second;
        //first = dmg, second = hl(amount of hp that can be healed)
    }
    checked[0][HP][MHP] = true;
    queue<state> q;
    q.push(state(HP, MHP, 0, 0));
    int min_step = 1e9;
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        //attack
        if(cur.mhp-lv_table[cur.lv].first<=0){//win
            cout<<cur.step+1<<endl; 
            return 0;
        }else if(cur.hp-MDMG>0 && !checked[cur.lv][cur.hp-MDMG][cur.mhp-lv_table[cur.lv].first]){//if doesn't die && not checked
            q.push(state(cur.hp-MDMG, cur.mhp-lv_table[cur.lv].first, cur.lv, cur.step+1));
            checked[cur.lv][cur.hp-MDMG][cur.mhp-lv_table[cur.lv].first] = true;
        }

        //heal
        int temp_hp = min(cur.hp+lv_table[cur.lv].second, HP);
        temp_hp -= MDMG;
        if(temp_hp>0 && !checked[cur.lv][temp_hp][cur.mhp]){// still alive && not checked
            if(cur.step+1<min_step) q.push(state(temp_hp, cur.mhp, cur.lv, cur.step+1));
            checked[cur.lv][temp_hp][cur.mhp] = true;
        }

        //level up
        if(cur.lv+1<L&&cur.hp-MDMG>0&&!checked[cur.lv+1][cur.hp-MDMG][cur.mhp]){//doens't exceed level limit && still alive && not checked
            if(cur.step+1<min_step) q.push(state(cur.hp-MDMG, cur.mhp, cur.lv+1, cur.step+1));
            checked[cur.lv+1][cur.hp-MDMG][cur.mhp] = true;
        }
    }
    cout<<-1<<endl;
}