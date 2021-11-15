#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include<algorithm>
using namespace std;
double f(double x) {
	double result = exp(x);
	return (result - 2 - x);
}
bool check_opposite_signs(double f_a, double f_b) {
	if (f_a * f_b >= 0)
		return false;
	else
		return true;
}
void False_Position_Mathod(double a0, double b0, double delta,double epsilon,int max) {
	cout << "**********************\n";
	cout << "False_Position_Mathod\n";
	cout << "**********************\n";
	double ai, bi;
	ai = a0;
	bi = b0;
	double c = bi - ((f(bi) * (bi - ai)) / (f(bi) - f(ai)));//Initialize value 
	for (int i = 1; i <= max; i++)
	{
		double d_x = ((f(bi)*(bi-ai))/(f(bi)-f(ai)));
	    c = bi - d_x;
		double a_c = c - ai;//closeness for consecutive iterations
		double f_c = f(c);
		cout << "# of iteration = " << i << "	   " << setprecision(5) << fixed << "a = " << ai << "	   " << "b = " << bi << "	   " << "c = " << c << "	   " << "f(c) =  " << f_c << "	   "  <<endl;
		if (f_c == 0) {
			break;
		}
		else if (check_opposite_signs(f(ai), f_c)) {
			ai = ai;
			bi = c;
		}
		else {
			ai = c;
			bi = bi;
		}
		d_x = min(fabs(d_x), a_c);
		if (fabs(d_x) < delta || fabs(f_c)<epsilon)
			break;
	}
	cout << "\nThe root of equation is : " << setprecision(5) << fixed << c << endl;
}
int main() {
	double a0, b0, f_a0, f_b0, delta,epsilon;
	//To try the code use the function --> exp(x) - 2 - x , the interval --> [-2.4,-1.6] 
	cout << "Enter the initial interval :: " << endl;
	cout << "a0 = "; cin >> a0;
	cout << "b0 = "; cin >> b0;
	delta = 5e-9;//tolerance value (error bound) , (accuracy value)
	epsilon = 5e-9;
	int max = 50;//maximum number of iterations
	f_a0 = f(a0);
	f_b0 = f(b0);
	if (!(check_opposite_signs(f_a0, f_b0)))
		cout << "False_Position Method Fails...." << endl;
	else {
		False_Position_Mathod(a0, b0, delta,epsilon,max);
	}
	return 0;

}