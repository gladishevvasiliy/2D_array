/// 2d-array.cpp: определяет точку входа для консольного приложения.
//cумму эл-тов в тех строках, которые не содержат отрицательных эл-тов
//макс среди сумм эл-тов диагоналей, паралельной главной

#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <clocale>
#include <cfloat>
#include <iostream>
#include <conio.h>


using namespace std;

void displayArray(int a[][3], int n);

int main()
{

	int const N = 3;
	int arr[N][N] = { { 1,2,3 },
	{ 4,5,6 },
	{ 7,8,9 } };
	printf_s("elements of array: ");
	/**/
	displayArray(arr, N);


	//cумму эл-тов в тех строках, которые не содержат отрицательных эл-тов
	int s = 0;
	int s1;
	for (int i = 0; i < N; i++) {
		s1 = 0;
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > 0) s1 = s1 + arr[i][j];
			else { s1 = 0; break; };
		}
		s += s1;

	}
	cout << "sum of the elemetns from rows that don't include negative numbers = " << s << endl;

	int n = 3;
	int m = (n * 2) - 1;
	float *arrSum = new float[m];

	//int tmp = (n * 2) - 1;
	//int const m = tmp;
	//float arrSum[N*2-1];
	for (int i = 0;i < m; i++) arrSum[i] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrSum[i + j] = arrSum[i + j] + arr[i][j];
		}
	}

	cout << "sumArr = ";
	for (int i = 0; i < m; i++)
		cout << arrSum[i] << " ";
	cout << endl;

	float minSumArr = arrSum[0];
	for (int i = 1; i < m; i++)
		if (arrSum[i] < minSumArr) minSumArr = arrSum[i];

	cout << "minSumArr = " << minSumArr << endl;

	system("pause");
	return 0;
}

void displayArray(int a[][3], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}
	cout << endl;
}
