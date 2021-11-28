#include<iostream>
#include"fun.h"

int main() {

	AMGraph ag;
	CreateUDN(ag);

	TraveralAMGraph(ag);

	//BFsTraverse(ag);

	cout << "请输入从第几个顶点遍历：";
	int index;
	cin >> index;
	DFS_AM(ag, index);

	return 0;
}