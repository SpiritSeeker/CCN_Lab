#include <ctime>
#include <string>
#include <cmath>
#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
	std::vector<int> lambdas = {1, 4, 10};			// Average arrival rate
	for (int lambda : lambdas)
	{	
		double U, e;
		int N = 10000;						// Number of arrivals
		std::vector<double> E(N);			// Arrival time of nth packet
		int histSlots = 20;					// Number of bins in histogram
		std::vector<int> arrivals(2 * N);	// Number of arrivals per interval
		std::vector<int> P(histSlots);		// Number of entries per histogram bin

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

		std::vector<int> k(histSlots);
		std::vector<double> Pk(histSlots);
		for (int i = 0; i < histSlots; i++){
			k[i] = i;
			Pk[i] = ((double)P[i]/(double)((int)E[N-1]));
		}

		std::string name = "Lambda = " + std::to_string(lambda);
		plt::named_plot(name, k, Pk);
	}
	plt::legend();
	plt::show();
	return 0;
}