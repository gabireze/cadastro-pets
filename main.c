#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

typedef struct lista {
  char nome[40];
  char especie[40];
  char raca[40];
  char sexo[2];
  char idade[3];
  char data_nasc[11];
  char descricao[140];
  unsigned long int codigo;
  struct lista * prox;
}
Lista;

//Decaração de funções
Lista * inserir_pets(Lista * primeiro);
void listar_pets(Lista * primeiro);
Lista * excluir_pets(Lista * primeiro);
void alterar_pets(Lista * primeiro);
void buscar_pets(Lista * primeiro);

main() {
  setlocale(LC_ALL, "Portuguese");

  //Declararação de variáveis
  Lista * primeiro = NULL;
  char opcao;

  //Repetir o programa
  while (opcao != 's') {
    //Menu de opcoes 
    printf(" %c----------------------------------------------------------------------------%c\n", 201, 187);
    printf(" | ");
    printf("\t\t              CADASTRO DE PETS");
    printf("\t\t\t              |\n");
    printf(" %c----------------------------------------------------------------------------%c\n", 200, 188);
    printf("               |   MENU   ");
    printf("|\t\t\t\t      \n");
    printf("   %c-----------%c----------%c------------%c \n", 201, 200, 188, 187);
    printf("   | <A>  Novo cadastro                |\n");
    printf("   |-----------------------------------|\n");
    printf("   | <B>  Listar                       |\n");
    printf("   |-----------------------------------|\n");
    printf("   | <C>  Excluir cadastro             |\n");
    printf("   |-----------------------------------|\n");
    printf("   | <D>  Alterar cadastro             |\n");
    printf("   |-----------------------------------|\n");
    printf("   | <E>  Buscar cadastro              |\n");
    printf("   |-----------------------------------|\n");
    printf("   | <S>  Sair                         |\n");
    printf("   %c-----------------------------------%c", 200, 188);

    //Lendo a opcao do menu   
    fflush(stdin);
    opcao = getch();

    //Menu de opcoes
    switch (opcao) {
    case 'A':
    case 'a':
      //Inserindo os pet.
      fflush(stdin);
      system("cls");
      printf(" %c----------------------------------------------------------------------------%c\n", 201, 187);
      printf(" | ");
      printf("\t\t\t          NOVO CADASTRO     ");
      printf("\t\t\t      |\n");
      printf(" %c----------------------------------------------------------------------------%c\n", 200, 188);
      primeiro = inserir_pets(primeiro);
      getch();
      system("cls");
      break;

    case 'B':
    case 'b':
      //Listando os pet.
      system("cls");
      printf(" %c----------------------------------------------------------------------------%c\n", 201, 187);
      printf(" | ");
      printf("\t\t\t     PETS CADASTRADOS");
      printf("\t\t\t      |\n");
      printf(" %c----------------------------------------------------------------------------%c\n", 200, 188);
      listar_pets(primeiro);
      getch();
      system("cls");
      break;

    case 'C':
    case 'c':
      //Excluindo pet da lista.
      system("cls");
      printf(" %c----------------------------------------------------------------------------%c\n", 201, 187);
      printf(" | ");
      printf("\t\t\t        EXCLUIR CADASTROS");
      printf("\t\t\t      |\n");
      printf(" %c----------------------------------------------------------------------------%c\n", 200, 188);
      primeiro = excluir_pets(primeiro);
      getch();
      system("cls");
      break;

    case 'D':
    case 'd':
      //Alterando pet da lista. 
      system("cls");
      printf(" %c----------------------------------------------------------------------------%c\n", 201, 187);
      printf(" | ");
      printf("\t\t\t       ALTERAR CADASTRADOS");
      printf("\t\t\t      |\n");
      printf(" %c----------------------------------------------------------------------------%c\n", 200, 188);
      alterar_pets(primeiro);
      getch();
      system("cls");
      break;

    case 'S':
    case 's':
      //Sair do programa.
      opcao = 's';
      break;

    default:
      //Previne um usuario digite uma opcao inexistente no menu.
      system("cls");
      break;
    }
  }
}

