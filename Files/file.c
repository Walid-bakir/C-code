/*
First manipulation with files
*/

#include <stdio.h>
#include <stdlib.h> // exit()

#define MAX_HW 20
void how_to(){

    FILE *ptr = fopen("abc.txt", "r");

    if (ptr == NULL){
        printf("No such file\n");
    }

    char buf[100];
    while(fscanf(ptr, "%*s %s %*s", buf) == 1){

        printf("%s\n", buf);
    }
    /*
    Output:
    AGE
    12
    25
    65
    */
}

//----------------------------------------------------------------------------//

void read_data(FILE *ptr, int data[], int *size){
    // read the data stored in the file pointed to by ptr in the array of integers.
    *size = 0;
    while(fscanf(ptr, "%d", &data[*size]) == 1){
        (*size)++;
    }
}

void print_data(int d[], int size){
    for (int i = 0; i <size; i++){
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

double average(int d[], int size){
    double avg = 0.0;
    for (int i = 0; i < size; i++){
        avg += d[i];
    }
    return (avg/size);
}

void test1(){
    FILE *ptr;
    int sz = MAX_HW;
    int data[MAX_HW] = {100,0};
    ptr = fopen("myhw", "r");
    read_data(ptr, data, &sz);// here the sz will be equal to 12 not to MAX_HW,
                              // because we only have 12 scores. That is why we used a pointer
                              // so it would change to be exactly the number of scores we have
    printf("My %d homework scores are : \n", sz);
    print_data(data, sz);
    printf("Average score = %10f\n", average(data, sz));
    fclose(ptr);
}

//----------------------------------------------------------------------------//
void print_file(FILE *ifp){
    int c;
    rewind(ifp); // the begining of the file
    while ((c = getc(ifp)) != EOF){
        putc(c, stdout);
    }
}

void double_spaced(FILE *ifp, FILE *ofp){
    int c;
    rewind(ifp); // the begining of the file
    while ((c = getc(ifp)) != EOF){
        putc(c, ofp);
        if (c == '\n'){
            putc('\n', ofp);
        }
    }
}




int main(int argc, char const *argv[]) {
    // how_to();
    // test1();
    FILE *ifp, *ofp;
    if (argc != 3){
        printf("Need input and output files\n");
        exit(1);
    }

    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");
    print_file(ifp);
    double_spaced(ifp, ofp);
    printf("Double spaced file\n");
    print_file(ofp);
    fclose(ifp);
    fclose(ofp);
    return 0;
}
