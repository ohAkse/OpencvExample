#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
typedef struct _point{
	int x, y;
}point;

typedef struct _circle {

	point center;
	double radius;
}circle;

double area(circle c);
double perm(circle c);

int main()
{
	 point center;
	 circle s;
	scanf("%d %d", &s.center.x, &s.center.y);
	scanf("%lf", &s.radius);
	cout << s.radius;
	double test = area(s);
	printf("%f %f", area(s), perm(s));

}


double area(circle c)
{
	double a = 3.14 * c.radius * c.radius;
	return a;
}
double perm(circle c)
{
	int y = 6.656 * c.radius;
	return y;
}