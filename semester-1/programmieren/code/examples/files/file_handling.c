#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("test.txt", "r");
    char text[81];

    if (!file)
        printf("Scheise, isch konnt' die Dadei ned öffne");

    fgets(text, 80, file); // Vorlesen

    while (!feof(file))
    {
        printf("%s", text);    // processing
        fgets(text, 80, file); // Nachlesen
    }
    fclose(file);
}