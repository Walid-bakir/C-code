#include<stdio.h>
#include<stdlib.h>

// in int main(int argc , char *argv[])
/*
argc represents the number of things that we enter into the command prompt
for example:
int main(int argc , char *argv[])
{
   printf("argc = %d\n", argc) \\ we wanna see what value is stored in argc
}
after compaling this programme (lets call it add),
if i do ./add , I will get argc = 1
if i do ./add walid bakir 65 , i will get argc = 4

argv[] is much like sys,argv[] in Python, it is a list of strings that holds
what we write in the command prompt

int main(int argc , char *argv[])
{
   int i;
   for (i = 0, i < argc , i++){
      printf("argv[%d] = %s\n", i, argv[i]);
 }
}

if i do ./args walid bakir 65 , i will get
argv[0] = ./args
argv[1] = walid
argv[2] = bakie
argv[3] = 65
*/
int main(int argc , char *argv[])
{
   printf("argc = %d" , argc);
   int i;
   for (i = 0; i < argc ; i++){
      printf("argv[%d] = %s\n", i, argv[i]);
 }
}
