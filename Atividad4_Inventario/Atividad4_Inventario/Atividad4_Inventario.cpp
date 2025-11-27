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


//Compara los datos que es estan a los lados del pivote. Para ordenar por el metodo de burbuja
void ordenarPorPrecio(Producto inventario[], int cantidadActual) {
    for (int i = 0; i < cantidadActual - 1; i++) {
        for (int j = 0; j < cantidadActual - i - 1; j++) {
            // Si el precio actual es mayor al siguiente, los intercambia
            if (inventario[j].precio > inventario[j + 1].precio) {
                Producto temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
}

//Esta funcion ordena por seleccion, busca el menor y lo mueve al inicio
void ordenarPorCantidad(Producto inventario[], int cantidadActual) {
    for (int i = 0; i < cantidadActual - 1; i++) {
        int minIdx = i; // Asumimos que el actual es el menor
        // Buscamos si hay alguien menor en el resto de la lista
        for (int j = i + 1; j < cantidadActual; j++) {
            if (inventario[j].cantidad < inventario[minIdx].cantidad) {
                minIdx = j; // Guardamos la posición del nuevo menor
            }
        }
        // Hacemos el intercambio (swap)
        Producto temp = inventario[minIdx];
        inventario[minIdx] = inventario[i];
        inventario[i] = temp;
    }
}

//Funcion para modificar los datos utilizando punteros
void modificarStock(Producto* prod, int nuevaCantidad) {
    // 'prod' es una dirección de memoria.
    // El operador flecha se usa para acceder a los campos desde un puntero.
    // Esto modifica directamente el dato original en memoria.
    prod->cantidad = nuevaCantidad;
    cout << "Stock actualizado correctamente para el producto: " << prod->nombre << endl;
}

//Funcion para mostrar el inventario
void mostrarInventario(Producto inventario[], int cantidadActual) {
    cout << "\n--- LISTA DE PRODUCTOS ---\n";
    cout << "ID\tNombre\t\tPrecio\t\tCant.\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < cantidadActual; i++) {
        // Imprime usando tabuladores (\t) para separar columnas
        cout << inventario[i].id << "\t"
            << inventario[i].nombre << "\t\t$"
            << inventario[i].precio << "\t\t"
            << inventario[i].cantidad << endl;
    }
    cout << "------------------------------------------------\n";
}