#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// My files
#include "/home/turi/Projects/terminal/include/terminal.h" 
#include "terminal.c"

int main(int argc, char *argv[]) {

// Variablen
    const char *path = ".";  // Standardmäßig aktuelles Verzeichnis
    char input[256];
    char commands[256];
    bool terminalIsRunning = true;

    while(terminalIsRunning){
    printf(">>> ");
    scanf("%s", input);

    if (strcmp(input, "ls") == 0) {     
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
    } else if (strcmp(input, "cd") == 0) {
        char new_path [256];
        scanf("%s", new_path);
        change_directory(new_path);
    }
    else 
    {
        printf("turish: unbekannter command (%s)\n", input);
    }
 }
    return 0;
}

// TODO
// >>> idk
