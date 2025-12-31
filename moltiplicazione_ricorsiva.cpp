#include <iostream>

using namespace std;

int moltiplicazione(int a, int b) {
    if(b == 0) return 0;
    else return a + moltiplicazione(a, b - 1);
}

int main() {
    cout << "Inserisci i due numeri da moltiplicare" << endl;
    int a;
    cin >> a;
    int b;
    cin >> b;

    cout << moltiplicazione(a, b) << endl;
}