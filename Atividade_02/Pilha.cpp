#include <iostream>
using namespace std;

class Pilha
{
    private:
        int tam = 0;
        int* p;
    public:
        Pilha(int tamanho) {
            p = new int[tamanho];
            tam = 0;
        }

        ~Pilha() {
            delete[] p; 
            cout << "Pilha destruída com sucesso!";
            cout << endl;
        }

        void verificaCapacidade(int num) {  
            int novaCapacidade = num == 1 ? tam + 1 : tam - 1;
            int *aux = new int[novaCapacidade];
                
            for(int i = 0; i < novaCapacidade; i++)
                aux[i] = p[i];

            delete[] p;
            p = aux;
        }   

        void add(int elemento) {
            verificaCapacidade(1);
            p[tam++] = elemento;
        }

        void remove() {
            verificaCapacidade(0);
            p[tam--] = 0;
        }

        void imprimir() {
            for(int i = tam-1; i >= 0; i--)
               cout << p[i] << " ";
            cout << endl; 
        }
};

int main()
{
    Pilha *p = new Pilha(1);

    p->add(1);
    p->add(2);
    p->add(3);
    p->add(4);
    p->add(5);
    p->add(6);

    p->imprimir();

    p->remove();
    p->remove();
    p->remove();
    p->remove();
    p->remove();
    p->remove();

    p->imprimir();

    p->~Pilha();

    return 0;
}
