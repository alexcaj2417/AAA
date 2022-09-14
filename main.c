/*Gato*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TITULO "juego del gato V 1.0\n"
#define MAX_FILAS 3
#define MAX_COLUMNAS 3
#define X 1
#define O 0
#define CASILLA_DE_X 1
#define CASILLA_DE_O 2
#define GANA_X 1
#define GANA_O 2
#define EMPATE 0
#define FIN_TURNOS 10
int main(){

    int i,j,k,turno,totalTurnos,repetirTurno,finJuego,empate;
    char volverJugar;
    int posicionFilaSeleccionada,posicionColumnaSeleccionada;
    int gato[MAX_FILAS][MAX_COLUMNAS];
    totalTurnos=1;
    setlocale(LC_ALL,"spanish");
    do{
        system("cls || clear");
        for (i=0;i<MAX_FILAS;i++){
            for (j=0;j<MAX_COLUMNAS;j++){
                gato[i][j]=0;
            }
        }
        finJuego=0;
        empate=1;
        do{
            printf(TITULO);
            for (k=0;k<MAX_FILAS;k++){
                printf(" ");
                switch(gato[k][0]){
                    case 0:
                        printf(" ");
                    break;
                    case X:
                        printf("X");
                    break;
                    default:
                        printf("O");
                    break;
                }

                printf(" | ");
                switch(gato[k][1]){
                    case 0:
                        printf(" ");
                    break;
                    case X:
                        printf("X");
                    break;
                    default:
                        printf("O");
                    break;
                }

                printf(" | ");
                switch(gato[k][2]){

                    case 0:
                        printf(" ");
                    break;
                    case X:
                        printf("X ");
                    break;
                    default:
                        printf("O ");
                    break;
                }

                printf("\n");
                if (k>=0 && k<MAX_FILAS-1){
                    printf("___________\n");
                }
            }

                repetirTurno=0;
                turno=totalTurnos%2;
                switch (turno){
                    case X:
                        do{
                            printf("Es turno del jugador X\n");
                            printf("Dime la fila(1  a 3): ");
                            scanf("%d",&posicionFilaSeleccionada);
                            --posicionFilaSeleccionada;
                            printf("Dime la columna(1 a 3): ");
                            scanf("%d",&posicionColumnaSeleccionada);
                            --posicionColumnaSeleccionada;
                            if ((gato[posicionFilaSeleccionada][posicionColumnaSeleccionada])==0){
                                gato[posicionFilaSeleccionada][posicionColumnaSeleccionada]=CASILLA_DE_X;
                                repetirTurno=0;
                            }
                            else {
                                printf("Esa casilla esta ocupada, elije otra\n\n");
                                repetirTurno=1;
                            }
                        }
                    while(repetirTurno==1);
                break;
                    default:
                        do{
                            printf("Es turno del jugador O\n");
                            printf("Dime la fila(1 a 3): ");
                            scanf("%d",&posicionFilaSeleccionada);
                            --posicionFilaSeleccionada;
                            printf("Dime la columna(1 a 3)");
                            scanf("%d",&posicionColumnaSeleccionada);
                            --posicionColumnaSeleccionada;
                            if ((gato[posicionFilaSeleccionada][posicionColumnaSeleccionada])==0){
                                gato[posicionFilaSeleccionada][posicionColumnaSeleccionada]=CASILLA_DE_O;
                                repetirTurno=0;
                            }
                            else {
                                printf("Esa casilla esta ocupada, elije otra\n");
                                repetirTurno=1;
                            }
                        }
                    while(repetirTurno==1);
                }
            if(gato[1][0]==1 && gato[1][1]==1 && gato[1][2]==1){
                finJuego=GANA_X;
            }
            else if(gato[2][1]==1 && gato[2][2]==1 && gato[2][0]==1){
                finJuego=GANA_X;
            }
            else if (gato[2][1]==1 && gato[1][1]==1 && gato[0][1]==1){
                finJuego=GANA_X;
            }

            else if(gato[0][0]==1 && gato[1][0]==1 && gato[2][0]==1){
                finJuego=GANA_X;
                }
            else if(gato[0][0]==1 && gato[1][1]==1 && gato[2][2]==1){
                finJuego=GANA_X;
            }
            else if(gato[0][2]==1 && gato[1][2]==1 && gato[2][2]==1){
                finJuego=GANA_X;
            }
            else if(gato[0][2]==1 && gato[1][1]==1 && gato[0][0]==1){
                finJuego=GANA_X;
            }
            else if(gato[0][2]==1 && gato[0][0]==1 && gato[0][1]==1){
                finJuego=GANA_X;
            }
            else if(gato[1][0]==2 && gato[1][1]==2 && gato[1][2]==2){
                finJuego=GANA_O;
            }
            else if(gato[2][1]==2 && gato[2][2]==2 && gato[2][0]==2){
                finJuego=GANA_O;
            }
            else if (gato[2][1]==2 && gato[1][1]==2 && gato[0][1]==2){
                finJuego=GANA_O;
            }

            else if(gato[0][0]==2 && gato[1][0]==2 && gato[2][0]==2){
                finJuego=GANA_O;
            }
            else if (gato[0][0]==2 && gato[1][1]==2 && gato[2][2]==2){
                finJuego=GANA_O;
            }
            else if(gato[0][2]==2 && gato[1][2]==2 && gato[2][2]==2){
                finJuego=GANA_O;
            }
            else if(gato[0][2]==2 && gato[1][1]==2 && gato[2][0]==2){
                finJuego=GANA_O;
            }
            else if(gato[0][2]==2 && gato[0][0]==2 && gato[0][1]==2){
                finJuego=GANA_O;
             }
             else{
                finJuego=EMPATE;
             }
            if(finJuego!=0){
                empate=FIN_TURNOS;
            }
            empate++;
            totalTurnos++;
            system("cls||clear");
        }
        while (empate<=FIN_TURNOS);

        system("cls||clear");
        for (k=0;k<MAX_FILAS;k++){
                printf(" ");
                switch(gato[k][0]){
                    case 0:
                        printf(" ");
                    break;
                    case X:
                        printf("X");
                    break;
                    default:
                        printf("O");
                    break;
                }

                printf(" | ");
                switch(gato[k][1]){
                    case 0:
                        printf(" ");
                    break;
                    case X:
                        printf("X");
                    break;
                    default:
                        printf("O");
                    break;
                }

                printf(" | ");
                switch(gato[k][2]){

                    case 0:
                        printf(" ");
                    break;
                    case X:
                        printf("X ");
                    break;
                    default:
                        printf("O ");
                    break;
                }

                printf("\n");
                if (k>=0 && k<MAX_FILAS-1){
                    printf("___________\n");
                }
            }

        if (finJuego==EMPATE){
            printf("Empete...\n");
        }
        else {
            if (finJuego==1){
                printf("El ganador es el jugador X\n");
            }
            else{
                printf("El ganador es el jugador O\n");
            }
        }
        getchar();
        printf("¿Quieres volver a jugar (S = si ó N = no)?");
        scanf("%c",&volverJugar);
    }
    while (volverJugar=='S'|| volverJugar=='s');
    return 0;
}
