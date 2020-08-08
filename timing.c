#include <stdio.h>
#include <time.h>

#include "yourfile.c" // Replace this with your file name

int main()
{
    clock_t t;
    t = clock();
    insert();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("insert() took %f seconds to execute \n", time_taken);

    t = clock();
    fetch();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("fetch() took %f seconds to execute \n", time_taken);

    clock_t t;
    t = clock();
    delete();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("delete() took %f seconds to execute \n", time_taken);

    return 0;
}
