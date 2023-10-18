#include <iostream>
#include <mpi.h> // Include the header file.

// In any MPI program:
// 
// 1. Launch
// 2. Initialization 
// 3. Ranking Assignment
// 4. Conditional Execution (add the pre-condition as well)
// 5. Communication
// 6. Finalization


int main(int argc, char **argv) {
    
    // Initialize the MPI environment
    // This is an alternative way to initialize MPI
    // MPI_Init(nullptr, nullptr);
    // If you want to passthrough arguments:
    MPI_Init(&argc, &argv);

    // Get the number of processes.
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int NUMBER_OF_PROCESSES_NEEDED = 2;

    // std::cout << size << std::endl;

    // Ensure there are 2 processes.
    if (size != NUMBER_OF_PROCESSES_NEEDED) {
        std::cerr << "This application meant to be run with only 2 processes.";
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    // Get the rank of the process
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    std::cout << "Rank: " << rank << std::endl;

    // Specific actions depnding on the process
    //
    // buf - initial address of send buffer (choice)
    // count - number of elements in send buffer (nonnegative integer)
    // datatype - datatype of each send buffer element (handle)
    // dest - rank of destination (integer)
    // tag - message tag (integer)
    //     - Tag? https://stackoverflow.com/questions/31386659/when-to-use-tags-when-sending-and-receiving-messages-in-mpi
    // comm - communicator (handle)

    if (rank == 0) {
        
        int value = 125; // Value to be sent to process 1
        int RANK_TO_BE_SENT_TO = 1;
        MPI_Send(&value, 1, MPI_INT, RANK_TO_BE_SENT_TO, 0, MPI_COMM_WORLD);

    } else if (rank == 1) {
        
        int value;
        // More about MPI_Status:
        // https://rookiehpc.org/mpi/docs/mpi_status/index.html
        // MPI_STATUS_IGNORE - https://www.mcs.anl.gov/research/projects/mpi/mpi-standard/mpi-report-2.0/node47.htm
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int mulValue = value * 2;
        std::cout << "Process 1 received " << value << " from Process 0" << std::endl;
        std::cout << "The multiplied value is " << mulValue << std::endl;

    }

    MPI_Finalize();

    return 0;

}
