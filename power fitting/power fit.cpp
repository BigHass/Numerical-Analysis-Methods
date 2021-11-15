#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std; 
double xk[5], yk[5];
void ReadPoints(){
	cout << "Enter the values of x and y coordinates:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter x" << i<<"= "; cin >> xk[i];
		cout << "Enter y" << i<<"= "; cin >> yk[i];
	}

}
int main() {
	// To find the least-square power curve y=Bx^3 we need find the constant B 
	ReadPoints();//for the data points
	int M = 3; // M is the degree for the power fit y=Bx^3  
	int N = 5; // N is the numbers of given points 
	double sum1 = 0, sum2 = 0, sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0,sumxtwoy = 0;

	for (int i = 0; i <N; i++) {
		sum1 += ((pow(xk[i], M)) * yk[i]);//sum1 : is the summation from k=1 to k=N for xk^M * yk 
		sum2 += ((pow(xk[i], (2 * M))));//sum2 : is  the summation from k=1 to k=N for xk^2*M
		sumx += xk[i];
		sumy += yk[i];
		sumxy += (xk[i] * yk[i]);
		sumxtwoy += (pow(xk[i],2) * yk[i]);
		sumx2 += pow(xk[i], 2);
		sumx3 += pow(xk[i], 3);
		sumx4 += pow(xk[i], 4);
	}
	cout << "sum(x): " << setprecision(3) << fixed << sumx << endl;
	cout << "sum(y): " << setprecision(3) << fixed << sumy << endl;
	cout << "sum(x*y): "<< setprecision(3)<<fixed << sumxy << endl;
	cout << "sum(x^2 * y): " << setprecision(3) << fixed << sumxtwoy << endl;
	cout << "sum(x^2): " << setprecision(3) << fixed << sumx2 << endl;
	cout << "sum(x^3): " << setprecision(3) << fixed << sumx3 << endl;
	cout << "sum(x^4): " << setprecision(3) << fixed << sumx4 << endl;
	cout << endl;
	double B = sum1 / sum2; // B is a coefficient of the least squares power curve y=Bx^3
	cout << "xk"<<"\t\t"<<"yk"<<"\t\t\t"<<"yk * xk^3"<<"\t\t"<<"xk^6" << endl;//Table content the given data point and obtaining the coefficient for a power fit
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << setprecision(3) << fixed<< xk[i] <<"\t\t" << yk[i] << "\t\t\t" << ((pow(xk[i], M)) * yk[i]) << "\t\t\t" << (pow(xk[i], (2 * M))) << endl;
		cout << "------------------------------------------------------------------------------" << endl;
	}
	cout << setprecision(3) << fixed << "\t\t\t\tsum1 = " << sum1;//result of the summation from k=1 to k=5 for yk * xk^3 
	cout << setprecision(3) << fixed <<"\t\tsum2 = " << sum2 << endl;//result of the summation from k=1 to k=5 for xk^6
	cout << "------------------------------------------------------------------------------" << endl;
	cout << setprecision(10) << "The coefficient B = " << B << endl;;//The coefficient of the least squares power curve
	cout << setprecision(10) << "The power fit is : y = " << B << " * x^"<<M << endl;// The result of power fit 


	return 0;
}