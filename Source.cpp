//LabFirst.cpp
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
struct Point 
{
	int x;
	int y;
};

class Trapecia 
{
public:

	Point A{};
	Point B{};
	Point C{};
	Point D{};
	double AB;
	double BC;
	double CD;
	double AD;
	Trapecia()
	{
		set_distance();
	}
	void set_distance()
	{
		AB = Distance(A, B);
		BC = Distance(B, C);
		CD = Distance(C, D);
		AD = Distance(A, D);
	}


	double Distance(Point a, Point b) 
	{
		//Pifagor
		return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
	}

	Trapecia(Point a, Point b, Point c, Point d)
	{
		A.x = a.x;
		A.y = a.y;
		B.x = b.x;
		B.y = b.y;
		C.x = c.x;
		C.y = c.y;
		D.x = d.x;
		D.y = d.y;
		set_distance();
	}

	double Ploschad() 
	{

		double a = (AB + CD) / 2,
			ab = pow(CD - AB, 2),
			cd = AD * AD - BC * BC;
		double res = a * sqrt(AD * AD - pow(((ab + cd) / (2 * (AB - CD))), 2));
		return res;
	}

	double Perimetr() 
	{
		return AB + BC + CD + AD;
	}

	void Print() 
	{
		cout << "Трапецiя с вершинами в точках: \n";
		cout << "A(x, y)= " << A.x << "," << A.y<<endl;
		cout << "B(x, y)= " << B.x << "," << B.y << endl;
		cout << "C(x, y)= " << C.x << "," << C.y << endl;
		cout << "B(x, y)= " << D.x << "," << D.y << endl;
		cout << ("\nЗ сторонами: ");
		cout << "\nAB:= " << AB << "\nBC:=" << BC<<"\nCD:= " << CD << "\nAD:= " << AD << endl;
		cout << "\nПлоща: = " << Ploschad();
		cout << "\nПериметр := " << Perimetr();
	}

	~Trapecia() {

	}
	//Перегрузка  виводу
	friend std::ostream& operator << (std::ostream& out, const Point& point) { return out; };

};

std::ostream& operator<<(std::ostream& out, const Trapecia& t)
{
	out << "\nТрапецiя з сторонами AB:= " << t.AB << "; BC:= " << t.BC << "; CD:= " << t.CD << "; AD:= " << t.AD <<";" << endl;
	return out;
}

Trapecia generate_points()
{
	const int count_points = 4;
	Point p[count_points];
	for (size_t i = 0; i < count_points; i++)
	{
		p[i].x = rand() % 10;
		p[i].y = rand() % 10;
	}
	Trapecia t(p[0], p[1], p[2], p[3]);
	return t;
}
int main()
{
	//srand(time(0));
	setlocale(0, "");
	Trapecia t = generate_points();
	Trapecia vec;
	//t.set_distance();
	t.Print();
	cout << "\nДемонстрацiя перегрузки виводу\n";
	cout << t;
	//cout <<t->A.x;
}