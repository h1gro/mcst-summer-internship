#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include "my_signal.h"

int main()
{
    struct matrix_t matrix = {};

    MatrixCtor(&matrix);

    // Устанавливаем обработчик для SIGINT
//     if (signal(SIGINT, sigint_handler) == SIG_ERR) {
//         perror("Ошибка signal()");
//         return 1;
//     }
//
//     while (1) {
//         printf("Работаю...\n");
//         sleep(1);
//     }
    return 0;
}

void sigint_handler(int sig)
{
    printf("Перехвачен SIGINT (Ctrl+C)\n");
    _exit(0);
}
