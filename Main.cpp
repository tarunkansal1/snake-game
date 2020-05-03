#include<iostream>
#include<conio.h>
//#include <vector>
//#include<windows.h>
using namespace std;

int X,score,gameover;
int Y;
int fruitx, fruity;
char g;
const int height = 20;
const int width = 20;
int ntail;
int prevx, prevy;
int tailx[100], taily[100];

void check_scr()
{
	if (X == fruitx && Y == fruity)
	{
		ntail++;
		score += 10;
		fruitx = rand() % width;
		fruity = rand() % height;

	}
}
void move()
{
	if (_kbhit())
	{
		g = _getch();
	}
	prevx = tailx[0];
	prevy = taily[0];
	int tempx, tempy;
	tailx[0] = X;
	taily[0] = Y;

	for (int i = 1; i < ntail; i++)
	{
		tempx = tailx[i];
		tempy = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = tempx;
		prevy = tempy;

	}
	

	
	
		switch (g)
		{
			case 'w':
				Y--;
				break;
			case 's':
				Y++;
				break;
			case 'a':
				X--;
				break;
			case 'd':
				X++;
				break;
			default:
				break;
		}
	
	//if (X == width-1 || Y == height|| Y == -1 || X == 0)
		//gameover = 1;
	if (X == width - 1)
		X = 1;
	if (X == 0)
		X = width - 2;
	if (Y == height)
		Y = 0;
	if (Y == -1)
		Y = height-1;

	for (int i = 0; i < ntail; i++)
	{
		if (tailx[i] == X && taily[i] == Y)
			gameover = 1;
	}

}
void draw()
{
	system("cls");
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << std::endl;
	for (int i=0;i<height;i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			else if (i == Y && j == X)
			{
				cout << "O";
			}
			else if (i == fruity && j == fruitx)
				cout << "F";
			else
			{
				int print = 0;
				for (int r = 0; r < ntail; r++)
				{
					if (tailx[r] == j && taily[r] == i)
					{
						cout << "*";
						print = 1;
					}
				}
				if (!print)
				cout << " ";
			}
		}
		cout << std::endl;
	}
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << std::endl;
	cout << "score:  " << score << std::endl;

}
int main()
{
	ntail = 0;
	score = 0;
	g = 'x';
	gameover = 0;
	X = width/2;
	Y = height/2;
	fruitx = rand() % width;
	fruity = rand() % height;
	while (!gameover)
	{
		draw();
		move();
		check_scr();
		//sleep(10);

	}
	cout << "play again::y,n" << std::endl;

	char r;
	cin >> r;
	if (r == 'y')
		main();

	return 0;
}