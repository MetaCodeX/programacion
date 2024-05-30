#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits> // Para limpiar el buffer de entrada

using namespace std;

class Mercancia {
private:
    int idProducto;
    float costoProducto;
    string nombreProducto;

public:
    void visualizarMercancias() {
    ifstream archivo("mercancia.txt");

    if (archivo.is_open()) {
        cout << "\n--- LISTA DE MERCANCIAS ---\n";
        cout << "ID\tCosto\tNombre\n";
        cout << "-----------------------------\n";

        Mercancia m;
        while (archivo >> m.idProducto >> m.costoProducto) {
            getline(archivo, m.nombreProducto); // Leer el nombre (puede tener espacios)
            cout << m.idProducto << "\t" << m.costoProducto << "\t" << m.nombreProducto << endl;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de mercancías.\n";
    }
}
    void agregarMercancia() {
    ofstream archivo("mercancia.txt", ios::app); // Abrir en modo append

    if (archivo.is_open()) {
        cout << "Ingrese ID del producto: ";
        while (!(cin >> idProducto)) {
            cout << "Entrada invalida. Ingrese un numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese costo del producto: ";
        while (!(cin >> costoProducto)) {
            cout << "Entrada invalida. Ingrese un numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese nombre del producto: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, nombreProducto); // Leer nombre con espacios

        archivo << idProducto << " " << costoProducto << " " << nombreProducto << endl;
        archivo.close();
        cout << "Mercancia agregada exitosamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

    void modificarMercancia(int id) {
        ifstream archivoLectura("mercancia.txt");
        ofstream archivoEscritura("mercancia_temp.txt");

        if (archivoLectura.is_open() && archivoEscritura.is_open()) {
            Mercancia m;
            bool encontrado = false;
            while (archivoLectura >> m.idProducto >> m.costoProducto) {
                getline(archivoLectura, m.nombreProducto);
                if (m.idProducto == id) {
                    cout << "Ingrese nuevo costo del producto: ";
                    while (!(cin >> m.costoProducto)) {
                        cout << "Entrada invalida. Ingrese un numero: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cout << "Ingrese nuevo nombre del producto: ";
                    cin.ignore();
                    getline(cin, m.nombreProducto);
                    encontrado = true;
                }
                archivoEscritura << m.idProducto << " " << m.costoProducto << " " << m.nombreProducto << endl;
            }

            archivoLectura.close();
            archivoEscritura.close();

            if (encontrado) {
                remove("mercancia.txt");
                rename("mercancia_temp.txt", "mercancia.txt");
                cout << "Mercancia modificada exitosamente.\n";
            } else {
                cout << "Mercancia no encontrada.\n";
                remove("mercancia_temp.txt");
            }
        } else {
            cout << "Error al abrir el archivo.\n";
        }
    }

    void eliminarMercancia(int id) {
        ifstream archivoLectura("mercancia.txt");
        ofstream archivoEscritura("mercancia_temp.txt");

        if (archivoLectura.is_open() && archivoEscritura.is_open()) {
            Mercancia m;
            bool encontrado = false;
            while (archivoLectura >> m.idProducto >> m.costoProducto) {
                getline(archivoLectura, m.nombreProducto);
                if (m.idProducto != id) {
                    archivoEscritura << m.idProducto << " " << m.costoProducto << " " << m.nombreProducto << endl;
                } else {
                    encontrado = true;
                }
            }

            archivoLectura.close();
            archivoEscritura.close();

            if (encontrado) {
                remove("mercancia.txt");
                rename("mercancia_temp.txt", "mercancia.txt");
                cout << "Mercancia eliminada exitosamente.\n";
            } else {
                cout << "Mercancia no encontrada.\n";
                remove("mercancia_temp.txt");
            }
        } else {
            cout << "Error al abrir el archivo.\n";
        }
    }
};

int main() {
    int opcion;
    Mercancia mercancia; // Objeto para trabajar con mercancías

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Mercancias\n";
        cout << "2. Proveedores\n";
        cout << "3. Ofertas\n";
        cout << "4. Ventas\n";
        cout << "5. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: // Mercancías
                int subOpcion;
                do {
                    cout << "\n--- MERCANCIAS ---\n";
                    cout << "1. Agregar mercancia\n";
                    cout << "2. Modificar mercancia\n";
                     cout << "3. Eliminar mercancia\n";
                    cout << "4. Visualizar mercancías\n"; // Opción agregada
                    cout << "5. Volver al menu principal\n";
                    cout << "Ingrese su opcion: ";
                    cin >> subOpcion;

                    switch (subOpcion) {
                        case 1:
                            mercancia.agregarMercancia();
                            break;
                        case 2:
                            int idModificar;
                            cout << "Ingrese el ID de la mercancia a modificar: ";
                            cin >> idModificar;
                            mercancia.modificarMercancia(idModificar);
                            break;
                        case 3:
                            int idEliminar;
                            cout << "Ingrese el ID de la mercancia a eliminar: ";
                            cin >> idEliminar;
                            mercancia.eliminarMercancia(idEliminar);
                            break;
                        case 4:
                            mercancia.visualizarMercancias(); // Llamar al método
                            break;
                        case 5:
                            break; // Volver al menú principal
                        default:
                            cout << "Opcion invalida.\n";
                    }
                } while (subOpcion != 4);
                break;

            case 2: // Proveedores
                // ... (Agregar opciones para proveedores)
                break;
            case 3: // Ofertas
                // ... (Agregar opciones para ofertas)
                break;
            case 4: // Ventas
                // ... (Agregar opciones para ventas)
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);

    return 0;
}
