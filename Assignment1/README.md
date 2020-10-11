# Assignment 1
----------------
## Generation of different traffic distributions
Files `poisson.cpp` and `pareto.cpp` contain the codes for generating and plotting Poisson and Pareto distributions, respectively. The matplotlib plotting library is used to generate the plots.
### Compile and Run
Unified `make` is recommended for compiliing all the Assignments. Instead, if individual compilation is necessary, run the following commands from the `Assignment1/` directory
```shell
g++ poisson.cpp -std=c++17 -I/usr/include/python3.5m -I../vendor/matplotlib-cpp -lpython3.5m -o poisson
g++ pareto.cpp -std=c++17 -I/usr/include/python3.5m -I../vendor/matplotlib-cpp -lpython3.5m -o pareto
```
and run using
```shell
./poisson
./pareto
```
#### Notes
* The code has been tested for C++ standard 11 and above. Replace `-std=c++17` with a version of your choice, if needed.
* This example demonstrates compiling with a Python3.5m backend. The include path and the linker directive are to be replaced with your installation of Python. The same applies for the unified compilation using Premake. Replace the given version of Python with your version in the `premake5.lua` file present in this directory. Changes have to be made in 4 locations.
