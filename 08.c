#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int tam;
     float *nota_aluno,media,soma;
   
    printf("informe a quantidade de alunos\n");
    scanf("%d",&tam); 
   nota_aluno=(float*)malloc(tam*sizeof(float));
   
 for (int i = 0; i < tam; i++) {
    printf("Informe as notas dos alunos\n");
    scanf("%f", &nota_aluno[i]);
  }
  
   for (int i = 0; i <= tam; i++) { // for para percorrer o vetor e colher todos os valores para somar

          soma = soma + nota_aluno[i];
          
        }
         media=soma/tam;
        printf("A media das notas da turma é %f", media);
    free(nota_aluno);
  return 0;
}
