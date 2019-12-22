#include<stdio.h>
#include <windows.h>
#define MAX_NUMBER_VERTICES (20) //������������ ���������� ������ � �����
#define FILE_OUTPUT_VISUAL "graphf.dot"

#pragma warning(disable : 4996)


typedef struct {
	int graph_classification;//0 -�������������� 1- ����������������
	int adjacency_matrix[MAX_NUMBER_VERTICES][MAX_NUMBER_VERTICES];//������� ���������
	int number_vertices;//���������� ������ � �����
}Graph;

void make_Graph(Graph* Gr, int vertices);//���� �����
void make_visual_file(Graph Gr, const char* file_name);//�������� ����� ������������ �����

int main() {
	Graph Gr;//���������� ����
	make_Graph(&Gr, 4);//������� ���� � �������� 4 �������
	make_visual_file(Gr, FILE_OUTPUT_VISUAL);//������� ���� ������������ �����
	remove("g.png");
	system("C:\\Users\\Anir\\Desktop\\LR_Graph\\dot.exe graphf.dot -Tpng -oC:\\Users\\Anir\\Desktop\\LR_Graph\\g.png");//����� ����������� ������ ���� � dot.���
	system("C:\\Users\\Anir\\Desktop\\LR_Graph\\g.png");//� � ����� g.png
}

void make_Graph(Graph* Gr, int vertices) {//���� �����
	int i, j;// ��������� ��� ������� �� ������� ���������
	Gr->number_vertices = vertices;//������������� ���������� ������ � �����
	printf("Classification: 0-oriented /1- non-oriented? :");
	scanf("%d", &Gr->graph_classification);//���� ������������ �����(0- �������������� /1- ����������������)

	printf("\nEnter the adjacency matrix for the graph :\n");
	for (i = 0; i < Gr->number_vertices; i++) {
		for (j = 0; j < Gr->number_vertices; j++) {
			scanf("%d", &Gr->adjacency_matrix[i][j]);//���� ������� ���������
		}
	}
	printf("\nGraph Make!\n");//����� ��������� ��� ���� ������
};

void make_visual_file(Graph Gr, const char* file_name) {//�������� ����� ������������ ����� �� ����� DOT
	FILE *f_out;//�������� ����������
	int i, j;
	f_out = fopen(file_name, "w");//������� ����
	if (!f_out) {//��������� ��� ���� ������, ���� ���
		printf("\nError make file:%s\n", file_name);//������� ��������� � ������
		return;//����� �� �-���
	}
	if (Gr.graph_classification) {
		fprintf(f_out, "strict graph G{ \n");//������� � ���� ����������� ��������
	}
	else
		fprintf(f_out, "digraph G{ \n");//������� � ���� ����������� ��������
	for (i = 0; i< Gr.number_vertices; i++) {//������ �� ������� ���������
		fprintf(f_out, "%d;\n", i); ///////////////����� ������� � ����
		for (j = 0; j < Gr.number_vertices; j++) {
			if (Gr.adjacency_matrix[i][j]) {//���� ���� �����  ����� ��������� (�� � ������� �������� 1)
				if (!Gr.graph_classification) {//� ����������� �� ������������ �����
					fprintf(f_out, "%d -> %d;\n", i, j);
				}
				else {
					fprintf(f_out, "%d -- %d;\n", i, j);//����� ��� �����������������
				}
			}

		}
	}
	fprintf(f_out, "}\n ");//����������� ����������� ��� ��������
	fclose(f_out);//������� �������� ���������

};