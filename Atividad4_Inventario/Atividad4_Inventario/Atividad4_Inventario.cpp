#include <iostream> //Permite entrada y salida de datos (cin, cout)
#include <string>    //Permite el uso de cadenas de texto (string)
#include <stdexcept> //Necesario para usar excepciones (runtime_error)
#include <algorithm> //Provee la función swap (útil para intercambiar valores)

using namespace std;

//Definimos el tamaño máximo que tendrá nuestro inventario
const int MAX_PRODUCTOS = 50;

//Definimos la estructura producto
struct Producto {
    int id;          //Identificador único
    string nombre;   //Nombre del producto
    float precio;    //Precio con decimales
    int cantidad;    //Stock disponible
};


int main()
{
    std::cout << "Hello World!\n";



    return 0;
}
