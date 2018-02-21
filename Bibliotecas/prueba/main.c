#include <stdio.h>
#include <stdlib.h>

int algo () {
    printf ("algo\n");
}

int otracosa () {
    printf ("otracosa\n");
}

int main() {
    int pepe;
    int* ptr;
    int (*add[2])();
    int (*pp) ();
    int array_int1[] = {1, 2, 3};
    int array_int2[] = {4, 5, 6};
    int ptr_array[];


    ptr = array_int1;

    printf ("%d\n", array_int1[1]);
    printf ("%d\n", ptr[2]);

/*

    add[0] = algo;
    //add ();

    add[1] = otracosa;
    //add ();

    pp = add[1];
    pp ();

*/
    //printf ("%d\n", *add);
/*
    ptr = &pepe;
    pepe = 44;

    printf ("%d\n", pepe);
    printf ("%d\n", *ptr);

    *ptr = 160;

    printf ("%d\n", pepe);
*/
    return 0;
}
