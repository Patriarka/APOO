#include <iostream>
using namespace std;

class Fila 
{
    private:
        int tam;
        int* v;
    public:
        Fila(int tamanho) {
            v = new int[tamanho];
            tam = 0;
        }

        ~Fila() {
            delete[] v; 
            cout << "Fila destruída com sucesso!";
            cout << endl;
        }

        void verificaCapacidade(int num) {  
            int novaCapacidade = num == 1 ? tam + 1 : tam - 1;
            int *aux = new int[novaCapacidade];
                
            for(int i = 0; i < novaCapacidade; i++)
                aux[i] = v[i];

            delete[] v;
            v = aux;
        }   

        void add(int elemento) {
            verificaCapacidade(1);
            v[tam++] = elemento;
        }

        void remove() {
            verificaCapacidade(0);
            for(int i = 0; i < tam; i++)
                v[i] = v[i+1];
            tam--;
        }

        void imprimir() {
            for(int i = 0; i < tam; i++)
                    cout << v[i] << " ";
                cout << endl;
        }
};

int main()
{
    Fila *f = new Fila(1);
    
    f->add(1);
    f->add(2);
    f->add(3);
    f->add(4);
    f->add(5);
    f->add(6);

    f->imprimir();

    f->remove();
    f->remove();
    f->remove();
    f->remove();
    f->remove();
    f->remove();

    f->imprimir();

    f->~Fila();

    return 0;
}

