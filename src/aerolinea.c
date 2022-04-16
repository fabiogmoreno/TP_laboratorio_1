/*
 ============================================================================
 Name        : aerolinea.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
///@brief Proceso a declarar variable de la firma para la funcion aritmetica
///
///

float TarjetaDebito(int km,int precio);
float TarjetaCredito(int km,int precio);
float Bitcoin(int km,int precio);
float PrecioUnitario(int km,int precio);
float DiferenciadePrecio(int precioA,int precioL);
///@brief En la funcion main se procede a realizar menu y abm de una agencia de avion
/// @param 1.Declaraciones de variable que subdivide su procedimiento.
/// @param 2.Se crea la funcion Ciclo repetitivo Do While: con la condicion que   repetir=true se seguira repitiendo,de lo contrario para salir repetir=false
/// @param 3.se crea varios printf:para precentar una imagen reprecentativo del menu del abm
/// @param 4 se crea un Swhitch:para crear 6 opciones del menu del amb
/// @return 5 se finaliza en esta funcion:con la opcion del swhitch 0: que se pondran la misma variable de la condicion Do while repetir=false.

int main()
{setbuf(stdout,NULL);
///@brief En la funcion main se procede a realizar menu y abm de una agencia de avion
/// @param 1.Declaraciones de variable que subdivide su funcion:
/// @param 2.Declaracion variable repetir=true para el siclo doWhile ,de lo contrario se sale con repetir=false
/// @param 3


    char repetir = TRUE;
    int opcion;

    int KM=0;
    int precioLatam=0,precioAerolinea=0;
    float DebitoDescuento10A=0,DebitoDescuento10L=0;
    float CreditoInteres25A=0,CreditoInteres25L=0;
    float BitcoinA=0,BitcoinL=0;
    float PrecioUnitarioA=0,PrecioUnitarioL=0;
    float Diferencia=0;

    int Bandera=0;
    //variables para datos forzados
    int ForzadaKM=7090,ForzadaPrecioL=159339,ForzadaPrecioA=162965;
    float FDebitoDescuento10A=0,FDebitoDescuento10L=0;
    float FCreditoInteres25A=0,FCreditoInteres25L=0;
    float FBitcoinA=0,FBitcoinL=0;
    float FPrecioUnitarioA=0,FPrecioUnitarioL=0;
    float FDiferencia=0;
    do {
        //system("cls");

        // Texto del menú
        printf("\n\n\t\t\tMenu de Opciones\n");
        printf("\t\t\t----------------\n");
        printf("\n\t1. Ingresar KM:(%dKM)\n ",KM);
        printf("\t2. Ingresar Vuelos:(Aerolineas:%d, Latam:%d)\n",precioAerolinea,precioLatam);
        printf("\t3. Calcular todos los costos\n");
        printf("\t4. Informar Resultados\n");
        printf("\t5. Carga forzada de datos\n");
        printf("\t0. SALIR\n");

        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);


        switch (opcion) {
            case 1:

                // Instrucciones para sumar dos números
                printf("\t\tIngrese el KM: ");
                scanf("%d", &KM);
                printf("\t---------------------------\n");
                printf("\t\t.............>Enter para volver al Menu");
                system("pause>nul");
                break;

            case 2:

                printf("\t\tIngrese el precio del vuelo Aerolinea: ");
                scanf("%d", &precioAerolinea);
                printf("\t\tIngrese el precio del vuelo Latam: ");
                scanf("%d", &precioLatam);
                printf("\t\t\t.............>Enter para volver al Menu");
                system("pause>nul");
                break;

            case 3:
            	if(KM==0 && precioAerolinea==0 && precioLatam==0)
            	{
            		printf("......>No realizaste cargas de Kilometro y los precio tipo de vuelos cargados completos previamente.Enter para volver al Menu");
            	}
            		else
            			{	///CALCULA:
            			            		/// REALIZA LLAMADO A LA FUNCION CALCULADO
            			            		/// LA VARIABLE DESCUENTO: REALIZA DESCUENTO DE 10% CON DEBITO,1 CON AEROLINEA Y LA 2 CON LATAM
            			            		/// LA VARIABLE CREDITO:REALIZA RECARGA DE 25% CON CREDITO,
            			            		///

            			            		DebitoDescuento10A=TarjetaDebito(KM,precioAerolinea);
            			            		DebitoDescuento10L=TarjetaDebito(KM,precioLatam);
            			            		CreditoInteres25A=TarjetaCredito(KM,precioAerolinea);
            			            		CreditoInteres25L=TarjetaCredito(KM,precioLatam);
            			            		BitcoinA=Bitcoin(KM,precioAerolinea);
            			            		BitcoinL=Bitcoin(KM,precioLatam);
            			            		PrecioUnitarioA=PrecioUnitario(KM,precioAerolinea);
            			            		PrecioUnitarioL=PrecioUnitario(KM,precioLatam);
            			            		Diferencia=DiferenciadePrecio(precioAerolinea,precioLatam);
            			            		 printf("\t\tCalcular los siguientes:\n");
            			            		 printf("\t\ta) Tarjeta de debito (descuento 10)\n");
            			            		 printf("\t\tb) Tarjeta de credito (interes 25)\n");
            			            		 printf("\t\tc) Bitcoin 1BTC -> 4606954.55 Pesos Argentinos)\n");
            			            		 printf("\t\td) Mostrar precio por km (precio unitario)\n");
            			            		 printf("\t\te) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
            			            		printf("\t\t\t\t.............>Realizaste todos los calculo nesesario para el siguiente informe.Enter para volver al Menu\n");
            			 }



                system("pause>nul");
                break;

			case 4:

				if(DebitoDescuento10A==0 && DebitoDescuento10L==0 && CreditoInteres25A==0 && CreditoInteres25L==0 && BitcoinA==0 && BitcoinL==0 && PrecioUnitarioA==0 && PrecioUnitarioL==0 && Diferencia==0)
				            				{
				            				printf(".............>Para esta opcion tiene que realizar calculo.Enter para volver al Menu");
				            				}

				            				else
				            			  {

				            				printf("\t\tLatam:\n");
				            				printf("\t\ta) Precio con tarjeta de debito: %f\n",DebitoDescuento10L);
				            				printf("\t\tb) Precio con tarjeta de credito: %f\n",CreditoInteres25L);
				            				printf("\t\tc) Precio pagando con bitcoin: %f\n",BitcoinL);
		                                    printf("\t\td) Precio unitario: %f\n",PrecioUnitarioL);
				            				printf("\t\tAerolineas:\n");
				            				printf("\t\ta) Precio con tarjeta de debito: %f\n",DebitoDescuento10A);
				            			    printf("\t\tb) Precio con tarjeta de credito: %f\n",CreditoInteres25A);
				            				printf("\t\tc) Precio pagando con bitcoin: %f\n",BitcoinA);
				            				printf("\t\td) Precio unitario: %f\n",PrecioUnitarioA);
				            				printf("\t\t La diferencia de precio entre Latam y Aerolinea: %f\n",Diferencia);
				            				printf("\t\t\t\t.............>Enter para volver al Menu\n");
				            				Bandera=1;
				            			  }
                system("pause>nul");
                break;
			case 5:
				if(Bandera==0)
				{
					printf("No realizaste procedimiento anteriores");
				}
				else
				{//ForzadaKM=7090,ForzadaPrecioL=159339,ForzadaPrecioA=162965;
					FDebitoDescuento10A=TarjetaDebito(ForzadaKM,ForzadaPrecioA);
					FDebitoDescuento10L=TarjetaDebito(ForzadaKM,ForzadaPrecioL);
					FCreditoInteres25A=TarjetaCredito(ForzadaKM,ForzadaPrecioA);
					FCreditoInteres25L=TarjetaCredito(ForzadaKM,ForzadaPrecioL);
					FBitcoinA=Bitcoin(ForzadaKM,ForzadaPrecioA);
					FBitcoinL=Bitcoin(ForzadaKM,ForzadaPrecioL);
					FPrecioUnitarioA=PrecioUnitario(ForzadaKM,ForzadaPrecioA);
					FPrecioUnitarioL=PrecioUnitario(ForzadaKM,ForzadaPrecioL);
					FDiferencia=DiferenciadePrecio(ForzadaPrecioA,ForzadaPrecioL);
					printf("\t\tLatam:\n");
									            				printf("\t\ta) Precio con tarjeta de debito: %f\n",FDebitoDescuento10L);
									            				printf("\t\tb) Precio con tarjeta de credito: %f\n",FCreditoInteres25L);
									            				printf("\t\tc) Precio pagando con bitcoin: %f\n",FBitcoinL);
							                                    printf("\t\td) Precio unitario: %f\n",FPrecioUnitarioL);
									            				printf("\t\tAerolineas:\n");
									            				printf("\t\ta) Precio con tarjeta de debito: %f\n",FDebitoDescuento10A);
									            			    printf("\t\tb) Precio con tarjeta de credito: %f\n",FCreditoInteres25A);
									            				printf("\t\tc) Precio pagando con bitcoin: %f\n",FBitcoinA);
									            				printf("\t\td) Precio unitario: %f\n",FPrecioUnitarioA);
									            				printf("\t\t La diferencia de precio entre Latam y Aerolinea: %f\n",FDiferencia);
									            				printf("\t\t\t\t.............>Enter para volver al Menu\n");
				}
				 system("pause>nul");
				break;
            case 0:
            	repetir = FALSE;
            	break;
        }
    } while (repetir);

    return 0;
}
//Funcion taarjeta del descuento 10% debito:
float TarjetaDebito(int km,int precio)
{
	float descuento;
	float porcentaje10;

	porcentaje10=((float)km*precio)*10/100;
	descuento=((float)km*precio)-porcentaje10;

	return descuento;
}

float TarjetaCredito(int km,int precio)
{
float interes;
float porcentaje25;

porcentaje25=((float)km*precio)*25/100;
interes=((float)km*precio)+porcentaje25;

return interes;

}

float Bitcoin(int km,int precio)
{
float precioUnitario;
float CalculoBitcoin;

precioUnitario=precio*km;
CalculoBitcoin=4606954.55/(precioUnitario*100);

return CalculoBitcoin;
}

float PrecioUnitario(int km,int precio)
{
float PrecioUnitario;
PrecioUnitario=precio*km;
return PrecioUnitario;
}
float DiferenciadePrecio(int precioA,int precioL)
{
float diferencia;
diferencia=precioA-precioL;
return diferencia;
}


