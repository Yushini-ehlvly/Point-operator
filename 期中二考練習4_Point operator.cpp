#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Point {
public:
	Point();
	Point(int, int);
	int getFirstNumber() const;
	int getSecondNumber()const;
	Point add(const Point&) const;
	Point subtract(const Point&) const;
	string toString() const;
	Point operator+();
	Point operator-();
	friend ostream& operator << (ostream&, const Point&);
private:
	int firstNumber;
	int secondNumber;
};

bool operator<(const Point& p1, const Point& p2);
Point operator+(const Point& p1, const Point& p2);
Point operator-(const Point& p1, const Point& p2);

Point::Point()
{
	firstNumber = 0;
	secondNumber = 1;
}

Point::Point(int x, int y)
{
	firstNumber = x;
	secondNumber = y;
}

int Point::getFirstNumber() const
{
	return firstNumber;
}

int Point::getSecondNumber() const
{
	return secondNumber;
}

Point Point::add(const Point & secondPoint) const
{
	int x = firstNumber + secondPoint.getFirstNumber();
	int y = secondNumber + secondPoint.getSecondNumber();
	return Point(x, y);
}

Point Point::subtract(const Point & secondPoint) const
{
	int x = firstNumber - secondPoint.getFirstNumber();
	int y = secondNumber - secondPoint.getSecondNumber();
	return Point(x, y);
}

string Point::toString() const
{
	stringstream ss;
	ss << '(' << firstNumber << ',' << secondNumber << ')';
	return ss.str();
}

Point Point::operator+()
{
	return *this;
}

Point Point::operator-()
{
	return Point(-firstNumber, secondNumber);
}

ostream & operator<<(ostream & out, const Point& point)
{
	out << '(' << point.firstNumber << ',' << point.secondNumber << ')';
	return out;
}

Point operator+(const Point & r1, const Point & r2)
{
	return r1.add(r2);
}

Point operator-(const Point & r1, const Point & r2)
{
	return r1.subtract(r2);
}

int main() {
	int x[3], y[3];
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	Point point1(x[0], y[0]);
	Point point2(x[1], y[1]);
	Point point3(x[2], y[2]);

	cout << point1 << '+' << point2 << '-' << point3 << '=' << point1 + point2 - point3;
}
