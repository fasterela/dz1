#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;

struct Complex{
	double real;
	double imag;
	Complex complexAdd(Complex c);
};

void read(Complex& c);
void print(Complex& c);


Complex complexCreate(double real, double imag);
Complex complexSub(Complex c1, Complex c2);
Complex complexMult(Complex c1, Complex c2);
Complex complexDiv(Complex c1, Complex c2);
double complexAbs(Complex c);
Complex complexStr(string str);

#endif

