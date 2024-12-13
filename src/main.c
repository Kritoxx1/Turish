#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// My files
#include "/home/turi/Projects/terminal/include/terminal.h" 
#include "terminal.c"

int main(int argc, char *argv[]) {

/* --------------------------------------------
 *
 *              VARIABLEN
 *
 * --------------------------------------------
 * */

    const char *path = ".";  // Standardmäßig aktuelles Verzeichnis
    char input[256];
    char commands[256] = "ls"; 
    bool terminalIsRunning = true;

    while(terminalIsRunning){
    printf(">>> ");
    scanf("%s", input);

    if (strcmp(input, commands) == 0) {     
        if (argc > 1) {
            path = argv[1]; // Wenn ein Pfad angegeben ist, dann diesen Verwenden.
        }

     list_directory(path);
    } 
    else if (strcmp(input, "exit") == 0) 
    {
        terminalIsRunning = false;
    } 
    else if (strcmp(input, "clear") == 0) 
    {
        clear_screen();
    } 
    else if (input == 0) 
    {
        printf(">>> ");         
    } 
    else 
    {
        printf("turish: unbekannter command (""%s"")\n", input);
    }
 }
    return 0;
}
