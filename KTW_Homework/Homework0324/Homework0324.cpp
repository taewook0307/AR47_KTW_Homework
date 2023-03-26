﻿#include <iostream>
#include <conio.h>
#include <Windows.h>
// 숙제0 : 전방향 다 움직이게 만들기
// 숙제1 : 잔상 지우기
// 숙제2 : 화면 밖으로 못 나가게 하기

// 안해도 되는 숙제
// 숙제3 : 장애물 만들고 배치하기
// 숙제4 : f를 누르면 폭탄이 설치되고 눈에 보여야 함.
// ------------------------------------------------------------------------- 숙제 구현 
// 
// 숙제5 : 일정시간이 지나고 폭탄이 터지면서

int main()
{
	const int ScreenYSize = 11;
	const int ScreenXSize = 11;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}

	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	char LastClickButton = '0';

#pragma region 장애물 설치
	for (int WallCount = 10; WallCount > 0; --WallCount)
	{
		int x = rand() % ScreenXSize;
		int y = rand() % ScreenYSize;

		Arr[y][x] = 'X';
	}
#pragma endregion

	while (true)
	{
		system("cls");

		Arr[PlayerY][PlayerX] = '*';

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}

		if (0 == _kbhit())		// 키를 누르지 않았다면
		{
			Sleep(200);

			continue;
		}

#pragma region 키 입력
		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
			if (Arr[PlayerY][PlayerX - 1] == '@' || Arr[PlayerY][PlayerX - 1] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}
			else
			{
				if (PlayerX == 0)						// 플레이어가 제일 좌측에 위치했을 경우
				{
					PlayerX = 0;
					LastClickButton = 'a';
				}
				else
				{
					PlayerX -= 1;
					Arr[PlayerY][PlayerX + 1] = 'a';
					LastClickButton = 'a';
				}
				break;
			}
		case 'd':
		case 'D':
			if (Arr[PlayerY][PlayerX + 1] == '@' || Arr[PlayerY][PlayerX + 1] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}
			else
			{
				if (PlayerX == ScreenXSize - 1)			// 플레이어가 제일 우측에 위치했을 경우
				{
					PlayerX = ScreenXSize - 1;
					LastClickButton = Ch;
				}
				else
				{
					PlayerX += 1;
					Arr[PlayerY][PlayerX - 1] = 'a';
					LastClickButton = Ch;
				}
				break;
			}
		case 's':
		case 'S':
			if (Arr[PlayerY + 1][PlayerX] == '@' || Arr[PlayerY + 1][PlayerX] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}
			else
			{
				if (PlayerY == ScreenYSize - 1)			// 플레이어가 제일 아래쪽에 위치했을 경우
				{
					PlayerY = ScreenYSize - 1;
					LastClickButton = Ch;
				}
				else
				{
					PlayerY += 1;
					Arr[PlayerY - 1][PlayerX] = 'a';
					LastClickButton = Ch;
				}
				break;
			}
		case 'w':
		case 'W':
			if (Arr[PlayerY - 1][PlayerX] == '@' || Arr[PlayerY - 1][PlayerX] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}
			else
			{

				if (PlayerY == 0)						// 플레이어가 제일 위쪽에 위치했을 경우
				{
					PlayerY = 0;
					LastClickButton = Ch;
				}
				else
				{
					PlayerY -= 1;
					Arr[PlayerY + 1][PlayerX] = 'a';
					LastClickButton = Ch;
				}
				break;
			}
		case 'f':										// 폭탄 설치
		case 'F':
			if (LastClickButton == 'a')					// 마지막으로 누른 키가 a일 경우
			{
				if (PlayerX == 0)
				{
					break;
				}
				else
				{
					Arr[PlayerY][PlayerX - 1] = '@';
				}
			}
			else if (LastClickButton == 'd')				// 마지막으로 누른 키가 d일 경우
			{
				if (PlayerX == ScreenXSize - 1)
				{
					break;
				}
				else
				{
					Arr[PlayerY][PlayerX + 1] = '@';
				}
			}
			else if (LastClickButton == 's')			// 마지막으로 누른 키가 s일 경우
			{
				if (PlayerY == ScreenYSize - 1)
				{
					break;
				}
				else
				{
					Arr[PlayerY + 1][PlayerX] = '@';
				}
			}
			else if (LastClickButton == 'w')			// 마지막으로 누른 키가 w일 경우
			{
				if (PlayerY == 0)
				{
					break;
				}
				else
				{
					Arr[PlayerY - 1][PlayerX] = '@';
				}
			}
			break;
		default:
			break;
		}
#pragma endregion

		Sleep(200);
	}
}