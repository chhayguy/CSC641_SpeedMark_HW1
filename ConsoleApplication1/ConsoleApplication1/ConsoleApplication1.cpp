#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

double sec(){
	return double(clock()) / double(CLOCKS_PER_SEC);
}
double millisec(){
	return clock()*1000. / CLOCKS_PER_SEC;
}

double DOUBLE() {
	return 0.;
}

int INTEGER() {
	return 0;
}

int main()
{
	int NINT = 0, NFLOAT = 0;
	double START, VINT, VFLOAT, AverageSpeed;

	START = sec();
	while (sec() < START + 3) { DOUBLE(); NFLOAT++; }
	VFLOAT = 60 * NFLOAT / (sec() - START);

	START = sec();
	while (sec() < START + 3) { INTEGER(); NINT++; }
	VINT = 60 * NINT / (sec() - START);

	AverageSpeed = 2 * VFLOAT*VINT / (VFLOAT + VINT);

	VFLOAT = 1.0; VINT = 2; AverageSpeed = 1;
	/*cout << VFLOAT, VINT, AverageSpeed;*/
	printf("VFLOAT: %f\n VINT: %u\n AverageSpeed: %f\n", VFLOAT, VINT, AverageSpeed);
}

