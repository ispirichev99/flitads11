#include<stdio.h>
#include <windows.h>
#define MAX_NUMBER_VERTICES (20) //максимальное количество вершин в графе
#define FILE_OUTPUT_VISUAL "graphf.dot"

#pragma warning(disable : 4996)


typedef struct {
	int graph_classification;//0 -ориентированны 1- неориентированны
	int adjacency_matrix[MAX_NUMBER_VERTICES][MAX_NUMBER_VERTICES];//матрица смежности
	int number_vertices;//количество вершин в графе
}Graph;

void make_Graph(Graph* Gr, int vertices);//ввод графа
void make_visual_file(Graph Gr, const char* file_name);//создание файла визуализации графа

int main() {
	Graph Gr;//переменная граф
	make_Graph(&Gr, 4);//создаем граф у которого 4 вершины
	make_visual_file(Gr, FILE_OUTPUT_VISUAL);//создаем файл визуализации графа
	remove("g.png");
	system("C:\\Users\\Anir\\Desktop\\LR_Graph\\dot.exe graphf.dot -Tpng -oC:\\Users\\Anir\\Desktop\\LR_Graph\\g.png");//сдесь прописываем полный путь к dot.ехе
	system("C:\\Users\\Anir\\Desktop\\LR_Graph\\g.png");//и к файлу g.png
}

void make_Graph(Graph* Gr, int vertices) {//ввод графа
	int i, j;// переменые для прохода по матрицы смежности
	Gr->number_vertices = vertices;//устанавливаем количество вершин в графе
	printf("Classification: 0-oriented /1- non-oriented? :");
	scanf("%d", &Gr->graph_classification);//ввод класификации графа(0- ориентированый /1- неориентированый)

	printf("\nEnter the adjacency matrix for the graph :\n");
	for (i = 0; i < Gr->number_vertices; i++) {
		for (j = 0; j < Gr->number_vertices; j++) {
			scanf("%d", &Gr->adjacency_matrix[i][j]);//ввод матрицы смежности
		}
	}
	printf("\nGraph Make!\n");//вывод сообщения что граф введен
};

void make_visual_file(Graph Gr, const char* file_name) {//создание файла визуализации файла на языке DOT
	FILE *f_out;//файловая переменная
	int i, j;
	f_out = fopen(file_name, "w");//создаем файл
	if (!f_out) {//проверяем что файл создан, если нет
		printf("\nError make file:%s\n", file_name);//выводим сообщение о ошибке
		return;//выход из ф-ции
	}
	if (Gr.graph_classification) {
		fprintf(f_out, "strict graph G{ \n");//выводим в файл конструкцию субграфа
	}
	else
		fprintf(f_out, "digraph G{ \n");//выводим в файл конструкцию субграфа
	for (i = 0; i< Gr.number_vertices; i++) {//проход по матрицы смежности
		fprintf(f_out, "%d;\n", i); ///////////////вывод вершины в файл
		for (j = 0; j < Gr.number_vertices; j++) {
			if (Gr.adjacency_matrix[i][j]) {//если есть связь  между вершинами (то в столбце значение 1)
				if (!Gr.graph_classification) {//в зависимости от класификации графа
					fprintf(f_out, "%d -> %d;\n", i, j);
				}
				else {
					fprintf(f_out, "%d -- %d;\n", i, j);//вывод для неориентированого
				}
			}

		}
	}
	fprintf(f_out, "}\n ");//закрывающая конструкция для субграфа
	fclose(f_out);//закрыие файловой переменой

};