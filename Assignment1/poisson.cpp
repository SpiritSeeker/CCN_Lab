#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
	int lambda = 1;					// Average arrival rate
	double U, e;
	int N = 10000;					// Number of arrivals
	double E[N];					// Arrival time of nth packet
	int histSlots = lambda * 4;		// Number of bins in histogram
	int arrivals[N];				// Number of arrivals per interval
	int P[histSlots];				// Number of entries per histogram bin

	E[0] = 0;
	for (int i = 0; i < N; i++) arrivals[i] = 0;
	for (int i = 0; i < histSlots; i++) P[i] = 0;

	srand(time(NULL));

	for (int i = 1; i < N; i++){
		U = (rand() % RAND_MAX+1) / (1.0*(RAND_MAX));
		e = -log(U) / lambda;
		E[i] = E[i-1] + e;			// Arrival time of ith packet
		arrivals[(int)(E[i])]++;	// Count number of packets per interval
	}

	// Count number of intervals with given number of arrivals
	for (int i = 0; i < int(E[N-1]); i++){
		if(arrivals[i] < histSlots)
			P[arrivals[i]]++;
	}

	for (int i = 0; i < histSlots; i++)
		cout << "P[" << i << "] = " << (P[i]/(double)((int)E[N-1])) << endl;
	return 0;
}