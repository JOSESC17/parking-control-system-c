#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///Definición de constantes para modificar el tamaño de la matriz. 
///La matriz consta de 4x3 = 12 puestos en total
#define X 4 /// FILAS
#define Y 3 /// COLUMNAS
#define TARIFASxHORA 1.5
 
void Menu();
int DisponibilidadPuestos(int matriz[X][Y]);
void Mapa(int matriz[X][Y]);
void Entrada(int matriz[X][Y],float horas_entrada[X][Y]);
void Salida(int matriz[X][Y],float horas_entrada[X][Y], float *dinero_total);

///Se inicializan las variables para los puestos, el valor acumulador de la caja y las horas de entrada.
int main(){
	int puestos [X][Y]={0};
    float caja_total = 0.0;
    float horas_entrada[X][Y]= {0.0};

    ///Esta variable corresponde al switch-case para el menú que dará la posibilidad de elegir opciones
    int opciones;
    ///Variable para el chequeo de disponibilidad 
    int disponibles;
    ///Dentro del bucle Do-While imprimiremos el menu y pondremos las condiciones en las que este se repetirá, a su vez,
    ///el programa chequea la disponibilidad de puestos con la variable "disponibles".
    do{
        ///Limpiamos el codigo con system("cls") por cada vez que se eliga una opción y no acumular espacio en la visualización del menú.
        system("cls");
        disponibles = DisponibilidadPuestos(puestos);
        printf("-----BIENVENIDO AL ESTACIONAMIENTO-----\n");
        printf("El limite del estacionamiento es: %d\n", X*Y);
        printf("Los puestos disponibles son: %d\n", disponibles);
      /// Llamamos a la función menú
        Menu();
        printf("Elige una opción del (1-6)\n");
        scanf("%d", &opciones);
        
        switch(opciones){
            case 1:
                system("cls");
                printf("----DISPONIBILIDAD DE PUESTOS----\n");
                printf("Puestos vacíos: %d\n", disponibles);
                printf("Puestos ocupados: %d\n", (X*Y)-disponibles);
                break;
            case 2:
                system("cls");
                Mapa(puestos);
                break;
            case 3:
                system("cls");
                Entrada(puestos,horas_entrada);
                break;
            case 4:
                system("cls");
                ///Se le asigna esa variable al puntero *dinero_total
                Salida(puestos, horas_entrada, &caja_total);
                break;
            case 5:
                system("cls");
                printf("Saldo acumulado en mi caja es: $%.2f\n", caja_total);
                printf("Su monto a pagar es: $%.2f \n",TARIFASxHORA);
                break;
            case 6:
                system("cls");
                printf("HASTA LUEGO! VUELVA PRONTO.\n");
                break;
            default:
                printf("Es inválido, elija nuevamente una opción.\n");
        ///Pausa antes de continuar 
        }if (opciones!=6){
        printf("Presionar Enter para continuar\n");
        ///Para limpiar el buffer o memoria de ese enter presionado
        fflush(stdin);
        ///El getchar() se debe a que el programa debe recibir el espacio del enter para continuar
        getchar();
        }
        
    }while(opciones!=6);
    
    return (0);
}
///Se despliega el Menú desarrollado
void Menu(){
printf("------MENÚ-----\n"); 
printf("1. Disponibilidad de puestos\n");
printf("2. Mapa del estacionamiento\n"); 
printf("3. Entrada\n"); 
printf("4. Salida y Tarifa\n");  
printf("5. Reporte de Caja\n"); 
printf("6. Salir\n"); 
printf("---------------\n");
 }
///En esta función recorremos con bucles anidados la matriz para verificar la presencia de 0 (puestos libres o vacios) para llevar el conteo.
int DisponibilidadPuestos(int matriz[X][Y]) {
    int contador_puestos_vacios = 0;
    for(int i =0;i<X;i++){
        for(int j = 0;j<Y;j++){
            if(matriz[i][j]==0){
                contador_puestos_vacios ++;
            }
        }
    }
return contador_puestos_vacios;
}
void Mapa(int matriz[X][Y]){
    printf("       ----MAPA----\n");
    ///Este es el encabezado de la cantidad de columnas
    printf("        1     2     3\n");
    printf("       --------------\n");
    ///Imprime la cantidad de filas
    for (int i=0;i<X;i++){
        printf("Fila %d",i);
        ///Este bucle for se inserta dentro del bucle anterior para formar un espacio cuadrado en donde recorre cada columna de las filas.
        ///Aquí se visualizarán los puestos disponibles con una "D" de Disponible (0) y "X" Ocupado (1).
        for(int j=0;j<Y;j++){
            if (matriz[i][j]==0){
                printf(" [D]  ");
        }   else{
                printf(" [X]  ");
        }
    }
        printf("\n");
} 
///Estos mensajes le hacen saber al usuario lo que significa cada inicial
    printf("       --------------\n");
    printf("X es OCUPADO\n");
    printf("D es DISPONIBLE\n");
}

