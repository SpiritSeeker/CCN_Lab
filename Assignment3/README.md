# Assignment 3

## Simulation of Stop-and-Wait protocol using Sockets
Files `sender.cpp` and `receiver.cpp` contain the codes for the sender and receiver, respectively. The in-house Socket library is used to create the sockets and to transfer data between them.
### Compile and Run
Unified `make` is recommended for compiling all the Assignments. Instead, if individual compilation is necessary, run the following commands from the `Assignment3/` directory
```shell
g++ receiver.cpp -std=c++17 -I../src -o receiver
g++ sender.cpp -std=c++17 -I../src -o sender
```
and run from two different terminals using
```shell
./receiver
./sender
```
#### Notes
* The code has been tested for C++ standard 11 and above. Replace `-std=c++17` with a version of your choice, if needed.