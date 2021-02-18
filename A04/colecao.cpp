#include <iostream>
using namespace std;

class Colecao 
{  
    protected:
        int *v; 
        int tam;

        Colecao(int tamanho){
            v = new int[tamanho];
            tam = 0;
        }

        ~Colecao(){
            delete[] v; 
        }

        void verificaCapacidade(int num){ 
                int novaCapacidade = num == 1 ? tam * 2 : tam - 1;
                int *aux = new int[novaCapacidade];
                
                for(int i = 0; i < novaCapacidade; i++)
                    aux[i] = v[i];

                delete[] v;
                v = aux;
        }   

    public:
        virtual int tamanho(){ return tam; };
        virtual void add(int elemento) = 0; 
        virtual void remove() = 0; 
        virtual void imprimir(){
            for(int i = 0; i < tam; i++)
                    cout << v[i] << " ";
                cout << endl;
        }
};

class Pilha: public Colecao
{
    public:
        Pilha(int tamanho):Colecao(tamanho){
            cout << "Estou construindo um objeto pilha {tamanho = " << tamanho << "}\n";
        }

        Pilha() : Pilha(0) {}

        void add(int elemento){
            verificaCapacidade(1);
            v[tam++] = elemento;
        }

        void remove(){
            verificaCapacidade(0);
            v[tam--] = 0;
        }

        void imprimir()override{
            for(int i = tam-1; i >= 0; i--)
               cout << v[i] << " ";
            cout << endl; 
        }

};

class Fila: public Colecao
{
    public:
        Fila(int tamanho):Colecao(tamanho){
            cout << "Estou construindo um objeto fila {tamanho = " << tamanho << "}\n";
        }

        Fila() : Fila(0) {}

        void add(int elemento){
            verificaCapacidade(1);
            v[tam++] = elemento;
        }

        void remove(){
            verificaCapacidade(0);
            for(int i = 0; i < tam; i++)
                v[i] = v[i+1];
            tam--;
        }
};

class Lista: public Colecao
{
    public:
        Lista(int tamanho):Colecao(tamanho){
            cout << "Estou construindo um objeto lista {tamanho = " << tamanho << "}\n";
        }
                            
        Lista() : Lista(0) {} 

        void add(int elemento){
            verificaCapacidade(1);
            v[tam++] = elemento;
        }

        void remove(){
            verificaCapacidade(0);
            v[tam--] = 0;
        }

        void addPosicao(int elemento, int pos){
            verificaCapacidade(1); 
            int* aux = new int[tam];

            if(pos == 0){ //inìcio
                for(int i = 0; i <= tam; i++)
                    aux[i] = v[i];
                for(int i = 0; i <= tam; i++)
                    v[i+1] = aux[i];
                v[pos] = elemento;
            }

            else if(tam-1 == pos || tam == pos) //fim
                v[tam] = elemento;

            else{ //meio
                for(int i = pos; i < tam; i++) 
                    aux[i] = v[i];
                for(int i = pos; i < tam; i++)
                    v[i+1] = aux[i];
                v[pos] = elemento;
            }
            delete[] aux;

            tam++;
        }

        void removePosicao(int pos){
            verificaCapacidade(0);
            if(tam <= 0) return;
            if(pos == 0){ //início
                for(int i = 0; i < tam; i++)
                    v[i] = v[i+1];
            } 
            else{ //meio
                for(int i = pos; i < tam; i++)
                    v[pos] = v[pos+1];
            }
            tam--;
        }       
};


int main()
{
    //Pilha
    Pilha* p = new Pilha(5);
    p->add(1);
    p->add(2);
    p->add(3);

    cout << "Tamanho: " << p->tamanho() << endl;

    p->imprimir();

    p->remove();
    p->remove();
    p->remove();

    p->imprimir();


    //Lista
    Lista* l = new Lista(5);
    l->add(2); 
    l->add(3); 
    l->add(4); 
    l->addPosicao(1,0);
    l->addPosicao(5,4);

    cout << "Tamanho: " << l->tamanho() << endl;

    l->imprimir();
    
    l->removePosicao(0);
    l->removePosicao(2);
    l->removePosicao(1);
    l->remove();
    l->remove();

    l->imprimir();

    //Fila
    Fila* f = new Fila(5);
    f->add(1);
    f->add(2);
    f->add(3);

    cout << "Tamanho: " << f->tamanho() << endl;

    f->imprimir();

    f->remove();
    f->remove();
    f->remove();

    f->imprimir();

    return 0;
}
