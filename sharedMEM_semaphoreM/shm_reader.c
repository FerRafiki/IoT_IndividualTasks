#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "common.h"

int main() {
    char *buff;
    int shm_id = shmget(SHM_KEY, 0, 0);
    if (shm_id == -1) exit(-1);

    buff = shmat(shm_id, NULL, 0);

    int sem_id = semget(SEM_KEY, 1, 0);
    if (sem_id == -1) exit(-1);

    struct sembuf sem_wait = {0, -1, 0};  // Espera semáforo

    while (1) {
        semop(sem_id, &sem_wait, 1);  // Espera notificación del writer
        printf("Reader recibió: %s\n", buff);
    }

    shmdt(buff);
    return 0;
}
