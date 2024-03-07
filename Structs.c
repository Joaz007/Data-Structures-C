#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    float grade[4]; 
} Aluno;

void Print_Student(Aluno Alunos){

    printf("Name: %s \n",Alunos.name);
    printf("Grades:");
    for (int i = 0; i < 4; i++){
        printf("%.2f ", Alunos.grade[i]);
    }

    printf("\n ");
        
    return;
}

int main(){
    Aluno Alunos;

    printf("Type the  name of the student:\n");
    fgets(Alunos.name, sizeof(Alunos.name), stdin);
    Alunos.name[strcspn(Alunos.name, "\n")] = 0;

    for (int i = 0; i < 4; i++){
    printf("Type the Grade[%i]: \n", i+1);
    scanf("%f", &Alunos.grade[i]);
    setbuf(stdin ,NULL);
    }


    Print_Student(Alunos);
    
    return 0;
}