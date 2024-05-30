#include<iostream>
#include<conio.h>
#include<windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



class Usuario {
public:
    int id;
    string nombreCompleto;
    string puesto;

    Usuario(int id, string nombreCompleto, string puesto) : id(id), nombreCompleto(nombreCompleto), puesto(puesto) {}
};

class Mercancia {
public:
    int id;
    string nombre;
    double precio;
    int idProveedor;        // ID del proveedor asociado
    vector<int> idsOfertas; // Vector de IDs de ofertas asociadas

    // Constructor
    Mercancia(int id, string nombre, double precio, int idProveedor = 0) :
        id(id), nombre(nombre), precio(precio), idProveedor(idProveedor) {}

    // Método para agregar una oferta asociada a la mercancía
    void agregarOferta(int idOferta) {
        idsOfertas.push_back(idOferta);
    }

    // Método para eliminar una oferta asociada a la mercancía
    void eliminarOferta(int idOferta) {
        for (auto it = idsOfertas.begin(); it != idsOfertas.end(); ++it) {
            if (*it == idOferta) {
                idsOfertas.erase(it);
                break;
            }
        }
    }

    // Método para mostrar la información de la mercancía (incluyendo proveedor y ofertas)
    void mostrarInformacion() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Precio: " << precio;
        if (idProveedor != 0) {
            cout << ", Proveedor ID: " << idProveedor;
        }
        if (!idsOfertas.empty()) {
            cout << ", Ofertas: ";
            for (int idOferta : idsOfertas) {
                cout << idOferta << " ";
            }
        }
        cout << endl;
    }
};

class Proveedor {
public:
    int id;
    string nombre;
    string contacto;

    // Constructor
    Proveedor(int id, string nombre, string contacto) :
        id(id), nombre(nombre), contacto(contacto) {}

    // Método para obtener los IDs de las mercancías asociadas al proveedor (a partir del archivo "mercancias.txt")
    vector<int> obtenerMercanciasAsociadas() const {
        vector<int> mercanciasAsociadas;
        ifstream archivo("mercancias.txt");
        int idMercancia, idProveedorLeido;
        string nombre, precio, idsOfertas;

        while (archivo >> idMercancia >> nombre >> precio >> idProveedorLeido >> idsOfertas) {
            if (idProveedorLeido == id) {
                mercanciasAsociadas.push_back(idMercancia);
            }
        }

        archivo.close();
        return mercanciasAsociadas;
    }

    // Método para mostrar la información del proveedor y las mercancías asociadas
    void mostrarInformacion() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Contacto: " << contacto << endl;

        vector<int> mercancias = obtenerMercanciasAsociadas();
        if (!mercancias.empty()) {
            cout << "Mercancias asociadas: ";
            for (int idMercancia : mercancias) {
                cout << idMercancia << " ";
            }
            cout << endl;
        } else {
            cout << "No hay mercancías asociadas a este proveedor." << endl;
        }
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm> // Para usar std::any_of

using namespace std;

class Oferta {
public:
    int id;
    string descripcion;
    double descuento;

    // Constructor
    Oferta(int id, string descripcion, double descuento) :
        id(id), descripcion(descripcion), descuento(descuento) {}

    // Método para obtener los IDs de las mercancías asociadas a la oferta
    vector<int> obtenerMercanciasAsociadas() const {
        vector<int> mercanciasAsociadas;
        ifstream archivo("mercancias.txt");
        int idMercancia, idProveedor;
        string nombre, precio, idsOfertasStr;

        while (archivo >> idMercancia >> nombre >> precio >> idProveedor >> idsOfertasStr) {
            // Convertir la cadena de IDs de ofertas a un vector
            vector<int> idsOfertasMercancia;
            size_t pos = 0;
            while ((pos = idsOfertasStr.find(",")) != string::npos) {
                idsOfertasMercancia.push_back(stoi(idsOfertasStr.substr(0, pos)));
                idsOfertasStr.erase(0, pos + 1);
            }
            if (!idsOfertasStr.empty()) {
                idsOfertasMercancia.push_back(stoi(idsOfertasStr));
            }

            // Verificar si la oferta actual está asociada a la mercancía (usando std::any_of)
            if (any_of(idsOfertasMercancia.begin(), idsOfertasMercancia.end(), [this](int idOferta) {
                    return idOferta == this->id;
                })) {
                mercanciasAsociadas.push_back(idMercancia);
            }
        }

        archivo.close();
        return mercanciasAsociadas;
    }

