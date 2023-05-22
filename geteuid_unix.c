#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int euid = geteuid();

    printf("EUID del processo = %d\n", euid);
    exit(0);
}

/*
* Questo codice serve a mostrare come si recupera il EUID del processo invocante tramite la chiamata geteuid().
*/