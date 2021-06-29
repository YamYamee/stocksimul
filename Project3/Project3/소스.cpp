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

double arr_percent[4][4] = { 0 }; //���� ��� ������ �����ֱ� ���ؼ� ����ϴ� �迭
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
int cash = 500000; //���� �ڻ길
int stock_money = 0;
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
	while (day <= 10) {
		predict_change_stock_price();
		while (!isDayOver) {
			main_interface();
			switch_interface();
		}
		adjust_change_stock_price();
		isDayOver = 0;
		day++;
		gotoxy(0, 10); printf("�������� �Ѿ�ϴ�");
		Sleep(2000);
		cls;
	}
}

void predict_change_stock_price() // �ְ��� ���� ��Ű�� �Լ�  1. ������ .... 2. a
{
	for (int i = 0; i < 4; i++)
	{
		stock_change_prediction[i] = rand() % 2;
	}
}

void adjust_change_stock_price() // �ְ��� ���� ��Ű�� �Լ�  1. ������ .... 2. a
{
	double price_change;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 4; i++)
	{
		switch (i) {
		case 0:
			switch (stock_change_prediction[i]) {
			case 0:
				for (int j = 0; j < 4; j++)
				{
					int r_8 = rand() % 30;
					price_change = ((100 - r_8) / 100.0);
					arr_percent[i][j] = -r_8;
					arr[0][j].price = arr[i][j].price * price_change;
				} 
				break;
			case 1:
				for (int j = 0; j < 4; j++)
				{
					int r_9 = rand() % 30;
					price_change = ((100 + r_9) / 100.0);
					arr_percent[i][j] = r_9;
					arr[0][j].price = arr[i][j].price * price_change;
				}
				break;
			}
			break;
		case 1:
			switch (stock_change_prediction[i]) {
			case 0:
				for (int j = 0; j < 4; j++)
				{
					int r_0 = rand() % 30;
					price_change = ((100 - r_0) / 100.0);
					arr_percent[i][j] = -r_0;
					arr[1][j].price = arr[i][j].price * price_change;
				}
				break;
			case 1:
				for (int j = 0; j < 4; j++)
				{
					int r_1 = rand() % 30;
					price_change = ((100 + r_1) / 100.0);
					arr_percent[i][j] = r_1;
					arr[1][j].price = arr[i][j].price * price_change;
				}
				break;
			}
			break;
		case 2:
			switch (stock_change_prediction[i]) {
			case 0:
				for (int j = 0; j < 4; j++)
				{
					int r_2 = rand() % 30;
					price_change = ((100 - r_2) / 100.0);
					arr_percent[i][j] = -r_2;
					arr[2][j].price = arr[i][j].price * price_change;
				}
				break;
			case 1:
				for (int j = 0; j < 4; j++)
				{
					int r_3 = rand() % 30;
					price_change = ((100 + r_3) / 100.0);
					arr_percent[i][j] = r_3;
					arr[2][j].price = arr[i][j].price * price_change;
				}
				break;
			}
			break;
		case 3:
			switch (stock_change_prediction[i]) {
			case 0:
				for (int j = 0; j < 4; j++)
				{
					int r_4 = rand() % 30;
					price_change = ((100 - r_4) / 100.0);
					arr_percent[i][j] = -r_4;
					arr[3][j].price = arr[i][j].price * price_change;
				}
				break;
			case 1:
				for (int j = 0; j < 4; j++)
				{
					int r_5 = rand() % 30;
					price_change = ((100 + r_5) / 100.0);
					arr_percent[i][j] = r_5;
					arr[3][j].price = arr[i][j].price * price_change;
				}
				break;
			}
			break;
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
	gotoxy(10, 9); printf("5. �������� �Ѿ��");

	gotoxy(20, 5); printf("���� �ڻ�: %d��", total_property);
	gotoxy(20, 6); printf("���ͷ�: %.2lf%%", (((double)(total_property - initial_price) / (initial_price) * 100)));
	gotoxy(20, 7); printf("%d����", day);
	gotoxy(0, 10);

}

void switch_interface()
{
	int key = 0;
	key = _getch();
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
		news();
		break;
	case 53:
		cls;
		isDayOver = 1;
		break;
	default:
		gotoxy(10, 9); printf("1,2,3,4 �� �ϳ��� Ŭ�����ֽʽÿ�.");
		Sleep(1000);
		cls;
		main_interface();
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
				cash -= arr[i][j].price * arr[i][j].number;
				total_property = cash + stock_money;

				Sleep(2000);
				return;
			}
		}
	}
	printf("��û�Ͻ� ������ �����ϴ�. \n");
	printf("���� ȭ������ ���ư��ϴ�. \n");
	Sleep(2000);
	rewind(stdin);
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
				cash += arr[i][j].price * arr[i][j].number;
				total_property = cash + stock_money;
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
			printf("%s: ���� ���: %.2lf %% \n", arr[i][j].name, arr_percent[i][j]);
		}
	}
	printf("\n");
	printf("�ƹ�Ű�� ������ ���� ȭ������ ���ư��ϴ�");
	_getch();
}

void news() {
	printf("�����Ӻ� : \n");
	if (stock_change_prediction[0] == 1) {
		gotoxy(10, 1); printf("XX���� �̱��� �¾籤 ���� ����\n");
	}
	else {
		gotoxy(10, 1); printf("XX���� �ӿ�, ���� ���� ���\n");
	}
	if (stock_change_prediction[1] == 1) {
		gotoxy(10, 2); printf("XX���� �ž� ���� ����\n");
	}
	else {
		gotoxy(10, 2); printf("XX���� ���ŵ� ���� �ٰ� �ְ� ������... ����� ����?\n");
	}
	if (stock_change_prediction[2] == 1) {
		gotoxy(10, 3); printf("�ڷγ� ��� ���߷� ������ ��������\n");
	}
	else {
		gotoxy(10, 3); printf("�ڷγ� ����Ÿ ���� ��������, ������ 2~3�� �� �����\n");
	}
	if (stock_change_prediction[3] == 1) {
		gotoxy(10, 4); printf("�۷ι� �Һ�ȸ��, OEM�ֹ� �߱���� �ѱ����� ����\n");
	}
	else {
		gotoxy(10, 4); printf("���� �������, ȯ�� �޶��� �д� ����\n");
	}
	printf("�ƹ�Ű�� ������ ���� ȭ������ ���ư��ϴ�");
	_getch();
}
