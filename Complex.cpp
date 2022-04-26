#include "Complex.h"

void read(Complex &c)
{
	cout << "¬ведите действительную часть:  ";
	cin >> c.real;
	cout << "¬ведите мнимую часть:   ";
	cin >> c.imag;
}

void print(Complex &c)
{
	cout << c.real << "+(" << c.imag << ")i";
}

Complex complexCreate(double real, double imag) {
	Complex result = { real, imag };
	return result;
}
Complex Complex:: complexAdd(Complex c1)
{
	return complexCreate(c1.real + this->real, c1.imag + this->imag);
}
Complex complexMult(Complex c1, Complex c2) {
	double a = c1.real;
	double b = c1.imag;
	double c = c2.real;
	double d = c2.imag;
	return complexCreate(a * c - b * d, b * c + a * d);
}
Complex complexSub(Complex c1, Complex c2){
	return complexCreate(c1.real - c2.real, c1.imag - c2.imag);
}
Complex complexDiv(Complex c1, Complex c2) {
	Complex c; double r;
	r = c2.real * c2.real + c2.imag * c2.imag;
	c.real = (c1.real * c2.real + c1.imag * c2.imag) / r;
	c.imag = (c1.imag * c2.real - c1.real * c2.imag) / r;
	return c;
}
double complexAbs(Complex c) {
	return (abs(c.imag * c.imag + c.real * c.real));
}
Complex complexStr(string str) {
	string imag, real;
	int i = 0, r = 0;
	for (int k = 0; k < str.length(); k++) {
		if ((str[k] == '+') && str.find('-') == -1) {
			imag.append(str, k + 1, str.length() - str.find('+') - 2);
			i = stod(imag);
			real.append(str, 0, str.find('+'));
			r = stod(real);
			break;
		}
		if ((str[k] == '+') && str.find('-') != -1) {
			imag.append(str, k + 1, str.length() - str.find('+') - 2);
			i = stod(imag);
			real.append(str, 0, str.find('-'));
			r = -1 * stod(real);
			break;
		}
		if ((str[k] == '-') && str.rfind('+') != -1 && k == 0) {
			real.append(str, k + 1, str.find('+') - 1);
			r = -1 * stod(real);
			imag.append(str, str.find('+') + 1, str.length());
			i = stod(imag);
			break;
		}
		if ((str[k] == '-') && str.rfind('+') == -1 && k != 0) {
			real.append(str, 1, str.find('-') - 1);
			r = -1 * stod(real);
			imag.append(str, str.rfind('-') + 1, str.length());
			i = -1 * stod(imag);
			break;
		}
	}
	return complexCreate(r, i);
		}