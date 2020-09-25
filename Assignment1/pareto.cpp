#include <ctime>
#include <vector>
#include <cmath>
#include <string>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
	std::vector<int> alphas = {2, 3, 5};	// Shape parameter
	for (int alpha : alphas)
	{
		double x_m = 0.1;					// Scale parameter
		double U, e;
		int N = 10000000;					// Number of packets
		std::vector<double> E(N);			// Arrival times
		int histSlots = floor(1 / x_m) * 2;	// Number of bins in histogram
		std::vector<int> arrivals(2 * N);	// Number of arrivals per interval
		std::vector<int> P(histSlots);		// Number of entries per histogram bin

		// Initialize the vectors
		E[0] = 0;
		for (int i = 0; i < 2 * N; i++) arrivals[i] = 0;
		for (int i = 0; i < histSlots; i++) P[i] = 0;

		srand(time(NULL));

		for (int i = 0; i < N; i++)
		{
			U = (rand() % RAND_MAX + 1) / (1.0 * RAND_MAX);		// Uniform distribution
			e = x_m / pow(U, 1.0 / alpha);						// Convert uniform to pareto distribution
			E[i] = E[i-1] + e;									// Calculate arrival time of packet
			if ((int)(E[i]) < 2 * N) arrivals[(int)(E[i])]++;	// Increment the appropriate bin
		}

		// Count number of intervals with given number of arrivals
		for (int i = 0; i < int(E[N-1]); i++)
		{
			if(arrivals[i] < histSlots)
				P[arrivals[i]]++;
		}

		// Generate PMF for plotting
		std::vector<int> k(histSlots);
		std::vector<double> Pk(histSlots);
		for (int i = 0; i < histSlots; i++)
		{
			k[i] = i;
			Pk[i] = ((double)P[i]/(double)((int)E[N-1]));
		}

		// Plot the curve
		std::string name = "$\\alpha$ = " + std::to_string(alpha);
		plt::named_plot(name, k, Pk);
	}
	plt::xlabel("Number of occurences");
	plt::ylabel("Probability");
	plt::title("Pareto distribution");
	plt::legend();
	plt::show();
	return 0;
}