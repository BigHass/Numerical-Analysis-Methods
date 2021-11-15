#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
using namespace std;
double function(double x) {
	double result = exp(x);
	return (result - 2 - x);
}
bool check_opposite_signs(double f_a, double f_b) {
	if (f_a * f_b >= 0)
		return false;
	else
		return true;
}
double find_midpoint(double a, double b) {
	double c = (a + b) / 2;
	return c;
}
void Bisection_Mathod(double a0, double b0, double delta) {
	cout << "****************\n";
	cout << "Bisection Method\n";
	cout << "****************\n";
	double ai, bi;
	ai = a0;
	bi = b0;
	int max = 50;//maximum number of iterations 
	for (int i = 1; i <= max; i++)
	{
		double  c = find_midpoint(ai, bi);
		double f_c = function(c);
		cout << "# of iteration = " << i << "	   " << setprecision(5) << fixed << "a = " << ai << "	   " << "b = " << bi << "	   " << "c = " << c << "	   " << "f(c) =  " << f_c << "	   " << "|b-a| = " << fabs(bi - ai) << endl;
		if (f_c == 0) {
			ai = c;
			bi = c;
			break;
		}
		else if (check_opposite_signs(function(ai), f_c)) {
			ai = ai;
			bi = c;
		}
		else {
			ai = c;
			bi = bi;
		}

		if (fabs(bi - ai) < delta)
			break;
	}
	cout << "\nThe root of equation is : " << setprecision(5) << fixed << (ai + bi) / 2 << endl;
}
int main() {
	long double a0, b0, f_a0, f_b0;
	//To try the code use the function --> exp(x) - 2 - x and the interval --> [-2.4,-1.6] 
	cout << "Enter the initial interval :: " << endl;
	cout << "a0 = "; cin >> a0;
	cout << "b0 = "; cin >> b0;
	const long double delta = 5e-9;//tolerance value (error bound) , (accuracy value)
	f_a0 = function(a0);
	f_b0 = function(b0);
	if (!(check_opposite_signs(f_a0, f_b0)))
		cout << "Bisection method fails...." << endl;
	else {
		Bisection_Mathod(a0, b0, delta);
	}
	return 0;

}