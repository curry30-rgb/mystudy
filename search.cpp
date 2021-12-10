#include<iostream>
using namespace std;
typedef int KeyType;
#define SIZE_MAX 100

typedef struct {
	KeyType key;
}ElemType;

typedef struct {
	ElemType R[SIZE_MAX]; 
	int length;
}SSTable;

void Initkey(SSTable &ST) {//初始化
	int n;
	cout << "请输入要建几个数据：";
	cin >> n;
	cout << "请输入数据";
	for (int i = 0; i < n; i++) {
		cin >> ST.R[i].key;
	}
	cout << "初始化成功" << endl;
	ST.length = n;
}

int Search_Bin(SSTable ST,KeyType key) {//非递归
	int low = 0;
	int mid;
	int high = ST.length-1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == ST.R[mid].key) {
			return mid + 1;
		}
		else if (key < ST.R[mid].key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}	
	}
	if (low > high) {
		return -1;
	}
}

int BinarySearch(SSTable ST, KeyType key, int low, int high) {//递归
	int mid;
	if (low > high) {
		return -1;
	}
	else {
		mid = (low + high) / 2;
		if (key == ST.R[mid].key) {
			return mid + 1;
		}
		else if (key<ST.R[mid].key){
			return BinarySearch(ST, key, low, mid-1);
		}
		else {
			return BinarySearch(ST, key, mid + 1, high);
		}
	}
}

int main(){
	int key;
	SSTable st;
	Initkey(st);
	cout << "请输入要查找的数据：";
	cin >> key;

	cout << "非递归：" << endl;
	int index = Search_Bin(st, key);//非递归
	if (index == -1) {
		cout << "查找失败，没有该值！" << endl;
	}
	else {
		cout << "在第" << index <<"位" << endl;
	}
	
	/*cout << "递归：" << endl;
	int index = BinarySearch(st, key,0,st.length-1);//递归
	if (index == -1) {
		cout << "查找失败，没有该值！" << endl;
	}
	else {
		cout << "在第" << index << "位" << endl;
	}
	*/
	return 0;
}