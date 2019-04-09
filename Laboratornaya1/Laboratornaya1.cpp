// Laboratornaya1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "Complex.h"
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <iterator>
#define space " "

using namespace std;

class person
{
protected:
	char name[80];
	int age;
public:
	virtual void get()
	{
		setlocale(LC_ALL, "Russian");
		cout << "\n Введите имя:\t";
		cin >> name;
		cout << "\n Введите возраст:\t";
		cin >> age;
	}
	virtual void put()
	{
		cout << "\n Имя:\t" << name;
		cout << "\n Возраст:\t" << age;

	}
};

class Skills :public person
{
private:
	int soft;
public:
	void get()
	{
		person::get();
		cout << "\n Баллы по программированию:\t";
		cin >> soft;
	}

	void put()
	{
		person::put();
		cout << "\n Баллы по программированию:\t" << soft;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "\n Начинаю работу с бинарными файлами... \t";

	Skills x;
	ofstream f;

	cout << "\n Создаю бинарный файл... Начинайте ввод информации. \t";
	f.open("C:\\Users\\Боженька\\Desktop\\ComplexItog\\Files\\BINAR.dat", ios::binary);
	x.get();
	f.write(reinterpret_cast<char*>(&x), sizeof(x));
	f.close();
	cout << "\n Данные записаны в бинарный файл. \t";


	ifstream in;
	in.open("C:\\Users\\Боженька\\Desktop\\ComplexItog\\Files\\BINAR.dat", ios::binary);
	in.read(reinterpret_cast<char*>(&x), sizeof(x));
	cout << "\n Начинаю считывание данных из бинарного файла... \t";
	x.put();
	in.close();
	cout << "\n Данные из бинарного файла считаны. \t";
	system("pause");


	int x1, x4;
	int x2, x3;
	float aa;
	setlocale(LC_ALL, "Russian");

	
	cout << "\n" << "Введите параметры для числа А:" << "\n";
	cin >> x1 >> x2;
	cout << "Введите параметры для числа B:" << "\n";
	cin >> x3 >> x4;

    Complex A(x1,x2),B(x3,x4),C,ZZ;

	cout << "Деление на вещественное." << "\n";
	cout << "Результат деления:" << "\n";
	C = A / 5;
	ZZ = B / 5;


	C.OutD();
	ZZ.OutD();
	cout << "Деление двух комплексных." << "\n";
	cout << "Результат деления:" << "\n";
	C = A / B;
	C.OutD();
	cout << "\n";
	cout << "Разность комплексных." << "\n";
	cout << "Результат разности:" << "\n";
	C = A - B;
	C.OutD();
	cout << "Сумма комплексных." << "\n";
	cout << "Результат суммы:" << "\n";
	C = A + B;
	C.OutD();
	cout << "Умножение двух комплексныx." << "\n";
	cout << "Результат умножения:" << "\n";
    C = A * B;
	C.OutD();
	
	cout << "Умножение float на complex."<< "\n";
	cout << "На какое число желаете умножить?" << "\n";
	cin >> aa ;
	cout << "Результат умножения числа А:" << "\n";
	C = A * aa;
	C.OutD();
	cout << "Результат умножения числа В:" << "\n";
	ZZ = B * aa;
	ZZ.OutD();
	system("pause");

	
}

