#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>

typedef struct lista {
  char nome[40];
  char especie[40];
  char raca[40];
  char sexo[2];
  char idade[3];
  char data_nasc[11];
  char descricao[140];
  char criado_em[80];
  char atualizado_em[80];
  unsigned long int codigo;
  struct lista * prox;
}
Lista;

//Decara��o de fun��es
Lista * inserir_pets(Lista * primeiro);
void listar_pets(Lista * primeiro);
Lista * excluir_pets(Lista * primeiro);
void alterar_pets(Lista * primeiro);
//void buscar_pets(Lista * primeiro);

main() {
  setlocale(LC_ALL, "Portuguese");

  //Declarara��o de vari�veis
  Lista * primeiro = NULL;
  char opcao;

  //Repetir o programa
  while (opcao != 's') {
    //Menu de opcoes 
    printf(" *----------------------------------------------------------------------------*\n");
    printf(" | ");
    printf("\t\t              CADASTRO DE PETS");
    printf("\t\t\t              |\n");
    printf(" *----------------------------------------------------------------------------*\n");
    printf("               |   MENU   ");
    printf("|\t\t\t\t      \n");
    printf("   *-----------*-------------*----------------------* \n");
    printf("   | <A> Inclus�o de novos animais                   |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <B>  Remo��o de animais                         |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <C>  Altera��o de informa��es                   |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <D>  Busca de um animal a partir do seu nome    |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <E>  Busca de animais por esp�cie               |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <E>  Busca de animais por esp�cie e ra�a        |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <E>  Busca de animais por esp�cie, ra�a e sexo  |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <E>  Contagem (quantidade de animais)           |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <E>  Contagem por esp�cie                       |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <S>  Listagem de todos os animais cadastrados   |\n");
    printf("   |-------------------------------------------------|\n");
    printf("   | <S>  Sair                                       |\n");
    printf("   *-------------------------------------------------*\n");

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
      printf(" *----------------------------------------------------------------------------*\n", 201, 187);
      printf(" | ");
      printf("\t\t\t          NOVO CADASTRO     ");
      printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n", 200, 188);
      primeiro = inserir_pets(primeiro);
      getch();
      system("cls");
      break;

    case 'B':
    case 'b':
      //Listando os pet.
      system("cls");
      printf(" *----------------------------------------------------------------------------*\n", 201, 187);
      printf(" | ");
      printf("\t\t\t     PETS CADASTRADOS");
      printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n", 200, 188);
      listar_pets(primeiro);
      getch();
      system("cls");
      break;

    case 'C':
    case 'c':
      //Excluindo pet da lista.
      system("cls");
      printf(" *----------------------------------------------------------------------------*\n", 201, 187);
      printf(" | ");
      printf("\t\t\t        EXCLUIR CADASTROS");
      printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n", 200, 188);
      primeiro = excluir_pets(primeiro);
      getch();
      system("cls");
      break;

    case 'D':
    case 'd':
      //Alterando pet da lista. 
      system("cls");
      printf(" *----------------------------------------------------------------------------*\n", 201, 187);
      printf(" | ");
      printf("\t\t\t       ALTERAR CADASTRADOS");
      printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n", 200, 188);
      alterar_pets(primeiro);
      getch();
      system("cls");
      break;
      
    case 'E':
    case 'e':
      //Alterando pet da lista. 
      system("cls");
      printf(" *----------------------------------------------------------------------------*\n", 201, 187);
      printf(" | ");
      printf("\t\t\t       BUSCAR CADASTRADOS");
      printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n", 200, 188);
      //buscar_pets(primeiro);
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
  Lista * anterior = NULL;
  char identificador = 'F';

  //Lendo as informacoes do pet
  printf("  Nome: ");
  fflush(stdin);
  fgets(pet.nome, 40, stdin);
  printf("\n");
  printf("  Esp�cie: ");
  fflush(stdin);
  fgets(pet.especie, 40, stdin);
  printf("\n");
  printf("  Ra�a: ");
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
  printf("  Descri��o: ");
  fflush(stdin);
  fgets(pet.descricao, 140, stdin);
  printf("\n");
  
	int codigo = 0;
	while (atual != NULL && atual -> codigo != codigo) {
    	codigo++;
    	anterior = atual;
    	atual = atual -> prox;
	}
  
  if (anterior == NULL) {
    pet.codigo = 1;
  } else {
  	pet.codigo = anterior->codigo + 1;
  }
  
	time_t     now;
    struct tm  ts;
	
	time(&now);
	ts = *localtime(&now);    
	strftime(pet.criado_em, sizeof(pet.criado_em), "%H:%M:%S %a %d-%m-%Y", &ts);

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
      fprintf(stderr, "Falha ao alocar mem�ria.");
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
    strcpy(NovoPet -> criado_em, pet.criado_em);
    NovoPet -> codigo = pet.codigo;
    NovoPet -> prox = primeiro;
    printf("  Cadastro realizado com sucesso.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return NovoPet;
  } else {
    printf("  Cadastro inv�lido.", 160);
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
    printf("\n  Esp�cie: ");
    printf("%s", atual -> especie);
    printf("\n  Ra�a: ");
    printf("%s", atual -> raca);
    printf("\n  Sexo: ");
    printf("%s", atual -> sexo);
    printf("\n  Idade: ");
    printf("%s", atual -> idade);
    printf("\n  Data de Nascimento: ");
    printf("%s", atual -> data_nasc);
    printf("\n  Descri��o: ");
    printf("%s", atual -> descricao);
    printf("\n  Criado em ");
    printf("%s\n", atual -> criado_em);
	
	if (strcmp (atual->atualizado_em, "") != 0){
		printf("\n  Atualizado em ");
		printf("%s\n", atual ->atualizado_em);
	}
    
	printf("-----//-----");
    printf("\n\n");
  }
	if (primeiro == NULL){
		printf("  Nenhum pet cadastrado.");
  		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}
}

Lista * excluir_pets(Lista * primeiro) {

  Lista * anterior = NULL; //Ponteiro para saber o elemento anterior ao elemento atual da lista.
  Lista * atual = primeiro; //Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
  unsigned long int codigo = 0;

  //Requisitando e lendo o codigo do pet a ser excluido.
  printf("  C�digo do pet a ser exclu�do: ", 162, 161);
  fflush(stdin);
  scanf("%u", & codigo);

  //Procurando o pet na lista.
  while (atual != NULL && atual -> codigo != codigo) {
    anterior = atual;
    atual = atual -> prox;
  }

  //Mensagem caso o pet nao seja encontrado.
  if (atual == NULL) {
    printf("\n  Pet n�o encontrado.", 198);
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
  }

  //Excluindo o primeiro pet da lista.   
  if (anterior == NULL) {
    printf("\n  Conte�do exclu�do com sucesso.", 163, 161);
    primeiro = atual -> prox;
    //Excluindo um pet do meio da lista.
  } else {
    printf("\n  Conte�do exclu�do com sucesso.", 163, 161);
    anterior -> prox = atual -> prox;
  }

  //Desalocando o espaco da memoria
  free(atual);
  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  return primeiro;
}

//Funcao para alterar pet
void alterar_pets(Lista * primeiro) {
  char nome_substituto[40], especie_substituto[40], raca_substituto[40], sexo_substituto[2], idade_substituto[3], data_nasc_substituto[11], descricao_substituto[140], atualizado_em[80];
  unsigned long int codigo;
  Lista * atual = primeiro;

  //Requisitando e lendo o codigo do pet a ser alterado.
  printf("  C�digo do pet a ser alterado: ", 162);
  fflush(stdin);
  scanf("%u", & codigo);

  //Procurando o pet na lista.
  while (atual != NULL && atual -> codigo != codigo) {
    atual = atual -> prox;
  }

  //Alterando os dados do pet.
  if (atual != NULL) {
  	int opcao;
	printf("\n Qual item deseja alterar? ");
	printf("\n<1> Nome");
	printf("\n<2> Esp�cie");
	printf("\n<3> Sexo");
	printf("\n<4> Ra�a");
	printf("\n<5> Idade");
	printf("\n<6> Data de Nascimento");
	printf("\n<7> Descri��o");
	printf("\n<0> Sair\n\n");
	scanf("%d",&opcao);
	
	time_t     now;
    struct tm  ts;
	
	switch(opcao){
		case 1:
			printf("\n  Novo nome: ");
			fflush(stdin);
			fgets(nome_substituto, 40, stdin);
			strcpy(atual -> nome, nome_substituto);
			time(&now);
			ts = *localtime(&now);    
			strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
			strcpy(atual -> atualizado_em, atualizado_em);
			break;
    
    	case 2:
    		printf("\n  Nova esp�cie: ");
			fflush(stdin);
			fgets(especie_substituto, 40, stdin);
			printf("\n");
			strcpy(atual -> especie, especie_substituto);
			time(&now);
			ts = *localtime(&now);    
			strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
			strcpy(atual -> atualizado_em, atualizado_em);
			break;
		
		case 3:
		    printf("\n  Nova ra�a: ");
			fflush(stdin);
			fgets(raca_substituto, 40, stdin);
			printf("\n");
			strcpy(atual -> raca, raca_substituto);
			time(&now);
			ts = *localtime(&now);    
			strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
			strcpy(atual -> atualizado_em, atualizado_em);
			break;
			
		case 4:
			printf("\n  Novo sexo: ");
			fflush(stdin);
			fgets(sexo_substituto, 2, stdin);
			printf("\n");
			strcpy(atual -> sexo, sexo_substituto);
			time(&now);
			ts = *localtime(&now);    
			strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
			strcpy(atual -> atualizado_em, atualizado_em);
			break;
			
		case 5:
		    printf("\n  Nova idade: ");
			fflush(stdin);
			fgets(idade_substituto, 2, stdin);
			printf("\n");
			strcpy(atual -> idade, idade_substituto);
			time(&now);
			ts = *localtime(&now);    
			strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
			strcpy(atual -> atualizado_em, atualizado_em);
			break;
			
		case 6:
		    printf("\n  Nova data de nascimento: ");
			fflush(stdin);
			fgets(data_nasc_substituto, 11, stdin);
			printf("\n");
			strcpy(atual -> data_nasc, data_nasc_substituto);
			time(&now);
			ts = *localtime(&now);    
			strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
			strcpy(atual -> atualizado_em, atualizado_em);
			break;
		
		case 7:
			printf("\n  Nova descri��o: ");
			fflush(stdin);
			fgets(descricao_substituto, 140, stdin);
			printf("\n");
			strcpy(atual -> descricao, descricao_substituto);
			time(&now);
			ts = *localtime(&now);    
			strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
			strcpy(atual -> atualizado_em, atualizado_em);
			break;
			
		default:
			printf("\n Op��o inv�lida");
			alterar_pets(primeiro);
			getch();
			system("cls");
				
	}
    printf("  Dado alterado com sucesso.");
  } else {
    printf("\n  Pet n�o encontrado.", 198);
  }
  printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
