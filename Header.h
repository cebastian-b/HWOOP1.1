#include <iostream>
using namespace std;
class Complex {
	double re, im;//datele clasei - de tip privat
public: //constructori - au acelasi nume cu clasa, nu returneaza nimic
	Complex(double x = 0, double y = 0);//constructor cu parametru ce ia valori implicite
	Complex(const Complex&);//constructor de copiere
	explicit Complex(const char*);//constructor cu parametru folosit la conversii din expresii de tipul"a+bi"
//metode
	//z=a+bi a=partea reala, b = partea imaginara
	double modul();//radical(a^2 + b^2)
	double argument();//unghiul dintre axa ox si punctul de afix corespunzator z=|z|(cos arg + i*sin arg)
	friend double distanta(const Complex&, const Complex&);
	double getRe(); void setRe(double);
	double getIm(); void setIm(double);
	//supraincarcare operatori
	Complex operator+(const Complex&);
		Complex operator-(const Complex&);
		Complex operator*(const Complex&);
		Complex operator/(const Complex&);
		int operator==(const Complex&);
		int operator!=(const Complex&);
		Complex operator-();
		Complex operator~();//conjugat
		Complex& operator++();//prefix
		Complex operator++(int);//postfix
		Complex& operator+=(const Complex&);
		Complex& operator-=(const Complex&);
		Complex& operator*=(const Complex&);
		Complex& operator/=(const Complex&);
		operator double() const;
		friend ostream& operator<<(ostream& os, const Complex&);
		friend istream& operator>>(istream& is, Complex&);
};

class EcGr2 {//membri
	const Complex a, b, c;
public:
	//constructori
	EcGr2(Complex a = 1, Complex b = 0, Complex c = 0, Complex x = 0);
	EcGr2(const EcGr2&);
	//metode 
	Complex getCoef2();
	Complex getCoef1();
	Complex getCoef0();
	void setCoef2(Complex);
	void setCoef1(Complex);
	void setCoef0(Complex);
	Complex eval(Complex);//evaloarea expresiei pentru un x dat
	Complex roots(Complex);//determinarea radacinilor
	friend EcGr2 operator+(const EcGr2&, const EcGr2&);
	friend EcGr2 operator-(const EcGr2&, const EcGr2&);
	friend EcGr2 operator*(const EcGr2&, const EcGr2&);
	friend ostream& operator<<(ostream& os, const Complex&);
	friend istream& operator>>(istream& is, Complex&);
};

