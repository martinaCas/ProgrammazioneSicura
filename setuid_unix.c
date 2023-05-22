#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int uid = getuid();
    int euid = geteuid();

    printf( "Prima di elevazione a root : RUID del processo = %d\n", uid);
    printf( "Prima di elevazione a root : EUID del processo = %d\n", euid);

    if(setuid(0) == -1){
            printf( "Non sono riuscito ad impostare EUID = 0 (root) .\n");
            exit(1);
    }

    uid = getuid();
    euid = geteuid();
    printf( "Dopo di elevazione a root : RUID del processo = %d\n", uid);
    printf( "Dopo di elevazione a root : EUID del processo = %d\n", euid);
    exit(0);
}