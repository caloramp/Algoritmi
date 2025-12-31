#include <iostream>

using namespace std;

int fattoriale(int n) {
    if(n == 0)
        return 1;
    else
        return n * fattoriale(n-1);
}

int main() {
    int n;

    cout << "Inserisci un numero: ";
    cin >> n;

    cout << fattoriale(n) << endl;
}