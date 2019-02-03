#include<iostream>
#include<queue>
using namespace std;
#define n 5
#define m 5
/***********************
using breadth first search 
s represent source
d represent destination
* represent empty space
0 represent obstacle
************************/
//  to get current position and distance from souce location
class CurPos{
    public:
	int row;
	int column;
	int dist;		// distance from source
	CurPos(int r,int c,int d){ row=r; column=c; dist=d;	}
};
int minDistance(char grid[n][m])
{
	CurPos source(0,0,0);
	// keeping track of visited blocks
	bool visited[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='0')
				visited[i][j]=true;				// occupied
			else
				visited[i][j]=false;
				
			// finding source
			if(grid[i][j]=='s'){
				source.row=i;
				source.column=j;
			}
		}
	}
	// queue to go through all possible path (not visited) 
	//applying bsf to matrix cells starting from source
	// queue element marked as visited 
	// ******queue is having coordinates of curPos and distance to source****** 
	queue<CurPos> q;
	q.push(source);
	visited[source.row][source.column]=true;
	while(q.empty()==0){
		// each iteration new object is defined of curPos.
		// dist data member will increase by one for each iteration to get shortest path
		// number of iterations is solution for shortest distance.
		CurPos p=q.front();		// updating current position of source p object to move through diff. location.
		q.pop();
		
		// destination found
		if(grid[p.row][p.column]=='d')
			return p.dist;
			
		// moving up
		if(p.row-1>=0 && visited[p.row-1][p.column]==false){
			q.push(CurPos(p.row-1,p.column,p.dist+1));
			visited[p.row-1][p.column]=true;
		}
		// down
		if(p.row+1<n && visited[p.row+1][p.column]==false){
			q.push(CurPos(p.row+1,p.column,p.dist+1));
			visited[p.row+1][p.column]=true;
		}
		// left
		if(p.column-1>=0 && visited[p.row][p.column-1]==false){
			q.push(CurPos(p.row,p.column-1,p.dist+1));
			visited[p.row][p.column-1]=true;
		}
		// right
		if(p.column+1<m && visited[p.row][p.column+1]==false){
			q.push(CurPos(p.row,p.column+1,p.dist+1));
			visited[p.row][p.column+1]=true;
		}
	}
	return -1;
}
int main()
{
	char mat[n][m]={
					{'0','*','0','s','*'},
					{'*','0','*','*','*'},
					{'0','*','0','*','*'},
					{'0','*','0','*','*'},
					{'d','*','*','*','*'} 
					};
	cout<<minDistance(mat);	
}