    // Método para mostrar la información de la oferta y las mercancías asociadas
    void mostrarInformacion() const {
        cout << "ID: " << id << ", Descripción: " << descripcion << ", Descuento: " << descuento << endl;

        vector<int> mercancias = obtenerMercanciasAsociadas();
        if (!mercancias.empty()) {
            cout << "Mercancias asociadas: ";
            for (int idMercancia : mercancias) {
                cout << idMercancia << " ";
            }
            cout << endl;
        } else {
            cout << "No hay mercancías asociadas a esta oferta." << endl;
        }
    }
};
class ModuloUsuarios {
public:
    void alta(Usuario usuario) {
        ofstream archivo("usuarios.txt", ios::app);
        archivo << usuario.id << " " << usuario.nombreCompleto << " " << usuario.puesto << "\n";
        archivo.close();
    }

    void baja(int id) {
        int idLeido;
        string nombreCompleto, puesto;
        ifstream archivo("usuarios.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> nombreCompleto >> puesto) {
            if (idLeido != id)
                temp << idLeido << " " << nombreCompleto << " " << puesto << "\n";
        }
        archivo.close();
        temp.close();
        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");
    }

    void cambio(int id, string nombreNuevo, string puestoNuevo) {
        int idLeido;
        string nombreCompleto, puesto;
        ifstream archivo("usuarios.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> nombreCompleto >> puesto) {
            if (idLeido == id)
                temp << id << " " << nombreNuevo << " " << puestoNuevo << "\n";
            else
                temp << idLeido << " " << nombreCompleto << " " << puesto << "\n";
        }
        archivo.close();
        temp.close();
        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");
    }

    void consulta() {
        int id;
        string nombreCompleto, puesto;
        ifstream archivo("usuarios.txt");
        cout << "Selecciona una opción:\n1. Consultar todos los usuarios\n2. Consultar por ID\n";
        string opcion;
        cin >> opcion;
        if (opcion == "1") {
            while (archivo >> id >> nombreCompleto >> puesto) {
                cout << "ID: " << id << ", Nombre completo: " << nombreCompleto << ", Puesto: " << puesto << "\n";
            }
        } else if (opcion == "2") {
            cout << "Introduce el ID del usuario a consultar: ";
            int idConsulta;
            cin >> idConsulta;
            while (archivo >> id >> nombreCompleto >> puesto) {
                if (id == idConsulta) {
                    cout << "ID: " << id << ", Nombre completo: " << nombreCompleto << ", Puesto: " << puesto << "\n";
                    break;
                }
            }
        } else {
            cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
        archivo.close();
    }
};

class ModuloAlmacen {
public:
    void altaMercancia(Mercancia mercancia) {
        ofstream archivo("mercancias.txt", ios::app);
        archivo << mercancia.id << " " << mercancia.nombre << " " << mercancia.precio << "\n";
        archivo.close();
    }

    void altaProveedor(Proveedor proveedor) {
        ofstream archivo("proveedores.txt", ios::app);
        archivo << proveedor.id << " " << proveedor.nombre << " " << proveedor.contacto << "\n";
        archivo.close();
    }

    void altaOferta(Oferta oferta) {
        ofstream archivo("ofertas.txt", ios::app);
        archivo << oferta.id << " " << oferta.descripcion << " " << oferta.descuento << "\n";
        archivo.close();
    }

    void bajaMercancia(int id) {
        int idLeido;
        string nombre;
        double precio;
        ifstream archivo("mercancias.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> nombre >> precio) {
            if (idLeido != id)
                temp << idLeido << " " << nombre << " " << precio << "\n";
        }
        archivo.close();
        temp.close();
        remove("mercancias.txt");
        rename("temp.txt", "mercancias.txt");
    }

    void bajaProveedor(int id) {
        int idLeido;
        string nombre, contacto;
        ifstream archivo("proveedores.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> nombre >> contacto) {
            if (idLeido != id)
                temp << idLeido << " " << nombre << " " << contacto << "\n";
        }
        archivo.close();
        temp.close();
        remove("proveedores.txt");
        rename("temp.txt", "proveedores.txt");
    }

