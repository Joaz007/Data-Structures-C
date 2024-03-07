#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    float grade[4]; 
} Alunos;

void Print_Student(Alunos Aluno){

    printf("Name: %s \n",Aluno.name);
    printf("Grades:");
    for (int i = 0; i < 4; i++){
        printf("%.2f ", Aluno.grade[i]);
    }
    printf("\n");
        
    return;
}

//broxa do CARALHO
int main(){
    Alunos Aluno;

    printf("Type the  name of the student:\n");
    fgets(Aluno.name, sizeof(Aluno.name), stdin);
    Aluno.name[strcspn(Aluno.name, "\n")] = 0;

    for (int i = 0; i < 4; i++){
    printf("Type the Grade[%i]: \n", i+1);
    scanf("%f", &Aluno.grade[i]);
    setbuf(stdin ,NULL);
    }

    Print_Student(Aluno);
    
    return 0;
}