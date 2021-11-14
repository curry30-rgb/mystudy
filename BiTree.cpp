#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct BiTNode {
	char data;
	struct BiTNode* lch, * rch;
}BiTNode, *BiTree;

typedef struct {
	BiTNode* base;
	BiTNode* top;
	int stacksize;
}SqStack;

int InitStack(SqStack& S) {//初始化栈
	S.base = new BiTNode[MAXSIZE];
	if (!S.base) {
		return 0;
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 1;
}

bool StackEmpty(SqStack S) {//判断栈是否为空
	if (S.top == S.base) {
		return true;
	}
	else {
		return false;
	}
}

void Push(SqStack& S,BiTNode &e) {//入栈
	if (S.top - S.base == S.stacksize) {
		cout << "error" << endl;
	}
	*S.top++ = e;
}

void Pop(SqStack& S, BiTNode &e) {//出栈
	if (S.top == S.base) {
		cout << "error" << endl;
	}
	e = *--S.top;
}

void CreateBiTree(BiTree& T) {//创建二叉树
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lch);
		CreateBiTree(T->rch);
	}
}

void InOrderTraverse(BiTree T) {//递归实现中序遍历二叉树
	if (T) {
		InOrderTraverse(T->lch);
		cout << T->data;
		InOrderTraverse(T->rch);
	}
}


void InOrderTraverse2(BiTree T) {//栈实现中序遍历二叉树
	SqStack S;
	InitStack(S);

	BiTree p = T;
	BiTNode q;
	while(p||!StackEmpty(S)){
		if (p) {
			Push(S,*p);
			p = p->lch;
		}
		else {
			Pop(S, q);
			cout << q.data;
			p = q.rch;
		}
	}
}


int Depth(BiTree T) {//计算二叉树的深度
	int m, n;
	if (T == NULL) {
		return 0;
	}
	else {
		m = Depth(T->lch);
		n = Depth(T->rch);
		if (m > n) {
			return m + 1;
		}
		else {
			return n + 1;
		}
	}
}

int NodeCount(BiTree T) {//计算结点个数
	if (T == NULL) {
		return 0;
	}
	else {
		return NodeCount(T->lch) + NodeCount(T->rch) + 1;
	}
}

int main() {
	BiTree bt=NULL;
	cout << "请输入字符：";
	CreateBiTree(bt);
	cout << "栈实现中序遍历二叉树：";
	InOrderTraverse2(bt);

	cout << endl;
	cout << "改二叉树的深度为：" ;
	int deph = Depth(bt);
	cout << deph << endl;

	cout << "改二叉树的结点个数为：" ;
	int count = NodeCount(bt);
	cout << count << endl;
	//ABC##DE#G##F###
}