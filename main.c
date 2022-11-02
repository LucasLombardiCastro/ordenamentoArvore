#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno_ ALUNO;
struct aluno_{
        char nome[30]; //String que contem o nome do aluno
        int *notas; //Vetor alocado dinamicamente com as notas dos alunos 
        float media;
}; 

ALUNO *entradaDados(int quantidadeAlunos, int quantidadeProvas);
void aluno_vetorApaga(ALUNO *alunos, int quantidadeAlunos);
void imprimeTabela(ALUNO *alunos, int quantidadeAlunos, int quantidadeProvas);

int main(void){
    //Entrada de Dados
    int quantidadeAlunos, quantidadeProvas;
    scanf("%d %d\n", &quantidadeAlunos, &quantidadeProvas);
    ALUNO *alunos = entradaDados(quantidadeAlunos, quantidadeProvas);
    //imprimeTabela(alunos, quantidadeAlunos, quantidadeProvas);

    ALUNO *arvoreAlunos;

    aluno_vetorApaga(alunos, quantidadeAlunos); //Desalocando memoria utilizada
    return 0;
}

ALUNO *entradaDados(int quantidadeAlunos, int quantidadeProvas){
    ALUNO *alunos = (ALUNO *) calloc(quantidadeAlunos,sizeof(ALUNO)); //Vetor que armazena alunos
    if(alunos == NULL)
        exit (2);

    for(int i = 0; i < quantidadeAlunos; ++i){
        float mediaNotas = 0; //Variavel Auxiliar
        scanf("%s", alunos[i].nome); //Entrada do Nome
        alunos[i].notas = (int *) malloc(sizeof(int) * quantidadeProvas); //Alocando espaco para o vetor de notas 
        for(int j = 0; j < quantidadeProvas; ++j){ //Entrada das notas
            scanf("%d", &alunos[i].notas[j]); 
            mediaNotas += alunos[i].notas[j];
        }
        alunos[i].media = mediaNotas / quantidadeProvas; //Caluculando media de cada aluno
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
        printf("%s --> ", alunos[i].nome);
        for(int j = 0; j < quantidadeProvas; ++j)
            printf("%d ", alunos[i].notas[j]);
        printf("\nMedia: %f\n", alunos[i].media);
        printf("\n");
    }
}