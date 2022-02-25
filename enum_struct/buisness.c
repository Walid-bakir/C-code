/*
struct that has a member that is the name of a business department: HR, Sales,
Research, Software, and Executive (use enums for the 4 departments).  A second
member that is an annual salary as an int. A third member that is a social
security number(unsigned).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum department {Hr, Research, Software, Executive};

typedef enum department department;

typedef struct Employee{
    department dep;
    int salary;
    unsigned int ssn; // social security number
}Employee;

char *print_dep(department dep){
    // print the departement name
    char *s;
    switch (dep) {
        case Hr: s = "HR";break;
        case Research: s = "Research";break;;
        case Software: s = "Software";break;;
        case Executive: s = "Executive";break;;
    }
    return s;
}

void printEmp(const Employee *emp){
    // print the employee info
    printf("department = %s | salary = %d | social_security = %d\n", print_dep(emp->dep), emp->salary, emp->ssn);
}

int salary_generator(department dep){
    // generate random salaries for each departement
    int salary = 2000;
    switch (dep) {
        case Hr: salary += 500;break;
        case Research: salary += 1000;break;
        case Software: salary += 1500;break;
        case Executive: salary += 2000;break;
    }
    return salary;
}

int main(int argc, char const *argv[]) {
    srand(time(0)); // to use random function
    int upper = 2090192902; // used in the social_security number generation
    int lower = 3000;
    for (int i = 0; i < 10; i++){
        Employee emp;
        int random_departement = rand()%4;
        emp.dep = random_departement;
        emp.salary = salary_generator(emp.dep);
        emp.ssn = (rand() %
           (upper - lower + 1)) + lower;;
        printEmp(&emp);
    }

    return 0;
}
