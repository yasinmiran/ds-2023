#include <iostream>
#include <mpi.h> // Include the header file.

// mpic++ ./main.cpp -o app
// mpiexec ./app
// mpiexec -n 3 ./app

int main(int argc, char **argv) {
    
    // Initialize the MPI environment
    // This is an alternative way to initialize MPI
    // MPI_Init(nullptr, nullptr);
    // If you want to passthrough arguments:
    MPI_Init(&argc, &argv);

    // Get the number of processes.
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << size << std::endl;

    // Ensure there are 3 processes.
    if (size != 3) {
        std::cerr << "This application meant to be run with only 3 processes.";
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE)
    }

}
