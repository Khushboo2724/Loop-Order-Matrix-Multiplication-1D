#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
/*#include <plplot.h>*/
/*#include "gnuplot_i.h"*/


double get_cpu_frequency() {
    // need to determine the CPU frequency of system.
    // my laptop freq is about 2.40 to 2.42 GHz
    return 2.4e9; // 2.4 GHz
}


uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}


void matrix_multiply_flat(double *A, double *B, double *result1, double *result2, double *result3, double *result4, double *result5, double *result6, int dim) {
    int i, j, k;
    /*int result1[dim][dim];
    int result2[dim][dim];
    int result3[dim][dim];
    int result4[dim][dim];
    int result5[dim][dim];
    int result6[dim][dim];*/

    //clock_t start_time1 = clock();
    double cpu_freq = get_cpu_frequency();

    uint64_t start_time1 = rdtsc();

    
    // Perform matrix multiplication
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            for (k = 0; k < dim; k++) {
                result1[i * dim + j] += A[i * dim + k] * B[k * dim + j];
            }
        }
    }

    uint64_t end_time1 = rdtsc();
    double elapsed_time1 = (double)(end_time1 - start_time1) / cpu_freq;


    /*clock_t end_time1 = clock();
    double elapsed_time1 = (double)(end_time1 - start_time1) / CLOCKS_PER_SEC;*/
    printf("Time taken for FIRST IJK matrix multiplication: %f seconds\n", elapsed_time1);


    
    //second
    //clock_t start_time2 = clock();
    uint64_t start_time2 = rdtsc();

    
    // Perform matrix multiplication
    for (j = 0; j < dim; j++) {
        for (i = 0; i < dim; i++) {
            for (k = 0; k < dim; k++) {
                result2[i * dim + j] += A[i * dim + k] * B[k * dim + j];
            }
        }
    }

    uint64_t end_time2 = rdtsc();
    double elapsed_time2 = (double)(end_time2 - start_time2) / cpu_freq;


    /*clock_t end_time2 = clock();
    double elapsed_time2 = (double)(end_time2 - start_time2) / CLOCKS_PER_SEC;*/
    printf("Time taken for SECOND JIK matrix multiplication: %f seconds\n", elapsed_time2);


    
    //third
    //clock_t start_time3 = clock();
    uint64_t start_time3 = rdtsc();

   
    // Perform matrix multiplication
    for (k = 0; k < dim; k++) {
        for (j = 0; j < dim; j++) {
            for (i = 0; i < dim; i++) {
                result3[i * dim + j] += A[i * dim + k] * B[k * dim + j];
            }
        }
    }

    uint64_t end_time3 = rdtsc();
    double elapsed_time3 = (double)(end_time3 - start_time3) / cpu_freq;


    /*lock_t end_time3 = clock();
    double elapsed_time3 = (double)(end_time3 - start_time3) / CLOCKS_PER_SEC;*/
    printf("Time taken for THIRD KJI matrix multiplication: %f seconds\n", elapsed_time3);


    
    //fourth
    //clock_t start_time4 = clock();
    uint64_t start_time4 = rdtsc();
    
    
    // Perform matrix multiplication
    for (i = 0; i < dim; i++) {
        for (k = 0; k < dim; k++) {
            for (j = 0; j < dim; j++) {
               result4[i * dim + j] += A[i * dim + k] * B[k * dim + j];
            }
        }
    }

     uint64_t end_time4 = rdtsc();
    double elapsed_time4 = (double)(end_time4 - start_time4) / cpu_freq;


    /*clock_t end_time4 = clock();
    double elapsed_time4 = (double)(end_time4 - start_time4) / CLOCKS_PER_SEC;*/
    printf("Time taken for FOURTH IKJ matrix multiplication: %f seconds\n", elapsed_time4);


    
    //fifth
    //clock_t start_time5 = clock();
    uint64_t start_time5 = rdtsc();

    
    // Perform matrix multiplication
    for (j = 0; j < dim; j++) {
        for (k = 0; k < dim; k++) {
            for (i = 0; i < dim; i++) {
                result5[i * dim + j] += A[i * dim + k] * B[k * dim + j];
            }
        }
    }

     uint64_t end_time5 = rdtsc();
    double elapsed_time5 = (double)(end_time5 - start_time5) / cpu_freq;


    /*clock_t end_time5 = clock();
    double elapsed_time5 = (double)(end_time5 - start_time5) / CLOCKS_PER_SEC;*/
    printf("Time taken for FIFTH JKI matrix multiplication: %f seconds\n", elapsed_time5);


    
    //sixth
    //clock_t start_time6 = clock();
    uint64_t start_time6 = rdtsc();

   
    // Perform matrix multiplication
    for (k = 0; k < dim; k++) {
        for (i = 0; i < dim; i++) {
            for (j = 0; j < dim; j++) {
                result6[i * dim + j] += A[i * dim + k] * B[k * dim + j];
            }
        }
    }

    uint64_t end_time6 = rdtsc();
    double elapsed_time6 = (double)(end_time6 - start_time6) / cpu_freq;


    /*clock_t end_time6 = clock();
    double elapsed_time6 = (double)(end_time6 - start_time6) / CLOCKS_PER_SEC;*/
    printf("Time taken for SIXTH KIJ matrix multiplication: %f seconds\n", elapsed_time6);



    /*// Print the result
    printf("Result:\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }*/
}

