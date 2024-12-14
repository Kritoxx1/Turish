// Hier sind die Terminal funktionen

void list_directory (const char *path) { // Lists the files where the user currently is.
    DIR *dir = opendir(path); // öffnet Verzeichnis
    if (dir == NULL) {
        perror("opendir");    // Fehlerbehebung, falls das Verzeichnis nicht geöffnet wird.
        exit(EXIT_FAILURE);
    }

    struct dirent *entry; // struct für Verzeichniseinträge

    while ((entry = readdir(dir)) != NULL) { // Einträge lesen
        printf("%s\n", entry->d_name); // Name des Eintrags wird ausgegeben.
    }

    closedir(dir); // Verzeichnis wird geschlossen.
}

void change_directory (const char *path) { // Changes to a other directory
    if (strcmp(path, "~") == 0) { // Überprüft ob der Benutzer "~" eingibt.
        const char *home = getenv("HOME");
        if (home == NULL) {
            printf("Error: HOME environment variable not set.\n");
            return;
        }
        path = home; // Setzt den Pfad auf das Home-Vereichnis
    }    
    if (chdir(path) == 0) {
        printf("changed to diretory: %s\n", path);
    } else {
        printf("Error changing to directory %s\n", path, strerror(errno));
    }
}

void clear_screen () {
    system("clear");
}


