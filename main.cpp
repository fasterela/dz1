#include "Complex.h"

int main() {

	setlocale(0, "");
	Complex c1{}, c2{}, rezult{};
	int num = 0;
	cout << "Калькулятор комплексных чисел" << endl;
	cout << "Введите 1 число:" << endl;
	read(c1);
	cout << "Введите 2 число:" << endl;
	read(c2);
	cout << "Выберите операцию:" << endl;
	cout << "1.Сложение" << endl;
	cout << "2.Умножение" << endl;
	cout << "3.Вычитание" << endl;
	cout << "4.Деление" << endl;
	if (cin >> num) {
		if (num == 1) {
			rezult = c1.complexAdd(c2);
			print(rezult);
		}
		if (num == 2) {
			rezult = complexMult(c1, c2);
			print(rezult);
		}
		if (num == 3) {
			rezult = complexSub(c1, c2);
			print(rezult);
		}
		if (num == 4) {
			rezult = complexDiv(c1, c2);
			print(rezult);
		}
	}
	else {
		cout << "Ошибка";
	}
	return 0;
}

int main(){
	setlocale(0, "");
	int i, n;
	cout << "Введите n(кол-во комплексных чисел):"; 
	cin >> n;
	ofstream f1("Complex.txt");
	for (i = 0; i < n; i++)
	{
		cout << "Введите комплексные числа:";
		string s;
		cin >> s;
		f1 << s;
		f1 << "\n";
	}
	f1.close();
	string str;
	ifstream f2("Complex.txt");
	vector <Complex> p(n);
	for (int i = 0; i < n; i++) {
		f2 >> str;
		p[i] = complexStr(str);
	}
	int maxAbs = 0;
	Complex maxComplex{0,0};

	for (int i = 0; i < n; i++) {
		if (complexAbs(p[i]) > maxAbs) {
			maxComplex = p[i];
			maxAbs = complexAbs(p[i]);
		}
	}
	print(maxComplex);
}
