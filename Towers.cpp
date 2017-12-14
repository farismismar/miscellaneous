#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#include "drivers.h"

double maxX, maxY;
double currentX, currentY;
int currentColor;
int n;						// number of disks
unsigned long successfulMovements;

void showIntro(void);
void move(int, int = 1, int = 3, int = 2);
void drawDisks(int);
void drawStakes(void);

int numOfDisks[4] = {0};	// number of disks on each stake taking numbers 1, 2, and 3 -- 0 is ignored.

int main(void)
{
	showIntro();

	initializeGraphics();

	maxX = getmaxx();
	maxY = getmaxy();

	gotoxy(1, 1);
	cout << "Towers Of Hanoi" << endl;
	cout << "Number of disks: " << n << " (Press ESC key to quit)";

	drawStakes();

	currentColor = WHITE;
	setcolor(currentColor);

	drawDisks(n);

	getch();
	numOfDisks[1] = n;

	move(n);
	successfulMovements = pow(2, n) - 1;

	sound(5000);
	delay(200);
	nosound();
	cout << endl << "Number of total movements: " << successfulMovements;

	getch();
	closegraph();
	return(0);
}

void move(int number, int from, int to, int through)
{
	if (number == 1) {
		setcolor(BLACK);
		rectangle(from * maxX / 4 + 5 * number, maxY - numOfDisks[from] * 10,
			from * maxX / 4 - 5 * number, maxY - numOfDisks[from] * 10 - 8);
		numOfDisks[from]--;
		setcolor(WHITE);
		numOfDisks[to]++;
      getch();
		rectangle(to * maxX / 4 + 5 * number, maxY - numOfDisks[to] * 10,
			to * maxX / 4 - 5 * number, maxY - numOfDisks[to] * 10 - 8);
	} else {
		move(number - 1, from, through, to);
		//cout << "Move " << number << " from " << from << " to " << to << endl;
		setcolor(BLACK);
		rectangle(from * maxX / 4 + 5 * number, maxY - numOfDisks[from] * 10,
			from * maxX / 4 - 5 * number, maxY - numOfDisks[from] * 10 - 8);
		numOfDisks[from]--;
		setcolor(WHITE);
		numOfDisks[to]++;
      getch();
		rectangle(to * maxX / 4 + 5 * number, maxY - numOfDisks[to] * 10,
			to * maxX / 4 - 5 * number, maxY - numOfDisks[to] * 10 - 8);
		move(number - 1, through, to, from);
   }
}

void drawDisks(int numOfBlocks)
{
	maxY -= 8;
	for (int counter = numOfBlocks; counter > 0; counter--) {
	rectangle(maxX / 4 + 5 * (numOfBlocks - counter + 1), maxY - counter * 10,
		maxX / 4 - 5 * (numOfBlocks - counter + 1), maxY - counter * 10 - 8);
   }
}

void drawStakes()
{
	currentColor=BLUE;
	setcolor(currentColor);
	rectangle(0, maxY, maxX, maxY - 15);
	setfillstyle(SOLID_FILL, currentColor);
	floodfill(maxX / 2, maxY - 7, currentColor);

	for (int x = 0; x < maxX - 6; x += maxX / 4) {
		if (x == 0) continue;
		line(x, maxY, x, maxY / 2 - 70);
   }
}

void showIntro()
{
	clrscr();
	gotoxy(1, 50);
	cout << "Press any key to go to graphics mode, and then hit any key to quit";

	gotoxy(1, 1);
	cout << "\t\t\tT O W E R S   O F   H A N O I" << endl << endl;
	cout << "Programmed By: Mohammad Al-Shami and Faris B. Mismar" << endl;
	cout << "Enter number of disks: ";
	cin >> n;

	if (!cin.good() || n < 3 || n > 16) {
		cin.clear();
		sound(5000);
		delay(400);
		nosound();
		showIntro();
   }
}