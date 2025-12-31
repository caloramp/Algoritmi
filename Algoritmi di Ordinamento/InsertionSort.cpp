//Inserion Sort è un algoritmo efficiente per ordinare un piccolo numero di elementi

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(int A[], int n) { //Prende come parametro un array A e la sua dimensione n
    for(int j = 1; j < n+1; j++) {
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] > key) { //Sposta l'elemento i a destra finché non è maggiore di key (A[j])
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

int main() {
    int A[10];
    srand(time(0));

    cout << "Generazione array con numeri pseudocasuali compresi tra 0 e 1000" << endl;
    for(int i = 0; i < 10; i++) {
        A[i] = rand() % 1000;
    }

    
    cout << "Array originale generato randomicamente" << endl;
    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array ordinato con Insertion Sort" << endl;

    insertionSort(A, 10);

    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}