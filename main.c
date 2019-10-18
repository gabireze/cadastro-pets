#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

typedef struct lista{
    char nome[40];
    char especie[40];
    char raca[40];
    char sexo[1];
    char idade[2];
    char data_nasc[10];
    char descricao[140];
    unsigned long int codigo;
    struct lista* prox;
}Lista;

//Declara��o de fun��es.
Lista* inserir_pets(Lista* primeiro);
void listar_pets(Lista* primeiro);
Lista* excluir_pets(Lista* primeiro);
void alterar_pets(Lista* primeiro);

main()
{
	setlocale(LC_ALL, "Portuguese");
	
    //Declara��o de vari�veis
    Lista *primeiro= NULL;
    char opcao;

    //Artif�cio para repetir o programa.
    while(opcao!='s')
    {
        //Menu de opcoes 
        printf(" %c----------------------------------------------------------------------------%c\n",201,187);
        printf(" | ");printf("\t\t\t     CADASTRO DE PETS");printf("\t\t\t      |\n");
        printf(" %c----------------------------------------------------------------------------%c\n",200,188);
        printf("\t       %c----------%c\t\t\t\t       ",201,187);
        printf("\t\t\t               |   MENU   ");printf("|\t\t\t\t      \n");
        printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
        printf("   | <A>  Novo cadastro                |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <B>  Listar                       |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <C>  Excluir cadastro             |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <D>  Alterar cadastro             |\n");
        printf("   |-----------------------------------|\n");
        printf("   | <S>  Sair                         |\n");
        printf("   %c-----------------------------------%c",200,188);
        printf("\n\n\n\n");
        printf("\t\t\t      By Adelman Benigno");

        //Lendo a opcao do menu   
        fflush(stdin);
        opcao= getch();

        //Menu de opcoes
        switch(opcao)
        {
            case 'A':
            case 'a':
                //Inserindo os restaurantes.
                fflush(stdin);
                system("cls");
                printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
                printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                primeiro= inserir_pets(primeiro);
                getch();
                system("cls");
                break;

            case 'B':
            case 'b':
                //Listando os restaurantes.
                system ("cls");
                printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                printf(" | ");printf("\t\t\t     PETS CADASTRADOS");printf("\t\t\t      |\n");
                printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                listar_pets(primeiro);
                getch();
                system("cls");
                break;

            case 'C':
            case 'c':
                //Excluindo restaurantes da lista.
                system ("cls");
                printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
                printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                primeiro= excluir_pets(primeiro);
                getch();
                system("cls");
                break;

            case 'D':
            case 'd':
                //Alterando restaurantes da lista. 
                system ("cls");
                printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
                printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                alterar_pets(primeiro);
                getch();
                system("cls");
                break;

            case 'S':
            case 's':
                //Artif�cio para sair do programa.
                opcao='s';
                break;

            default:
                //Artif�cio que previne a situa��o de um usu�rio qualquer, digitar uma opc�o inexistente no menu.
                system("cls");
                break;
        }
    }
}

Lista* inserir_pets (Lista *primeiro){
    Lista pet;
    Lista *atual= primeiro;
    char identificador= 'F';

    //Lendo as informa��es do restaurante.
    printf("  Nome: ");
    fflush (stdin); fgets(pet.nome, 40, stdin); printf ("\n");
    printf("  Esp�cie: ");
    fflush (stdin); fgets(pet.especie, 40, stdin); printf ("\n");
    printf("  Ra�a: ");
    fflush (stdin); fgets(pet.raca, 40, stdin); printf ("\n");
	printf("  Sexo (M ou F): ");
    fflush (stdin); fgets(pet.sexo, 2, stdin); printf ("\n");
    printf("  Idade: ");
    fflush (stdin); fgets(pet.idade, 2, stdin); printf ("\n");
    printf("  Data de Nascimento: ");
    fflush (stdin); fgets(pet.data_nasc, 10, stdin); printf ("\n");
    printf("  Descri��o: ");
    fflush (stdin); fgets(pet.descricao, 140, stdin); printf ("\n");
    printf("  C�digo: ",162);
    scanf("%u",&pet.codigo);printf ("\n");

    //Verificando se o cadastro j� existe.
    for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==pet.codigo){
            identificador= 'V';
            break;
        }
    }
    
    if(identificador!='V' && strlen(pet.nome)!=1){
        //Alocando os espa�os e guardando as informa��es do restaurante.
        Lista* NovoPet=(Lista*) malloc (sizeof(Lista));
		if (NovoPet == NULL) {
    		fprintf(stderr, "Falha ao alocar mem�ria");
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
//        strcpy(NovoPet->endereco, pet.endereco);
        NovoPet->codigo= pet.codigo;
        NovoPet->prox= primeiro;
        printf("  Cadastro realizado com sucesso.");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return NovoPet;
    }else{
        printf("  Cadastro inv�lido.",160);
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
    }
}

void listar_pets (Lista* primeiro){
    Lista* atual;//Ponteiro para percorrer a lista sem perder a refer�ncia do primeiro elemento da lista.

    //Imprimindo os restaurantes da lista, e suas repectivas informa��es.
    for(atual= primeiro ; atual!= NULL; atual= atual->prox){
        printf("\n  Nome: ");
        printf("%s", atual->nome);
//        printf("\n  Endere%co: ",135);
//        printf("%s", atual->endereco);
        printf("\n  C%cdigo: ",162 );
        printf("%u", atual->codigo);
        printf("\n\n");
    }
    if(primeiro==NULL)
        printf("  Nenhum restaurante cadastrado.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_pets(Lista *primeiro){

    Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    unsigned long int codigo=0;

    //Requisitando e lendo o c�digo do restaurante a ser exclu�do.
    printf("  C%cdigo do restaurante a ser exclu%cdo: ", 162,161);
    fflush(stdin);
    scanf("%u",&codigo);

    //Procurando o restaurante na lista.
    while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
    }

    //Mensagem caso o restaurante n�o seja encontrado.
    if(atual==NULL){
        printf("\n  Restaurante n%co encontrado.", 198);
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
    }

    //Excluindo o primeiro restaurante da lista.   
    if(anterior==NULL){
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        primeiro= atual->prox;
        //Excluindo um restaurante do meio da lista.
    }else{
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        anterior->prox= atual->prox;
    }

    //Desalocando o espa�o da mem�ria.
    free(atual);
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
}

//Fun��o para alterar restaurantes.
void alterar_pets(Lista* primeiro){
    char nome_substituto[40], endereco_substituto[40];
    unsigned long int codigo;
    Lista* atual=primeiro;

    //Requisitando e lendo o c�digo do restaurante a ser alterado.
    printf("  C%cdigo do restaurante a ser alterado: ", 162);
    fflush(stdin);
    scanf("%u",&codigo);

    //Procurando o restaurante na lista.
    while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
    }

    //Alterando os dados do restaurante.
    if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 40, stdin);
        strcpy(atual->nome,nome_substituto);
        printf("\n  Novo endere%co: ",135);
//        fflush (stdin); fgets(endereco_substituto, 40, stdin); printf ("\n");
//        strcpy(atual->endereco,endereco_substituto);
        printf("  Dados alterados com sucesso.");
    }else{
        printf("\n  Restaurante n%co encontrado.",198);
    }
    printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
