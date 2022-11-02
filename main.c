#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno_ ALUNO;
struct aluno_{
        char nome[30]; //String que contem o nome do aluno
        int *notas; //Vetor alocado dinamicamente com as notas dos alunos 
}; 

ALUNO *entradaDados(int quantidadeAlunos, int quantidadeProvas);
void aluno_vetorApaga(ALUNO *alunos, int quantidadeAlunos);
void imprimeTabela(ALUNO *alunos, int quantidadeAlunos, int quantidadeProvas);

int main(void){
    //Entrada de Dados
    int quantidadeAlunos, quantidadeProvas;
    scanf("%d %d\n", &quantidadeAlunos, &quantidadeProvas);
    ALUNO *alunos = entradaDados(quantidadeAlunos, quantidadeProvas);
    if(alunos == NULL) printf("Alunos eh NULL\n");
    imprimeTabela(alunos, quantidadeAlunos, quantidadeProvas);

    aluno_vetorApaga(alunos, quantidadeAlunos);
    return 0;
}

ALUNO *entradaDados(int quantidadeAlunos, int quantidadeProvas){
    ALUNO *alunos = (ALUNO *) calloc(quantidadeAlunos,sizeof(ALUNO)); //Vetor que armazena alunos
    if(alunos == NULL)
        exit (2);

    for(int i = 0; i < quantidadeAlunos; ++i){
        scanf("%s", alunos[i].nome);
        alunos[i].notas = (int *) malloc(sizeof(int) * quantidadeProvas);
        for(int j = 0; j < quantidadeProvas; ++j){
            scanf("%d", &alunos[i].notas[j]); 
        }
    }
       
    return alunos;
}

void aluno_vetorApaga(ALUNO *alunos, int quantidadeAlunos){
    //Responsavel por apagar alunos que estao no vetor alunos dado
    for(int i = 0; i < quantidadeAlunos; ++i)
        free(alunos[i].notas); //Apagando o vetor associado ao aluno dado   
    free(alunos); //Apagando o vetor de notas associado ao aluno dado

}   

void imprimeTabela(ALUNO *alunos, int quantidadeAlunos, int quantidadeProvas){
    //Imprimindo os dados de todos os alunos 
    for(int i = 0; i < quantidadeAlunos; ++i){
        printf("%s ", alunos[i].nome);
        for(int j = 0; j < quantidadeProvas; ++j)
            printf("%d ", alunos[i].notas[j]);
        printf("\n");
    }
}