#include <stdio.h>
#include <stdlib.h>

#define NUM_BLOCKS 32
#define BLOCK_WIDTH 1

__global__ void hello()
{
    printf("Hello world! I'm thread %d in block %d\n", threadIdx.x, blockIdx.x);
}


int main(int argc,char **argv)
{
    int num_blocks = NUM_BLOCKS, block_width = BLOCK_WIDTH;
    if(argc>1){
        num_blocks = atoi(argv[1]);
        block_width = atoi(argv[2]);
    }
    // launch the kernel
    hello<<<num_blocks, block_width>>>();

    // force the printf()s to flush
    cudaDeviceSynchronize();
    
    return 0;
}
