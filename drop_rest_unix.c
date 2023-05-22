#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int uid, euid;
    int priv_uid;

    uid = getuid();
    euid = geteuid();

    priv_uid = euid; /*nell'ipotesi che il binario sia SETUID root*/

    printf("Prima dell'abbassamento dei privilegi : RUID del processo = %d\n", uid);
    printf("Prima dell'abbassamento dei privilegi : EUID del processo = %d\n", euid);

    if(setuid(uid) == -1){
            printf("Non sono riuscito ad abbassare i privilegi. \n");
            exit(1);
    }

    uid = getuid();
    euid = geteuid();
    printf("Dopo l'abbassamento dei privilegi : RUID del processo = %d\n", uid);
    printf("Dopo l'abbassamento dei privilegi : EUID del processo = %d\n", euid);

    exit(0);
}