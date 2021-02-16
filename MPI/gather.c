#include <stdio.h>
#include <mpi.h>

void main(int argc, char *argv[])
{
    int rank, size, *param, mine[2];
    int sndcnt, rcvcnt;
    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    sndcnt = 2;
    mine[0] = rank;
    mine[1] = 23 + rank;
    if (rank == 0)
    {
        rcvcnt = 2;
        param = (int *)malloc(2 * size * sizeof(int));
    }

    MPI_Gather(mine, sndcnt, MPI_INT, param, rcvcnt, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        for (i = 0; i < size; ++i)
        {
            printf("Process:%d param[%d] is %d \n", param[2 * i], i, param[2 * i + 1]);
        }
    }
    MPI_Finalize();
}