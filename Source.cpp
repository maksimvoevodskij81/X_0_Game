#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void showMap(int map[][3], int SIZE_ROW, int SIZE_COL);
bool gameOver(int map[][3],int SIZE_ROW, int SIZE_COL, int valum);
void moveComputer(int map[][3], int SIZE_ROW, int SIZE_COL);
int main()
{
	setlocale(LC_ALL, "ru");
	const int SIZE_ROW = 3;
	const int SIZE_COL = 3;
	int map[SIZE_ROW][SIZE_COL] = {};
	int x = 0, y = 0;
	int choose = 0;
	
	showMap(map,SIZE_ROW,SIZE_COL);
	while (true)
	{
		cout << " enter the coordinates to make a move :\n";
		      //j  i
		cin >> x >> y;
		//j  i
		if(map[x][y]!=2)
		map[x][y] = 1;
		showMap(map,SIZE_ROW,SIZE_COL);
			if (gameOver( map,SIZE_ROW,SIZE_COL,1)==true)
			{
				cout << " you won !!!\n\n";
				break;
			}
		cout << " computer running :\n";
		moveComputer(map, SIZE_ROW, SIZE_COL);
		showMap(map, SIZE_ROW, SIZE_COL);
		if (gameOver(map, SIZE_ROW, SIZE_COL, 2) == true)
		{
			cout << " you lose :\n";
			break;
		}
	}
}
void showMap(int arr[][3],int SIZE_ROW,int SIZE_COL)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			cout << arr[j][i] << "\t";
		}
		cout << endl << endl;
	}
}
bool gameOver(int map[][3], int SIZE_ROW, int SIZE_COL, int valum)
{
	int countRow = 0;
	int countCol = 0;
	int countDiag = 0;
	int countDiag2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[j][i] == valum)
			{
				countRow++;
			}
			if (map[i][j] == valum)
			{
				countCol++;
			}
			if (map[j][j] == valum)
			{
				countDiag++;
			}
			if (map[2 - j][j] == valum)
			{
				countDiag2++;
			}
		}
		if (countRow == 3 || countCol == 3 || countDiag == 3 || countDiag2 == 3)
		{
			return true;
		}
		countRow = 0;
		countCol = 0;
		countDiag = 0;
		countDiag2 = 0;
		return false;
	}
}
void moveComputer(int map[][3], int SIZE_ROW, int SIZE_COL)
{
	int x = 0, y = 0;
	do
	{
		srand(time(0));
		x = rand() % 3;
		y = rand() % 3;
	} while (map[x][y] != 0);
	{
		map[x][y] = 2;
	}
}