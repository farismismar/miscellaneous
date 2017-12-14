#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "drivers.h"

const double PI = 3.141592653589793;	// After 15 digits from decimal point, variation is noticeable.

class Complex {
	friend ostream &operator << (ostream &, Complex &);
public:
	double real;
	double imaginary;

	void toPhasor(void);
	void drawAxes(void);
	void drawDiagram(void);

	Complex(double r = 0, double i = 0)
	{
		real = r;
		imaginary = i;
	}

	Complex operator - (Complex &cplx)
	{
		Complex ans;
		ans.real = real - cplx.real;
		ans.imaginary = imaginary - cplx.imaginary;

		return(ans);
	}

	Complex operator + (Complex &cplx)
	{
		Complex ans;

		ans.real = real + cplx.real;
		ans.imaginary = imaginary + cplx.imaginary;

		return(ans);
	}

	Complex operator * (Complex &cplx)
	{
		Complex ans;

		ans.real = real * cplx.real - imaginary * cplx.imaginary;
		ans.imaginary = imaginary * cplx.real + real * cplx.imaginary;

		return(ans);
	}

	Complex operator / (Complex &cplx)
	{
		Complex ans;
		double modulusSq;		// Magnitude of complex number squared |z|^2

		modulusSq = pow(cplx.real, 2.0) + pow(cplx.imaginary, 2.0);
		ans.real = (real * cplx.real + imaginary * cplx.imaginary) / modulusSq;
		ans.imaginary = (imaginary * cplx.real - real * cplx.imaginary) / modulusSq;

		return(ans);
	}
};

void Complex::toPhasor()
{
	double theta;
	double r;

	r = sqrt(pow(real, 2.0) + pow(imaginary, 2.0));
	theta = atan(imaginary / real) * 180.0 / PI;

	cout << "(" << r << "<" << theta << ")" << endl;
}

void Complex::drawAxes()
{
	initializeGraphics();

	int maxX = getmaxx();
	int maxY = getmaxy();

	double factor = 10.0;

	setcolor(WHITE);

	line(0, maxY / 2, maxX, maxY / 2);
	line(maxX / 2, 0, maxX / 2, maxY);

	for (int x = 0; x <= maxX; x += (int) 2 * factor)
		line(x, maxY / 2 - 5, x, maxY / 2 + 5);

	for (double y = 0; y <= maxY; y += (int) 2 * factor)
		line(maxX / 2 + 5, y, maxX / 2 - 5, y);
	putpixel(maxX / 2, maxY / 2, WHITE);
}

void Complex::drawDiagram()
{
	int maxX = getmaxx();
	int maxY = getmaxy();
	double factor = 20.0;

	setcolor(rand() % 16);
	line(maxX / 2, maxY / 2, maxX / 2 + real * factor, maxY / 2 - imaginary * factor);

	cout << *this << endl;	// pointer to the same class, prints the complex number.
	this->toPhasor();			// types the phasor representation of the complex number.

	setcolor(WHITE);
	outtextxy(maxX - 250, maxY - 30, "Done By: Faris B. Mismar 2002");
	outtextxy(maxX - 250, maxY - 20, "Complex Phasor Representation");
}

ostream &operator << (ostream &output, Complex &cplx)
{
	if (cplx.imaginary < 0)
		output << cplx.real << " - " << -cplx.imaginary << "i";
	else if (cplx.imaginary > 0)
		output << cplx.real << " + " << cplx.imaginary << "i";
	else
		output << cplx.real;

	return(output);
}

int main(void)
{
	clrscr();
	randomize();
   
	Complex a(1, 3);			// a = 1 + 3i
	Complex b(-2, -2);		// b =  -2 - 2i

	a.drawAxes();

	a.drawDiagram();
	b.drawDiagram();

	(a + b).drawDiagram();
	(a - b).drawDiagram();
	(a * b).drawDiagram();
	(a / b).drawDiagram();

	getch();
	return(0);
}

