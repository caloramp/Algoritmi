#include <iostream>

using namespace std;

int potenza(int a, int n) {
    if(n == 0) return 1; //Caso base
    else return (a * potenza(a, n - 1)); //Divisione e riunificazione
}

int main() {
    cout << "Inserisci la base: ";
    int a;
    cin >> a;

    cout << "Inserisci l'esponente: ";
    int n;
    cin >> n;

    cout << potenza(a, n) << endl;
}