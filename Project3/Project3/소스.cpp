#define _CRT_SECURE_NO_WARNINGS
#define cls system("cls")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//구조체를 통해서 주식을 만들자 - 미리 몇개 / 얼마/ 개수 설정(?)
typedef struct stock {
	char name[20]; //주식 이름
	int price; //주가
	int number; //보유한 주식의 개수
} Stock;

double arr_percent[4][4] = { 0 }; //전일 대비 증감을 보여주기 위해서 사용하는 배열
int stock_change_prediction[4];

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
int total_property = 500000;
int initial_price = 500000;
int cash = 500000; //현금 자산만
int stock_money = 0;
int isTerminate = 0;
int isDayOver = 0;

//언제 날짜가 초과되는지 정해야함
int day = 1; //날짜 경과. 10일차에서 종료

//메인 인터페이스. 현재 날짜의 경과, 보유한 자산, 보유한 주식, 수익등을 보여주고 주식 매수 매도 주식 차트를 볼 수 있음
void main_interface();
//화면 전환을 담당하는 함수
void switch_interface();
//주식을 구매하는 함수
void purchase();
//주식을 판매하는 함수
void sell();
//주식의 전일 대비 증감과 현재 가격을 보여주는 함수
void show_stock();
//뉴스를 통해 랜덤 이벤트를 발생시키는 함수
void news();

void predict_change_stock_price();
void adjust_change_stock_price();



void gotoxy(int x, int y) { //gotoxy함수 화면에 출력되는 문자의 위치를 바꾸는데 사용됨
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
		gotoxy(0, 10); printf("다음날로 넘어갑니다");
		Sleep(2000);
		cls;
	}
}

void predict_change_stock_price() // 주가를 변동 시키는 함수  1. 예정된 .... 2. a
{
	for (int i = 0; i < 4; i++)
	{
		stock_change_prediction[i] = rand() % 2;
	}
}

void adjust_change_stock_price() // 주가를 변동 시키는 함수  1. 예정된 .... 2. a
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

	gotoxy(10, 5); printf("1. 주식 매수");
	gotoxy(10, 6); printf("2. 주식 매도");
	gotoxy(10, 7); printf("3. 주가 확인");
	gotoxy(10, 8); printf("4. 뉴스 보기");
	gotoxy(10, 9); printf("5. 다음날로 넘어가기");

	gotoxy(20, 5); printf("현재 자산: %d원", total_property);
	gotoxy(20, 6); printf("수익률: %.2lf%%", (((double)(total_property - initial_price) / (initial_price) * 100)));
	gotoxy(20, 7); printf("%d일차", day);
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
		gotoxy(10, 9); printf("1,2,3,4 중 하나를 클릭해주십시오.");
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
	printf("구매 할 주식 이름을 입력하세요: \n");
	gets_s(stockname);

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
				cash -= arr[i][j].price * arr[i][j].number;
				total_property = cash + stock_money;

				Sleep(2000);
				return;
			}
		}
	}
	printf("요청하신 종목이 없습니다. \n");
	printf("메인 화면으로 돌아갑니다. \n");
	Sleep(2000);
	rewind(stdin);
	return;
}

void sell()
{
	char stockname[20];
	int stocknumber;
	printf("판매 할 주식 이름을 입력하세요: \n");
	gets_s(stockname);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (strcmp(stockname, arr[i][j].name) == 0)
			{
				printf("판매할 개수를 입력하세요: ");
				scanf("%d", &stocknumber);
				if (stocknumber > arr[i][j].number)
				{
					printf("소유한 주식보다 요청하신 값이 큽니다!");
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
	printf("요청하신 종목이 없습니다. \n");
	printf("메인 화면으로 돌아갑니다. \n");
	Sleep(2000);
	return;
}

void show_stock()
{
	for (int i = 0; i < 4; i++)
	{
		switch (i) {
		case 0:
			printf("전자\n");
			break;
		case 1:
			printf("제약\n");
			break;
		case 2:
			printf("항공\n");
			break;
		case 3:
			printf("의류\n");
			break;
		}
		for (int j = 0; j < 4; j++)
		{
			printf("%s: 현재 주가: %d      ", arr[i][j].name, arr[i][j].price);
			printf("%s: 전일 대비: %.2lf %% \n", arr[i][j].name, arr_percent[i][j]);
		}
	}
	printf("\n");
	printf("아무키나 누르면 메인 화면으로 돌아갑니다");
	_getch();
}

void news() {
	printf("뉴스속보 : \n");
	if (stock_change_prediction[0] == 1) {
		gotoxy(10, 1); printf("XX전자 미국에 태양광 발전 투자\n");
	}
	else {
		gotoxy(10, 1); printf("XX전자 임원, 마약 혐의 기소\n");
	}
	if (stock_change_prediction[1] == 1) {
		gotoxy(10, 2); printf("XX제약 신약 개발 성공\n");
	}
	else {
		gotoxy(10, 2); printf("XX제약 공매도 대폭 줄고 주가 강보합... 상승제 언제?\n");
	}
	if (stock_change_prediction[2] == 1) {
		gotoxy(10, 3); printf("코로나 백신 개발로 여행이 가능해져\n");
	}
	else {
		gotoxy(10, 3); printf("코로나 직격타 입은 관광업계, 앞으로 2~3년 더 힘들듯\n");
	}
	if (stock_change_prediction[3] == 1) {
		gotoxy(10, 4); printf("글로벌 소비회복, OEM주문 중국대신 한국으로 몰려\n");
	}
	else {
		gotoxy(10, 4); printf("섬유 수출업계, 환율 급락에 패닉 상태\n");
	}
	printf("아무키나 누르면 메인 화면으로 돌아갑니다");
	_getch();
}
