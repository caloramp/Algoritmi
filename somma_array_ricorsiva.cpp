#include <iostream>

using namespace std;

int sommaIterativa(int A[], int n) {
    int somma = 0;
    for(int i = 0; i < n; i++) {
        somma += A[i];
    }
    return somma;
}

int sommaRicorsiva(int A[], int n) {
    if(n == 1) return A[0];
    else return (A[n-1] + sommaRicorsiva(A, n-1));
}

int sommaDivisa(int A[], int inizio, int fine) {
    if(inizio == fine) 
        return A[inizio]; 
    int medio = (inizio + fine) / 2;
    int sinistra = sommaDivisa(A, inizio, medio);
    int destra = sommaDivisa(A, medio + 1, fine);
    return sinistra + destra;
}

int main() {
    int A[5] = {3, 7, 2, 9, 4};

    cout << "Somma iterativa = " << sommaIterativa(A, 5) << endl;

    cout << "Somma ricorsiva = " << sommaRicorsiva(A, 5) << endl;

    cout << "Somma divisa = " << sommaDivisa(A, 0, 4) << endl;
}