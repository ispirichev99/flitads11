#include <stdio.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)
#define SET_MAX (255)//макимальный размер множества

typedef struct Set {//тип можество
	char data[SET_MAX];//элементы множества
	int count;//количество эл. в множестве
} SET;

void make(SET *St, char *str);//создание множества
void printf_set(SET St);//вывод множества
void add_set(SET *St, char ch);//добовление в множество
void delete_set(SET *St, char ch);//удаление из множества
int contains(SET St, char ch);//проверка входит и элемент в множество

int main() {
	SET stack1, stack2;//обьявление 2 множеств
	char buf[40];
	char ch;
	//создание мнлжеств
	printf("Input SET #1: ");
	scanf("%s", buf);
	while (getchar() != '\n');
	make(&stack1, buf);

	printf("Input SET #2: ");
	scanf("%s", buf);
	while (getchar() != '\n');
	make(&stack2, buf);


	//добавление в множества
	printf("Input element add SET#1: ");
	scanf("%c", &ch);
	while (getchar() != '\n');
	add_set(&stack1, ch);
	printf("\nInput element add SET#2: ");
	scanf("%c", &ch);
	while (getchar() != '\n');
	add_set(&stack2, ch);


	printf("\nSet #1: \n");
	printf_set(stack1);

	printf("Set #2: \n");
	printf_set(stack2);
	//удаление из множеств
	printf("Input element delete SET#1: ");
	scanf("%c", &ch);
	while (getchar() != '\n');

	delete_set(&stack1, ch);
	printf("\nInput element delete SET#2: ");
	scanf("%c", &ch);
	while (getchar() != '\n');
	delete_set(&stack2, ch);

	printf("\nSet #1: \n");
	printf_set(stack1);

	printf("Set #2: \n");
	printf_set(stack2);
	getch();
	return 0;
}

void make(SET *St, char *str) {//создание множеств
	int i;
	St->count = 0;//устанавливаем что множество пустое
	for (i = 0; i<strlen(str); i++) {//цикл по количеству эл. множества
		if (!contains(*St, str[i])) {//если эл. нет в множестве
			++St->count;//увеличиваем количество эл. множества на 1
			St->data[St->count - 1] = str[i];//добовляем эл. в множество
		}
	}
};

void printf_set(SET St) {//вывод мн-ва
	int i;
	for (i = 0; i<St.count; i++) {//цикл по эл. мн-ва
		printf("%c ", St.data[i]);//вывод эл. мн-ва
	}
	printf("\n");
};

void add_set(SET *St, char ch) {//добавление в мн-во
	if (contains(*St, ch) == 0) {//проверка что эл. нет в множестве
		++St->count;//увеличиваем счетчик
		St->data[St->count - 1] = ch;//заносим эл. в множество
	}
};
void delete_set(SET *St, char ch) {// удаление из множества
	int idx = -1, i;
	for (i = 0; i<St->count; i++) {//проход по множеству
		if (St->data[i] == ch) {//если ел. найден
			idx = i;//запомонаем его
			break;//выходим из цикла
		}
	}
	if (idx>-1) {//если idx больше -1 , то эл. был найден, иначе эл. нет вможестве
		for (i = idx; i < St->count - 1; i++) {//проход по множеству начиная с найденого элемента
			St->data[i] = St->data[i + 1];//циклически сдвигаем элементы в лево
		}
		--St->count;//уменьшаем счетчик элементов множества
	}
};

int contains(SET St, char ch) {//проверка на пренодлежность элемента множеству
	int i;
	for (i = 0; i<St.count; i++) {//цикл по элементам множества
		if (St.data[i] == ch) {//если элемент найден
			return 1;//возращаем результат функции 1
		}
	}
	return 0;//иначе возвращаем результат функции 0
};
