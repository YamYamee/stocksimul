#define _CRT_SECURE_NO_WARNINGS
#define cls system("cls")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//����ü�� ���ؼ� �ֽ��� ������ - �̸� � / ��/ ���� ����(?)
typedef struct stock {
	char name[20]; //�ֽ� �̸�
	int price; //�ְ�
	int number; //������ �ֽ��� ����
} Stock;

double arr_percent[4][4]; //���� ��� ������ �����ֱ� ���ؼ� ����ϴ� �迭
int stock_change_prediction[4];

Stock arr[4][4] =
{
		{
			{"�Ｚ����", 30000, 0},
			{"SK���̴н�",500000,0},
			{"LG����", 20000, 0 },
			{"�׳�����", 50000, 0}
		},
		{
			{"��������", 3000, 0},
			{"�������", 50000, 0},
			{"��������", 30000, 0 },
			{"�ȳ�����", 20000, 0}
		},
		{
			{"�����װ�", 35000, 0},
			{"�ѱ��Ѱ�", 25000,0},
			{"�����װ�", 23400, 0 },
			{"�����װ�", 12000, 0}
		},
		{
			{"�f�f�Ƿ�", 34500, 0},
			{"����Ű", 23400,0},
			{"�ظ�", 23200, 0 },
			{"�Ƶ𵵽�", 39000, 0}
		}
};

//��������
int total_property = 500000;
int initial_price = 500000;
int cash; //���� �ڻ길
int isTerminate = 0;
int isDayOver = 0;

//���� ��¥�� �ʰ��Ǵ��� ���ؾ���
int day = 1; //��¥ ���. 10�������� ����

//���� �������̽�. ���� ��¥�� ���, ������ �ڻ�, ������ �ֽ�, ���͵��� �����ְ� �ֽ� �ż� �ŵ� �ֽ� ��Ʈ�� �� �� ����
void main_interface();
//ȭ�� ��ȯ�� ����ϴ� �Լ�
void switch_interface();
//�ֽ��� �����ϴ� �Լ�
void purchase();
//�ֽ��� �Ǹ��ϴ� �Լ�
void sell();
//�ֽ��� ���� ��� ������ ���� ������ �����ִ� �Լ�
void show_stock();
//������ ���� ���� �̺�Ʈ�� �߻���Ű�� �Լ�
void news();

void predict_change_stock_price();
void adjust_change_stock_price();



void gotoxy(int x, int y) { //gotoxy�Լ� ȭ�鿡 ��µǴ� ������ ��ġ�� �ٲٴµ� ����
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{	
	while (day > 10) {
		predict_change_stock_price();
		while (!isDayOver) {
			main_interface();
			switch_interface();
		}
		adjust_change_stock_price();
		day++;
	}
}

void predict_change_stock_price() // �ְ��� ���� ��Ű�� �Լ�  1. ������ .... 2. a
{
	double price_change;
	for (int i = 0; i < 4; i++)
	{
		stock_change_prediction[4] = rand() % 2;
	}
	srand((unsigned int)time(NULL));
}

void adjust_change_stock_price() // �ְ��� ���� ��Ű�� �Լ�  1. ������ .... 2. a
{
	double price_change;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			price_change = ((double)(100 + ((rand() % 30) - 15)) / 100);
			arr_percent[i][j] = (price_change * 100) - 100;
			arr[i][j].price = arr[i][j].price * price_change;
		}
	}
	srand((unsigned int)time(NULL));
}

void main_interface()
{
	cls;

	gotoxy(10, 5); printf("1. �ֽ� �ż�");
	gotoxy(10, 6); printf("2. �ֽ� �ŵ�");
	gotoxy(10, 7); printf("3. �ְ� Ȯ��");
	gotoxy(10, 8); printf("4. ���� ����");

	gotoxy(20, 5); printf("���� �ֽ�:");
	gotoxy(20, 6); printf("���� �ڻ�: %d��", total_property);
	gotoxy(20, 7); printf("���ͷ�: %.2lf%%", (((double)(total_property - initial_price) / (initial_price) * 100)));
	gotoxy(20, 8); printf("%d���� \n", day);

}

void switch_interface()
{
	int key = 0;
	key = _getch();
	if (key != 49 && key != 50 && key != 51 && key != 52) {
		gotoxy(10, 9); printf("1,2,3,4 �� �ϳ��� Ŭ�����ֽʽÿ�.");
		Sleep(1000);
		cls;
		main_interface();
	}
	switch (key)
	{
	case 49:
		cls;
		purchase();
		break;
	case 50:
		cls;
		sell();
		break;
	case 51:
		cls;
		show_stock();
		break;
	case 52:
		cls;
		//���� �������� - �̺�Ʈ
		break;
	}

	rewind(stdin);
}


void purchase()
{
	char stockname[20];
	int stocknumber;
	printf("���� �� �ֽ� �̸��� �Է��ϼ���: \n");
	gets_s(stockname);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (strcmp(stockname, arr[i][j].name) == 0)
			{
				printf("������ ������ �Է��ϼ��� \n");
				scanf("%d", &stocknumber);
				arr[i][j].number = stocknumber;
				if (arr[i][j].price * arr[i][j].number > total_property)
				{
					printf("���� �ڻ꺸�� ��û�Ͻ� ���� Ů�ϴ�!");
					Sleep(2000);
					cls;
					purchase();
				}
				total_property -= arr[i][j].price * arr[i][j].number;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				Sleep(2000);
				return;
			}
		}
	}
	printf("��û�Ͻ� ������ �����ϴ�. \n");
	printf("���� ȭ������ ���ư��ϴ�. \n");
	Sleep(2000);
	rewind(stdin);////////////////////////////////////////////////////////////////////////////////////
	return;
}

void sell()
{
	char stockname[20];
	int stocknumber;
	printf("�Ǹ� �� �ֽ� �̸��� �Է��ϼ���: \n");
	gets_s(stockname);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (strcmp(stockname, arr[i][j].name) == 0)
			{
				printf("�Ǹ��� ������ �Է��ϼ���: ");
				scanf("%d", &stocknumber);
				if (stocknumber > arr[i][j].number)
				{
					printf("������ �ֽĺ��� ��û�Ͻ� ���� Ů�ϴ�!");
					Sleep(2000);
					cls;
					sell();
				}
				arr[i][j].number -= stocknumber;
				total_property += arr[i][j].price * arr[i][j].number;
				return;
			}
		}
	}
	printf("��û�Ͻ� ������ �����ϴ�. \n");
	printf("���� ȭ������ ���ư��ϴ�. \n");
	Sleep(2000);
	return;
}

void show_stock()
{
	for (int i = 0; i < 4; i++)
	{
		switch (i) {
		case 0:
			printf("����\n");
			break;
		case 1:
			printf("����\n");
			break;
		case 2:
			printf("�װ�\n");
			break;
		case 3:
			printf("�Ƿ�\n");
			break;
		}
		for (int j = 0; j < 4; j++)
		{
			printf("%s: ���� �ְ�: %d      ", arr[i][j].name, arr[i][j].price);
			printf("%s: ���� ���: %d %% \n", arr[i][j].name, arr_percent[i][j]);
		}
	}
	printf("\n");
	printf("�ƹ�Ű�� ������ ���� ȭ������ ���ư��ϴ�");
	_getch();
}
