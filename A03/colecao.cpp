#include <iostream>
using namespace std;

class Colecao
{
    protected:
        int* v;
        int tam;

    public:
        void verificaCapacidade(int num) {  
            int novaCapacidade = num == 1 ? tam + 1 : tam - 1;
            int *aux = new int[novaCapacidade];
                
            for(int i = 0; i < novaCapacidade; i++)
                aux[i] = v[i];

            delete[] v;
            v = aux;
        }   

        int tamanho() {
            return this->tam;
        }
};

class Fila: public Colecao
{
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

class Lista: public Colecao
{
    public:
        Lista(int tamanho) {
            v = new int[tamanho];
            tam = 0;
        }

        ~Lista() {
            delete[] v; 
            cout << "lista destruída com sucesso!";
            cout << endl;
        }
        
        void add(int elemento) {
            verificaCapacidade(1);
            addPosicao(elemento, tam);
        }

        void remove() {
            verificaCapacidade(0);
            removePosicao(0);
        }

        void addPosicao(int elemento, int pos) {
            verificaCapacidade(1); 
            int* aux = new int[tam];

            if(pos == 0){ 
                for(int i = 0; i <= tam; i++)
                    aux[i] = v[i];
                for(int i = 0; i <= tam; i++)
                    v[i+1] = aux[i];
                v[pos] = elemento;
            }

            else if(tam-1 == pos || tam == pos)
                v[tam] = elemento;

            else{ 
                for(int i = pos; i < tam; i++) 
                    aux[i] = v[i];
                for(int i = pos; i < tam; i++)
                    v[i+1] = aux[i];
                v[pos] = elemento;
            }
            delete[] aux;

            tam++;
        }

        void removePosicao(int pos) {
            verificaCapacidade(0);
            if(tam <= 0) return;
            if(pos == 0) { 
                for(int i = 0; i < tam; i++)
                    v[i] = v[i+1];
            } 
            else { 
                for(int i = pos; i < tam; i++)
                    v[pos] = v[pos+1];
            }
            tam--;
        }     

        void imprimir() {
            for(int i = 0; i < tam; i++)
                    cout << v[i] << " ";
                cout << endl;
        }  
};

class Pilha: public Colecao
{
    public:
        Pilha(int tamanho) {
            v = new int[tamanho];
            tam = 0;
        }

        ~Pilha() {
            delete[] v; 
            cout << "Pilha destruída com sucesso!";
            cout << endl;
        }


        void add(int elemento) {
            verificaCapacidade(1);
            v[tam++] = elemento;
        }

        void remove() {
            verificaCapacidade(0);
            v[tam--] = 0;
        }

        void imprimir() {
            for(int i = tam-1; i >= 0; i--)
               cout << v[i] << " ";
            cout << endl; 
        }
};

int main()
{
    Lista* l = new Lista(1);
    Pilha* p = new Pilha(1);
    Fila* f = new Fila(1);

    p->add(1);
    p->add(2);
    p->add(3);
    p->add(4);
    p->add(5);
    p->add(6);

    p->imprimir();

    cout << "Tamanho da Pilha: ";
    cout << p->tamanho() << endl;

    p->remove();
    p->remove();
    p->remove();
    p->remove();
    p->remove();
    p->remove();

    p->imprimir();

    p->~Pilha();

    l->add(1);
    l->add(2);
    l->add(3);
    l->add(4);
    l->add(5);
    l->add(6);

    l->imprimir();

    l->remove();
    l->remove();
    l->remove();
    l->remove();
    l->remove();
    l->remove();

    l->imprimir();

    l->addPosicao(1, 0);
    l->addPosicao(2, 1);
    l->addPosicao(3, 2);
    l->addPosicao(4, 3);
    l->addPosicao(5, 4);
    l->addPosicao(6, 5);

    l->imprimir();

    cout << "Tamanho da Lista: ";
    cout << l->tamanho() << endl;

    l->removePosicao(0);
    l->removePosicao(1);
    l->removePosicao(2);
    l->removePosicao(3);
    l->removePosicao(4);
    l->removePosicao(5);

    l->~Lista();

    f->add(1);
    f->add(2);
    f->add(3);
    f->add(4);
    f->add(5);
    f->add(6);

    f->imprimir();

    cout << "Tamanho da Fila: ";
    cout << f->tamanho() << endl;

    f->remove();
    f->remove();
    f->remove();
    f->remove();
    f->remove();
    f->remove();

    f->imprimir();

    f->~Fila();

    cout << "Tamanho da Lista: ";
    cout << l->tamanho() << endl;

    cout << "Tamanho da Pilha: ";
    cout << p->tamanho() << endl;

    cout << "Tamanho da Fila: ";
    cout << f->tamanho() << endl;

    return 0;
}