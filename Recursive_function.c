#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 3 * 2 * 1 */

int Factorial_Calculator(int number){
    int fat;

    if (number <= 1){
        return 1;
    } else {
        fat = number * Factorial_Calculator(number -1);
        return fat;
    }
}

int main(){
    int num, result;

    printf("Type the number to calculate the factorial:\n");
    scanf("%d", &num);
    setbuf(stdin, NULL);

    result = Factorial_Calculator(num);
    printf("The factorial of %d is %d\n", num, result);

    return 0;
}