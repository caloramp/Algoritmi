#include <iostream>

using namespace std;

bool supera(int A[], int n, int T) {
    if(T < 0) return true;
    if(n == 0) return false;

    return supera(A, n - 1, T - A[n - 1]);
}

int main() {
    int A[5] = {3, 7, 2, 9, 4};

    cout << "Inserisci un numero: ";
    int T;
    cin >> T;
    
    if(supera(A, 5, T)) 
        cout << "Soglia superata" << endl;
    else
        cout << "Soglia non superata" << endl;
}