#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void merge(int A[], int left, int mid, int right) {
    //Calcolo delle dimensioni dei due vettori L e R
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];
    
    //Copio la prima parte di A in L
    for(int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }

    //Copio la seconda parte di A in R
    for(int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    //Confronto valore per valore gli elementi dei due array e li inserisco in A in ordine
    while (i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
    }

    // Se L ha ancora elementi, li copio
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Se R ha ancora elementi, li copio
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    //Pulizia della memoria allocata dinamicamente
    delete[] L;
    delete[] R;
}

void mergeSort(int A[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, right);
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

    cout << "Array ordinato con Merge Sort" << endl;

    mergeSort(A, 0, 9);

    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}