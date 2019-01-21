#include <iostream>
using namespace std;
typedef unsigned int uint;

struct Node{
	int v;
	int p;
};

uint N;
int root = 0, size = 0;
Node heap[100000];

void push(int v, int idx){


	if(heap[idx].v > v){
		push(v, heap[idx].p);
	}else{
		push(?.?);
	}

}

int top(){

}

void pop(){

}

int main(){
	cin >> N;

	while(N--){
		uint cmd;
		cin >> cmd;
		if(cmd != 0){

		}else{
			
		}
	}
	return 0;
}

