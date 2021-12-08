//code for fun
#include<iostream>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
typedef struct edge{
	int from;
	int to;
	int weight;
}edge;
vector<edge> edges;
vector<int> pre(10001); //紀錄父節點，如果自己為父節點，則記錄該子樹的大小，在跑完get_pre()之後則會通通指向根節點 
bool cmp(edge a, edge b){
	return a.weight < b.weight;//用來sort邊的權重，由小到大排序。 
}
int get_pre(int a){
	int temp=a, ro;
	while(pre[temp]>=0){ // 若本身為根節點則pre[temp]會記錄-(該樹的大小) 
		temp=pre[temp];//往上找根節點 
	}	
	//現在的temp為a的根結點了 
	while(a!=temp){//將路徑中的每個pre[]都從父節點改成根結點。 
		ro=pre[a];
		pre[a]=temp;
		a=ro; //往上找一層繼續更新	
	}
	return temp; //回傳根結點 
}
int main(){
	faster;
	int n,m;
	while(cin>>n>>m&&n!=0){
		edges.clear();
		for(int i=0;i<n;i++){
			pre[i]=-1; //初始每個點自成一棵子樹 
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;
			b--;
			edge input={a, b, c};
			edges.push_back(input);//邊的輸入 
		}
		sort(edges.begin(),edges.end(),cmp);
		int sum=0, count=0; //count是計算合併次數，應該要有n-1次
		for(int i=0;i<m;i++){//開始合併子樹 
			int aroot=get_pre(edges[i].from), broot=get_pre(edges[i].to);
        	if(aroot != broot){
                sum+=edges[i].weight;
                if(pre[aroot]<=pre[broot]){
                    pre[aroot]+=pre[broot];
                    pre[broot]=aroot;
                }
                else{
                    pre[broot]+=pre[aroot];
                    pre[aroot]=broot;
                }
                count++;
            }
		} 
		if(count==n-1)
            cout << sum << "\n";
        else
            cout << "-1\n"; 
	}	
}

