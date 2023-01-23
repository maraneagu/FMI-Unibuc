#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
    // AL DOILEA ARGUMENT - DE UNDE CITIM
    char* fromFile = argv[1];
    
    // AL TREILEA ARGUMENT - UNDE SCRIEM
    char* toFile = argv[2];

   	// LAB 2 - 1.2
    // DESCHIDEM FISIERUL DE UNDE CITIM
    int ff = open(fromFile, O_RDONLY, S_IRWXU);
    
    // DESCHIDEM FISIERUL UNDE SCRIEM
    int tf = open(toFile, O_CREAT | O_WRONLY, S_IRWXU);

    // VOM CITI DIN FISIERUL DE INTRARE BLOCURI DE DIMENSIUNE DMAX
    int dmax = 1024;
    char* c = malloc(sizeof(char) * dmax);

    int r,w;
    // CAT TIMP MAI PUTEM CITI DIN FISIER
    while((r = read(ff, c, dmax)) > 0){
        int written = 0;
        
        // CAT TIMP NU AM CITIT UN BLOC DE DIMENSIUNE DMAX
        while((w = write(tf, c+written, dmax-written)) > 0)
            written += w;
    }

   // INCHIDEM FISIERELE DESCHISE
    close(ff);
    close(tf);
    return 0;
}