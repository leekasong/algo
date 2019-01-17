#include <cstdio>
#include <queue>
using namespace std;

struct Info{
	int bo[4];
	int v;
	int visit;
};

Info map[100][100];
int ans = 0;
int N,L,R;
int startPos = -1;
queue<Info> q, iq;

int abs(int a, int b) { return a > b ? a-b : b-a;}

void clear(){
	startPos = -1;
	q = iq;
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

void recal(){
	q.push(		
}


void run(){
	int complete = 0;
	while(!complete){
		clear();
		find();
		recal();
	}
}

int main(){
	scanf("%d%d%d", &N, &L, &R);
	for(int r = 0; r < N; r++){
		for(int c = 0; c < N; c++){
			scanf("%d", &map[r][c]);
		}
	}
	
	run();

	return 0;
}
