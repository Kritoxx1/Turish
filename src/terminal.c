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

void change_directory () { // Changes to a other directory

}

void clear_screen () {
    system("clear");
}


