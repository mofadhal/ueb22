#include <stdio.h>
#include <stdlib.h>

struct mtz {
    int z;
    int s;
    int *matr;
};
typedef struct mtz mtz_t;

//------------------
void clearr() { while ((getchar()) != '\n'); }

//--------------------------------------------
void setZeile(mtz_t *t, unsigned int x) {

    t->z = x;
    printf("Zeile :	%d\n", t->z);

}

//------------------------------------------
void setSpalte(mtz_t *t, unsigned int y) {
    t->s = y;
    printf("Spalte : %d\n", t->s);
}

//-----------------------------------
int getZeile() {
    int x;
    printf("Geben Sie bitte der Anzahl der Zeilen\n");
    if (scanf("%d", &x) != 1 || x <= 0) {
        printf("\n\n	*** Die Eingabe soll ein Zahl groesser 0 sein ***	\n\n\n");
        while ((getchar()) != '\n');
        x = getZeile();
    }
    return x;
}

//--------------------------------
int getSpalte() {
    int x;
    printf("Geben Sie bitte der Anzahl der Spalten\n");
    if (scanf("%d", &x) != 1 || x <= 0) {
        printf("\n\n	*** Die Eingabe soll ein Zahl groesser 0 sein ***	\n\n\n");
        while ((getchar()) != '\n');
        x = getSpalte();
    }
    return x;
}

//---------------------------------
void createArr(mtz_t *t) {
    t->matr = malloc(sizeof(int) * (t->s * t->z));
}

//-----------------------------
int getElement() {
    int x;
//printf("Geben Sie bitte der Anzahl der Zeilen\n");
    if (scanf("%d", &x) != 1) {
        printf("\n\n	*** Die Eingabe soll ein Zahl sein ***	\n\n\n");
        while ((getchar()) != '\n');
        x = getElement();
    }
    return x;
}

//---------------------------------------------
void fillArr(mtz_t *t) {

    for (int i = 0; i < t->s; i++) {
        printf("Beginnen Sie mit der Eingabe von Elemente der %d te  Zeile\n", i + 1);
        for (int j = 0; j < t->z; j++) {
            printf("Geben Sie bitte das Element an der %d te Spalte der %d te  Zeile\n", j + 1, i + 1);
            t->matr[(i * t->z) + j] = getElement();
            clearr();
            //printf(" %d  \n",t->matr[(i * t->z) + j ]  );
        }
    }
}

//-----------------------------
void printArr(mtz_t *t) {
    printf("	---------	\n");
    printf("Die Matrize sieht so aus\n	---------	\n");
    for (int i = 0; i < t->s; i++) {
        printf("| ");
        for (int j = 0; j < t->z; j++) {
            printf("%d ", t->matr[(i * t->z) + j]);
        }
        printf("|\n");
    }
    printf("	---------	\n");
}

//---------------------------------
int getSpaltenindex(mtz_t *t) {
    int x;
    if (scanf("%d", &x) != 1 || x <= 0 || x > t->s) {
        printf("\n\n	*** Die Eingabe soll ein Zahl zwischen 1 und  %i sein ***	\n\n\n", t->s);
        while ((getchar()) != '\n');
        x = getSpaltenindex(t);
    }
    return x;
}

//--------------------------------
void agII(mtz_t *t) {
    int index;
    printf("Geben Sie bitte der Spaltenindex, um Maximum in der Spalte zu finden \n");
    index = getSpaltenindex(t);
    clearr();
    index -= 1;
    int max = t->matr[index];
    for (int i = 0; i < t->s; i++) {
        if (max < (t->matr[i * (t->z) + index])) { max = t->matr[i * (t->z) + index]; }
    }
    printf("Der groesste Zahl in der %d te Spalte is : %d\n", index + 1, max);
}

//--------------------------
int getZeilenindex(mtz_t *t) {
    int x;
    if (scanf("%d", &x) != 1 || x <= 0 || x > t->s) {
        printf("\n\n	*** Die Eingabe soll ein Zahl zwischen 1 und  %i sein ***	\n\n\n", t->s);
        while ((getchar()) != '\n');
        x = getZeilenindex(t);
    }
    return x;
}

//---------------------------
void agIII(mtz_t *t) {
    int index;
    printf("Geben Sie bitte der Zeilenindex, um Maximum in der Zeile zu finden: \n");
    index = getZeilenindex(t);
    clearr();
    index -= 1;
    int max = t->matr[index * (t->z) + 0];
    for (int i = 0; i < t->s; i++) {
        if (max < (t->matr[index * (t->z) + i])) { max = t->matr[index * (t->z) + i]; }
    }
    printf("Der groesste Zahl in der %d te Zeile ist : %d\n", index + 1, max);
}

//------------------------
int getIndex(mtz_t *t) {
    int x;
    if (scanf("%d", &x) != 1 || x <= 0 || x > t->s) {
        printf("\n\n	*** Die Eingabe soll ein Zahl zwischen 1 und  %i sein ***	\n\n\n", t->s);
        while ((getchar()) != '\n');
        x = getIndex(t);
    }
    return x;
}

//--------------------------
void swap(int *x, int *y) {
    int xx = *x;
    *x = *y;
    *y = xx;

}

//--------------------
void swapZeilen(mtz_t *t) {
    if (t->z <= 1) { printf("Die Matrize hat nur eine Zeile, daher bleibt sie unberuehrt\n"); }
    else {
        printf("Geben Sie bitte beide Zeilen, die vertaucht werden\n");
        printf("Die Zeile : ");
        int x = getIndex(t);
        clearr();
        printf("\nUnd die Zeile : \n");
        int y = getIndex(t);
        clearr();
        for (int i = 0; i < t->z; i++) {
            swap(&t->matr[(x - 1) * (t->z) + i], &t->matr[(y - 1) * (t->z) + i]);
        }
    }
}

//--------------------------
void auswahl_opration() {
    printf("\nWaehlen Sie eine OptionsNummer :\n0) Exit\n1) Max Zahl einer Spalte\n"
           "2) Max Zahl einer Zeile\n3) zwei Zeilen vertauchen\n4) Neue Matrize uebergeben\n5) Aktueller Matrix\n");
}

int opp() {
    int x;
    if (scanf("%d", &x) != 1 || x < 0 || x > 5) {
        printf("\n\n	*** Die Eingabe soll ein Zahl zwischen 0 und  5 sein ***	\n\n\n");
        auswahl_opration();
        while ((getchar()) != '\n');
        x = opp();
    }
    return x;
}

//---------------------------------
int main(int argc, char **argv) {
    mtz_t t;
    int x = getZeile();
    clearr();
    setZeile(&t, x);
    int y = getSpalte();
    setSpalte(&t, y);
    clearr();
    createArr(&t);
    fillArr(&t);
    printArr(&t);
    while (1 == 1) {
        auswahl_opration();
        int p = opp();
        switch (p) {
            case 0:
                printf("Ende Programm\n");
                exit(0);
            case 1:
                agII(&t);
                break;
            case 2:
                agIII(&t);
                break;
            case 3:
                swapZeilen(&t);
                printArr(&t);
                break;
            case 4:
                printf("Sie wollen eine neue Matrize eingeben\n");
                x = getZeile();
                clearr();
                setZeile(&t, x);
                y = getSpalte();
                clearr();
                setSpalte(&t, y);
                createArr(&t);
                fillArr(&t);
                printArr(&t);

                break;
            case 5:
                printArr(&t);
                break;
            default:
                break;

        }
    }
    return 0;
}






