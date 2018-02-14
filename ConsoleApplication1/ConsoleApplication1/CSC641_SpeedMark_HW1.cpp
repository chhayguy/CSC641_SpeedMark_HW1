 //File: CSC641_SpeedMark_HW1.cpp
 //Author: Richard Chhay
 //Institution: San Francisco State University
 //Date: February 13, 2018
 //Course: CSC 641 COMPUTER PERFORMANCE EVALUATION
 //Summary: This program seeks to provide an assessment of a computer's processing speed by using floating point and integer operations.
	//		When the program is ran it will perform two tests, matrix inversions and bubble sort. The program will record and calculate 
	//		the average speed that it takes for the tasks to be completed. 
//Sources: 
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;
const int x = 100, y = 100;
const float PI = 3.1415;

// ====== Time functions ======
double sec()
{
	return double(clock()) / double(CLOCKS_PER_SEC);
}
double millisec()
{
	return clock()*1000. / CLOCKS_PER_SEC;
}

// ====== Bubble Sort Assessment ======
void MakeRandArray(int c[], int n) // Populate the array
{
	int i;
	for (i = 0; i<n; i++) c[i] = rand();
}

void swap(int& a, int& b)
{
	int temp = a; a = b; b = temp;
}

void BubbleSort(int c[], int na)
{
	int i, done = 0; // Sort termination flag
	while ((!done) && (na > 1))
	{
		done = 1;
		for (i = 0; i < na - 1; i++)
			if (c[i] > c[i + 1])
			{
				swap(c[i], c[i + 1]); done = 0;
			}
		na--;
	}
}

int testBS(int c[], int na) // Test of correct sorting
{
	for (int i = 0; i < na - 1; i++) if (c[i]>c[i + 1]) return 0;
	return 1;
}

//	====== Integral Assessment ======
float integral(float(*f)(float x), float a, float b, int n) {
	float step = (b - a) / n;  // width of each small rectangle
	float area = 0.0;  // signed area
	for (int i = 0; i < n; i++) {
		area += f(a + (i + 0.5) * step) * step; // sum up each small rectangle
	}
	return area;
}

// ====== BEGIN MAIN ======
int main()
{
		int NINT = 0, NFLOAT = 0;
		double START, VINT, VFLOAT, AverageSpeed;

		// ====== Integral ======
		cout << "Begin Integral Assessment";
		START = sec(); // start timer for matrix inversion
		while (sec() < START + 10) { cout.precision(7); integral(cos, 0, PI / 2, 1000); NFLOAT++; }
		VFLOAT = NFLOAT / (sec() - START); // (number of ops * 60) / (final time - start time)
		cout << "\nNumber of Operations: " << NFLOAT << "\nElapsed Time for Matrix Inversion: " << (sec() - START);

		// ======= Bubble Sort =======
		// Initializing array to be sorted
		cout << "\n\nBegin Bubble Sort";
		int c[100000], na, delta = 5000;
		cout.setf(ios::fixed, ios::floatfield);
		cout.setf(ios::showpoint);

		// Populating array with data
		for (na = delta; na <= 10 * delta; na += (delta / 2))
		{
			MakeRandArray(c, na);
		}

		START = sec();	// start timer for bubble sort
		while (sec() < START + 10) { BubbleSort(c, na); NINT++; }
		if (testBS(c, na)) {
			cout << "\nNumber of Operations = " << setw(6) << na <<
				"\nTime Elaspsed Bubble Sort =" << setprecision(2) << setw(6) << sec() - START;
		}
		else {
			cout << "Bubble Sort Error!";
		}
		VINT = NINT / (sec() - START); // (number of ops * 60) / (final time - start time)

		//Calculating Average Speed
		AverageSpeed = (2 * VFLOAT*VINT) / (VFLOAT + VINT);

		cout << "\n\n\n====== FINAL RESULTS ======";
		printf("\nVFLOAT: %f\nVINT: %f\nAverageSpeed: %f\n", VFLOAT, VINT, AverageSpeed);

		return 0;
}

