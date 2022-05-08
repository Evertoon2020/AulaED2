#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "projetoP1.h"

#define MIN 1
#define MAX 1000000
#define RUN 2

int main(){

    int opcao, QTDE;
    opcao = menu();
    QTDE = submenu();
    calculandoTempo10Tentativas(opcao, QTDE);
    calculandoTempoVetorOrdenado(opcao, QTDE);
    calculandoTempoVetorDesordenado(opcao, QTDE);
    return 0;
}
