#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

void main(int argc, char *argv[])
{
    int rank, size, *ranks;
    char *param;
    char msg[100];
    int sndcnt, rcvcnt;
    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    sndcnt = 100;
    //srank = itoa(rank,srank,10);
    sprintf(msg, "Process %d with message: Hello\n", rank);
    // strcat(mine, srank);

    if (rank == 0)
    {
        rcvcnt = 100;
        param = (char *)malloc(100 * size * sizeof(char));
    }

    MPI_Gather(&msg, sndcnt, MPI_CHAR, param, rcvcnt, MPI_CHAR, 0, MPI_COMM_WORLD);
    if (rank == 0)
        for (i = 0; i < size; ++i)
            printf("%s", param + i * 100);
    MPI_Finalize();
}