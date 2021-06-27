#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//구조체를 통해서 주식을 만들자 - 미리 몇개 / 얼마/ 개수 설정(?)
typedef struct stock {
	char name[20]; //주식 이름
	int price; //주가
	int number; //보유한 주식의 개수
} Stock;


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
int total_property;
int pre_property; //현재 자산 - 주식 + 현금
int cash; //현금 자산만

//주식을 구매하는 함수
void purchase();
//주식을 판매하는 함수
void sell();
//랜덤을 통해서 함수를 돌려서 주가 변동 - 한국의 기준에 맞춰서 상한가/하한가
void change_stock_price(Stock arr[4][4]);
//이벤트를 통해서 주식의 개수 유상증자/무상증자
void change_stock_number(Stock arr[4][4]);
//printf를 통해서 현재 나의 상황과 주식의 상황(모든 주식) 보여주는 함수
void pre_sit();
//각각의 종목의 가격이나 개수를 처음으로 설정하는 함수. 최초 1회만 실행 됨. 일단 배열로 구현하고 나중에 이 함수를 통해 매번 달라지게 끔 할게.


int main()
{
	printf("%s %d %d \n", arr[0][0].name, arr[0][0].price, arr[0][0].number);
	purchase();
	printf("%d", total_property);
}

void change_stock_price(Stock arr[4][4]) // 주가를 변동 시키는 함수
{
	double price_change;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			price_change = ((double)(100 + ((rand() % 30) - 15)) / 100);
			arr[i][j].price = arr[i][j].price * price_change;
		}
	}
	srand((unsigned int)time(NULL));
}

void purchase()
{
	char stockname[20];
	int stocknumber;
	printf("구매 할 주식 이름을 입력하세요: ");
	gets(stockname);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (strcmp(stockname, arr[i][j].name) == 1)
			{
				printf("구매할 개수를 입력하세요");
				scanf("%d", &stocknumber);
				arr[i][j].number = stocknumber;
				total_property -= arr[i][j].price * arr[i][j].number;

				printf("구매 후 남은 자산: %d \n", total_property);
				printf("현재 보유 중이신 개수: %d \n", stocknumber);
			}
		}
	}
	printf("요청하신 종목이 없습니다.");
}
