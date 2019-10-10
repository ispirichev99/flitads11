#include <stdio.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)
#define SET_MAX (255)//����������� ������ ���������

typedef struct Set {//��� ��������
	char data[SET_MAX];//�������� ���������
	int count;//���������� ��. � ���������
} SET;

void make(SET *St, char *str);//�������� ���������
void printf_set(SET St);//����� ���������
void add_set(SET *St, char ch);//���������� � ���������
void delete_set(SET *St, char ch);//�������� �� ���������
int contains(SET St, char ch);//�������� ������ � ������� � ���������

int main() {
	SET stack1, stack2;//���������� 2 ��������
	char buf[40];
	char ch;
	//�������� ��������
	printf("Input SET #1: ");
	scanf("%s", buf);
	while (getchar() != '\n');
	make(&stack1, buf);

	printf("Input SET #2: ");
	scanf("%s", buf);
	while (getchar() != '\n');
	make(&stack2, buf);


	//���������� � ���������
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
	//�������� �� ��������
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

void make(SET *St, char *str) {//�������� ��������
	int i;
	St->count = 0;//������������� ��� ��������� ������
	for (i = 0; i<strlen(str); i++) {//���� �� ���������� ��. ���������
		if (!contains(*St, str[i])) {//���� ��. ��� � ���������
			++St->count;//����������� ���������� ��. ��������� �� 1
			St->data[St->count - 1] = str[i];//��������� ��. � ���������
		}
	}
};

void printf_set(SET St) {//����� ��-��
	int i;
	for (i = 0; i<St.count; i++) {//���� �� ��. ��-��
		printf("%c ", St.data[i]);//����� ��. ��-��
	}
	printf("\n");
};

void add_set(SET *St, char ch) {//���������� � ��-��
	if (contains(*St, ch) == 0) {//�������� ��� ��. ��� � ���������
		++St->count;//����������� �������
		St->data[St->count - 1] = ch;//������� ��. � ���������
	}
};
void delete_set(SET *St, char ch) {// �������� �� ���������
	int idx = -1, i;
	for (i = 0; i<St->count; i++) {//������ �� ���������
		if (St->data[i] == ch) {//���� ��. ������
			idx = i;//���������� ���
			break;//������� �� �����
		}
	}
	if (idx>-1) {//���� idx ������ -1 , �� ��. ��� ������, ����� ��. ��� ���������
		for (i = idx; i < St->count - 1; i++) {//������ �� ��������� ������� � ��������� ��������
			St->data[i] = St->data[i + 1];//���������� �������� �������� � ����
		}
		--St->count;//��������� ������� ��������� ���������
	}
};

int contains(SET St, char ch) {//�������� �� �������������� �������� ���������
	int i;
	for (i = 0; i<St.count; i++) {//���� �� ��������� ���������
		if (St.data[i] == ch) {//���� ������� ������
			return 1;//��������� ��������� ������� 1
		}
	}
	return 0;//����� ���������� ��������� ������� 0
};