#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**problemi con open e O_RDONLY*/

int main(int argc, char *argv[]){

    uid_t uid = getuid();
    uid_t euid = geteuid();


    printf( "Prima di setreuid(euid, uid) : RUID del processo = %d\n", uid);
    printf( "Prima di setreuid(euid, uid) : EUID del processo = %d\n", euid);

    if(setreuid(euid, uid) == -1){
            printf( "Non sono riuscito a scambiare UID <--> EUID .\n");
            exit(1);
    }

    uid = getuid();
    euid = geteuid();

    printf( "Dopo setreuid(euid, uid)  : RUID del processo = %d\n", uid);
    printf( "Dopo setreuid(euid, uid)  : EUID del processo = %d\n", euid);

    if(open("/etc/shadow", O_RDONLY) == -1)
    printf("Non sono riuscito ad aprire /etc/shadow.\n");
    else
    printf("Sono riuscito ad aprire /etc/shadow.\n");

    if(setreuid(euid, uid) == -1){
        printf( "Non sono riuscito a scambiare UID <--> EUID .\n");
            exit(1);
    }

    uid = getuid();
    euid= geteuid();

    printf( "Dopo setreuid(euid, uid)  : RUID del processo = %d\n", uid);
    printf( "Dopo setreuid(euid, uid)  : EUID del processo = %d\n", euid);

    exit(0);
}