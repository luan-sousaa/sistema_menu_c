#include <stdio.h>
#include <stdlib.h>
char senha[8], nome_cliente[50][10] , nome_pet[50][10] ;
int telefone[10] , opcao, quant, i , numeroClientes;

void cadastro(){
	imprimirNomePetshop();
    if (numeroClientes < 10) {
        printf("Nome Cliente :\n");
        fflush(stdin);
        scanf("%s", &nome_cliente[numeroClientes]);
        
        printf("Nome Pet :\n");
        fflush(stdin);
        scanf("%s", &nome_pet[numeroClientes]);
        
        printf("Numero de telefone :\n");
        fflush(stdin);
        scanf("%i",&telefone[numeroClientes]);
        system("cls");
        printf("CADASTRADO COM SUCESSO!");
        numeroClientes++;
	} else {
		printf("Numero maximo de cadastros atingido!\n");
	}
}