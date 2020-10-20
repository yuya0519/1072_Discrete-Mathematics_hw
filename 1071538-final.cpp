#include<iostream>
using namespace std;

void DFS(int**link , int*ckeck, int n ,int p);
int main()
{
	int cases;
	cin >> cases;
	int*answer = new int[cases];
	for(int i=0;i<cases;i++){		
		int point;
		int line;
		cin >> point >> line;
		int p, q;
		bool abu = true;
		int*check = new int[point];
		for (int j = 0; j < point; j++)
			check[j] = 1;
		int**link = new int*[point];
		int *ptoq = new int[line + 1];
		for (int j = 0; j < point; j++) 
			link[j] = new int[point];
		for (int j = 0; j < point; j++)
			for (int k = 0; k < point; k++)
				link[j][k] = -1;
		for (int j = 0; j < line; j++) {
			cin >> p >> q;
			link[p][q] = 1;
			link[q][p] = 1;
		}
		DFS(link, check, 0 , point);
		for (int j = 0; j < point; j++) 
			if (check[j] != 0){
				abu = false;
				break;
			}
		if (abu == true)
			answer[i] = 1;
		else
			answer[i] = 0;	
		delete[]check;
		delete[]link;
		delete[]ptoq;
	}
	cout << endl << endl;
	for (int i = 0; i < cases; i++) {
		if (answer[i] == 1)
			cout << "connected" << endl;
		else
			cout << "disconnected" << endl;
	}
	cout << endl;
	system("pause");
}
void DFS(int**link,int* check, int n,int p)
{
	for(int i=0;i< p;i++){
		if (link[n][i] == 1 && check[i]!=0) {
			check[i] = 0;
			DFS(link, check, i,p);	
		}
	}
}