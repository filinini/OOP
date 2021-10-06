#pragma once
#include <iostream>
#include "Matrix.h"
#include "ctime"
#include <cassert>

using namespace std;

void Test()                                   //Текс main
{
	srand(time(0));
	Matrix mtrx = Matrix(4);
	mtrx.Inic();
	cout << "Матрица 1" << endl;
	cout << mtrx.ToString() << endl;

	cout << endl;

	Matrix mtrx2 = Matrix(4);
	mtrx2.Inic();
	cout << "Матрица 2" << endl;
	cout << mtrx2.ToString() << endl;


	Matrix mtrx3 = mtrx.Summtrx(mtrx2);
	cout << "\nСумма матриц" << endl;
	cout << mtrx3.ToString() << endl;

	mtrx.Transposition();
	cout << "\nТранспонированная 1 матрица" << endl;
	cout << mtrx.ToString() << endl;
	assert(Matrix::Count == 3);
	cout << "\nКоличество созданных матриц" << endl;
	cout << Matrix::Count << endl;
}

void Test2()                                    //Проверка SetElem и GetElem
{
	Matrix mtrx = Matrix(3);
	mtrx.SetElem(1, 1, 5);
	assert(mtrx.GetElem(1, 1) == 5);
}

void Test3()                                   //Проверка Summtrx                          
{
	Matrix mtrx = Matrix(3);
	mtrx.Inic();
	Matrix mtrx2 = Matrix(3);
	mtrx2.Inic();
	Matrix mtrx3 = mtrx.Summtrx(mtrx2);
	for (int i=0; i<3; i++)
		for (int j = 0; j < 3; j++)
		{
			assert(mtrx.GetElem(i, j) + mtrx2.GetElem(i, j) == mtrx3.GetElem(i, j));	
		}
}

void Test4()  //Проверка транспонирования
{
	Matrix mtrx = Matrix(3);
	mtrx.Inic();
	Matrix mtrx2 = mtrx;
	mtrx2.Transposition();
	assert(mtrx.GetElem(1, 0) == mtrx2.GetElem(0,1));
}

void Test5() //конструктор копирования
{
	cout << "\n Конструктор копирования. Матрица1: " << endl;
	Matrix mtrx = Matrix(3);
	mtrx.Inic();
	cout << mtrx.ToString() << endl;
	Matrix newmtrx = Matrix(mtrx);
	cout << "Новая матрица(копия матрицы1): " << endl;
	cout << newmtrx.ToString() << endl;
}