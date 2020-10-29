# Assignment 2

## Implementation of inter-process communication using Sockets
Files `server.cpp` and `client.cpp` contain the codes for the socket server and socket client, respectively. The in-house Socket library is used to create the sockets and to transfer data between them.
### Compile and Run
Unified `make` is recommended for compiliing all the Assignments. Instead, if individual compilation is necessary, run the following commands from the `Assignment2/` directory
```shell
g++ server.cpp -std=c++17 -I../src -o server
g++ client.cpp -std=c++17 -I../src -o client
```
and run from two different terminals using
```shell
./server
./client
```
#### Notes
* The code has been tested for C++ standard 11 and above. Replace `-std=c++17` with a version of your choice, if needed.