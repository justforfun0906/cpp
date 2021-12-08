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
vector<int> pre(10001); //�������`�I�A�p�G�ۤv�����`�I�A�h�O���Ӥl�𪺤j�p�A�b�]��get_pre()����h�|�q�q���V�ڸ`�I 
bool cmp(edge a, edge b){
	return a.weight < b.weight;//�Ψ�sort�䪺�v���A�Ѥp��j�ƧǡC 
}
int get_pre(int a){
	int temp=a, ro;
	while(pre[temp]>=0){ // �Y�������ڸ`�I�hpre[temp]�|�O��-(�Ӿ𪺤j�p) 
		temp=pre[temp];//���W��ڸ`�I 
	}	
	//�{�b��temp��a���ڵ��I�F 
	while(a!=temp){//�N���|�����C��pre[]���q���`�I�令�ڵ��I�C 
		ro=pre[a];
		pre[a]=temp;
		a=ro; //���W��@�h�~���s	
	}
	return temp; //�^�Ǯڵ��I 
}
int main(){
	faster;
	int n,m;
	while(cin>>n>>m&&n!=0){
		edges.clear();
		for(int i=0;i<n;i++){
			pre[i]=-1; //��l�C���I�ۦ��@�ʤl�� 
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;
			b--;
			edge input={a, b, c};
			edges.push_back(input);//�䪺��J 
		}
		sort(edges.begin(),edges.end(),cmp);
		int sum=0, count=0; //count�O�p��X�֦��ơA���ӭn��n-1��
		for(int i=0;i<m;i++){//�}�l�X�֤l�� 
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

