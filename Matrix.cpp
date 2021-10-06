#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include "ctime"

using namespace std;

int Matrix::Count = 0;

Matrix::~Matrix()
{
	Count--;
}

Matrix::Matrix()
{
	n =1;
	mtrx = nullptr;
}

Matrix::Matrix(const Matrix& ob)
	:Matrix(ob.n)
{
	this->mtrx = nullptr;

		if (n < 1 ||  n > INT32_MAX )
			throw 1;

		mtrx = new int* [n];

		for (int i = 0; i < n; i++)
		{
			mtrx[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				mtrx[i][j] = ob.mtrx[i][j];

			}
		}
}

Matrix::Matrix(int N)    //Вызывается конструктор с параметром
{
	n = N;
	mtrx = nullptr;
	try
	{
		if (n < 1)       //Проверка на корректность введенного порядка матрицы
			throw 123;
		mtrx = new int* [n];
		for (int i = 0; i < n; i++)
		{
			mtrx[i] = new int[n];
		}
	}
	catch (int i)
	{
		cout << "ошибка:" << i << "некоректное n" << endl;
	}
	Count++;
}

void Matrix::Transposition()              //Реализация метода транспонирования матрицы
{
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			t = mtrx[i][j];
			mtrx[i][j] = mtrx[j][i];
			mtrx[j][i] = t;
		}
	}
}

void Matrix::SetElem(int i, int j, int a)  //Реализация метода обращения к данным матрицы
{
	mtrx[i][j] = a;
}

int Matrix::GetElem(int i, int j)          //Реализация метода возвращения значений матрицы
{
	return  mtrx[i][j];
}

Matrix Matrix::Summtrx(Matrix mtrx1)      //Реализация метода суммирования двух матриц
{
	Matrix C = Matrix(this->n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			C.SetElem(i, j, this->mtrx[i][j] + mtrx1.GetElem(i, j));
	return C;
}

char* Matrix::ToString()
{
	char** str = new char* [n];
	int index = 0;
	char* mystring = new char[n * n * 6];
	mystring[0] = '\0';
	for (int i = 0; i < n; i++)
	{
		str[i] = new char[n * 6];
		str[i][0] = '\0';
		for (int j = 0; j < n; j++)
		{
			char ch[5];
			_itoa_s(mtrx[i][j], ch, 10);
			ch[4] = '\0';
			strcat_s(str[i], n * 6, ch);

			strcat_s(str[i], n * 6, " ");
		}
		if (i < n - 1)
			strcat_s(str[i],n * 6, "\n");
		strcat_s(mystring, n * n * 6, str[i]);

	}

	return mystring;
}

void Matrix::Inic()                       //Реализация метода инициализации матрицы
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mtrx[i][j] = -100 + rand() % 200;
}
