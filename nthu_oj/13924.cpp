#include<bits/stdc++.h>
using namespace std;
int N,M; // N: number of groups, M: number of table types
typedef struct group_state{
    group_state(int people, int arrive_time, int duration, int id):
        people(people),arrive_time(arrive_time),duration(duration),id(id){}
    int people;
    int arrive_time;
    int duration;
    int id;
} group_state;
struct cmp{
    auto operator()(const group_state &a, const group_state &b) const{
        return a.arrive_time < b.arrive_time;//
    }
};
auto cmp2 = [](const group_state &a, const group_state &b){
    //sort by group size from small to large
    //if the group sizes are the same, sort by arrival time
    //from late to early
    //if the first group on the waiting list can't be seated
    //use upper_bound to find the first group with the size that is larger than the largest table available
    //then choose the group before it
    //then it's the group with the largest group size 
    //and the ealiest arrival time among the groups that has the same groups size.
    //and the group can be seated with the largest table available
    if(a.people!=b.people){
        return a.people < b.people;//large to small
    }else{
        return a.arrive_time > b.arrive_time;//late to early
    }
};
set<group_state, cmp> waiting_groups_time;// sort by arrival time
set<group_state, decltype(cmp2)> waiting_groups_size(cmp2);// sort by group size 
map<int, int> aval_table_cnt; // number of available tables for each table size size:cnt
multiset<pair<int, int>> table_in_use; // {release time: table size}
int ans[200005];
//sort by end time->table_in_use.begin().first=the first release time
void assignTable(int time){//assign table at 'time'
    while(!aval_table_cnt.empty()&&!waiting_groups_size.empty()){
        //repeatedly assigning
        group_state TargetGroup = *waiting_groups_time.begin();
        auto TargetTable = aval_table_cnt.lower_bound(TargetGroup.people);
        auto MaxTable = aval_table_cnt.rbegin();
        if(TargetTable!=aval_table_cnt.end()){//found smth
            //assgning to the first group
            //cout<<"Assigning Group:"<<TargetGroup.id<<"to table with size of"<<TargetTable->first<<'\n';
            ans[TargetGroup.id] = time;

            waiting_groups_size.erase(TargetGroup);
            waiting_groups_time.erase(TargetGroup);
            //target table is an iterator of the map, first: size, second: count
            table_in_use.insert({time+TargetGroup.duration, TargetTable->first});

            TargetTable->second--;
            if(TargetTable->second==0) aval_table_cnt.erase(TargetTable);
        }else{
            //find other group
            int largest_avl_table_size = MaxTable->first;
            auto it = waiting_groups_size.upper_bound(group_state(largest_avl_table_size,-1,0,0));
            if(it == waiting_groups_size.begin()){
                break;
            }
            TargetGroup = *(--it);
            TargetTable = aval_table_cnt.lower_bound(TargetGroup.people);
            //cout<<"Assigning Group:"<<TargetGroup.id<<"to table with size of"<<TargetTable->first<<'\n';
            ans[TargetGroup.id] = time;

            waiting_groups_size.erase(TargetGroup);
            waiting_groups_time.erase(TargetGroup);
            //target table is an iterator of the map, first: size, second: count
            table_in_use.insert({time+TargetGroup.duration, TargetTable->first});

            TargetTable->second--;
            if(TargetTable->second==0) aval_table_cnt.erase(TargetTable);
        }
    }
}
void releaseTable(int time){//release all table that end before 'time'
    while(!table_in_use.empty()&&table_in_use.begin()->first<=time){
        aval_table_cnt[table_in_use.begin()->second]++;
        int release_time = table_in_use.begin()->first;
        table_in_use.erase(table_in_use.begin());
        assignTable(release_time);
    }
}
int main(){
    cin>>N>>M;
    vector<group_state> group_list;
    for(int i=0;i<N;i++){
        int arrive_time, people, duration;
        cin>>arrive_time>>people>>duration;
        group_list.push_back(group_state(people, arrive_time, duration, i));
    }
    for(int i=0;i<M;i++){
        int size, number;
        cin>>size>>number;
        aval_table_cnt[size] = number;
    }
    for(int i=0;i<N;i++){   
        releaseTable(group_list[i].arrive_time-1);
        waiting_groups_size.insert(group_list[i]);
        waiting_groups_time.insert(group_list[i]);
        releaseTable(group_list[i].arrive_time);
        assignTable(group_list[i].arrive_time);
    }
    while(!waiting_groups_size.empty()){
        releaseTable(1e9);
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]<<'\n';
    }
}