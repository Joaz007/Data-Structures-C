#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int *vector, size;

    //Determining the size chosen by the user
    printf("Type the size of the vector: \n");
    scanf("%d", &size);
    setbuf(stdin, NULL);

    vector = malloc(size * sizeof(int));//Allocating memory
    
    for (int i = 0; i < size; i++){
        printf("inform the vector[%d]:\n", i);
        scanf("%d", &vector[i]);
        setbuf(stdin, NULL);
    }
    
    printf("All values:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
    free(vector);//freeing the dynamic allocation

    return 0;
}