    void bajaOferta(int id) {
        int idLeido;
        string descripcion;
        double descuento;
        ifstream archivo("ofertas.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> descripcion >> descuento) {
            if (idLeido != id)
                temp << idLeido << " " << descripcion << " " << descuento << "\n";
        }
        archivo.close();
        temp.close();
        remove("ofertas.txt");
        rename("temp.txt", "ofertas.txt");
    }

    void cambioMercancia(int id, string nombreNuevo, double precioNuevo) {
        int idLeido;
        string nombre;
        double precio;
        ifstream archivo("mercancias.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> nombre >> precio) {
            if (idLeido == id)
                temp << id << " " << nombreNuevo << " " << precioNuevo << "\n";
            else
                temp << idLeido << " " << nombre << " " << precio << "\n";
        }
        archivo.close();
        temp.close();
        remove("mercancias.txt");
        rename("temp.txt", "mercancias.txt");
    }

    void cambioProveedor(int id, string nombreNuevo, string contactoNuevo) {
        int idLeido;
        string nombre, contacto;
        ifstream archivo("proveedores.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> nombre >> contacto) {
            if (idLeido == id)
                temp << id << " " << nombreNuevo << " " << contactoNuevo << "\n";
            else
                temp << idLeido << " " << nombre << " " << contacto << "\n";
        }
        archivo.close();
        temp.close();
        remove("proveedores.txt");
        rename("temp.txt", "proveedores.txt");
    }

    void cambioOferta(int id, string descripcionNueva, double descuentoNuevo) {
        int idLeido;
        string descripcion;
        double descuento;
        ifstream archivo("ofertas.txt");
        ofstream temp("temp.txt");
        while (archivo >> idLeido >> descripcion >> descuento) {
            if (idLeido == id)
                temp << id << " " << descripcionNueva << " " << descuentoNuevo << "\n";
            else
                temp << idLeido << " " << descripcion << " " << descuento << "\n";
        }
        archivo.close();
        temp.close();
        remove("ofertas.txt");
        rename("temp.txt", "ofertas.txt");
    }

