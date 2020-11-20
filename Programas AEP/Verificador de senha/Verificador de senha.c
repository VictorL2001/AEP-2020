#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                            //Declaração de VAR
struct conta{
  char usuario[50], senha[10];
};

struct conta x[10];
int cont=0;
                                            //Menu do sistema
int menu(){
  int escolha, num;
  char string_usuario[50], verificacao_senha[10];
  printf("\n\n1- Entrar em uma conta.\n");
  printf("2- Criar conta nova.\n");
  printf("3- Ver todos os usuarios e senhas.\n");
  printf("4- Mudar senha.\n");
  printf("5- Sair do sistema.\n");
  scanf("%d", &escolha);
  system("cls");
  printf("***********************************************\n");
  switch(escolha){                          //Case 1 = Sistema para entrar em uma conta
    case 1:
      verifica();
    break;
    case 2:                                  //Case 2 = Criar uma nova conta
      criarconta();
    break;
    case 3:                                 //Case 3 = Mostrar todas as contas criadas
      for (int vetor=0; vetor<cont;vetor++){
        printf("%d- Usuario: %s | Senha: %s\n", vetor+1, x[vetor].usuario, x[vetor].senha);
      }
    break;
    case 4:                                 //Mudar senha
      num=verifica();
      system("cls");
      if (num>=0){
        printf(" Digite a nova senha:  ");
        scanf("%s", &x[num].senha);
      }else{
        printf(" Senha ou nome de usuario esta errado!!!\n");
      }
    break;
    case 5:                                 //Fechar o programa
      return 0;
    break;
    default: printf(" Atividade nao encontrada\n");
  }
  printf("***********************************************\n");
  main();
}
                                            //Função para criar uma conta
int criarconta(){
  printf(" Digite o nome do usuario:  ");
  scanf("%s", &x[cont].usuario);
  printf(" Digite a senha do usuario:  ");
  scanf("%s", &x[cont].senha);
  return cont++;
}
                                            //Função para verificar conta e senha
int verifica(){
  char string_usuario[50], verificacao_senha[10];
  int num, y=-1;
  printf(" Digite o nome do usuario:  ");
  scanf("%s",&string_usuario);
  for (int vetor=0;vetor<cont;vetor++){
    num=strcmp(string_usuario,x[vetor].usuario);
    if(num==0){
      vetor=cont;
    }
  }
  if (num!=0){
    printf(" Usuario nao encontrado!!!\n");
  }else{
    printf(" Digite a senha:  ");
    scanf("%s",&verificacao_senha);
    for (int vetor=0;vetor<cont;vetor++){
      num=strcmp(verificacao_senha,x[vetor].senha);
      if(num==0){
        y=vetor;
        vetor=cont;
      }
    }
    if(num==0){
      printf(" Senha de usuario correta!!!\n");
    }else{
      printf(" Senha de usuario incorreta!!!\n");
    }
  }
  return y;
}
                                            //Main
int main(){
  if (cont==0){
    printf("*** Bem vindo ao sistema de validacao de senha e usuario ***\n\n");
    printf(" Vamos criar a primeiro usuario!!!\n\n");
    criarconta();
  }
  menu();
  return 0;
}
