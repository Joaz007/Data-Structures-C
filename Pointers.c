#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SpeedCalculator(int miles, float *km_h, float *m_s){

    *km_h = miles * 1.6;
    *m_s = *km_h / 3.6;

printf("%2.0f \n", *m_s);

    return;
}

//Pointers only take the memory address
int main(){
    int milesph;//Start value
    float kmh, ms; //Speeds kilometer/hour, meter/second 
    
    //Determining the information chosen by the user
    printf("Type the speed in miles/h:\n");
    scanf("%d", &milesph);
    setbuf(stdin ,NULL);

    SpeedCalculator(milesph, &kmh, &ms);    //Call function

    printf("Speed in Miles per hour: %d \n", milesph);
    printf("Speed in Kilometers per hour: %.2f \n", kmh);
    printf("Speed in Meter per second: %.2f \n", ms);

    return 0;
}