    void consultaMercancia() {
        int id;
        string nombre;
        double precio;
        ifstream archivo("mercancias.txt");
        cout << "Selecciona una opción:\n1. Consultar todas las mercancías\n2. Consultar por ID\n";
        string opcion;
        cin >> opcion;
        if (opcion == "1") {
            while (archivo >> id >> nombre >> precio) {
                cout << "ID: " << id << ", Nombre: " << nombre << ", Precio: " << precio << "\n";
            }
        } else if (opcion == "2") {
            cout << "Introduce el ID de la mercancía a consultar: ";
            int idConsulta;
            cin >> idConsulta;
            while (archivo >> id >> nombre >> precio) {
                if (id == idConsulta) {
                    cout << "ID: " << id << ", Nombre: " << nombre << ", Precio: " << precio << "\n";
                    break;
                }
            }
        } else {
            cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
        archivo.close();
    }

    void consultaProveedor() {
        int id;
        string nombre, contacto;
        ifstream archivo("proveedores.txt");
        cout << "Selecciona una opción:\n1. Consultar todos los proveedores\n2. Consultar por ID\n";
        string opcion;
        cin >> opcion;
        if (opcion == "1") {
            while (archivo >> id >> nombre >> contacto) {
                cout << "ID: " << id << ", Nombre: " << nombre << ", Contacto: " << contacto << "\n";
            }
        } else if (opcion == "2") {
            cout << "Introduce el ID del proveedor a consultar: ";
            int idConsulta;
            cin >> idConsulta;
            while (archivo >> id >> nombre >> contacto) {
                if (id == idConsulta) {
                    cout << "ID: " << id << ", Nombre: " << nombre << ", Contacto: " << contacto << "\n";
                    break;
                }
            }
        } else {
            cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
        archivo.close();
    }

    void consultaOferta() {
        int id;
        string descripcion;
        double descuento;
        ifstream archivo("ofertas.txt");
        cout << "Selecciona una opción:\n1. Consultar todas las ofertas\n2. Consultar por ID\n";
        string opcion;
        cin >> opcion;
        if (opcion == "1") {
            while (archivo >> id >> descripcion >> descuento) {
                cout << "ID: " << id << ", Descripción: " << descripcion << ", Descuento: " << descuento << "\n";
            }
        } else if (opcion == "2") {
            cout << "Introduce el ID de la oferta a consultar: ";
            int idConsulta;
            cin >> idConsulta;
            while (archivo >> id >> descripcion >> descuento) {
                if (id == idConsulta) {
                    cout << "ID: " << id << ", Descripción: " << descripcion << ", Descuento: " << descuento << "\n";
                    break;
                }
            }
        } else {
            cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
        archivo.close();
    }
};

void limpiarPantalla() {
    cout << "\033[2J\033[1;1H";
}

int main(){
	ModuloUsuarios moduloU;
	ModuloAlmacen moduloA;
    string opcion, nombreCompleto, puesto, nombre, contacto, descripcion;
	int inicio, i, manual, modulos, esc, id;
	double precio, descuento;

	cout<<"\t --BIENVENIDO A LA TERMINAL DE INICIO--"<<endl;
	do{
		cout<<"\t --ESCRIBA EL NUMERO DE LA ACCION A REALIZAR : --"<<endl;
		cout<<"\n1--DESCARGAR MANUAL DE USUARIO"<<endl<<"2--INICIAR SISTEMA"<<endl;
		cin>>inicio;
		system("cls");
		switch(inicio){
			case 1:
				system("cls");
				//AQUI IRIAN UNOS COMANDOS PARA QUE SE CREE UN MANUAL DE USUARIO EN UN ARCHIVO .txt
				break;
			case 2:
				system("cls");
				cout<<"\t INICIANDO SISTEMA";
				for(i=1;i<=3;i++){
					Sleep(500);
					if(i==3){
						cout<<" ."<<endl;
					}
					else{
						cout<<" .";
					}
				}
				system("cls");
				do{
					cout<<"\t --ESCRIBA EL NUMERO DEL MODULO A USAR : --"<<endl;
					cout<<"\n1--USUARIOS"<<endl<<"2--ALMACEN"<<endl<<"3--TIENDA"<<endl<<"4--REGRESAR AL INICIO"<<endl<<"5--APAGAR SISTEMA"<<endl;
					cin>>modulos;
					limpiarPantalla();
					switch(modulos){
						case 1:
							while (true) {
                                cout << "Selecciona una opcion:\n1. Alta\n2. Baja\n3. Cambio\n4. Consulta\n5. Regresar\n";
                                cin >> opcion;
                                limpiarPantalla();
                                if (opcion == "1") {
                                    cout << "Introduce el ID del usuario: ";
                                    cin >> id;
                                    cout << "Introduce el nombre completo del usuario: ";
                                    cin.ignore();
                                    getline(cin, nombreCompleto);
                                    cout << "Introduce el puesto del usuario: ";
                                    getline(cin, puesto);
                                    moduloU.alta(Usuario(id, nombreCompleto, puesto));
                                } else if (opcion == "2") {
                                    cout << "Introduce el ID del usuario para dar de baja: ";
                                    cin >> id;
                                    moduloU.baja(id);
                                } else if (opcion == "3") {
                                    cout << "Introduce el ID del usuario para cambiar: ";
                                    cin >> id;
                                    cout << "Introduce el nuevo nombre completo: ";
                                    cin.ignore();
                                    getline(cin, nombreCompleto);
                                    cout << "Introduce el nuevo puesto: ";
                                    getline(cin, puesto);
                                    moduloU.cambio(id, nombreCompleto, puesto);
                                } else if (opcion == "4") {
                                    moduloU.consulta();
                                } else if (opcion == "5") {
                                    esc=1;
                                    system("cls");
                                    break;
                                } else {
                                    cout << "Opcion no valida. Intentalo de nuevo.\n";
                                }
                                cout << "Presiona Enter para continuar...";
                                cin.ignore();
                                cin.get();
                                limpiarPantalla();
                            }
							break;
						case 2:
							while (true) {
                                cout << "Selecciona un modulo:\n1. Mercancias\n2. Proveedores\n3. Ofertas\n4. Regresar\n";
                                cin >> opcion;
                                limpiarPantalla();
                                if (opcion == "1") {
                                    cout << "Selecciona una opcion:\n1. Alta\n2. Baja\n3. Cambio\n4. Consulta\n";
                                    cin >> opcion;
                                    if (opcion == "1") {
                                        cout << "Introduce el ID de la mercancia: ";
                                        cin >> id;
                                        cout << "Introduce el nombre de la mercancia: ";
                                        cin.ignore();
                                        getline(cin, nombre);
                                        cout << "Introduce el precio de la mercancia: ";
                                        cin >> precio;
                                        moduloA.altaMercancia(Mercancia(id, nombre, precio));
                                    } else if (opcion == "2") {
                                        cout << "Introduce el ID de la mercancia para dar de baja: ";
                                        cin >> id;
                                        moduloA.bajaMercancia(id);
                                    } else if (opcion == "3") {
                                        cout << "Introduce el ID de la mercancia para cambiar: ";
                                        cin >> id;
                                        cout << "Introduce el nuevo nombre: ";
                                        cin.ignore();
                                        getline(cin, nombre);
                                        cout << "Introduce el nuevo precio: ";
                                        cin >> precio;
                                        moduloA.cambioMercancia(id, nombre, precio);
                                    } else if (opcion == "4") {
                                        moduloA.consultaMercancia();
                                    } else {
                                        cout << "Opcion no valida. Intentalo de nuevo.\n";
                                    }
                                } else if (opcion == "2") {
                                    cout << "Selecciona una opcion:\n1. Alta\n2. Baja\n3. Cambio\n4. Consulta\n";
                                    cin >> opcion;
                                    if (opcion == "1") {
                                        cout << "Introduce el ID del proveedor: ";
                                        cin >> id;
                                        cout << "Introduce el nombre del proveedor: ";
                                        cin.ignore();
                                        getline(cin, nombre);
                                        cout << "Introduce el contacto del proveedor: ";
                                        getline(cin, contacto);
                                        moduloA.altaProveedor(Proveedor(id, nombre, contacto));
                                    } else if (opcion == "2") {
                                        cout << "Introduce el ID del proveedor para dar de baja: ";
                                        cin >> id;
                                        moduloA.bajaProveedor(id);
                                    } else if (opcion == "3") {
                                        cout << "Introduce el ID del proveedor para cambiar: ";
                                        cin >> id;
                                        cout << "Introduce el nuevo nombre: ";
                                        cin.ignore();
                                        getline(cin, nombre);
                                        cout << "Introduce el nuevo contacto: ";
                                        getline(cin, contacto);
                                        moduloA.cambioProveedor(id, nombre, contacto);
                                    } else if (opcion == "4") {
                                        moduloA.consultaProveedor();
                                    } else {
                                        cout << "Opcion no valida. Intentalo de nuevo.\n";
                                    }
                                } else if (opcion == "3") {
                                    cout << "Selecciona una opcion:\n1. Alta\n2. Baja\n3. Cambio\n4. Consulta\n";
                                    cin >> opcion;
                                    if (opcion == "1") {
                                        cout << "Introduce el ID de la oferta: ";
                                        cin >> id;
                                        cout << "Introduce la descripcion de la oferta: ";
                                        cin.ignore();
                                        getline(cin, descripcion);
                                        cout << "Introduce el descuento de la oferta: ";
                                        cin >> descuento;
                                        moduloA.altaOferta(Oferta(id, descripcion, descuento));
                                    } else if (opcion == "2") {
                                        cout << "Introduce el ID de la oferta para dar de baja: ";
                                        cin >> id;
                                        moduloA.bajaOferta(id);
                                    } else if (opcion == "3") {
                                        cout << "Introduce el ID de la oferta para cambiar: ";
                                        cin >> id;
                                        cout << "Introduce la nueva descripcion: ";
                                        cin.ignore();
                                        getline(cin, descripcion);
                                        cout << "Introduce el nuevo descuento: ";
                                        cin >> descuento;
                                        moduloA.cambioOferta(id, descripcion, descuento);
                                    } else if (opcion == "4") {
                                        moduloA.consultaOferta();
                                    } else {
                                        cout << "Opcion no valida. Intentalo de nuevo.\n";
                                    }
                                } else if (opcion == "4") {
                                    esc=1;
                                    system("cls");
                                    break;
                                } else {
                                    cout << "Opcion no valida. Intentalo de nuevo.\n";
                                }
                                cout << "Presiona Enter para continuar...";
                                cin.ignore();
                                cin.get();
                                limpiarPantalla();
                            }
							break;
						case 3:
							cout<<"c";
							break;
						case 4:
							esc=1;
							system("cls");
							break;
						case 5:
							esc=2;
							system("cls");
							break;
					}
                limpiarPantalla();
				}while(esc<=0);
		}
		if(esc==1){
			esc=0;
		}
		else{
			esc=esc;
		}
	}while(esc<=1);
	getch();
	return 0;
}

