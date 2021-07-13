#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>

struct Tentradas{
	char nombre[50];
	float importe;
	int maxentradas;
	int totalmaxentradas;
};

void banner();

int main(){

    setlocale(LC_ALL, "spanish");

	FILE *pfichero;
	struct Tentradas maqentradas[20];
	char sel_operacion, sel_entradas, seguir_compra, otra_operacion, cliente;
	int nentradas=0, i, nmaxclientes=10;

	int totalmaxentradas=5;

	float precio=0.0, pago_introducido, pago_total=0.0, vuelta=0.0;

	pfichero=fopen("entradas.txt", "r");

	system("color F5");

	if (pfichero == NULL) {
		printf("\n");
		printf("  No se encuentra el fichero 'entradas.txt'\n");
		printf("\n");
		return 0;
	}

	while(fscanf(pfichero, "%s %f %i", maqentradas[nentradas].nombre, &maqentradas[nentradas].importe, &maqentradas[nentradas].maxentradas)!=EOF){
		nentradas++;
	}
	fclose(pfichero);

	do{
		banner();
	do{

		printf("\n");
		printf("     Teclea 'C' para comprar entradas\n     Teclea 'P' para pagar entradas\n     Teclea 'S' para ver la cesta actual\n");
		fflush(stdin);
		printf("\n");
		printf("  Selecciona la operacion que deseas realizar: ");
		scanf("%c",&sel_operacion);
		system("cls");

		if ((sel_operacion == 'C') || (sel_operacion == 'c')){
			printf("\n");
			printf("  Has seleccionado la opcion 'COMPRAR ENTRADAS'.\n");
			do{
				for(i=0;i<nentradas;i++){
					printf("     \t%s\t", maqentradas[i].nombre);
					if(maqentradas[i].importe==1){
						printf("%.2f euro\t",maqentradas[i].importe);
					}else{
						printf("%.2f euros\t",maqentradas[i].importe);
					}
					printf("Quedan: %i\n\n",maqentradas[i].maxentradas);
				}
				printf("\n");
				printf("        Volver(V)\n");
				fflush(stdin);
                printf("\n");
                printf("  Selecciona la entrada que quieres comprar: ");
				scanf("%c",&sel_entradas);
				system("cls");
				if ((sel_entradas == 'A') || (sel_entradas == 'a')){
					if(maqentradas[0].maxentradas==0){
						printf("\n");
						printf("La entrada ");
						printf(maqentradas[0].nombre);
						printf(" esta agotada\n");
						break;
					}else{
						precio+=maqentradas[0].importe;
						maqentradas[0].maxentradas--;
					}
				}
				else if((sel_entradas == 'I') || (sel_entradas == 'i')){
					if(maqentradas[1].maxentradas==0){
						printf("\n");
						printf("La entrada ");
						printf(maqentradas[1].nombre);
						printf(" esta agotada\n");
						break;
					}else{
						precio+=maqentradas[1].importe;
						maqentradas[1].maxentradas--;
					}
				}
				else if((sel_entradas == 'R') || (sel_entradas == 'r')){
					if(maqentradas[2].maxentradas==0){
						printf("\n");
						printf("La entrada ");
						printf(maqentradas[2].nombre);
						printf(" esta agotada\n");
						break;
					}else{
						precio+=maqentradas[2].importe;
						maqentradas[2].maxentradas--;
					}
				}
				else if((sel_entradas == 'S') || (sel_entradas == 's')){
					if(maqentradas[3].maxentradas==0){
						printf("\n");
						printf("La entrada ");
						printf(maqentradas[3].nombre);
						printf(" esta agotada\n");
						break;
					}else{
						precio+=maqentradas[3].importe;
						maqentradas[3].maxentradas--;
					}
				}
				else if((sel_entradas == 'M') || (sel_entradas == 'm')){
					if(maqentradas[4].maxentradas==0){
						printf("\n");
						printf("La entrada ");
						printf(maqentradas[4].nombre);
						printf(" esta agotada\n");
						break;
					}else{
						precio+=maqentradas[4].importe;
						maqentradas[4].maxentradas--;
					}
				}
				else if((sel_entradas == 'N') || (sel_entradas == 'n')){
					if(maqentradas[5].maxentradas==0){
						printf("\n");
						printf("La entrada ");
						printf(maqentradas[5].nombre);
						printf(" esta agotada\n");
						break;
					}else{
						precio+=maqentradas[5].importe;
						maqentradas[5].maxentradas--;
					}
				}
				else if((sel_entradas == 'V') || (sel_entradas == 'v')){
					break;
				}
				else{
					printf("\n");
					printf("  La letra introducida no corresponde a ningun tipo de entrada.\n  Selecciona otra entrada por favor.\n");
				}
				fflush(stdin);
				printf("\n");
				printf("  ¿Quieres comprar otra entrada?\n     Teclea 'S' para si\n     Teclea 'N' para no\n");
				scanf("%c",&seguir_compra);
				system("cls");
			}while ((seguir_compra != 'N') && (seguir_compra != 'n'));
		}


		if((sel_operacion == 'S')||(sel_operacion == 's')){
			printf("\n");
			printf("  Su cesta actual es:\n     -Entrada Adulto Normal: %i\n     -Entrada Infantil Normal: %i\n     -Entrada Adulto Fila Rapida: %i\n     -Entrada Infantil Fila Rapida: %i\n     -Entrada Adulto con Menu: %i\n     -Entrada Infantil con Menu: %i\n",totalmaxentradas-maqentradas[0].maxentradas, totalmaxentradas-maqentradas[1].maxentradas, totalmaxentradas-maqentradas[2].maxentradas, totalmaxentradas-maqentradas[3].maxentradas, totalmaxentradas-maqentradas[4].maxentradas, totalmaxentradas-maqentradas[5].maxentradas);
		}

		if((sel_operacion == 'P') || (sel_operacion == 'p')){
			if(precio==0){
				printf("\n");
				printf("  No has comprado ninguna entrada.\n");
			}else{
				printf("\n");
				printf("  Introduce el dinero\n");
				while(pago_total<precio){
					printf("\n");
					printf("  Cantidad a introducir: %.2f\n",precio-pago_total);
					printf("\n");
					fflush(stdin);
					scanf("%f",&pago_introducido);
					pago_total+=pago_introducido;
					system("cls");
				}
				vuelta=pago_total-precio;
				printf("\n");
				printf("Esta es la vuelta: %.2f\n",vuelta);
				break;
			}


		}if((sel_operacion== 'N') || (sel_operacion =='n')){
			break;
		}
		if((sel_operacion != 'C') && (sel_operacion != 'c') && (sel_operacion != 'S') && (sel_operacion != 's') && (sel_operacion != 'P') && (sel_operacion != 'p') && (sel_operacion != 'N') && (sel_operacion != 'n')){
			printf("\n");
			printf("  La letra introducida no es correcta, no corresponde a ninguna operacion\n");
		}
		printf("\n");
		printf("  ¿Deseas realizar otra operacion?\n     Teclea 'S' para si\n     Teclea 'N' para no\n");
		fflush(stdin);
		scanf("%c",&otra_operacion);
		system("cls");

	}while((otra_operacion != 'N') && (otra_operacion != 'n'));

	if(pago_total<precio){
		printf("\n");
		printf("  Introduce el dinero\n");
		while(pago_total<precio){
			printf("\n");
			printf("  Cantidad a introducir: %.2f\n",precio-pago_total);
			fflush(stdin);
			scanf("%f", &pago_introducido);
			pago_total+=pago_introducido;
			system("cls");
		}
		vuelta=pago_total-precio;
		printf("\n");
		printf("  Esta es la vuelta: %.2f euros\n",vuelta);
	}

	printf("\n");
	printf("  ¡Muchas gracias por tu compra!\n");
	printf("\n");
	printf("  ¡DISFRUTA DE TU VISITA!\t");

	Sleep(6000);
	system("cls");
	printf("\n");
	printf("  ¿Hay algun otro cliente?\n     Teclea 'N' si no hay mas clientes\n     Teclea cualquier otro caracter si hay otro cliente\n");
	fflush(stdin);
	scanf("%c",&cliente);
	system("cls");

	}while((cliente != 'N')&&(cliente != 'n'));

	system("cls");
	printf("\n");
	printf("  Cerrando programa...");
	Sleep(2000);
	return 0;
}


void banner(){
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t VENTA DE ENTRADAS DE AQUAPARK");
	Sleep(3000);
	system("cls");
}
