#include <stdio.h>
#include <omp.h>

int main(){
    int num_iterations;
    printf("enter the number of iterations:");
    scanf("%d",&num_iterations);
    #pragma  omp parallel
    {
        #pragma omp for schedule(static,2)
        for(int i=0; i < num_iterations;i++){
            printf("Thread %d: Iteration %d\n",omp_get_thread_num(),i);
        }
    }
    return 0;
}
// PS C:\23cs177pp> gcc -fopenmp lab2.c -o lab2
// PS C:\23cs177pp> ./lab2.exe
// enter the number of iterations:2
// Thread 0: Iteration 0
// Thread 0: Iteration 1
// PS C:\23cs177pp> ./lab2.exe
// enter the number of iterations:5
// Thread 0: Iteration 0
// Thread 0: Iteration 1
// Thread 2: Iteration 4
// Thread 1: Iteration 2
// Thread 1: Iteration 3
// PS C:\23cs177pp> 
