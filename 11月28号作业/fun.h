#pragma once
#include<iostream>
using namespace std;
#define MaxInt 0
#define MVNum 100
typedef char VerTexType;  //顶点的数据为字符型
typedef int ArcType;  //权值类型为int型

typedef struct {
	int base[100];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue &Q) {
	Q.front = 0;
	Q.rear = 0;
}

void EnQueue(SqQueue& Q,int e) {
	Q.base[Q.rear] = e;
	Q.rear += 1;
}

int DeQueue(SqQueue& Q) {
	int e;
	e = Q.base[Q.front];
	Q.front += 1;
	return e;
}

void TravelQueue(SqQueue Q) {
	for (int i =Q.front; i < Q.rear; i++) {
		cout << Q.base[i] << " ";
	}
}

bool QueueEmpty(SqQueue Q) {
	if (Q.front = Q.rear) {
		return false;
	}
	else {
		return true;
	}
}

typedef struct {
	VerTexType vexs[MVNum]; //顶点数组
	ArcType arcs[MVNum][MVNum]; //邻接矩阵
	int vexnum, arcnum;
}AMGraph;

int LocateVex(AMGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}

void CreateUDN(AMGraph& G) {
	cout << "输入顶点数和边数：";
	cin >> G.vexnum >> G.arcnum;

	cout << "依次输入顶点字符：";
	for (int i = 0; i < G.vexnum; i++) {//输入vexs数组数据，即顶点的数据字符
		cin >> G.vexs[i];
	}

	for (int i = 0; i < G.vexnum; i++) {//先把arcs数组初始化为最大值
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}

	cout << "输入一条边依附的顶点和权值：" << endl;
	for (int k = 0; k < G.arcnum; k++) {//构造邻接矩阵
		VerTexType v1, v2;
		
		cin >> v1 >> v2;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = G.arcs[i][j];
	}
}

void TraveralAMGraph(AMGraph G) {
	cout << "输出邻接矩阵的各行各列：" << endl;
	cout << '\t';
	for (int i = 0; i < G.vexnum; i++) {
		cout << '\t' << G.vexs[i];
	}
	cout << endl << endl << endl << endl;

	for (int i = 0; i < G.vexnum; i++) {
		cout << '\t' << G.vexs[i];
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] != 0) {
				cout << '\t' << G.arcs[i][j];
			}
			else {
				cout << '\t' << "0";
			}
		}
		cout << endl << endl << endl << endl;
	}
}
bool visited1[MVNum];
void DFS_AM(AMGraph G, int v) {//从第v个顶点出发遍历
	cout << G.vexs[v] << " ";
	visited1[v] = true;
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != 0) && (!visited1[w])) {
			DFS_AM(G, w);
		}
	}
}

int NextAdjVex(AMGraph G, int v, int w) {//返回v相对于w的下一个邻接点
	for (int i = w; i < G.vexnum; i++) {
		if ((G.arcs[v][i] != 0) && (visited1[i] == false)) {
			return i;
		}
	}
	return -1;
}

int visited2[100];
void BFsTraverse(AMGraph G){
	SqQueue q;
	InitQueue(q);

	EnQueue(q, 0);
	visited2[0] = true;

	
	int v, n = 0, i = 0;
	while (q.rear - q.front != G.vexnum) {
		for (int j = 0; j < G.vexnum; j++) {
			if ((G.arcs[i][j] != 0) && (visited2[j] == false)) {
				/*v = DeQueue(q);
				cout << G.vexs[v] << " ";*/
				EnQueue(q, j);
				visited2[j] = true;
			}
		}
		i=q.base[n];
		n++;
	}


	for (int i = q.front; i < q.rear; i++) {
		cout << G.vexs[q.base[i]] << " ";
	}
}