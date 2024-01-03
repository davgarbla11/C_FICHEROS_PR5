#include <stdio.h>
#define TAM 50

int lecturaFichero(char nombreFicheroEntrada[TAM], int vInte[TAM]);
void calculoFrecuencias(int vInte[TAM], int tam, int vFrec[TAM]);
void imprimirResultado(int vFrec[10], char nombreFicheroSalida[TAM]);


int main() {    

    char nombreFicheroEntrada[TAM] = "entrada.txt";
    char nombreFicheroSalida[TAM] = "salida.txt";
    int vInte[TAM];
    int vFrec[10];
    int tam = 0;

    tam = lecturaFichero(nombreFicheroEntrada, vInte);

    calculoFrecuencias(vInte, tam, vFrec);

    return 0;
}

int lecturaFichero(char nombreFicheroEntrada[TAM], int vInte[TAM]) {

    FILE * f;
    int cont = 0;
    f = fopen(nombreFicheroEntrada, "r");

    if (f = NULL) {

        printf("No se ha podido abrir correctamente el fichero.");

    } else {

        fscanf(f, "%d", &vInte[cont]);
        cont++;
        while(!feof(f)) {

            fscanf(f, "%d", &vInte[cont]);
            cont++;

        }

        fclose(f);
    }

    return cont;

}

void calculoFrecuencia(int vInte[TAM], int tam, int vFrec[10]){
    int i, n;
    
    for (n=1; n<11; n++) {

        for (i = 0; i<tam; i++) {

            if(vInte[i] == n) {

                vFrec[n-1]=vFrec[n-1]+1;
            }

        }

    }

}

void imprimirResultado(int vFrec[10], char nombreFicheroSalida[TAM]) {

    int cont = 0;

    FILE * f;
    f = fopen(nombreFicheroSalida, "w");

    if (f == NULL ) {

        printf("No se ha podido abrir el fichero correctamente.\n");

    } else {

        for(cont = 0; cont < 10; cont++) {

            fprintf(f, "%d - %d\n", cont+1, vFrec[cont]);
        
        }

        fclose(f);
    }


}