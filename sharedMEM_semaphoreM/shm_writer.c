#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include "common.h"

#define MAX_LEN 80

int main() {
    char *buff;
    int shm_id = shmget(SHM_KEY, 4096, IPC_CREAT | 0666);
    if (shm_id == -1) exit(-1);

    buff = shmat(shm_id, NULL, 0);

    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) exit(-1);

    struct sembuf sem_signal = {0, 1, 0};  // Incrementa semáforo

    while (1) {
        printf("Escribe mensaje: ");
        fgets(buff, MAX_LEN, stdin);

        // Notifica al reader que hay nuevo contenido
        semop(sem_id, &sem_signal, 1);
    }

    shmdt(buff);
    return 0;
}