int main() {
    int dim;
    
    // taking size of the matrix
    printf("Enter the dimension of the square matrices calloc rdtsc: ");
    scanf("%d", &dim);

    // Allocating memory for flattened matrices

    /*int *A_flat = (int *)malloc(dim * dim * sizeof(int));
    int *B_flat = (int *)malloc(dim * dim * sizeof(int));*/

    double *A_flat = (double *)malloc(dim * dim * sizeof(double));  //changed to double
    double *B_flat = (double *)malloc(dim * dim * sizeof(double));
    double *result1 = (double *)calloc(dim * dim, sizeof(double)); // Initialize result matrix with zeros
    double *result2 = (double *)calloc(dim * dim, sizeof(double)); // Initialize result matrix with zeros
    double *result3 = (double *)calloc(dim * dim, sizeof(double)); // Initialize result matrix with zeros
    double *result4 = (double *)calloc(dim * dim, sizeof(double)); // Initialize result matrix with zeros
    double *result5 = (double *)calloc(dim * dim, sizeof(double)); // Initialize result matrix with zeros
    double *result6 = (double *)calloc(dim * dim, sizeof(double)); // Initialize result matrix with zeros

    // Filling flattened matrices with random numbers
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < dim * dim; i++) {
        /*A_flat[i] = rand() % 10; // Random number between 0 and 9
        B_flat[i] = rand() % 10; // Random number between 0 and 9*/

        A_flat[i] = (double)rand() / RAND_MAX * 10.0; // Random number between 0 and 10
        B_flat[i] = (double)rand() / RAND_MAX * 10.0; // Random number between 0 and 10
    }
    

    // Perform matrix multiplication
    matrix_multiply_flat(A_flat, B_flat, result1, result2, result3, result4, result5, result6, dim);

    /*char *x[] = {"IJK", "JIK", "KJI", "IKJ", "JKI", "KIJ"}; //x axis
    double y[] = {elapsed_time1, elapsed_time2, elapsed_time3, elapsed_time4, elapsed_time5, elapsed_time6};  //y axis
    int num_points = sizeof(x) / sizeof(x[0]);*/
    
    

   /* plinit();  //plplot
    plline(num_points, x, y);

    plcol0(1);
    pllab("X", "Y", "Time Execution Plot");

      plend();*/

    
    
    /*h = gnuplot_init();  //glplot

    // Plot the data
    gnuplot_resetplot(h);
    gnuplot_setstyle(h, "lines");
    gnuplot_plot_xy(h, x, y, 6, "Time Execution Plot");
    gnuplot_close(h);*/

    // Free allocated memory
    free(A_flat);
    free(B_flat);
    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);
    free(result6);

    return 0;
}
