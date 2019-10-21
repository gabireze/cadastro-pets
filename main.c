#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

typedef struct lista
{
	char nome[26];
	char especie[26];
	char raca[26];
	char sexo[2];
	char idade[3];
	char data_nasc[12];
	char descricao[101];
	char criado_em[51];
	char atualizado_em[51];
	unsigned long int codigo;
	struct lista * prox;
}

Lista;

//Decaração de funções
Lista* inserir_pets(Lista *primeiro);
void listar_pets(Lista *primeiro);
Lista* excluir_pets(Lista *primeiro);
void alterar_pets(Lista *primeiro);
void contar_pets(Lista *primeiro);
void contar_especie_pets(Lista *primeiro);
void buscar_nome_pets(Lista *primeiro);
void buscar_especie_pets(Lista *primeiro);
void buscar_especie_raca_pets(Lista *primeiro);
void buscar_especie_raca_sexo_pets(Lista *primeiro);
//void gravar(Lista *primeiro);
//void recuperar(Lista *primeiro);

main()
{
	setlocale(LC_ALL, "Portuguese");
	system("color fc");
	//Declararação de variáveis
	Lista *primeiro = NULL;
	char opcao;

	//Repetir o programa
	while (opcao != 's')
	{
		//Menu de opcoes 
		printf(" *----------------------------------------------------------------------------*\n");
		printf(" | ");
		printf("\t\t              CADASTRO DE PETS");
		printf("\t\t\t              |\n");
		printf(" *----------------------------------------------------------------------------*\n");
		printf("               |   MENU   ");
		printf("|\t\t\t\t      \n");
		printf("   *-----------*-------------*----------------------*\n");
		printf("   |<A> Inclusão de novos animais                    |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<B>  Remoção de animais                          |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<C>  Alteração de informações                    |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<D>  Busca de um animal a partir do seu nome     |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<E>  Busca de animais por espécie                |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<F>  Busca de animais por espécie e raça         |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<G>  Busca de animais por espécie, raça e sexo   |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<H>  Contagem (quantidade de animais)            |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<I>  Contagem por espécie                        |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<J>  Listagem de todos os animais cadastrados    |\n");	//done
		printf("   |-------------------------------------------------|\n");
		printf("   |<S>  Sair                                        |\n");	//done
		printf("   *-------------------------------------------------*\n");

		//Lendo a opcao do menu   
		fflush(stdin);
		opcao = getch();

		//Menu de opcoes
		switch (opcao)
		{
			case 'A':
			case 'a':
				system("color 02");
				//Inserindo os pet.
				fflush(stdin);
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t          INCLUSÃO DE NOVOS ANIMAIS     ");
				printf("\t\t|\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				primeiro = inserir_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'J':
			case 'j':
				system("color 90");
				//Listando os pet.
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t     LISTAGEM DE TODOS OS ANIMAIS CADASTRADOS");
				printf("\t\t\t|\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				listar_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'B':
			case 'b':
				system("color 4f");
				//Excluindo pet da lista.
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t        REMOÇÃO DE ANIMAIS");
				printf("\t\t\t     |\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				primeiro = excluir_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'C':
			case 'c':
				system("color fb");
				//Alterando pet da lista. 
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t       ALTERAÇÃO DE INFORMAÇÕES");
				printf("\t\t\t      |\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				alterar_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'H':
			case 'h':
				system("color 57");
				//Contagem de todos os animais cadastrados
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t       CONTAGEM (QUANTIDADE DE ANIMAIS)");
				printf("\t\t\t|\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				contar_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'I':
			case 'i':
				system("color 86");
				//Contagem de animais cadastrados por espécie
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t       CONTAGEM POR ESPÉCIE");
				printf("\t\t\t       |\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				contar_especie_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'D':
			case 'd':
				system("color 0c");
				//Contagem de animais cadastrados por espécie
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t       BUSCA DE UM ANIMAL A PARTIR DO SEU NOME");
				printf("\t      |\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				buscar_nome_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'E':
			case 'e':
				system("color bd");
				//Contagem de animais cadastrados por espécie
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t       BUSCA DE ANIMAIS POR ESPÉCIE");
				printf("\t\t       |\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				buscar_especie_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'F':
			case 'f':
				system("color f6");
				//Contagem de animais cadastrados por espécie
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t\t  BUSCA DE ANIMAIS POR ESPÉCIE E RAÇA");
				printf("\t\t     |\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				buscar_especie_raca_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'G':
			case 'g':
				system("color eb");
				//Contagem de animais cadastrados por espécie
				system("cls");
				printf(" *----------------------------------------------------------------------------*\n", 201, 187);
				printf(" | ");
				printf("\t\t    BUSCA DE ANIMAIS POR ESPÉCIE, RAÇA E SEXO");
				printf("\t\t      |\n");
				printf(" *----------------------------------------------------------------------------*\n", 200, 188);
				buscar_especie_raca_sexo_pets(primeiro);
				getch();
				system("cls");
				break;

			case 'S':
			case 's':
				system("color 08");
				//Sair do programa.
				opcao = 's';
				break;
				
			/*case 'Z':
			case 'z':
				system("color 08");
				//Sair do programa.
				gravar(primeiro);
				opcao = 's';
				break;*/
				
			/*case 'Y':
			case 'y':
				system("color 08");
				//Sair do programa.
				recuperar(primeiro);
				break;*/

			default:
				//Previne um usuario digite uma opcao inexistente no menu.
				system("cls");
				break;
		}
	}

	free(primeiro);
}

/*    void gravar(Lista *primeiro) {
    	Lista *atual = primeiro;
        FILE *arq;
        // Esses dados vão ser gravados !
        int ret;
        // arquivo alvo
        char nomearq[] = "vet.dat";
        // arquivo tem que ter permissão w para escrita e b para abrir como binario
        arq = fopen(nomearq, "wb");
        if (arq != NULL) {
            // aqui é feita a escrita !!
            ret = fwrite(atual, sizeof(atual), sizeof(atual), arq);
            if (ret == sizeof(atual))
                printf("Gravacao com sucesso\n");
            else
                printf("Foram gravados apenas %d elementos\n", ret);
            fclose(arq);
        }
        else
            puts("Erro: criacao do arquivo");
    }*/
    
/*   void recuperar(Lista *primeiro) {
   	Lista *atual = primeiro;
        FILE *arq;
        int i, ret;
        char nomearq[] = "vet.dat";

        arq = fopen(nomearq, "rb");
        if (arq != NULL) {
            // estou recuperando AQUI
            ret = fread(atual, sizeof(atual), 1, arq);
            printf("%s",ret);
            if (ret == sizeof(atual)) {
                primeiro = ret;
            }
            else
                printf("Foram lidos apenas %d elementos\n", ret);
            fclose(arq);
        }
        else
            puts("Erro: abertura do arquivo");
    }*/

Lista* inserir_pets(Lista *primeiro)
{
	Lista pet;
	Lista *atual = primeiro;
	Lista *anterior = NULL;
	char identificador = 'F';

	//Lendo as informacoes do pet
	printf("  Nome: ");
	fflush(stdin);
	fgets(pet.nome, 26, stdin);
	printf("\n");
	printf("  Espécie: ");
	fflush(stdin);
	fgets(pet.especie, 26, stdin);
	printf("\n");
	printf("  Raça: ");
	fflush(stdin);
	fgets(pet.raca, 26, stdin);
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
	fgets(pet.data_nasc, 12, stdin);
	printf("\n");
	printf("  Descrição: ");
	fflush(stdin);
	fgets(pet.descricao, 101, stdin);
	printf("\n");

	int codigo = 0;
	while (atual != NULL && atual->codigo != codigo)
	{
		codigo++;
		anterior = atual;
		atual = atual->prox;
	}

	if (anterior == NULL)
	{
		pet.codigo = 1;
	}
	else
	{
		pet.codigo = anterior->codigo + 1;
	}

	time_t now;
	struct tm ts;

	time(&now);
	ts = *localtime(&now);
	strftime(pet.criado_em, sizeof(pet.criado_em), "%H:%M:%S %a %d-%m-%Y", &ts);

	//Verificando se o cadastro ja existe.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		if (atual->codigo == pet.codigo)
		{
			identificador = 'V';
			break;
		}
	}

	if (identificador != 'V' && strlen(pet.nome) != 1)
	{
		//Alocando os espacoes e guardando as informacoes do pet
		Lista *NovoPet = (Lista*) malloc(sizeof(Lista));
		if (NovoPet == NULL)
		{
			fprintf(stderr, "Falha ao alocar memória.");
			printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
			return primeiro;
		}

		strcpy(NovoPet->nome, pet.nome);
		strcpy(NovoPet->especie, pet.especie);
		strcpy(NovoPet->raca, pet.raca);
		strcpy(NovoPet->sexo, pet.sexo);
		strcpy(NovoPet->idade, pet.idade);
		strcpy(NovoPet->data_nasc, pet.data_nasc);
		strcpy(NovoPet->descricao, pet.descricao);
		strcpy(NovoPet->criado_em, pet.criado_em);
		NovoPet->codigo = pet.codigo;
		NovoPet->prox = primeiro;
		printf("  Cadastro realizado com sucesso.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return NovoPet;
		free(NovoPet);
	}
	else
	{
		printf("  Cadastro inválido.", 160);
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return primeiro;
	}

	free(atual);
	free(anterior);
}

void contar_pets(Lista *primeiro)
{
	Lista * atual;	//Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.
	int contador = 0;
	//Imprimindo os pets da lista, e suas repectivas informacoes.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		contador++;
	}

	if (primeiro == NULL)
	{
		printf("  Nenhum pet cadastrado.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}

	if (contador > 1)
	{
		printf("\n  Existem %d pets cadastrados no sistema", contador);
	}
	else if (contador = 1)
	{
		printf("\n  Existe apenas %d pet cadastrado no sistema", contador);
	}

	free(atual);
}

void contar_especie_pets(Lista *primeiro)
{
	Lista * atual;	//Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.

	Lista *comparar = (Lista*) malloc(sizeof(Lista));
	if (comparar == NULL)
	{
		fprintf(stderr, "Falha ao alocar memória.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return;
	}

	int contador = 0;

	printf(" \n Digite a espécie: ");
	fflush(stdin);
	fgets(comparar->especie, 26, stdin);

	//Imprimindo os pets da lista, e suas repectivas informacoes.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		if (strcmp(atual->especie, comparar->especie) == 0)
		{
			contador++;
		}
	}

	if (primeiro == NULL)
	{
		printf("  Nenhum pet cadastrado.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}

	if (contador > 1)
	{
		printf("\n  Existem %d pets da espécie %s cadastrados no sistema", contador, comparar->especie);
	}
	else if (contador == 1)
	{
		printf("\n  Existe apenas %d pet da espécie %s cadastrado no sistema", contador, comparar->especie);
	}

	free(atual);
	free(comparar);
}

void buscar_nome_pets(Lista *primeiro)
{
	Lista * atual;	//Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.

	Lista *comparar = (Lista*) malloc(sizeof(Lista));
	if (comparar == NULL)
	{
		fprintf(stderr, "Falha ao alocar memória.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return;
	}

	int contador = 0;

	printf(" \n Digite o nome: ");
	fflush(stdin);
	fgets(comparar->nome, 26, stdin);

	//Imprimindo os pets da lista, e suas repectivas informacoes.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		if (strcmp(atual->nome, comparar->nome) == 0)
		{
			printf("\n-----//-----");
			printf("\n  ID #");
			printf("%u", atual->codigo);
			printf("\n  Nome: ");
			printf("%s", atual->nome);
			printf("\n  Espécie: ");
			printf("%s", atual->especie);
			printf("\n  Raça: ");
			printf("%s", atual->raca);
			printf("\n  Sexo: ");
			printf("%s", atual->sexo);
			printf("\n  Idade: ");
			printf("%s", atual->idade);
			printf("\n  Data de Nascimento: ");
			printf("%s", atual->data_nasc);
			printf("\n  Descrição: ");
			printf("%s", atual->descricao);
			printf("\n  Criado em ");
			printf("%s\n", atual->criado_em);

			if (strcmp(atual->atualizado_em, "") != 0)
			{
				printf("  Atualizado em ");
				printf("%s\n", atual->atualizado_em);
			}

			printf("-----//-----");
			printf("\n\n");
		}
	}

	if (primeiro == NULL)
	{
		printf("  Nenhum pet cadastrado.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}

	free(atual);
	free(comparar);
}

void buscar_especie_pets(Lista *primeiro)
{
	Lista * atual;	//Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.

	Lista *comparar = (Lista*) malloc(sizeof(Lista));
	if (comparar == NULL)
	{
		fprintf(stderr, "Falha ao alocar memória.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return;
	}

	int contador = 0;

	printf(" \n Digite a espécie: ");
	fflush(stdin);
	fgets(comparar->especie, 26, stdin);

	//Imprimindo os pets da lista, e suas repectivas informacoes.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		if (strcmp(atual->especie, comparar->especie) == 0)
		{
			printf("-----//-----");
			printf("\n  ID #");
			printf("%u", atual->codigo);
			printf("\n  Nome: ");
			printf("%s", atual->nome);
			printf("\n  Espécie: ");
			printf("%s", atual->especie);
			printf("\n  Raça: ");
			printf("%s", atual->raca);
			printf("\n  Sexo: ");
			printf("%s", atual->sexo);
			printf("\n  Idade: ");
			printf("%s", atual->idade);
			printf("\n  Data de Nascimento: ");
			printf("%s", atual->data_nasc);
			printf("\n  Descrição: ");
			printf("%s", atual->descricao);
			printf("\n  Criado em ");
			printf("%s\n", atual->criado_em);

			if (strcmp(atual->atualizado_em, "") != 0)
			{
				printf("\n  Atualizado em ");
				printf("%s\n", atual->atualizado_em);
			}

			printf("-----//-----");
			printf("\n\n");
		}
	}

	if (primeiro == NULL)
	{
		printf("  Nenhum pet cadastrado.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}

	free(atual);
	free(comparar);
}

void buscar_especie_raca_pets(Lista *primeiro)
{
	Lista * atual;	//Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.

	Lista *comparar = (Lista*) malloc(sizeof(Lista));
	if (comparar == NULL)
	{
		fprintf(stderr, "Falha ao alocar memória.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return;
	}

	int contador = 0;

	printf(" \n Digite a espécie: ");
	fflush(stdin);
	fgets(comparar->especie, 26, stdin);
	printf(" \n Digite a raça: ");
	fflush(stdin);
	fgets(comparar->raca, 26, stdin);

	//Imprimindo os pets da lista, e suas repectivas informacoes.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		if (strcmp(atual->especie, comparar->especie) == 0)
		{
			if (strcmp(atual->raca, comparar->raca) == 0)
			{
				printf("-----//-----");
				printf("\n  ID #");
				printf("%u", atual->codigo);
				printf("\n  Nome: ");
				printf("%s", atual->nome);
				printf("\n  Espécie: ");
				printf("%s", atual->especie);
				printf("\n  Raça: ");
				printf("%s", atual->raca);
				printf("\n  Sexo: ");
				printf("%s", atual->sexo);
				printf("\n  Idade: ");
				printf("%s", atual->idade);
				printf("\n  Data de Nascimento: ");
				printf("%s", atual->data_nasc);
				printf("\n  Descrição: ");
				printf("%s", atual->descricao);
				printf("\n  Criado em ");
				printf("%s\n", atual->criado_em);

				if (strcmp(atual->atualizado_em, "") != 0)
				{
					printf("\n  Atualizado em ");
					printf("%s\n", atual->atualizado_em);
				}

				printf("-----//-----");
				printf("\n\n");
			}
		}
	}

	if (primeiro == NULL)
	{
		printf("  Nenhum pet cadastrado.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}

	free(atual);
	free(comparar);
}

void buscar_especie_raca_sexo_pets(Lista *primeiro)
{
	Lista * atual;	//Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.

	Lista *comparar = (Lista*) malloc(sizeof(Lista));
	if (comparar == NULL)
	{
		fprintf(stderr, "Falha ao alocar memória.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return;
	}

	int contador = 0;

	printf(" \n Digite a espécie: ");
	fflush(stdin);
	fgets(comparar->especie, 26, stdin);
	printf(" \n Digite a raça: ");
	fflush(stdin);
	fgets(comparar->raca, 26, stdin);
	printf(" \n Digite o sexo: ");
	fflush(stdin);
	fgets(comparar->sexo, 2, stdin);

	//Imprimindo os pets da lista, e suas repectivas informacoes.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		if (strcmp(atual->especie, comparar->especie) == 0)
		{
			if (strcmp(atual->raca, comparar->raca) == 0)
			{
				if (strcmp(atual->sexo, comparar->sexo) == 0)
				{
					printf("-----//-----");
					printf("\n  ID #");
					printf("%u", atual->codigo);
					printf("\n  Nome: ");
					printf("%s", atual->nome);
					printf("\n  Espécie: ");
					printf("%s", atual->especie);
					printf("\n  Raça: ");
					printf("%s", atual->raca);
					printf("\n  Sexo: ");
					printf("%s", atual->sexo);
					printf("\n  Idade: ");
					printf("%s", atual->idade);
					printf("\n  Data de Nascimento: ");
					printf("%s", atual->data_nasc);
					printf("\n  Descrição: ");
					printf("%s", atual->descricao);
					printf("\n  Criado em ");
					printf("%s\n", atual->criado_em);

					if (strcmp(atual->atualizado_em, "") != 0)
					{
						printf("\n  Atualizado em ");
						printf("%s\n", atual->atualizado_em);
					}

					printf("-----//-----");
					printf("\n\n");
				}
			}
		}
	}

	if (primeiro == NULL)
	{
		printf("  Nenhum pet cadastrado.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}

	free(atual);
	free(comparar);
}

void listar_pets(Lista *primeiro)
{
	Lista * atual;	//Ponteiro para percorrer a lista sem perder a referencia do primeiro elemento da lista.

	//Imprimindo os pets da lista, e suas repectivas informacoes.
	for (atual = primeiro; atual != NULL; atual = atual->prox)
	{
		printf("-----//-----");
		printf("\n  ID #");
		printf("%u", atual->codigo);
		printf("\n  Nome: ");
		printf("%s", atual->nome);
		printf("\n  Espécie: ");
		printf("%s", atual->especie);
		printf("\n  Raça: ");
		printf("%s", atual->raca);
		printf("\n  Sexo: ");
		printf("%s", atual->sexo);
		printf("\n  Idade: ");
		printf("%s", atual->idade);
		printf("\n  Data de Nascimento: ");
		printf("%s", atual->data_nasc);
		printf("\n  Descrição: ");
		printf("%s", atual->descricao);
		printf("\n  Criado em ");
		printf("%s\n", atual->criado_em);

		if (strcmp(atual->atualizado_em, "") != 0)
		{
			printf("\n  Atualizado em ");
			printf("%s\n", atual->atualizado_em);
		}

		printf("-----//-----");
		printf("\n\n");
	}

	if (primeiro == NULL)
	{
		printf("  Nenhum pet cadastrado.");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	}

	free(atual);
}

Lista* excluir_pets(Lista *primeiro)
{
	Lista *anterior = NULL;	//Ponteiro para saber o elemento anterior ao elemento atual da lista.
	Lista *atual = primeiro;	//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
	unsigned long int codigo = 0;

	//Requisitando e lendo o codigo do pet a ser excluido.
	printf("  Código do pet a ser excluído: ", 162, 161);
	fflush(stdin);
	scanf("%u", &codigo);

	//Procurando o pet na lista.
	while (atual != NULL && atual->codigo != codigo)
	{
		anterior = atual;
		atual = atual->prox;
	}

	//Mensagem caso o pet nao seja encontrado.
	if (atual == NULL)
	{
		printf("\n  Pet não encontrado.", 198);
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
		return primeiro;
	}

	//Excluindo o primeiro pet da lista.   
	if (anterior == NULL)
	{
		printf("\n  Conteúdo excluído com sucesso.", 163, 161);
		primeiro = atual->prox;
		//Excluindo um pet do meio da lista.
	}
	else
	{
		printf("\n  Conteúdo excluído com sucesso.", 163, 161);
		anterior->prox = atual->prox;
	}

	//Desalocando o espaco da memoria
	free(atual);
	printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	return primeiro;
	free(atual);
	free(anterior);
}

//Funcao para alterar pet
void alterar_pets(Lista *primeiro)
{
	char nome_substituto[26], especie_substituto[26], raca_substituto[26], sexo_substituto[2], idade_substituto[3], data_nasc_substituto[12], descricao_substituto[101], atualizado_em[51];
	unsigned long int codigo;
	Lista *atual = primeiro;

	//Requisitando e lendo o codigo do pet a ser alterado.
	printf("  Código do pet a ser alterado: ");
	fflush(stdin);
	scanf("%u", &codigo);

	//Procurando o pet na lista.
	while (atual != NULL && atual->codigo != codigo)
	{
		atual = atual->prox;
	}

	//Alterando os dados do pet.
	if (atual != NULL)
	{
		int opcao;
		printf("\n Qual item deseja alterar? ");
		printf("\n<1> Nome");
		printf("\n<2> Espécie");
		printf("\n<3> Sexo");
		printf("\n<4> Raça");
		printf("\n<5> Idade");
		printf("\n<6> Data de Nascimento");
		printf("\n<7> Descrição");
		printf("\n<0> Sair\n\n");
		scanf("%d", &opcao);

		time_t now;
		struct tm ts;

		switch (opcao)
		{
			case 1:
				printf("\n  Novo nome: ");
				fflush(stdin);
				fgets(nome_substituto, 26, stdin);
				strcpy(atual->nome, nome_substituto);
				time(&now);
				ts = *localtime(&now);
				strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
				strcpy(atual->atualizado_em, atualizado_em);
				break;

			case 2:
				printf("\n  Nova espécie: ");
				fflush(stdin);
				fgets(especie_substituto, 26, stdin);
				printf("\n");
				strcpy(atual->especie, especie_substituto);
				time(&now);
				ts = *localtime(&now);
				strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
				strcpy(atual->atualizado_em, atualizado_em);
				break;

			case 3:
				printf("\n  Nova raça: ");
				fflush(stdin);
				fgets(raca_substituto, 26, stdin);
				printf("\n");
				strcpy(atual->raca, raca_substituto);
				time(&now);
				ts = *localtime(&now);
				strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
				strcpy(atual->atualizado_em, atualizado_em);
				break;

			case 4:
				printf("\n  Novo sexo: ");
				fflush(stdin);
				fgets(sexo_substituto, 2, stdin);
				printf("\n");
				strcpy(atual->sexo, sexo_substituto);
				time(&now);
				ts = *localtime(&now);
				strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
				strcpy(atual->atualizado_em, atualizado_em);
				break;

			case 5:
				printf("\n  Nova idade: ");
				fflush(stdin);
				fgets(idade_substituto, 3, stdin);
				printf("\n");
				strcpy(atual->idade, idade_substituto);
				time(&now);
				ts = *localtime(&now);
				strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
				strcpy(atual->atualizado_em, atualizado_em);
				break;

			case 6:
				printf("\n  Nova data de nascimento: ");
				fflush(stdin);
				fgets(data_nasc_substituto, 12, stdin);
				printf("\n");
				strcpy(atual->data_nasc, data_nasc_substituto);
				time(&now);
				ts = *localtime(&now);
				strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
				strcpy(atual->atualizado_em, atualizado_em);
				break;

			case 7:
				printf("\n  Nova descrição: ");
				fflush(stdin);
				fgets(descricao_substituto, 101, stdin);
				printf("\n");
				strcpy(atual->descricao, descricao_substituto);
				time(&now);
				ts = *localtime(&now);
				strftime(atualizado_em, sizeof(atualizado_em), "%H:%M:%S %a %d-%m-%Y", &ts);
				strcpy(atual->atualizado_em, atualizado_em);
				break;

			default:
				printf("\n Opção inválida");
				alterar_pets(primeiro);
				getch();
				system("cls");

		}

		printf("  Dado alterado com sucesso.");
	}
	else
	{
		printf("\n  Pet não encontrado.", 198);
	}

	printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
