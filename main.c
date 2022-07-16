//Resposta Questão 04.2 : Letra G) Ordem Simétrica


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define LSIZE 10
#define MAX 100



typedef struct{
  int numMatricula;
  char nome[100];
  char email[100];
} TAluno;

struct SNoAlunoDE{
  TAluno aluno;
  struct SNoAlunoDE *dir;
  struct SNoAlunoDE *esq;

};

typedef struct SNoAlunoDE TRaizArvAluno;
typedef TRaizArvAluno *PRaizArvAluno;

PRaizArvAluno iniArvAluno(void){
  PRaizArvAluno no;
  no = (PRaizArvAluno) malloc(sizeof(TRaizArvAluno));
  no->esq = NULL;
  no->dir = NULL;
  return no;
}

PRaizArvAluno incAluno(TAluno aluno, PRaizArvAluno raiz){
  if(raiz == NULL){
      raiz = iniArvAluno();
      raiz->aluno = aluno;
    
    }else if (aluno.numMatricula != raiz->aluno.numMatricula){
      int esq = (aluno.numMatricula > raiz->aluno.numMatricula);
      
      if(esq == 1){
        raiz->esq = incAluno(aluno, raiz->esq);
      
      }else{
        raiz->dir = incAluno(aluno, raiz->dir);
        
      }
    
    }
    return raiz;
}

void printArvOrdenada(PRaizArvAluno raiz){
  if(raiz->esq!=NULL)
    printArvOrdenada(raiz->esq);
    printf("[ %d, ", raiz->aluno.numMatricula);
    printf("%s, ", raiz->aluno.nome);
    printf("%s ] ;\n ", raiz->aluno.email);
  
  if(raiz->dir!=NULL)
    printArvOrdenada(raiz->dir);
  
 

}

int quantNos(PRaizArvAluno raiz){
  if(raiz == NULL){
    return 0;
  }
  return 1 + quantNos(raiz->esq) + quantNos(raiz->dir);
}

int quantNiveis(PRaizArvAluno raiz){
   if(raiz == NULL){
     return -1;
   }
    int esq = quantNiveis(raiz->esq);
    int dir = quantNiveis(raiz->dir);
    return (esq > dir) ? esq + 1 : dir + 1; 
  
}


int main(){
    PRaizArvAluno raiz = NULL;
    TAluno testando;
    int numeros[8] = {23, 12, 6, 1, 15, 9, 3, 6};
    int numeros2[8] = {1, 3, 6, 9, 12, 15, 23, 4};
    int numeros3[8] = {9, 3, 15, 1, 23, 6, 12, 3};


   for(int i = 0; i < 8; i++){
     testando.numMatricula = numeros2[i];
     strcpy(testando.nome, "alunoGenerico");
     strcpy(testando.email, "emailAluno@generico");
     raiz = incAluno(testando, raiz);
          
   }
  printArvOrdenada(raiz);
  printf("Quantidade de niveis: %d  \n", quantNiveis(raiz));  
  printf("Quantidade de nós: %d  \n", quantNos(raiz));
  
  
return 0;

}