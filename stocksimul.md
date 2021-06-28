#define _CRT_SECURE_NO_WARNINGS
#define cls system("cls")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//구조체를 통해서 주식을 만들자 - 미리 몇개 / 얼마/ 개수 설정(?)
typedef struct stock {
	char name[20]; //주식 이름
	int price; //주가
	int number; //보유한 주식의 개수
} Stock;

arr_percent[4][4]; //전일 대비 증감을 보여주기 위해서 사용하는 배열

Stock arr[4][4] =
{
		{
			{"삼성전자", 30000, 0},
			{"SK하이닉스",500000,0},
			{"LG전자", 20000, 0 },
			{"그냥전자", 50000, 0}
		},
		{
			{"제일제약", 3000, 0},
			{"약약제약", 50000, 0},
			{"땡땡제약", 30000, 0 },
			{"냠냠제약", 20000, 0}
		},
		{
			{"히히항공", 35000, 0},
			{"한국한공", 25000,0},
			{"멋진항공", 23400, 0 },
			{"슈퍼항공", 12000, 0}
		},
		{
			{"킼킼의류", 34500, 0},
			{"나잌키", 23400,0},
			{"쀼마", 23200, 0 },
			{"아디도스", 39000, 0}
		}
};

//전역변수
int total_property = 50000;
int initial_price = 500000;

int day; //날짜 경과. 50일차에서 종료
int pre_property; //현재 자산 - 주식 + 현금
int cash; //현금 자산만

//메인 인터페이스. 현재 날짜의 경과, 보유한 자산, 보유한 주식, 수익등을 보여주고 주식 매수 매도 주식 차트를 볼 수 있음
void main_interface();
//주식을 구매하는 함수
void purchase();
//주식을 판매하는 함수
void sell();
//랜덤을 통해서 함수를 돌려서 주가 변동 - 한국의 기준에 맞춰서 상한가/하한가
void change_stock_price();
//이벤트를 통해서 주식의 개수 유상증자/무상증자
void change_stock_number(Stock arr[4][4]);
//printf를 통해서 현재 나의 상황과 주식의 상황(모든 주식) 보여주는 함수
void pre_sit();
//주식의 전일 대비 증감과 현재 가격을 보여주는 함수
void show_stock();
//뉴스를 통해 랜덤 이벤트를 발생시키는 함수
void news();
//화면 전환을 담당하는 함수
void switch_interface();


void gotoxy(int x, int y) { //gotoxy함수 화면에 출력되는 문자의 위치를 바꾸는데 사용됨
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
	main_interface();
}

void change_stock_price() // 주가를 변동 시키는 함수
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

void switch_interface()
{
	int key = 0;
	key = _getch();
	switch (key)
	{
	case 49:
		cls;
		purchase();
	case 50:
		cls;
		sell();
	case 51:
		cls;
		show_stock();
	case 52:
		cls;
	}

	rewind(stdin);
}


void purchase()
{
	char stockname[20];
	int stocknumber;
	printf("구매 할 주식 이름을 입력하세요: \n");
	gets(stockname);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (strcmp(stockname, arr[i][j].name) == 0)
			{
				printf("구매할 개수를 입력하세요 \n");
				scanf("%d", &stocknumber);
				arr[i][j].number = stocknumber;
				if (arr[i][j].price * arr[i][j].number > total_property)
				{
					printf("소유 자산보다 요청하신 값이 큽니다!");
					Sleep(2000);
					cls;
					purchase();
				}
				total_property -= arr[i][j].price * arr[i][j].number;

				Sleep(2000);
				main_interface();
			}
			else
			{
				printf("요청하신 종목이 없습니다. \n");
				printf("메인 화면으로 돌아갑니다. \n");
				Sleep(2000);
				main_interface();
			}
		}
	}
	rewind(stdin);
}

void sell()
{
	char stockname[20];
	int stocknumber;
	printf("판매 할 주식 이름을 입력하세요: \n");
	gets(stockname);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (strcmp(stockname, arr[i][j].name) == 0)
			{
				printf("판매할 개수를 입력하세요: ");
				scanf("%d", &stocknumber);
				arr[i][j].number = stocknumber;
				total_property += arr[i][j].price * arr[i][j].number;

			}
			else
			{
				printf("요청하신 종목이 없습니다. \n");
				printf("메인 화면으로 돌아갑니다. \n");
				Sleep(2000);
				main_interface();
			}
		}
	}

}

void show_stock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
				printf("%s: 현재 주가: %d \n", arr[i][j].name, arr[i][j].price);
				printf("%s: 전일 대비: %d \% \n", arr[i][j].name, arr_percent[i][j]);

		}
	}
}

void main_interface()
{
	cls;

	gotoxy(10, 5); printf("1. 주식 매수");
	gotoxy(10, 6); printf("2. 주식 매도");
	gotoxy(10, 7); printf("3. 주가 확인");
	gotoxy(10, 8); printf("4. 뉴스 보기");

	gotoxy(20, 5); printf("보유 주식:");
	gotoxy(20, 6); printf("현재 자산: %d", total_property);
	gotoxy(20, 7); printf("수익률: %lf", ( ((double)(total_property - initial_price)  / (initial_price) * 100)));
	gotoxy(20, 8); printf("%d일차 \n", day);

	switch_interface();
}
