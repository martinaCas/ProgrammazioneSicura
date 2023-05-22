#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int uid = getuid();

    printf("RUID del processo = %d\n", uid);
    exit(0);
}

/*
*Questo codice serve a mostrare come si recupera il RUID del processo invocante tramite la chiamata getuid().
*Comandi da terminale: 
    gcc -o getuid_unix getuid_unix.c
    ./getuid_unix

    *** RUID del processo = 1000, quindi ora si esegue una seconda volta ma come root grazie al comando sudo

    sudo ./getuid_unix

    *** RUID del processo = 0
*/