#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int tam;
     float *nota_aluno;
   
    printf("informe a quantidade de alunos\n");
    scanf("%s",tam); 
    nota_aluno=malloc(tam*sizeof(float));
   
 for (int i = 0; i <= tam; i++) {
    printf("Informe as notas dos alunos\n");
    scanf("%d", &nota_aluno[i]);
  }
  for (int i = 0; i <= tam; i++) {
    printf("vetor[%d]=%d\n",i,nota_aluno[i]);
  }
    free(nota_aluno);
  return 0;
}
