#include<iostream>
#include<utility>
#include<queue>
#define yosoro ios_base::sync_with_stdio(false)
using namespace std;
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};
char world[1000][1000];
int step[1000][1000];
int main(){
	yosoro;
	int width,obstacle;
	cin>>width>>obstacle;
	for(int i=0;i<obstacle;i++){
		int a,b;
		cin>>a>>b;
		world[a-1][b-1]='X';
	}
	for(int i=0;i<width;i++){
		for(int j=0;j<width;j++){
			step[i][j]=-1;
		}	
	}
	int row,col,red_row,red_col;
	cin>>row>>col>>red_row>>red_col;
	red_row--;red_col--;
	queue< pair<int, int> > q;
	step[row-1][col-1]=0;
	pair<int,int> start =make_pair(row-1, col-1);
	q.push(start);
	bool find=0;
	while(!q.empty()){
		pair<int, int> now= q.front();
		q.pop();
		row=now.first;
		col=now.second;
		if(row==red_row&&col==red_col){
			find = true;
			break;
		}
		for(int i=0;i<4;i++){
			int new_row=row+dx[i];
			int new_col=col+dy[i];
			if(new_row<0||new_row>=width||new_col<0||new_col>=width) continue;
   	 		if(world[new_row][new_col]=='X') continue;
    		if(step[new_row][new_col]!=-1) continue;
  			step[new_row][new_col]=step[row][col]+1;
  			pair<int, int> next=make_pair(new_row, new_col);
       		q.push(next);
		}
	}
	if(find==true){
		cout<<step[red_row][red_col];
	}
	else{
		cout<<-1;
	}
}
