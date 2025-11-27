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

//Declaramos las funciones aquí arriba para que el 'main' sepa que existen
//antes de que sean implementadas al final del archivo.
void cargarDatosEjemplo(Producto inventario[], int& cantidadActual);
void registrarProducto(Producto inventario[], int& cantidadActual);
void mostrarInventario(Producto inventario[], int cantidadActual);
int buscarPorID(Producto inventario[], int cantidadActual, int idBuscado);
void ordenarPorPrecio(Producto inventario[], int cantidadActual);
void ordenarPorCantidad(Producto inventario[], int cantidadActual);
void modificarStock(Producto* prod, int nuevaCantidad); // Recibe un puntero


//Inica la funcion principal
int main()
{   
    Producto inventario[MAX_PRODUCTOS]; //Se crea el arreglo que almacenará los productos
    int cantidadActual = 0; //Contador para saber cuántos espacios del arreglo están ocupados
    int opcion;

    // Llamamos a esta función para llenar el arreglo con 10 productos iniciales
    cargarDatosEjemplo(inventario, cantidadActual);


    return 0;
}



void cargarDatosEjemplo(Producto inventario[], int& cantidadActual) {
    //Llena manualmente las primeras 10 posiciones del arreglo
    inventario[0] = { 101, "Laptop", 12000, 5 };
    inventario[1] = { 102, "Mouse", 250.00, 20 };
    inventario[2] = { 103, "Teclado", 500.00, 15 };
    inventario[3] = { 104, "Monitor", 4500.00, 8 };
    inventario[4] = { 105, "USB", 150.00, 50 };
    inventario[5] = { 106, "HDMI", 100.00, 30 };
    inventario[6] = { 107, "Tablet", 8000.00, 12 };
    inventario[7] = { 108, "Libreta", 350.00, 25 };
    inventario[8] = { 109, "Webcam", 950.00, 10 };
    inventario[9] = { 110, "Silla", 3500.00, 4 };
    cantidadActual = 10; //Actualiza el contador
}

void registrarProducto(Producto inventario[], int& cantidadActual) {
    if (cantidadActual >= MAX_PRODUCTOS) {
        cout << "Inventario lleno.\n";
        return;
    }
    Producto p;
    cout << "Ingrese ID: "; cin >> p.id;
    cout << "Ingrese Nombre: "; cin.ignore(); getline(cin, p.nombre);
    cout << "Ingrese Precio: "; cin >> p.precio;
    cout << "Ingrese Cantidad: "; cin >> p.cantidad;

    // Guarda el nuevo producto en la siguiente posición libre
    inventario[cantidadActual] = p;
    cantidadActual++; // Aumenta el contador de productos
    cout << "Producto registrado con exito.\n";
}

//Esta funcion busca por Id y lanza y una excepcio si falla
int buscarPorID(Producto inventario[], int cantidadActual, int idBuscado) {
    for (int i = 0; i < cantidadActual; i++) {
        if (inventario[i].id == idBuscado) {
            return i; // Retorna la posición índice donde lo encontró
        }
    }
    // Si termina el ciclo for sin éxito, lanza el error manualmente
    throw runtime_error("El ID proporcionado no existe en el inventario.");
}