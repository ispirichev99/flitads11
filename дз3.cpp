#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;

//�-��� ������ � �������
void dfs(int v,int size,int **gr, bool *& visited)
{
	if (visited[v]) {//���� ������� ��������, �� ���� �� ������� ���
		return;
	}
	visited[v] = true;//�������� ���������
	for (int i = 0; i < size; i++)//���� �� ������� ���������
		if (gr[v][i])//���� ���� �����
			dfs(i,size,gr,visited);//�������� �-��� ������ � �������
}


int main()
{
	int n;//������ ������� ���������
	int** matrix_smeg;//������� ���������
	bool* visited;//��������� �������
	bool flag = true;//���������� ���������� ����� (������ ���� ���� ������)
	setlocale(0, "");
	cout << "������� ������ ������� ���������: ";
	cin >> n;
//�������� ������
	matrix_smeg = new int* [n];
	visited = new bool[n];
	cout << "������� ������� ���������:\n";
	for (int i = 0; i < n; i++) {
		matrix_smeg[i] = new int[n];
		visited[i] = false;//��������� ��� ������� �� ��������
		for (int j = 0; j < n; j++) {
			cin >> matrix_smeg[i][j];//������ ������� ���������
		}
	}

	dfs(0,n, matrix_smeg, visited);//�������� �-��� ������ � ������� � ������ �������
	for (int i = 0; i < n; i++)//���� �� ��������� �������� �����
		if (!visited[i])//���� ������� �� ��������, �� ���� �� ��������  ��������
		{
			if (flag) {
				cout << "\n���� �� ��������  ��������, �� �������� �������: ";
			}
			flag = false;//������������� ���� ��� ���� �� ������
			cout << " " << i + 1;			//������� �� �������� �������
		}
	cout << endl;
///���� ��������  ��������
	if (flag) {
		cout << "\n����  ��������  ��������\n";
	}
	system("pause");
//����������� ������
	for (int i = 0; i < n; i++)
		delete[] matrix_smeg[i];
	delete[] matrix_smeg;
	delete[] visited;
	return 1;
}