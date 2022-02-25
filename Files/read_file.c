/*
Open and read a file of integers into an array that is created with
the first integer telling you how many to read.

Date : 24/02/2022
Author : Walid Bakir
*/

#define LIST_SIZE 20

#include <stdio.h>
#include <stdlib.h>


void read_data(int data[], int *size){
    // read the integers in the file and store them in data list.
    // size will be the first integer in the file.
    FILE *intFile = fopen("answer_hw3", "r");
    fscanf(intFile, "%d", size); // get the first int and store it in the refrence
                                // to the pointer size.
    for (int i = 0; i < *size; i++){
        // read the required number of ints
        fscanf(intFile, "%d", &data[i]);
    }
    fclose(intFile);
}

void print_data(int data[], int size){
    // print the integers in the data list.
    printf("The %d integers that were read from the file : \n", size);
    for (int i = 0; i < size; i++){
        printf("%d\t", data[i]);
        if ((i + 1) % 10 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

double average(int d[], int size){
    // Compute the averge of the read values.
    double avg = 0.0;
    for (int i = 0; i < size; i++){
        avg += d[i];
    }
    return (avg/size);
}

int max_data(int data[], int size){
    // Compute the maximum of the read values.
    int maxi = data[0];
    for (int i = 1; i < size; i++){
        if (maxi < data[i]){
            maxi = data[i];
        }
    }
    return maxi;
}

void max_average_data(int data[], double *avg, int *max, int size){
    // Compute bith the average and maximum at the same time
    *max = data[0];
    *avg = 0.0;
    for (int i = 0; i < size; i++){
        if (*max < data[i]){
            *max = data[i];
        }
        *avg += data[i];
    }
    *avg = (*avg)/size;
}

int main(int argc, char const *argv[]) {
    int size = LIST_SIZE;
    int data[LIST_SIZE]; // We used a global variable and a pointer size,
                         // so that when we get the value of the size, it will be
                         // changed for the variable LIST_SIZE as well.

    read_data(data, &size);
    print_data(data, size);
    printf("The average of the read integer values is : %lf\n", average(data, size));
    printf("The maximum of the read integer values is : %d\n", max_data(data, size));

    int maximum;
    double average;
    max_average_data(data, &average, &maximum, size);
    printf("The average of the read integer values is : %lf\n", average);
    printf("The maximum of the read integer values is : %d\n", maximum);
    return 0;
}
