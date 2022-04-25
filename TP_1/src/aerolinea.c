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

///se declara funcion para realizar los calculo aritmetico
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
///variable para el menu:dentro de do while y switch
    char repetir = TRUE;
    int opcion;
///variables para ingreso de datos de Kilometro y Precio de Aerolinea y Latam
    int KM=0;
    int precioLatam=0,precioAerolinea=0;
///variables para calculo aritmetico
    float DebitoDescuento10A=0,DebitoDescuento10L=0;
    float CreditoInteres25A=0,CreditoInteres25L=0;
    float BitcoinA=0,BitcoinL=0;
    float PrecioUnitarioA=0,PrecioUnitarioL=0;
    float Diferencia=0;
///se crea una bandera en la opcion 4 dentro del switch ,para habilitar despues la opcion 5 carga forzada
    int Bandera=0;
///variables:para carga forzada
    int ForzadaKM=7090,ForzadaPrecioL=159339,ForzadaPrecioA=162965;
    float FDebitoDescuento10A=0,FDebitoDescuento10L=0;
    float FCreditoInteres25A=0,FCreditoInteres25L=0;
    float FBitcoinA=0,FBitcoinL=0;
    float FPrecioUnitarioA=0,FPrecioUnitarioL=0;
    float FDiferencia=0;
 ///se crea el do while con la condicion true y false,con el funcionamiento de trabajar con el menu abm
    do {
       ///se crea varios sprintf para presentar una imagen de menu
        printf("\n\n\t\t\tMenu de Opciones\n");
        printf("\t\t\t----------------\n");
        printf("\n\t1. Ingresar KM:(%dKM)\n ",KM);
        printf("\t2. Ingresar Vuelos:(Aerolineas:%d, Latam:%d)\n",precioAerolinea,precioLatam);
        printf("\t3. Calcular todos los costos\n");
        printf("\t4. Informar Resultados\n");
        printf("\t5. Carga forzada de datos\n");
        printf("\t0. SALIR\n");
        ///se ingresan en la 6 opciones switch para el proceso del abm
        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);


        switch (opcion) {
            case 1:

                /// En la primera opcion se ingresa el Km correspondiente
                printf("\t\tIngrese el KM: ");
                scanf("%d", &KM);
                printf("\t---------------------------\n");
                printf("\t\t.............>Enter para volver al Menu");
                system("pause>nul");
                break;

            case 2:
            	///En la segunda opcion se ingresa los precion de Aerolinea y Latam
                printf("\t\tIngrese el precio del vuelo Aerolinea: ");
                scanf("%d", &precioAerolinea);
                printf("\t\tIngrese el precio del vuelo Latam: ");
                scanf("%d", &precioLatam);
                printf("\t\t\t.............>Enter para volver al Menu");
                system("pause>nul");
                break;

            case 3:
            	///En la 3ra opcion tiene que realizar calculo,si la condicion de previamente alla ingresado el KM y los precio de Latam y Aerolinea
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
				///el la 4ta opcion se mostrara el informe si en la opcion 3 se calculo, sino te muestra un mensaje que vuelva al menu
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
				///se realiza carga de datos forzados si la opcion 4 realizo su funcionamiento sino se procede volver al menu
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
            	///En la opcion 0 se procede a finalizar el switch y el do while
            	repetir = FALSE;
            	break;
        }
    } while (repetir);

    return 0;
}
///@brief En la funcion float TarjetaDebito se procede a realizar calculo del descuento del 10 porciento con km y precio
/// @param se declara variable porcentaje10 y descuento
/// @param con porcentaje10 se sacara el 10 por ciento
/// @param con descuento se calculara el descuento del 10 por ciento
/// @return se retornara en descuento

float TarjetaDebito(int km,int precio)
{
	float descuento;
	float porcentaje10;

	porcentaje10=((float)km*precio)*10/100;
	descuento=((float)km*precio)-porcentaje10;

	return descuento;
}
///@brief En la funcion float TarjetaCredito se procede a realizar calculo de interes del  25 porciento con km y precio
/// @param se declara variable interes y porcentaje25
/// @param con porcentaje25 se calcula 25 por ciento del km x precio
/// @param con interes se calculara el incremento  del 25 por ciento
/// @return se retornara en interes

float TarjetaCredito(int km,int precio)
{
float interes;
float porcentaje25;

porcentaje25=((float)km*precio)*25/100;
interes=((float)km*precio)+porcentaje25;

return interes;

}
///@brief En la funcion float Bitcoin se procede a realizar calculo   km y precio igualando el total de bitcoin
/// @param se declara variable precioUnitario y calculoBitcoin
/// @param con precioUnitario se calcula Km por Precio
/// @param con CalculoBitcoin se calculara el valor del mismo con precio unitario
/// @return   se retornara en CalculoBitcoin

float Bitcoin(int km,int precio)
{
float precioUnitario;
float CalculoBitcoin;

precioUnitario=precio*km;
CalculoBitcoin=4606954.55/(precioUnitario*100);

return CalculoBitcoin;
}
///@brief En la funcion float PrecioUnitario  se procede a realizar solamente con km por  precio
/// @param se declara variable PrecioUnitario
/// @param con PrecioUnitario se calcula el Km x precio
/// @return   se retornara en PrecioUnitario

float PrecioUnitario(int km,int precio)
{
float PrecioUnitario;
PrecioUnitario=precio*km;
return PrecioUnitario;
}
///@brief En la funcion float DiferenciadePrecio  se calcularan el precio de Latam menos Aerolinea
/// @param se declara variable diferencia
/// @param con diferencia se calcula el precio de Latam menos Aerolinea
/// @return   se retornara en diferencia
float DiferenciadePrecio(int precioA,int precioL)
{
float diferencia;
diferencia=precioA-precioL;
return diferencia;
}


