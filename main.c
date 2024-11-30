#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcoes1.h"


char senha[8], nome_cliente[50][10] , nome_pet[50][10], pet[50][10], escolha_pet[50][10] , opcao_menu_pet[10][20] , diaEscolhido[10][50] , nomeDoutor[10][50];
int telefone[10], opcao, dia[10] , lista_cliente[10], lista_medico[10], i, numeroPets=0 , opcao_serv[10] , numeroConsulta = 0  , opcao_doutor,opcao_cliente[10];
int opcao_dia[10] , numeroClientes;



void agendamento() {
    imprimirNomePetshop(); 

    if (numeroPets >= 10) {
        printf("Numero maximo de agendamentos atingido!\n");
    } else {
        printf("AGENDAR BANHO OU TOSA\n\n");
        printf("Digite o nome do pet: ");
        fflush(stdin);
        scanf("%s", nome_pet[numeroPets]);

        printf("Escolha uma opcao para o servico:\n");
        printf("1 - Banho\n");
        printf("2 - Tosa\n");
        printf("3 - Banho e Tosa\n");
        printf("Digite a opcao desejada: ");
        fflush(stdin);
        scanf("%i", &opcao_serv[numeroPets]);

        switch (opcao_serv[numeroPets]) {
            case 1:
                printf("\n\nOPCAO BANHO SELECIONADA COM SUCESSO!\n");
                strcpy(opcao_menu_pet[numeroPets], "Banho");
				system("cls");
                break;
            case 2:
                printf("\n\nOPCAO TOSA SELECIONADA COM SUCESSO!\n");
                strcpy(opcao_menu_pet[numeroPets], "Tosa");
				system("cls");
                break;
            case 3:
                printf("\n\nOPCAO BANHO E TOSA SELECIONADA COM SUCESSO!\n");
                strcpy(opcao_menu_pet[numeroPets], "Banho e Tosa");
				sleep(1);
				system("cls");
                break;
            default:
                printf("\n\nOpcao invalida, tente novamente!\n\n");
                return;
        }

        numeroPets++;
    }
	
    printf("CADASTRO CONCLUIDO");
}



void consulta(){
	if (numeroConsulta < 10 && numeroClientes > 0) {
		imprimirNomePetshop();
		printf("CONSULTAS \n\n");
		printf("Datas: \n");
		printf("1 - Quinta-feira \n2 - Sexta-feira\n");
		printf("Digite a opcao desejada: ");
		scanf("%i", &opcao_dia[numeroConsulta]);
		

		switch (opcao_dia[numeroConsulta]) {
			case 1:
				strcpy(diaEscolhido[numeroConsulta], "quinta-feira");
				break;
			case 2:
				strcpy(diaEscolhido[numeroConsulta], "sexta-feira");
				break;
			default:
				printf("Opcao invalida!\n");
				return;
		}

		printf("\nClientes Cadastrados:\n");
		for (i = 0; i < numeroClientes; i++) {
			printf("%d - %s\n", i + 1, nome_cliente[i]);
		}

		printf("\nPara qual cliente voce deseja marcar a consulta? ");
		printf("Digite o numero do cliente (1 a %d): ", numeroClientes);
		scanf("%i", &opcao_cliente[numeroConsulta]);
		opcao_cliente[numeroConsulta]--;  // Ajuste para base 0

		if (opcao_cliente[numeroConsulta] < 0 || opcao_cliente[numeroConsulta] >= numeroClientes) {
			printf("Opcao invalida, tente novamente\n");
			return;
		}

		printf("\nDoutor/Doutora:\n");
		printf("1 - Luan\n");
		printf("2 - Fabiano\n");
		printf("Digite a opcao desejada: ");
		scanf("%i", &opcao_doutor);
		system("cls");

		switch (opcao_doutor) {
			case 1:
				strcpy(nomeDoutor[numeroConsulta], "Luan");
				break;
			case 2:
				strcpy(nomeDoutor[numeroConsulta], "Fabiano");
				break;
			default:
				printf("Opcao invalida, Dr./Dr? nao selecionado.\n");
				return;
		}

		numeroConsulta++;
		printf("\nConsulta marcada com sucesso!\n");
	} else {
		printf("Numero maximo de consultas atingido ou nenhum cliente cadastrado!\n");
	
	}
}

void imprimirNomePetshop(){
	printf("\n-----PETSHOP LUANNA'S-----\n");
}


void menu(){
    	imprimirNomePetshop();
	    printf("MENU DE OPCOES \n");
	    printf("1 - CADASTRASTO CLIENTE\n2 - AGENDAR BANHO OU TOSA\n3 - CONSULTA\n4 - IMPRIMIR RELATORIO FINAL\n5 - SAIR\n");
	    scanf("%i",&opcao);
		system("cls");
	    
		}
		
		
		
void relatorio() {
    imprimirNomePetshop();
    printf("INFORMACOES DE CLIENTES CADASTRADOS:\n\n");
    for (i = 0; i < numeroClientes; i++) {
        printf("%d - Nome: %s\n Pet: %s\n Telefone: %d\n", i + 1, nome_cliente[i], nome_pet[i], telefone[i]);
    }

    printf("\nINFORMACOES DE AGENDAMENTOS DE BANHO/TOSA:\n\n");
    for (i = 0; i < numeroPets; i++) {
        printf("%d - Nome do Pet: %s, Servico: %s\n", i + 1, nome_pet[i],opcao_menu_pet[i]);
    }

    printf("\nINFORMACOES DE CONSULTAS AGENDADAS:\n\n");
    for (i = 0; i < numeroConsulta; i++) {
        printf("%d - Data: %d, Cliente: %s, Doutor/Doutora: %s\n", i + 1, diaEscolhido[i], nome_cliente[opcao_cliente[i]], nomeDoutor[i]);
    
	}
}


int main(){
	imprimirNomePetshop();
	setlocale(LC_ALL,"Portuguese");
    while(1){
        printf("Digite Sua Senha :\n");
        gets(senha);
		system("cls");
        if (strcmp(senha, "patinha") == 0){
            printf("Login Feito Com Sucesso\n");
            break;
        }else{
            printf("Senha Incorreta\n");
            printf("Tente Novamente\n");

        }}
        
	menu();
		
	while(1){
	
	switch (opcao){
    	case 1 :
    		printf("cadastrar cliente\n");
    		cadastro();
    		menu();
			
		break;
		case 2 :
    		printf("agenda de banho  \n");
    		agendamento();
    		menu();
		break; 
		case 3 :
    		printf("consulta\n");
    		consulta();
    		menu();
		break;
		case 4 :
    		printf("imprimir relatorio final\n");
    		relatorio();
    		menu();
		break;
		case 5 :
			printf("VOLTE SEMPRE AO PETSHOP LUANNA'S ");
		
			exit(0);
		break;
    	
	}}}

	
	
	
	
	
	
	
	
	