Lista * inserir_pets(Lista * primeiro) {
  Lista pet;
  Lista * atual = primeiro;
  char identificador = 'F';

  //Lendo as informacoes do pet
  printf("  Nome: ");
  fflush(stdin);
  fgets(pet.nome, 40, stdin);
  printf("\n");
  printf("  Espécie: ");
  fflush(stdin);
  fgets(pet.especie, 40, stdin);
  printf("\n");
  printf("  Raça: ");
  fflush(stdin);
  fgets(pet.raca, 40, stdin);
  printf("\n");
  printf("  Sexo (M ou F): ");
  fflush(stdin);
  fgets(pet.sexo, 2, stdin);
  printf("\n");
  printf("  Idade: ");
  fflush(stdin);
  fgets(pet.idade, 3, stdin);
  printf("\n");
  printf("  Data de Nascimento: ");
  fflush(stdin);
  fgets(pet.data_nasc, 11, stdin);
  printf("\n");
  printf("  Descrição: ");
  fflush(stdin);
  fgets(pet.descricao, 140, stdin);
  printf("\n");
  printf("  Código: ", 162);
  scanf("%u", &pet.codigo);
  printf("\n");

  //Verificando se o cadastro ja existe.
  for (atual = primeiro; atual != NULL; atual = atual -> prox) {
    if (atual -> codigo == pet.codigo) {
      identificador = 'V';
      break;
    }
  }

  if (identificador != 'V' && strlen(pet.nome) != 1) {
    //Alocando os espacoes e guardando as informacoes do pet
    Lista * NovoPet = (Lista * ) malloc(sizeof(Lista));
    if (NovoPet == NULL) {
      fprintf(stderr, "Falha ao alocar memória.");
      printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
      return primeiro;
    }
    strcpy(NovoPet -> nome, pet.nome);
    strcpy(NovoPet -> especie, pet.especie);
    strcpy(NovoPet -> raca, pet.raca);
    strcpy(NovoPet -> sexo, pet.sexo);
    strcpy(NovoPet -> idade, pet.idade);
    strcpy(NovoPet -> data_nasc, pet.data_nasc);
    strcpy(NovoPet -> descricao, pet.descricao);
    NovoPet -> codigo = pet.codigo;
    NovoPet -> prox = primeiro;
    printf("  Cadastro realizado com sucesso.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return NovoPet;
  } else {
    printf("  Cadastro inválido.", 160);
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
  }
}

void listar_pets(Lista * primeiro) {
  Lista * atual; //Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.

  //Imprimindo os pets da lista, e suas repectivas informacoes.
  for (atual = primeiro; atual != NULL; atual = atual -> prox) {
    printf("-----//-----");
    printf("\n  ID #");
    printf("%u", atual -> codigo);
    printf("\n  Nome: ");
    printf("%s", atual -> nome);
    printf("\n  Espécie: ");
    printf("%s", atual -> especie);
    printf("\n  Raça: ");
    printf("%s", atual -> raca);
    printf("\n  Sexo: ");
    printf("%s", atual -> sexo);
    printf("\n  Idade: ");
    printf("%s", atual -> idade);
    printf("\n  Data de Nascimento: ");
    printf("%s", atual -> data_nasc);
    printf("\n  Descrição: ");
    printf("%s", atual -> descricao);
    printf("-----//-----");
    printf("\n\n");
  }
  if (primeiro == NULL)
    printf("  Nenhum pet cadastrado.");
  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista * excluir_pets(Lista * primeiro) {

  Lista * anterior = NULL; //Ponteiro para saber o elemento anterior ao elemento atual da lista.
  Lista * atual = primeiro; //Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
  unsigned long int codigo = 0;

  //Requisitando e lendo o codigo do pet a ser excluido.
  printf("  Código do pet a ser excluído: ", 162, 161);
  fflush(stdin);
  scanf("%u", & codigo);

  //Procurando o pet na lista.
  while (atual != NULL && atual -> codigo != codigo) {
    anterior = atual;
    atual = atual -> prox;
  }

  //Mensagem caso o pet nao seja encontrado.
  if (atual == NULL) {
    printf("\n  Pet não encontrado.", 198);
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
  }

  //Excluindo o primeiro pet da lista.   
  if (anterior == NULL) {
    printf("\n  Conteúdo excluído com sucesso.", 163, 161);
    primeiro = atual -> prox;
    //Excluindo um pet do meio da lista.
  } else {
    printf("\n  Conteúdo excluído com sucesso.", 163, 161);
    anterior -> prox = atual -> prox;
  }

  //Desalocando o espaco da memoria
  free(atual);
  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  return primeiro;
}

//Funcao para alterar pet
void alterar_pets(Lista * primeiro) {
  char nome_substituto[40], especie_substituto[40], raca_substituto[40], sexo_substituto[2], idade_substituto[3], data_nasc_substituto[11], descricao_substituto[140];
  unsigned long int codigo;
  Lista * atual = primeiro;

  //Requisitando e lendo o codigo do pet a ser alterado.
  printf("  Código do pet a ser alterado: ", 162);
  fflush(stdin);
  scanf("%u", & codigo);

  //Procurando o pet na lista.
  while (atual != NULL && atual -> codigo != codigo) {
    atual = atual -> prox;
  }

  //Alterando os dados do pet.
  if (atual != NULL) {
    printf("\n  Novo nome: ");
    fflush(stdin);
    fgets(nome_substituto, 40, stdin);
    strcpy(atual -> nome, nome_substituto);
    printf("\n  Nova espécie: ");
    fflush(stdin);
    fgets(especie_substituto, 40, stdin);
    printf("\n");
    strcpy(atual -> especie, especie_substituto);
    printf("\n  Nova raça: ");
    fflush(stdin);
    fgets(raca_substituto, 40, stdin);
    printf("\n");
    strcpy(atual -> raca, raca_substituto);
    printf("\n  Novo sexo: ");
    fflush(stdin);
    fgets(sexo_substituto, 2, stdin);
    printf("\n");
    strcpy(atual -> sexo, sexo_substituto);
    printf("\n  Nova idade: ");
    fflush(stdin);
    fgets(idade_substituto, 2, stdin);
    printf("\n");
    strcpy(atual -> idade, idade_substituto);
    printf("\n  Nova data de nascimento: ");
    fflush(stdin);
    fgets(data_nasc_substituto, 11, stdin);
    printf("\n");
    strcpy(atual -> data_nasc, data_nasc_substituto);
    printf("\n  Nova descrição: ");
    fflush(stdin);
    fgets(descricao_substituto, 140, stdin);
    printf("\n");
    strcpy(atual -> descricao, descricao_substituto);
    printf("  Dados alterados com sucesso.");
  } else {
    printf("\n  Pet não encontrado.", 198);
  }
  printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
