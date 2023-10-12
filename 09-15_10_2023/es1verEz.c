#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <float.h>
#include <string.h>
#include <time.h>

// Per separare nel terminale
#define LINE_SPLITTER puts("\n-------------")
#define CLEAR_CONSOLE system("clear") == 1 ? system("cls") : system("clear")
/*
    Group components:
    > Nicholas Magi <nicholas.magi@studio.unibo.it>;
    > Tommaso Maestri <tommaso.maestri@studio.unibo.it>;
    > Leonardo Perretta <leonardo.perretta2@studio.unibo.it>;
    > Riccardo Ventrucci <riccardo.ventrucci@studio.unibo.it>;
*/

struct Coordinate{
    int latitudine;
    int longitudine;
};

struct Continente{
    char nome[100];
    struct Coordinate confineAltoSinistro;
    struct Coordinate confineBassoDestro;
};

bool ControlloGiusto(struct Continente cont, struct Coordinate coor){
    if(cont.confineBassoDestro.latitudine<coor.latitudine&&cont.confineAltoSinistro.latitudine>coor.latitudine){
        if(cont.confineAltoSinistro.longitudine<coor.longitudine&&cont.confineBassoDestro.longitudine>coor.longitudine)
            return true;
    }
    
    return false;
}

void Dormi(int tempo){
    sleep(tempo);
    CLEAR_CONSOLE;
}

bool Controllo(char risp[7], struct Continente cont, struct Coordinate daIndovinare){
    if(strcmp(risp, cont.nome)==0){
                if(ControlloGiusto(cont, daIndovinare)){
                    printf("Hai indovinato!!!");
                    return true;
                }
    }
    return false;
}

int main(){

    // continenti modello ONU quindi 5
    struct Continente america;
    strcpy(america.nome, "America");
    america.confineAltoSinistro.latitudine = 100;
    america.confineAltoSinistro.longitudine = 0;
    america.confineBassoDestro.latitudine = 0;
    america.confineBassoDestro.longitudine = 50;
    struct Continente europa;
    strcpy(europa.nome, "Europa");
    europa.confineAltoSinistro.latitudine = 100;
    europa.confineAltoSinistro.longitudine = 51;
    europa.confineBassoDestro.latitudine = 0;
    europa.confineBassoDestro.longitudine = 100;
    struct Continente africa;
    strcpy(africa.nome, "Africa");
    africa.confineAltoSinistro.latitudine = 100;
    africa.confineAltoSinistro.longitudine = 101;
    africa.confineBassoDestro.latitudine = 0;
    africa.confineBassoDestro.longitudine = 150;
    struct Continente asia;
    strcpy(asia.nome, "Asia");
    asia.confineAltoSinistro.latitudine = 100;
    asia.confineAltoSinistro.longitudine = 151;
    asia.confineBassoDestro.latitudine = 0;
    asia.confineBassoDestro.longitudine = 200;
    struct Continente oceania;
    strcpy(oceania.nome, "Oceania");
    oceania.confineAltoSinistro.latitudine = 100;
    oceania.confineAltoSinistro.longitudine = 201;
    oceania.confineBassoDestro.latitudine = 0;
    oceania.confineBassoDestro.longitudine = 250;

    srand(time(0));
    while(true){
        printf("In 3 secondi ti verranno mostrate le coordinate, indovina in quale dei 5 continenti è");
        Dormi(1000);
        printf("3"); Dormi(1000);
        printf("2"); Dormi(1000);
        printf("1"); Dormi(500);
        printf("VIA!!!"); Dormi(300);

        struct Coordinate daIndovinare;
        daIndovinare.latitudine= rand()%100+1;
        daIndovinare.longitudine=rand()%100*2.5+1;
        printf("La latidine è: %d \nLa longitudine è:%d", daIndovinare.latitudine, daIndovinare.longitudine);
        Dormi(5000);
        printf("Indovina il continente (quando hai finito di scrivere il continente premi ctrl+Z/D): ");
        char contRisp[7];
        int numCar=0;
        while(getchar()!=EOF){
            numCar++;
        }
        scanf("%s", contRisp);
        if(numCar>7){
            if(Controllo(contRisp, america, daIndovinare))
                break;
            if(Controllo(contRisp, europa, daIndovinare))
                break;
            if(Controllo(contRisp, africa, daIndovinare))
                break;
            if(Controllo(contRisp, asia, daIndovinare))
                break;
            if(Controllo(contRisp, oceania, daIndovinare))
                break;
            printf("\nHai sbagliato :( \nRiprova con delle coordinate nuove");
        }
        Dormi(1);
    }

    return 0;
}