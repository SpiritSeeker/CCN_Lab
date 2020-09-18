# Assignment 1
----------------
## Generating traffic following a Poisson distribution
The file `poisson.cpp` plots Poisson distributed traffic for different average arrival rates. The matplotlib plotting library is used to generate the plots.
### Compile and Run
From the root folder compile using
```shell
g++ Assignment/poisson.cpp -std=c++11 -I/usr/include/python3.5m -Ivendor/matplotlib-cpp -lpython3.5m -o Assignment1/poisson
```
and run using
```shell
./Assignment1/poisson
```
#### Notes
* The code has been tested for C++ standard 11 and above. Replace `-std=c++11` with a version of your choice, if needed.
* This example demonstrates compiling with a Python3.5m backend. The include path and the linker directive are to be replaced with your installation of Python.
--------------------
