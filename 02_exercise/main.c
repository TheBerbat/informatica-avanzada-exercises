#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>

int main()
{
    FILE *fptr;
    char line[500];
    char *dni;
    char path_dni[500];
    struct stat st = {0};
    
    fptr = fopen("./file.txt", "r");
    if (fptr == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    if (stat("estudiantes", &st) == -1)
        mkdir("estudiantes", 0700);

    while(fgets(line, sizeof(line), fptr) != NULL)
    {
        dni = strtok(line, " ");
        if (dni)
        {
            sprintf(path_dni, "estudiantes/%s", dni);
            
            if ( mkdir(path_dni, S_IRWXU) < 0)
                printf("Error creating folder. Errno %d\n", errno);
        }
    }
    
    fclose(fptr);
    return 0;
}