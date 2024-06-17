// may 29

#include <stdio.h>

int main(){

    const unsigned int array_size = 10;

    int grades[] = {56, 78, 93, 67, 82, 46, 71, 65, 54, 88};

    for ( unsigned int i = 0; i < array_size; ++i) {
        printf("grades[%d]= %d", i, grades[i]);
        printf("and is located at memory address %p\n", &grades[i]);

    } 

    printf("\nUsing the memory address of symbol &:\n");
    printf("is &grades[0] == grades?\n");

    printf("The answer is %d, since &grades [0] has memory address %p and grades has memory address of %p. \n", &grades[0] == grades, &grades[0], grades);

    printf("\nUsing the derefrecing symbol *:\n");
    printf("Is *(grades +5) == grades[5]?\n");

    printf("The answer is %d, since *(grades+5) is %d and grades[5] is of %d. \n", *(grades+5) == grades[5], *(grades+5), grades[5]);
   
    printf("\nUsing the memory address symbol & again:\n");
    printf("Is (5+grades) == &grades[5]?\n");

    printf("The answer is %d, since (5+grades) has memory address %p and &grades[5] has memory address of %p.\n\n", (5+grades) == &grades[5], (5+grades), &grades[5]);


}
