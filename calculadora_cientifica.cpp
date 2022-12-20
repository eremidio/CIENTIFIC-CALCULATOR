/* Vamos escrever um app que implementa uma calculadora científica em C++
Compilar este programa com o comando: g++ -o calculadora_cientifica calculadora_cientifica.cpp `pkg-config gtkmm-3.0 --cflags --libs` 
*/

/*CABEÇALHO*/
#include<gtkmm/application.h>
#include"calculadora_cientifica_metodos.h"
using namespace std;
using namespace Glib;
using namespace Gtk;

int main(int argc, char* argv[]){
//Ponteiro smart
RefPtr<Application> app=Application::create(argc, argv);
//Instanciando a classe do app
calculator calculadora_cientifica;
calculadora_cientifica.property_resizable();	
calculadora_cientifica.set_default_size(800, 400);
//Rodando o app
return app->run(calculadora_cientifica);
}
