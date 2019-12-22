#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;

//ф-ция обхода в глубину
void dfs(int v,int size,int **gr, bool *& visited)
{
	if (visited[v]) {//если вершина пройдена, то пути из вершины нет
		return;
	}
	visited[v] = true;//отмечайм проуденой
	for (int i = 0; i < size; i++)//цикл по матрицы смежности
		if (gr[v][i])//если есть ребро
			dfs(i,size,gr,visited);//вызываем ф-цию обхода в глубину
}


int main()
{
	int n;//размер матрицы смежности
	int** matrix_smeg;//матрица смежности
	bool* visited;//пройденые вершины
	bool flag = true;//переменная связаности графа (истина если граф связан)
	setlocale(0, "");
	cout << "Введите размер матрицы смежности: ";
	cin >> n;
//выделяем память
	matrix_smeg = new int* [n];
	visited = new bool[n];
	cout << "Введите матрицу смежности:\n";
	for (int i = 0; i < n; i++) {
		matrix_smeg[i] = new int[n];
		visited[i] = false;//заполняем что вершины не пройдены
		for (int j = 0; j < n; j++) {
			cin >> matrix_smeg[i][j];//вводим матрицу смежности
		}
	}

	dfs(0,n, matrix_smeg, visited);//вызываем ф-цию обхода в глубину с первой вершины
	for (int i = 0; i < n; i++)//цикл по пройденым вершинам графа
		if (!visited[i])//если вершина не пройдена, то граф не является  связаным
		{
			if (flag) {
				cout << "\nГраф не является  связаным, не связаные вершины: ";
			}
			flag = false;//устанавливаем флаг что граф не связан
			cout << " " << i + 1;			//выводим не связаные вершины
		}
	cout << endl;
///Граф является  связаным
	if (flag) {
		cout << "\nГраф  является  связаным\n";
	}
	system("pause");
//освобождаем память
	for (int i = 0; i < n; i++)
		delete[] matrix_smeg[i];
	delete[] matrix_smeg;
	delete[] visited;
	return 1;
}