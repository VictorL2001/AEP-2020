#include <stdio.h>
#include <stdlib.h>

int main(){
  char nome[100];
  int escolha,cont;
  FILE *amigos;
  printf("*** Simulador de pesquisa de amigos ***\n");
  printf("1- Adicionar um amigo.\n");
  printf("2- Ver todos os amigos.\n");
  printf("3- Fechar o programa.\n");
  scanf("%d", &escolha);
  switch(escolha){
    case 1:
      amigos=fopen("amigos.txt", "a");
      if(amigos == NULL) {
        printf("Erro na abertura do arquivo!");
        return 1;
      }
      printf(" Digite o nome do amigo que deseja adicionar:  ");
      setbuf(stdin, NULL);
      scanf("%[^\n]s", nome);
      setbuf(stdin, NULL);
      fprintf(amigos,"%s \n", nome);
      fclose(amigos);
      system("cls");
    break;
    case 2:
      system("cls");
      cont=1;
      amigos=fopen("amigos.txt", "r");
      if(amigos == NULL) {
        printf("Erro na abertura do arquivo!");
        return 1;
      }
      while(fgets(nome,sizeof(nome),amigos)!= NULL){
        printf("%d- %s",cont, nome);
        cont++;
      }
      printf("\n\n");
      fclose(amigos);
    break;
    case 3:
      system("cls");
      printf("*** Obrigado por utilizar esse programa ***\n");
      return 0;
    break;
    default:printf("*** Atividade nao encontrada! ***\n");
  }
  main();
}
