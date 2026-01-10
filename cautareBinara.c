#include <stdio.h>
#include <string.h>

int cautare_binara(int v[], int n, int cautat) {
    int st = 0, dr = n-1;

    while (st <= dr) {
       int mij = (st + dr)/2;

        if (v[mij] == cautat)
            return mij;
        else if (v[mij] < cautat)
            st = mij + 1;
        else
            dr = mij - 1;
    }
    return -1;
}

void BBl(int s[], int n){

    int temp;
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (s[j]> s[j+1]) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main() {

    int numere[100];
    int numar_elm;
    int de_cautat;

    printf("Cate numere va ajea sirul?: ");
    scanf("%d", &numar_elm);

    printf("Scrieți cele %d numere:\n", numar_elm);
    for (int i = 0; i < numar_elm; i++) {
        printf("numere[%d] = ", i);
        scanf("%d", &numere[i]);
    }
    BBl(numere, numar_elm);

    printf("sirul sortat: ");
    for (int i = 0; i < numar_elm; i++) {
        printf("%d ", numere[i]);
    }
    printf("\n");


    printf("scrie un numar de cautat: ");
    scanf("%d", &de_cautat);

        int pozitie = cautare_binara(numere, numar_elm, de_cautat);

        if (pozitie != -1){
            printf("\nNumarul %d a fost gasit la indexul %d.\n", de_cautat, pozitie);
        } else {
            printf("\nNumarul %d nu exista in vector.\n", de_cautat);
        }

        return 0;

}