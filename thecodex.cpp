#include <iostream>
#include <string>

using namespace std;

int main() {
  int opcion;
  string admin[1][2] = {{"MetaCodeX", "Farewell"}};
  string almac[3][4]= {{"Annie", "Annie01"}};
  string cajer[3][4]= {{"Iker", "Iker01"}};
  string usu, pass;
  int codex;
    int opcionAdm;
  do {
    cout << "\nBienvenido al portal de usuarios de MacroStasis" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Iniciar Sesion" << endl;
    cout << "2. Salir del programa" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1: // Iniciar Sesión
        system("cls");
        cout << "Bienvenido al portal de usuarios de MacroStasis" << endl;
        cout << "Ingrese su nombre de usuario: ";
        cin >> usu;

        cout << endl << "Ingrese su contraseña: ";
        cin >> pass;
        cout << endl;
        codex=0;
        if (usu == admin[0][0] && pass == admin[0][1]) {
          codex = 1;
        }
        for (int i = 0; i < 3; i++){
            if (usu == almac[i][0] && pass == almac[i][1]){
          codex = 2;
          break;
        }
        }
        for (int i = 0; i < 3; i++){
            if (usu == cajer[i][0] && pass == cajer[i][1]){
          codex = 3;
          break;
        }
        }
        if (codex == 0) {
                 system("cls");
    cout << "Usuario o Contrasena Incorrectos. Intente nuevamente." << endl;
    continue;
  }

        switch (codex) {
          case 1: // Administrador
            system("cls");

             opcionAdm=0;
            cout << "Portal de Administrador" << endl;
            cout << "\nModulo de administracion de usuarios" << endl;
            cout << "---------------------------------" << endl;
            cout << "1. Agregar nuevo usuario" << endl;
            cout << "2. Editar informacion de usuario" << endl;
            cout << "3. Eliminar usuario" << endl;
            cout << "4. Mostrar lista de usuarios" << endl;
            cout << "5. Regresar al menu principal" << endl;
            cout << "---------------------------------" << endl;

            do {
              cout << "Ingrese su opcion: ";
              cin >> opcionAdm;

              switch (opcionAdm) {
                case 1:

                  break;
                case 2:

                  break;
                case 3:

                  break;
                case 4:

                  break;
                case 5:
                    system("cls");
                  break;
                default:
                  cout << "Opcion no valida." << endl;
              }
            } while (opcionAdm != 5);

            break;
          case 2: // Jefe de cajas
            cout << "Portal de Jefe de Cajas" << endl;
             system("cls");
            opcionAdm=0;
            cout << "Portal de Jefe de Almacen" << endl;
            cout << "\nModulo de Almacen" << endl;
            cout << "---------------------------------" << endl;
            cout << "1. Modulo de Mercancia" << endl;
            cout << "2. Modulo de Provedores" << endl;
            cout << "3. Modulo de Ofertas" << endl;
            cout << "4. Regresar al Menu Principal" << endl;
            cout << "---------------------------------" << endl;

            do {
              cout << "Ingrese su opcion: ";
              cin >> opcionAdm;

              switch (opcionAdm) {
                case 1:

                  break;
                case 2:

                  break;
                case 3:

                  break;
                case 4:
                    system("cls");
                  break;
                default:
                  cout << "Opcion no valida." << endl;
              }
            } while (opcionAdm != 4);

            break;
          case 3: // Cajero
            system("cls");
             system("cls");
            int opcionAdm;
            cout << "Portal de Cajeros" << endl;
            cout << "\nModulo de Cajeros" << endl;
            cout << "---------------------------------" << endl;
            cout << "1. Compra de Producto" << endl;
            cout << "2. Cancelacion de Producto" << endl;
            cout << "3. Cambio de Producto" << endl;
            cout << "4. Regresar al Menu Principal" << endl;
            cout << "---------------------------------" << endl;

            do {
              cout << "Ingrese su opcion: ";
              cin >> opcionAdm;

              switch (opcionAdm) {
                case 1:
                  // ... Código para Compra de Producto
                  break;
                case 2:
                  // ... Código para Cancelacion de Producto
                  break;
                case 3:
                  // ... Código para Cambio de Producto
                  break;
                case 4:
                    system("cls");
                  break; // Sale del bucle del menú de Cajeros
                default:
                  cout << "Opcion no valida." << endl;
              }
            } while (opcionAdm != 4); // Sale del menú de Cajeros

            break; // Sale del caso de Cajeros
            break;
          default:
            cout << "Rol no reconocido." << endl;
        }

        break;
      case 2:
        system("cls");
        cout << "Saliendo del programa..." << endl;
        return 0;
      default:
        cout << "Opción no válida. Intente nuevamente." << endl;
    }
  } while (opcion != 2);
  return 0;
}
