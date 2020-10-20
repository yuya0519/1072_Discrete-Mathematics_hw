# 1072_Discrete-Mathematics_hw 
## 主要目標:   
實作 Depth-First Search algrithm 

## 程式運行方式:   

**該程式執行軟體為Visual 2019。**   
請將程式碼複製至上述軟體中，再編譯執行。     

## 簡要使用說明:  
- Input: 第一行為測資個數，接著每筆測資開頭先是點數 N，緊接著是邊數|E|，接著|E|對相連的點。
> 輸入範例  
![avatar](https://upload.cc/i1/2020/10/20/8tFcPI.jpg)

- Output: 判斷該圖是否每一點都有連接，有就輸出"connected"，無則輸出"disconnected"。  
> 輸出範例  
![avatar](https://upload.cc/i1/2020/10/20/Lem4wx.jpg)  

## 程式結構說明:  

### 基本原理:  
運用DFS演算法去嘗試走訪所有的邊，如果有走訪過的點標記已走過，最後檢查是否有未走過的點，如果有就為"disconnected"，反之則為"connected"。

![avatar](https://upload.cc/i1/2020/05/21/l6H1Bb.jpg
)
### 引用函式庫說明:
```cpp
#include<iostream> //負責輸出/輸入
```

### Global變數說明:
```cpp
int cases; //存放測資個數 
```
```cpp
int*answer //存放最後要輸出的答案  
```
```cpp
int point; //存放點數
```
```cpp
int line; //存放邊數
```
```cpp
int p, q; //存放當下走的點
```
```cpp
bool abu = true; //存放是否為connected
```
```cpp
int*check; //存放該點是否走過
```
```cpp
int**link; //存放該點是否有連接
```
### 詳細程式碼說明

```cpp
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
```
> 將輸入都讀入，並且創建好將用到的變數，
> 並將所有相連的點的link標記為1。
```cpp
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
	}
```
> 呼叫函數計算，
> 檢查所有點是否走過，並將結果存入 answer中，
> 清除記憶體。
```cpp
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
```
> 輸出結果
```cpp
void DFS(int**link,int* check, int n,int p)
{
	for(int i=0;i< p;i++){
		if (link[n][i] == 1 && check[i]!=0) {
			check[i] = 0;
			DFS(link, check, i,p);	
		}
	}
}
```
> 實作 DFS演算法走過所有能走的點，並且標記
