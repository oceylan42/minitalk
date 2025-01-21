#include <stdio.h>
#include <Windows.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_LENGHT 1024

static char g_string[MAX_LENGHT]; // Veriyi tutacağımız buffer

// Gelen sinyali işlemek için signal handler
void handle_signal(int sig)
{
    int index = 0; // Stringin hangi indekse geldiğini takip eder

    if(sig == SIGUSR1)
    { 
        g_string[index++] = '1'; // 1 bitlik bir  veri alındı
    }      
    else if(sig == SIGUSR2)
    {
        g_string[index++] = '0'; // 0 bitlik bir veri alındı
    }

    if(g_string[index - 1] == '\0' || index >= MAX_LENGHT)
    {
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), g_string, strlen(g_string), NULL, NULL);
        index = 0;

    }
}

int main()
{
    pid_t pid = getpid();

}