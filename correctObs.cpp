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
class Adapter{ //converts the given int into a workable string
    public: 
        string conjunction;
        int current_digit;
        string wordify(int num){
            conjunction = "";
            if (num != 0){
                bool first = true;
                while (num > 0){
                    current_digit = num%10;
                    switch(current_digit){
                        case 1:
                            conjunction = "one" + conjunction;
                            break;
                        case 2: 
                            conjunction = "two" + conjunction;
                            break;
                        case 3:
                            conjunction = "three" + conjunction;
                            break;
                        case 4:
                            conjunction = "four" + conjunction;
                            break;
                        case 5:
                            conjunction = "five" + conjunction;
                            break;
                        case 6:
                            conjunction = "six" + conjunction;
                            break;
                        case 7:
                            conjunction = "seven" + conjunction;
                            break;
                        case 8:
                            conjunction = "eight" + conjunction;
                            break;
                        case 9:
                            conjunction = "nine" + conjunction;
                            break;
                        case 0:
                            conjunction = "zero" + conjunction;
                            break;
                    }
                    if ((num/10)>0){
                        conjunction = "," + conjunction;
                    }
                    num /= 10;
                } 
            }
            else{
                conjunction += "zero";
            }
            conjunction += "!";
            return conjunction;
        }
        
};

class Word_Maker{ //converts list into three-seven-four
    public:
        int i = 0;
        string new_string;
        string generate_id(string num){
            new_string = "[";
            const std::string s(num);
            while (s[i] != '!'){
                if (s[i] == ','){
                    new_string += "-";
                }
                else{
                    new_string += s[i];
                }
                i += 1;
            }
            new_string += "]";
            i = 0;
            cout<<new_string<<endl;
            return new_string;
        }
};

void iniciar(int valTota, int parada){
    if (valTota != 0 && parada!= 0){
        unique_ptr<Subject> subject = make_unique<Subject>(); // we got subject to register all the listeners
        shared_ptr<IObserver> display = make_shared<Mostrar>();

        subject -> agregarLista(display);
        subject ->setTotal(valTota);
        subject ->setPuntoAccion(parada);
        subject ->bajarCantidad();
    }
    else{
        cout << "Tanto el valor del temporizador como el del observer deben ser mayores a cero...\n" << "Intente de nuevo..." << endl;
        sleep(2); 
    }
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
                cout << "Por favor ingrese el valor en cual se espera que el observer envie un mensaje. Se enviara a los: ";
                cin >> valParada;
                cout << "---Iniciando Temporizador---\n";
                iniciar(valTot, valParada);
                break;

            case 2:
                {
                Adapter adapter;
                Word_Maker new_id;
                int id;
                string miString;
                cout << "Por favor ingrese su numero de carné: ";
                cin >> id;
                miString = adapter.wordify(id);
                cout << "Ahora su carné sera generado en palabras...\n";
                sleep(2);
                new_id.generate_id(miString);
                cout << "\n";
                break;
                }

            case 3:
                exit(1);

            default:
                cout << "Por favor seleccione una opcion valida\n";
                break;

        }
    }
    return 0;
}