void Entrada(int matriz[X][Y], float horas_entrada[X][Y]){
    ///El primer paso en esta lógica es llamar a la función de DisponibilidadPuestos para chequear cuáles lugares están vacíos y cuáles no.
    ///Como es una función que recibe enteros dentro de una función vacía debemos asignarle un valor para poder llamarla.

    ///Debemos asignar nuevas variables por los condicionales para evitar valores fuera de rango.
    int puestos_disponibles, fila, columnas;
    puestos_disponibles = DisponibilidadPuestos(matriz);
    ///El primer paso de estos condicionales es verificar está lleno el estacionamiento (la matriz) 
    if(puestos_disponibles==0){
        printf("ESTÁ FULL, NO PUEDES ENTRAR\n");
    ///Si no está lleno, solicita al usuario la posición en los cuales desea ponerse.
    }else{
        printf("Introduce una fila entre (0-3): \n");
        scanf("%d", &fila);
        printf("Introduce una columna entre (0-2): \n");
        scanf("%d", &columnas);
        ///En esta condición establecemos el rango que debe introducir el usuario en las columnas.

        ///Para esta condición establecemos el rango que debe introducir el usuario en las filas.
        ///Para las filas y columnas debemos poner la condición de >= debido a que la matriz empieza su conteo desde 0.
        if (fila<0 || fila>=X){
            printf("Fuera de rango, introduzca de nuevo\n");
            return;

        }else if(columnas< 0 || columnas>=Y){
            printf("Fuera de rango, introduzca de nuevo\n");
            return;
        ///Este caso verificamos el puesto elegido para cambiar el estado de vacío (0) a ocupado (1)
        }else if (matriz[fila][columnas]==0){
            matriz [fila][columnas] =1;
        ///Solicitar al usuario las horas que estará en el estacionamiento dentro de un bucle para evitar valores fuera de rango
            do{
            printf("Introduzca las hora de entrada: (0:00-24:00h): \n");
            scanf("%f", &horas_entrada[fila][columnas]);

            if (horas_entrada[fila][columnas]<0.0 || horas_entrada[fila][columnas] >24){
                printf("Valor inválido, introduzca de nuevo");
                }
            }while(horas_entrada[fila][columnas]<0.0 || horas_entrada[fila][columnas] >24);

            printf("Perfecto, ha quedado registrado\n");
            return;

        }else{
            printf("Vuelva a escoger, ya se encuentra ocupado\n");
            return;
            
        }
    }
}

void Salida(int matriz[X][Y],float horas_entrada[X][Y], float *dinero_total){
    int fila_salida, columna_salida;
    printf("----SALIDA DEL ESTACIONAMIENTO----\n");
    ///Para que el ciclo se repita al poner un valor incorrecto debemos utilizar un bucle do-while para las filas y otro para las columnas
    do{
    printf("Introduce una fila entre (0-3) en donde se encuentra su vehículo: \n");
    scanf("%d", &fila_salida);
    if (fila_salida<0 || fila_salida>=X){
            printf("Fuera de rango, introduzca de nuevo\n");
        }
    }while(fila_salida<0 || fila_salida>=X);

    do{
    printf("Introduce una columna entre (0-2) en donde se encuentra su vehículo: \n");
    scanf("%d", &columna_salida);
    ///Verificamos nuevamente los rangos permitidos para los puestos.
    if(columna_salida< 0 || columna_salida>=Y){
            printf("Fuera de rango, introduzca de nuevo\n");
        }
    }while(columna_salida< 0 || columna_salida>=Y);


    ///Para que el puesto cambie de ocupado a vacío debemos modificar la matriz con el condicional de 1 a 0.
    if(matriz[fila_salida][columna_salida]==1){

        ///Antes de ejecutar el cambio se debe asegurar el cobro de la tarfia.
        ///Para eso debemos inicializar variables que retornan la hora, el pago de la tarifa y el tiempo que permaneció el vehículo.
        float hora_salida, pago_tarifa, tiempo_e;

        do{
            printf("Introduzca la hora de salida (0-24)horas: \n");
            scanf("%f", &hora_salida);

            if(hora_salida<horas_entrada[fila_salida][columna_salida]||hora_salida>24.0){
                printf("Hora fuera de rango, introduzcala de nuevo.\n");
            }

        } while(hora_salida<horas_entrada[fila_salida][columna_salida]||hora_salida>24.0);

        tiempo_e = hora_salida - horas_entrada[fila_salida][columna_salida];
        pago_tarifa = tiempo_e * TARIFASxHORA;

        ///Esta operación suma el dinero acumulado por el cobro de tarifa en la caja total. 
        *dinero_total += pago_tarifa;

        ///Para reestablecer los valores iniciales de las matrices y evitar que se guarden las datos anteriores debemos declararlas de nuevo fuera del bucle.
        matriz[fila_salida][columna_salida]=0;
        horas_entrada [fila_salida][columna_salida] =0.0;

        printf("--------------------------------\n");
        printf("El tiempo que tardó fue: %.2f\n", tiempo_e);
        printf("El monto total ha sido: $%.2f\n", pago_tarifa);
        printf("--------------------------------\n");
        printf("Gracias por su confianza, vuelva pronto.\n");

    }else{
        printf("Vuelva a escoger, no existe ningún carro en ese puesto.\n");
        return;
    }
}