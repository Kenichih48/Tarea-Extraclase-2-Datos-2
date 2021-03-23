#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <unistd.h>

using namespace std;

class IObserver{
    public:
        virtual void update(const string &msg) = 0;
};

class Subject{
    private:
        list<shared_ptr<IObserver>> listaObservadores;

        int minimaCantidad = 10;

        int totalCant;

        void notificar(){
            for(auto obs = listaObservadores.begin(); obs != listaObservadores.end(); obs++){
                (*obs) -> update("EL NIVEL ES MENOR A LA CANTIDAD MINIMA ASIGANDA");
            }
        }

    public:
        void agregarLista(shared_ptr<IObserver> observador){
            listaObservadores.push_back(observador);
        }
        void quitarLista(shared_ptr<IObserver> observador){
            listaObservadores.remove(observador);
        }
        void setTotal(int valor){
            totalCant = valor;
        }
        void setPuntoAccion(int valor){
            minimaCantidad = valor;
        }
        void bajarCantidad(){
            for(totalCant; totalCant > 0; totalCant-=1){
                //system("cls");
                cout << "Tiempo: " << totalCant << endl;
                if(totalCant == minimaCantidad){
                    notificar();
                }
                sleep(1);
            }
        }
};
class Mostrar : public IObserver{
    private:
        string __class__;
    public:
        Mostrar(){
            __class__ = __func__;
        }

        void update(const string &message) override{
            cout << "---" << message << "---" << endl;
        } 
};

void iniciar(int valTota, int parada){
    unique_ptr<Subject> subject = make_unique<Subject>(); // we got subject to register all the listeners
    shared_ptr<IObserver> display = make_shared<Mostrar>();

    subject -> agregarLista(display);
    subject ->setTotal(valTota);
    subject ->setPuntoAccion(parada);
    subject ->bajarCantidad();
}

int main(){
    while(true){
        int opcion;
        cout <<"\n";
        cout << "Seleccione una opcion: \n" << "1. OBSERVER\n" << "2. ADAPTER\n" << "3. Salir\n" << "opcion: ";
        cin >> opcion;
        cout << "\n";

        switch(opcion){
            case 1:
                int valTot;
                int valParada;
                cout << "Se tendra un temporizador en cual usted decidira el tiempo y un punto en el cual el observer enviara un mensaje...\n";
                sleep(2);
                cout << "Por favor ingrese el valor para el temporizador en segundos: ";
                cin >> valTot;
                cout << "s\n";
                cout << "Por favor ingrese el valor en cual se espera que el observer envie un mensaje. Se enviara a los: ";
                cin >> valParada;
                cout << "s\n";
                cout << "---Iniciando Temporizador---\n";
                iniciar(valTot, valParada);
                break;

            case 2:
                cout << "Hola xd\n";
                break;

            case 3:
                exit(1);

            default:
                cout << "Por favor seleccione una opcion valida\n";
                break;

        }
    }
    return 0;
}