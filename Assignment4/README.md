# Assignment 4

## Simulation of Go-back-N ARQ protocol using Sockets
Files `send.cpp` and `recv.cpp` contain the codes for the sender and receiver, respectively. The in-house Socket library is used to create the sockets and to transfer data between them.
### Compile and Run
Unified `make` is recommended for compiling all the Assignments. Instead, if individual compilation is necessary, run the following commands from the `Assignment4/` directory
```shell
g++ recv.cpp -std=c++17 -I../src -o recv
g++ send.cpp -std=c++17 -I../src -o send
```
and run from two different terminals using
```shell
./recv
./send
```
#### Notes
* The code has been tested for C++ standard 11 and above. Replace `-std=c++17` with a version of your choice, if needed.