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

int sumArray(int arr[][3], int N);
int minSumArr(int arrSum[], int N);
void displayArray1D(int a[], int n);
void displayArray2D(int a[][3], int n);
void sumDiangle(int arr[][3], int arrSum[], int N, int M);


int main()
{
	int const N = 3; 
	int arr[N][N] = { { 2,-2,3 },
					{ -4,4,6 },
					{ 7,-23,9 } };
	////////////////////////// OUTPUT ARR //////////////////////////
	printf_s("elements of array: ");
	displayArray2D(arr, N);
	//////////////////////// SUM POSITIVE ROWS ////////////////////
	cout << "sum of the elemetns from rows that don't include negative numbers = " << sumArray(arr, N) << endl;
	int arrSum[(N * 2) - 1] = { 0 };
	/////////////////////// SUM DIANGLE //////////////////////////
	sumDiangle(arr, arrSum, N, (N * 2) - 1);
	cout << "sumArr = ";
	displayArray1D(arrSum, (N * 2) - 1);
	////////////////////// MIN SUM DIANGLE //////////////////////
	cout << "minSumArr = " << minSumArr(arrSum, N) << endl;

	system("pause");
	return 0;
}

void displayArray2D(int a[][3], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}
	cout << endl;
}

void displayArray1D(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int sumArray(int arr[][3], int N) {
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
	return s;
}

void sumDiangle(int arr[][3], int arrSum[], int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arrSum[i + j] = arrSum[i + j] + arr[i][j];
		}
	}
}

int minSumArr(int arrSum[], int N) {
	int minSum = arrSum[0];
	for (int i = 1; i < (N * 2) - 1; i++)
		if (arrSum[i] < minSum) minSum = arrSum[i];
	return minSum;
}