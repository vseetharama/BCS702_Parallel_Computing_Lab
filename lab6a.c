#include <stdio.h>
#include <mpi.h>

#define SIZE 20000000

int main(int argc, char *argv[])
{
    int rank;

    static int data_recv[SIZE];
    static int data_send[SIZE];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // data_send[1] = rank;

    if (rank == 0) {
        for (rank = 1; rank < 20; rank++) {
            MPI_Send(data_send, SIZE, MPI_INT, rank, 0, MPI_COMM_WORLD);
        }
    }
    else {
        MPI_Recv(data_recv, SIZE, MPI_INT, 0, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    if (rank != 0)
        printf("Process %d received %d\n", rank, data_recv[0]);
    else
        printf("Process 0 received 0\n");

    MPI_Finalize();
    return 0;
}
