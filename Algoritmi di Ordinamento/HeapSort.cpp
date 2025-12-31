#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class T>
class Heap {
    private:
        //Array che rappresenta l'heap
        T *array;
        //Dimensione dell'heap (<= della dimesione dell'array)
        int heapSize;

        //Funzione che ritorna l'indice del nodo parent
        int parent(int i) { 
            /* L'indice del nodo Parent si ottiene facendo floor(i/2), o alternativamente, si può eseguire 
             * in maniera più efficiente facendo lo shift di 1 a destra della rappresentazione binaria di i
             */
            // return i/2
            return (i >> 1);
        }

        //Metodo che ritorna l'indice del nodo figlio sinistro (Left)
        int left(int i) {
            /* L'indice del nodo Left si ottiene facendo 2*i, o alternativamente in maniera più efficiente
             * facendo lo shift di 1 a sinistra della rappresentazione binaria di i
             */
           // return 2*i
           return (i << 1);
        }

        // Metodo che ritorna l'indice del nodo figlio destro (Right)
        int right(int i) {
            /* L'indice del nodo Right si ottiene facendo 2*i + 1, o alternativamente in maniera più efficiente
             * facendo lo shift di 1 a sinistra ed aggiungendo 1 come bit meno significativo
             */
            // return (2*i + 1)
            return ((i << 1) | 1);
        }
    
    public:
        //Costruttore
        Heap() {
            this->heapSize = 0;
        }

        // Metodo che mantiene la proprietà del max heap
        void maxHeapify(int i) {
            int max = i;
            int l = left(i);
            int r = right(i);

            if(l <= heapSize && array[l] > array[max])
                max = l;
            
            if(r <= heapSize && array[r] > array[max])
                max = r;
            
            if(max != i) {

                swap(array[i], array[max]);
                maxHeapify(max);
            }
        }

        void minHeapify(int i) {
            int min = i;
            int l = left(i);
            int r = right(i);

            if(l <= heapSize && array[l] < array[min])
                min = l;
            
            if(r <= heapSize && array[r] < array[min])
                min = r;
            
            if(min != i) {

                swap(array[i], array[min]);
                minHeapify(min);
            }
        }

        void buildMaxHeap(T *A, int n) {
            heapSize = n;
            array = A;

            for(int i = heapSize / 2; i > 0; i--) {
                maxHeapify(i);
            }
        }
        void buildMinHeap(T *A, int n) {
            heapSize = n;
            array = A;

            for(int i = heapSize / 2; i > 0; i--) {
                minHeapify(i);
            }
        }

        void print() {
            for(int i = 1; i <= heapSize; i++) {
                cout << array[i] << "\t";
            }
            cout << endl;
        }
          
};

int main() {
    cout << "Quanti elementi deve avere l'array?" << endl;
    int n = 0;
    cin >> n;

    srand(time(0));

    int *A = new int[n];
    for(int i = 0; i <= n; i++) {
        A[i] = rand() % 100;
    }

    cout << "Array originale" << endl;
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    Heap<int> *heap = new Heap<int>();

    cout << "Trasformazione in Max Heap" << endl;
    heap->buildMaxHeap(A, n);
    heap->print();

    cout << "Trasformazione in Min Heap" << endl;
    heap->buildMinHeap(A, n);
    heap->print();


    delete heap;
    delete[] A;
}