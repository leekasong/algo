#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Info{
	int bo[4];
	int v;
	int visit;
};

struct Pos{
	int x,y;
	Info *pInfo;
};

const int distx[4] = {1,0,-1,0};
const int disty[4] = {0,-1,0,1};

Info map[100][100];
int ans = 0;
int N,L,R;

int abs(int a, int b) { return a > b ? a-b : b-a;}

void clear(){
	for(int r = 0; r < N; r++){
		for(int c= 0; c < N; c++){
			memset(map[r][c].bo, 0, sizeof(int)*4);
			map[r][c].visit = 0;
		}
	}
}

void find(){
	for(int r = 0; r < N; r++){
		for(int c = 0; c < N; c++){
			for(int i = 0; i < 4; i++){
				int nx = c + distx[i];
				int ny = r + disty[i];
				if(nx>=0 && ny >= 0 && nx < N && ny < N){
					int diff = abs(map[ny][nx].v, map[r][c].v);
					if(diff>=L && diff <= R){
						map[r][c].bo[i] = 1;
					}
				}
			}
		}
	}
}

int bfs(int sx, int sy){
	int sum = 0, cnt = 0;
	queue<Pos> q;
	vector<Pos> list;

	map[sy][sx].visit = 1;
	q.push({sx,sy,&map[sy][sx]});

	while(!q.empty()){
		Pos pos = q.front(); q.pop();
		sum += map[sy][sx].v;
		cnt += 1;
		list.push_back({sx,sy,0});
		for(int i = 0; i < 4; i++){
			if(pos.pInfo->bo[i]){
				int nx = pos.x + distx[i];
				int ny = pos.y + disty[i];
				if(nx >= 0 && ny >= 0 && nx < N && ny < N && map[ny][nx].visit == 0){
					map[ny][nx].visit = 1;
					Pos npos = {nx,ny,&map[ny][nx]};
					q.push(npos);
				}
			}
		}
	}

	int lsize = list.size();
	if(lsize <= 1) return -1;

	ans++;
	for(int i = 0; i <lsize; i++){
		int tx = list[i].x, ty = list[i].y;
		map[ty][tx].v = sum / cnt;
	}

	return 0;
}

int recal(){
	int flag= 1;
	for(int r = 0; r < N; r++){
		for(int c = 0; c < N; c++){
			if(map[r][c].visit == 0){
				if(0 == bfs(r,c)) flag = 0;
			}
		}
	}
	return flag;
}


void run(){
	int complete = 0;
	while(!complete){
		clear();
		find();
		complete = recal();
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &N, &L, &R);
	for(int r = 0; r < N; r++){
		for(int c = 0; c < N; c++){
			scanf("%d", &map[r][c].v);
		}
	}
	
	run();
	printf("%d\n", ans);

	return 0;
}
