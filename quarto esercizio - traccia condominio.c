/*
 ============================================================================
 Name        : quarto.c
 Author      : piersilvio
 Version     :
 Copyright   :
 Description : prova itinere sui condomini
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max 100

//dichiarazione della struttura
typedef struct{

	char id[10];
	char nome[10];
	char cognome[10];
	char piano[50];
	char interno[50];
	float quota_vers;
	float tot_spesa_ord;
	float tot_spesa_straord;
	char saldo[50];

}condominio;

//dichiarazione array di record
condominio cond[max];

//dichiarazione delle funzioni
void ricerca();
void inserimento();
void stampa();

//variabili globali
int n_cond = 0;
int scelta;
int i;

int main(){


	do{

		printf(":: inserire numero condomini: \n");
		fflush(stdout);
		scanf("%d", &n_cond);

	}while(n_cond <= 0);

	inserimento();

	do{

		printf(":: ricerca del condomino (1) \n");
		printf(":: stampa tabella (2) \n");
		printf(":: esci dal sistema (3) \n");
		fflush(stdout);
		scanf("%d", &scelta);

		switch(scelta){

		case 1:
			ricerca();
		break;
		case 2:
			stampa();
		break;
		}

	}while(scelta != 3);


	return 0;
}

void inserimento(){

	double saldo_lav = 0;
	char debito[50] = "DEBITO";
	char credito[50] = "CREDITO";
	char pari[50] = "PARI ALLA QUOTA VERSATA";

	for(i = 0; i < n_cond; i++){

			printf(":: codice id: \n");
			fflush(stdout);
			scanf("%s", cond[i].id);

			printf(":: nome: \n");
			fflush(stdout);
			scanf("%s", cond[i].nome);

			printf(":: cognome: \n");
			fflush(stdout);
			scanf("%s", cond[i].cognome);

			printf(":: piano: \n");
			fflush(stdout);
			scanf("%s", cond[i].piano);

			printf(":: interno: \n");
			fflush(stdout);
			scanf("%s", cond[i].interno);

			printf(":: quota versata: \n");
			fflush(stdout);
			scanf("%f", &cond[i].quota_vers);

			printf(":: totale spesa ordinaria: \n");
			fflush(stdout);
			scanf("%f", &cond[i].tot_spesa_ord);

			printf(":: totale spesa straordinaria: \n");
			fflush(stdout);
			scanf("%f", &cond[i].tot_spesa_straord);


			saldo_lav = cond[i].tot_spesa_ord + cond[i].tot_spesa_straord;

			if(saldo_lav < cond[i].quota_vers){

				strcpy(cond[i].saldo, debito);

			}else if(saldo_lav > cond[i].quota_vers){

				strcpy(cond[i].saldo, credito);

			}else{

				strcpy(cond[i].saldo, pari);
			}


		}
}

void stampa(){

	for(i = 0; i < n_cond; i++){

		printf("id: %s \n", cond[i].id);
		printf("id: %s \n", cond[i].nome);
		printf("id: %s \n", cond[i].cognome);
		printf("id: %s \n", cond[i].piano);
		printf("id: %s \n", cond[i].interno);
		printf("id: %f \n", cond[i].quota_vers);
		printf("id: %f \n", cond[i].tot_spesa_ord);
		printf("id: %f \n", cond[i].tot_spesa_straord);
		printf("id: %s \n", cond[i].saldo);
		printf("\n");
	}
}


void ricerca(){

	char id[10];
	_Bool flag;
	int scelta_int;

	do{

            printf(":: inserire il codice id del condomino: \n");
			fflush(stdout);
			scanf("%s", id);

			flag = 0; //flag = false;

			for(i = 0; i < n_cond; i++){

				if(id == cond[i].id){

					printf(":: ricerca risolta con successo! \n");
                    printf("id: %s \n", cond[i].id);
                    printf("id: %s \n", cond[i].cognome);
                    printf("id: %s \n", cond[i].piano);
                    printf("id: %s \n", cond[i].interno);
                    printf("id: %f \n", cond[i].quota_vers);
                    printf("id: %f \n", cond[i].tot_spesa_ord);
                    printf("id: %f \n", cond[i].tot_spesa_straord);
                    printf("id: %s \n", cond[i].saldo);

                    flag = 1;
				}
			}
			if(flag == 0){
                printf("%d", flag);
                printf(":: ricerca non riuscita! \n");
			}






			printf(":: effettuare una nouva scelta? (1-si) (2-no) \n");
			fflush(stdin);
			scanf("%d", &scelta_int);

	}while(scelta_int == 1);

}
