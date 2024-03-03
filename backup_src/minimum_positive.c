#include "stdio.h"
#include "stdlib.h"

int main(int argc, char*argv[])
{
    int *array = malloc((argc -1) * sizeof(int)); 
    int *array_copy = malloc((argc -1) * sizeof(int));
    memset(array_copy, 0, argc -1);
    int size = argc - 1;
    int i = 0;
    for (i = 0; i < size; i++) {
        array[i] = atoi(argv[i+1]);
    }

    for (i = 0; i < size; i++) {
        if (array[i] <= size && array[i] > 0) {
            array_copy[array[i] - 1] = 1;
        } 
    }

    for (i = 0; i < size; i++) {
        if (array_copy[i] == 0) {
            break;
        }
    }

    printf("Mininum missing: %d", i + 1);
    

    free(array);
    free(array_copy);
    return 0;
}
