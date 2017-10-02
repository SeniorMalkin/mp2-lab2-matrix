// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
	try
	{
		TMatrix<int> a(5), b(5), c(5);
		int i, j;

		setlocale(LC_ALL, "Russian");
		cout << "������������ �������� ��������� ������������� ����������� ������"
			<< endl;
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++)
			{
				a[i][j] = i * 10 + j;
				b[i][j] = (i * 10 + j) * 100;
			}
		c = a + b;
		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a + b" << endl << c << endl;
		cout << c[3][3];
		TMatrix<int> d(3), e(5);
		for (i = 0; i < 3; i++)
			for (j = i; j < 3; j++)
			{
				d[i][j] = i * 10 + j;

			}
		e = d + a;
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}
//---------------------------------------------------------------------------
