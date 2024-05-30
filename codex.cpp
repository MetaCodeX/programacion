#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;

    string admin[1][2] = {{"MetaCodeX", "Farewell"}};
    string almac[5][3]= {{"A0001","Annie","Annie01"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"}};//0.ID 1.Usser 2.Password
    string cajer[5][3]= {{"C0001","Iker", "Iker01"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"}};//0.ID 1.Usser 2.Password
    string changes[10][3]= {{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"}};
    string Merc[10][3]= {{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"}};
    int    price[10][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    string Prov[10][3]= {{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"}};
    string Sale[10][3]= {{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"},{"0","0","0"}};
    int ticket2[10][5]= {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    string ticket1[10][7]={{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"},{"0","0","0","0","0","0","0"}};
    int opcion;
    string usu, pass;
    int codex;
    int opc=0;
    bool again=false;
    int macro;
    bool scape=false;
    bool meta=false;
    string aggname,aggpass,aggID;
    int i=0,prices;
    char aggrank;
    int charger;
    bool fanylu=true;
    string mercID,mercName,mercPrice;
    string ProvID,ProvName,ProvConcept;
    string SaleID;
    char SaleType;
    int SalePer,SaleType2;
    string tickID,prodID,tickDay,tickHour,cajerID,checker;
    int worth,change,prodStack,payment;

    /*Zona de opciones*/
void checkTick(){
     system("cls");
     cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
     cout << "4. Consulta de Ticket" << endl<< endl;
        cout << "[ Ticket ID ]\n";
        for (int i = 0; i < 10; i++) {
      cout << "[   " << setw(8) << ticket1[i][0] << "] "<<endl;
    }
    cout << endl<< endl<< endl;
    cout << "Ingrese ID de ticket a analizar: " << endl<< endl; cin>>checker;
        cout<<endl<<endl<<endl<<endl;
    for (int i = 0; i < 10; ++i) {
        if(ticket1[i][0]==checker){
            for (int j = 0; i < 10; ++i) {

           cout<<"ID de Ticket: "<<ticket1[j][0]<<endl;
           cout<<"Fecha: "<<ticket1[j][1]<<endl;
           cout<<"Hora: "<<ticket1[j][2]<<endl;
           cout<<"ID del Vendedor: "<<ticket1[j][3]<<endl;
           cout<<"Nombre del Vendedor: "<<ticket1[j][4]<<endl;
           cout<<"Nombre del Producto: "<<ticket1[j][5]<<endl;
           cout<<"Metodo de Pago: "<<ticket1[j][6]<<endl;
           cout<<"Cantidad de productos: "<<ticket2[j][0]<<endl;
           cout<<"Total de productos: "<<ticket2[j][1]<<endl;
           cout<<"Precio Unitario: "<<ticket2[j][4]<<endl;
           cout<<"Monto: "<<ticket2[j][2]<<endl;
           cout<<"Cambio: "<<ticket2[j][3]<<endl;
           system("pause");
           break;
        }
        cout << "\n";
    }
     break;
    }
  system("cls");

}
void editTick(){
     system("cls");
     cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
     cout << "3. Cambios de Ticket" << endl << endl;
     cout << "Inserte ID de ticket" <<endl;
     cin  >> tickID;
     for (int i = 0; i < 9; i++) {
                if (ticket1[i][0] == tickID){
            cout << "Ticket 1:\n";

           cout<<"ID de Ticket: "<<endl; cin>>ticket1[i][0];
           cout<<"Fecha: "<<endl; cin>>ticket1[i][1];
           cout<<"Hora: "<<endl; cin>>ticket1[i][2];
           cout<<"ID del Vendedor: "<<endl; cin>>ticket1[i][3];
           cout<<"ID del Producto: "<<endl; cin>>prodID;

            cout << "\nTicket 2:\n";

         cout<<"Cantidad de productos: "<<endl; cin>>ticket2[i][0];
         /*cout<<"Total de productos: "<<endl; cin>>ticket2[i][1]
         cout<<"Precio Unitario: "<<endl; cin>>ticket2[i][4]*/
         cout<<"Monto: "<<endl; cin>>ticket2[i][2]; worth=ticket2[i][2];
         /*cout<<"Cambio: "<<endl; cin>>ticket2[i][3]*/
         for (int o=0;o<9;o++){
                            if(Merc[o][0]==prodID){
                        ticket1[i][5]=Merc[o][1];//Nombre del producto
                        ticket2[i][0]=prodStack;//cantidad de productos
                            if(price[o][1]==1){
                            ticket2[i][1]=(prodStack/2)*price[o][0]+(prodStack%2)*price[o][0];//descuento 2x1 total a cantidad de productos
                            }else
                            if(price[o][2]==1){
                            ticket2[i][1]=price[o][0]*(1-price[o][3]/100);
                            }else
                            if(price[o][1]==1 && price[o][2]==1){
                            ticket2[i][1]=((prodStack/2)*(price[o][0]*(1-price[o][3]/100))+(prodStack%2)*(price[o][0]*(1-price[o][3]/100)));
                            }else{
                            ticket2[i][1]=price[o][0]*prodStack;}
                            }
                            ticket2[i][4]=price[o][0];

                    break;
             }
        break;
        }
       cout << "\n";
        break;
    }

}
void delTick(){
     system("cls");
     cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
     cout << "2. Baja de Ticket" << endl << endl;
     cout << "Inserte ID de ticket" <<endl;
     cin  >> tickID;
     for (int i = 0; i < 9; i++) {
                if (ticket1[i][0] == tickID){
                     ticket1[i][0] = "0";
                     ticket1[i][1] = "0";
                     ticket1[i][2] = "0";
                     ticket1[i][3] = "0";
                     ticket1[i][4] = "0";
                     ticket1[i][5] = "0";
                     ticket1[i][6] = "0";

                     ticket1[i][0] = "0";
                     ticket1[i][1] = "0";
                     ticket1[i][2] = "0";
                     ticket1[i][3] = "0";
                     ticket1[i][4] = "0";
                     cout<<endl<<"Ticket eliminado correctamente"<<endl;
                     system("pause");
                     system("cls");
                     break;

                }else{cout<<endl<<"Ticket No Existente"<<endl;}
  break;
                }



}
void addTick(){
     system("cls");
     cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
     cout << "1. Alta de Ticket" << endl<< endl;
     cout << "Inserte ID de ticket" <<endl;
     cin  >> tickID;
     cout << "Inserte ID de Producto" <<endl;
     cin  >> prodID;
     cout << "Inserte ID del Vendedor" <<endl;
     cin  >> cajerID;
     cout << "inserte cantidad de producto"<< endl;
     cin  >> prodStack;
     cout << "inserte fecha"<<endl;
     cin  >> tickDay;
     cout << "inserte hora" <<endl;
     cin  >> tickHour;
     cout << "Metodo de pago: "<<endl;
     cout << "1.Efectivo, 2.Vales, 3.Debito, 4.Credito"<<endl;
     cin  >>  payment;
     cout << "Dinero Disponible:"<<endl;
     cin  >>  worth;
     cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
/*Primer Array String [//ID Ticket //Fecha //Hora //IDUsuario //Usuario // Producto] string ticket1[10][6] //Payment */
/*Segundo Array Int [  //prodStack//total //Monto//Cambio] int ticket2[10][4]  */
             for (int i = 0; i < 9; i++) {
                if (ticket1[i][0] == "0") {
                        //ticket2
                        ticket1[i][0] =tickID;//Id de ticket
                        ticket1[i][1] =tickDay;//Dia del Ticket
                        ticket1[i][2] =tickHour;//Hora del ticket
                        for (int j = 0; j < 9; j++) {
                            if (cajer[j][0] == cajerID) {
                        ticket1[i][3] =cajerID;//ID del Cajero
                        ticket1[i][4] =cajer[j][1];//Usuario del cajero
                        break;
                }
            }
                    if(payment==1){
                        ticket1[i][6] = "Efectivo";
                    }
                    if(payment==2){
                        ticket1[i][6] = "Vales";
                    }
                    if(payment==3){
                        ticket1[i][6] = "Debito";
                    }
                    if(payment==4){
                        ticket1[i][6] = "Credito";
                    }
                        for (int o=0;o<9;o++){
                            if(Merc[o][0]==prodID){
                        ticket1[i][5]=Merc[o][1];//Nombre del producto
                        ticket2[i][0]=prodStack;//cantidad de productos
                            if(price[o][1]==1){
                            ticket2[i][1]=(prodStack/2)*price[o][0]+(prodStack%2)*price[o][0];//descuento 2x1 total a cantidad de productos
                            }else
                            if(price[o][2]==1){
                            ticket2[i][1]=price[o][0]*(1-price[o][3]/100);
                            }else
                            if(price[o][1]==1 && price[o][2]==1){
                            ticket2[i][1]=((prodStack/2)*(price[o][0]*(1-price[o][3]/100))+(prodStack%2)*(price[o][0]*(1-price[o][3]/100)));
                            }else{
                            ticket2[i][1]=price[o][0]*prodStack;}
                            }
                            ticket2[i][4]=price[o][0];

                    break;
             }
                            ticket2[i][2]=worth;
                            ticket2[i][3]=ticket2[i][2]-ticket2[i][1];

          }
           break;
        }
        cout<<endl<<endl<<endl<<endl;
        cout << "Ticket 1:\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 6; ++j) {
           cout<<"ID de Ticket: "<<ticket1[i][0]<<endl;
           cout<<"Fecha: "<<ticket1[i][1]<<endl;
           cout<<"Hora: "<<ticket1[i][2]<<endl;
           cout<<"ID del Vendedor: "<<ticket1[i][3]<<endl;
           cout<<"Nombre del Vendedor: "<<ticket1[i][4]<<endl;
           cout<<"Nombre del Producto: "<<ticket1[i][5]<<endl;
           cout<<"Metodo de Pago: "<<ticket1[i][6]<<endl;
           break;
        }
        cout << "\n";
        break;
    }

            cout << "\nTicket 2:\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
         cout<<"Cantidad de productos: "<<ticket2[i][0]<<endl;
         cout<<"Total de productos: "<<ticket2[i][1]<<endl;
         cout<<"Precio Unitario: "<<ticket2[i][4]<<endl;
         cout<<"Monto: "<<ticket2[i][2]<<endl;
         cout<<"Cambio: "<<ticket2[i][3]<<endl;
        break;
        }
       cout << "\n";
        break;
    }

}
void modMerc(){
        opc=0;
        cout <<" Modulo de Mercancias " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << " 1.Agregar Mercancia"   << endl;
        cout << " 2.Retirar Mercancia"   << endl;
        cout << " 3.Modificar Mercancia" << endl;
        cout << " 4.Revisar  Mercancia"  << endl;
        cout << " 5.Volver Atras"        << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Entrada: ";
        cin  >> opc;
        switch(opc){
    case 1:
        system("cls");
        cout << " Agregar Mercancia " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Introduce ID del producto"<<endl;
        cin  >>mercID;
        cout << "Introduce el Nombre del producto"<<endl;
        cin  >>mercName;
        cout << "Introduce precio del producto"<<endl;
        cin  >>mercPrice;
        for (int i = 0; i < 9; i++) {
                if (Merc[i][0] == "0") {
                        Merc[i][0]=mercID;
                        Merc[i][1]=mercName;
                        Merc[i][2]=mercPrice;
                        prices=stoi(mercPrice);
                        price[i][0]=prices;
                         cout << endl<< " producto añadido correctamente " << endl;
                        system("pause");
                        break;
                }
        }
        system("cls");
        break;
    case 2:
         system("cls");
        cout << " Retirar Mercancia " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Introduce ID del producto"<<endl;
        cin  >>mercID;
        for (int i = 0; i < 9; i++) {
                if (Merc[i][0] == mercID) {
                        Merc[i][0]="0";
                        Merc[i][1]="0";
                        Merc[i][2]="0";
                        price[i][0]=0;
                        cout << endl<< " producto eliminado correctamente " << endl;
                        system("pause");
                        break;
                }else{cout<<"Producto Inexistente";break;}
        }
        system("cls");
        break;
    case 3:
        system("cls");
        cout << " Modificar Mercancia " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Introduce ID del producto"<<endl;
        cin  >>mercID;
        cout << "Introduce el Nuevo Nombre del producto :"<<endl;
        cin  >>mercName;
        cout << "Introduce el Nuevo precio del producto"<<endl;
        cin  >>mercPrice;
        for (int i = 0; i < 9; i++) {
                if (Merc[i][0] == mercID) {
                        Merc[i][1]=mercName;
                        Merc[i][2]=mercPrice;
                        cout<< Merc[i][0]<<endl;
                        cout<< Merc[i][1]<<endl;
                        cout<< Merc[i][2]<<endl;
                        system("pause");
                        break;
                }else{cout<<"producto no existe"; }
        }
        break;
    case 4:
        system("cls");
          cout << "[ ProdID ] [ Producto ] [ Precio ]"<<endl;
            for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 3; ++j) {
    cout << " [" << setw(5) << Merc[i][j] << " ]"; // Ajustar ancho a 5 caracteres
  }
  cout << endl; // Salto de línea al final de cada fila
}


        break;
    case 5:
        return;break;
        }


}
void modProv(){
    opc=0;
        cout <<" Modulo de Proovedores " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << " 1.Agregar proovedor"   << endl;
        cout << " 2.Retirar Proovedor"   << endl;
        cout << " 3.Modificar proovedor" << endl;
        cout << " 4.Revisar  Proovedor"  << endl;
        cout << " 5.Volver Atras"        << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Entrada: ";
        cin  >> opc;
        switch(opc){
    case 1:
        system("cls");
        cout << " Agregar Proovedor " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Introduce ID del Proovedor"<<endl;
        cin  >>ProvID;
        cout << "Introduce el Nombre del proovedor"<<endl;
        cin  >>ProvName;
        cout << "Introduce concepto del proovedor"<<endl;
        cin  >>ProvConcept;
        for (int i = 0; i < 9; i++) {
                if (Prov[i][0] == "0") {
                        Prov[i][0]=ProvID;
                        Prov[i][1]=ProvName;
                        Prov[i][2]=ProvConcept;
                        cout<< Prov[i][0]<<endl;
                        cout<< Prov[i][1]<<endl;
                        cout<< Prov[i][2]<<endl;
                        system("pause");
                        break;
                }
        }
        system("cls");
        break;
    case 2:
         system("cls");
        cout << " Retirar provedor " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Introduce ID del proovedor"<<endl;
        cin  >>ProvID;
        for (int i = 0; i < 9; i++) {
                if (Prov[i][0] == ProvID) {
                        Prov[i][0]="0";
                        Prov[i][1]="0";
                        Prov[i][2]="0";

                        break;
                }else{cout<<"Producto Inexistente";break;}
        }
        system("cls");
        break;
    case 3:
        system("cls");
        cout << " Modificar Proovedor " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Introduce ID del producto"<<endl;
        cin  >>ProvID;
        cout << "Introduce el Nuevo Nombre del producto :"<<endl;
        cin  >>ProvName;
        cout << "Introduce el Nuevo concepto del producto"<<endl;
        cin  >>ProvConcept;
        for (int i = 0; i < 9; i++) {
                if (Prov[i][0] == ProvID) {
                        Prov[i][1]=ProvName;
                        Prov[i][2]=ProvConcept;
                        cout<< Prov[i][0]<<endl;
                        cout<< Prov[i][1]<<endl;
                        cout<< Prov[i][2]<<endl;
                        system("pause");
                        break;
                }else{cout<<"producto no existe"; }
        }
        break;
    case 4:
        system("cls");
          cout << "[ ProvID ] [ Nombre ] [ Concepto ]"<<endl;
            for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 3; ++j) {
    cout << " [" << setw(5) << Prov[i][j] << " ]"; // Ajustar ancho a 5 caracteres
  }
  cout << endl; // Salto de línea al final de cada fila
}


        break;
    case 5:
        return;break;
        }


}
void modSale(){
    opc=0;
        cout <<" Modulo de Ofertas" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << " 1.Agregar Oferta"   << endl;
        cout << " 2.Retirar Oferta"   << endl;
        cout << " 3.Modificar Oferta" << endl;
        cout << " 4.Revisar  Ofertas"  << endl;
        cout << " 5.Volver Atras"        << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Entrada: ";
        cin  >> opc;
        switch(opc){
        case 1:
            system("cls");
            cout << " 1.Agregar Oferta"   << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            cout << " Introduce ID Del producto" << endl;
            cin  >> SaleID;
            cout << " Introduce tipo de oferta: " << endl;
            cout << " A-. (2 x 1) // B-. Descuento : " << endl;
            cin  >> SaleType;
            if (SaleType == 'B' || SaleType == 'b'){
            cout << "Porcentaje del Descuento: "<<endl;
            cin  >> SalePer;
            }

            switch(SaleType){

        case 'A'://2 por Uno!!
        case 'a':
            system("cls");
            for (int i = 0; i < 9; i++) {
                if (Merc[i][0] == SaleID) {
                    price[i][1]++;
                    cout << price[i][1] <<endl;
                cout << endl<< " Oferta 2 X 1 Añadido al articulo: "<<SaleID<<endl;
                system("pause");
                    break;
                }else { cout<<"Producto Inexistente"<<endl;  system("pause"); break;}
            }
            break;
        case 'B'://Descuentos!!
        case 'b':
             for (int i = 0; i < 9; i++) {
                if (Merc[i][0] == SaleID) {
                    price[i][2]++;
                    price[i][3] = SalePer;
                     cout << price[i][2] <<endl;
                      cout << price[i][3] <<endl;
                     cout << endl<< " Oferta de Descuento Añadido al articulo: "<<SaleID<<"Con el descuento del %"<<SalePer<<endl;
                system("pause");
                    break;
                } else { cout<<"Producto Inexistente"<<endl;  system("pause"); break;}


            }
            system("cls");

            break;
            }

            system("cls");
            break;
        case 2:
            system("cls");
            cout << " 2.Retirar Oferta"   << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            cout << " Introduce ID Del producto" << endl;
            cin  >> SaleID;


             for (int i = 0; i < 9; i++) {
                if (Merc[i][0] == SaleID &&  price[i][1] == 1 || Merc[i][0] == SaleID && price[i][2] == 1  ) {
                        price[i][1]--;
                        price[i][2]--;
                        price[i][3]==0;
                        cout<<"Ofertas Eliminadas en el producto: "<<SaleID<<endl; system("pause"); break;
                }else { cout<<"Producto sin Ofertas"<<endl;  system("pause"); break;}
            }

            system("cls");
            break;
        case 3:
            system("cls");
            cout << " 1.Modificar"   << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            cout << " Introduce ID Del producto" << endl;
            cin  >> SaleID;
            cout << " Desea Modificar descuentos?" ;
            cout << "Y= Si // N= No";
            cin  >> SaleType;
            if (SaleType == 'Y' || SaleType == 'y'){
            cout << "Porcentaje del Descuento: "<<endl;
            cin  >> SalePer;
              for (int i = 0; i < 9; i++) {
            if (Merc[i][0] == SaleID && price[i][2]==1){  price[i][3]= SalePer; break; } else { cout<<endl<<"no tiene descuento"; break; }
            }
            }
            cout << " Desea Retirar alguna Oferta?" ;
            cout << "Y= Si // N= No";
            cin  >> SaleType;
            if (SaleType == 'Y' || SaleType == 'y'){
            cout << "que oferta desea retirar? "<<endl;
             cout << "1.2x1 // 2.Descuento "<<endl;
            cin  >> SaleType2;
            for (int i = 0; i < 9; i++) {
            if (Merc[i][0] == SaleID){
                 switch(SaleType2){
            case 1: price[i][1]==0; break;
            case 2: price[i][2]==0;break;
                default: cout << "Eleccion no valida"<<endl;break;
                }
            }
            }
            }
 cout << "Correcciones aplicadas" <<endl;system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
          cout << "[ ProdID ] "<<endl;
            for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 1; ++j) {
    cout << " [" << setw(5) << Merc[i][j] << " ]"; // Ajustar ancho a 5 caracteres
  }
  cout << endl; // Salto de línea al final de cada fila
}
cout << endl;
            cout << "[ Precio ] [ 2X1 ] [ Descuentos ] [Porcentaje]"<<endl;
            for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 4; ++j) {
    cout << " [" << setw(5) << price[i][j] << " ]"; // Ajustar ancho a 5 caracteres
  }
  cout << endl; // Salto de línea al final de cada fila
}           system("pause");
            system("cls");
            break;
        case 5: return;break;


        }
}
void changer(int charger, char aggrank){
        switch(aggrank){

    case 'J':
    case 'j':
            for(int i=0;i<9;i++)
            {
                 if(changes[i][0]=="0"){
                        if(charger==1)
                            {
                                changes[i][0]="Añadiendo ";
                            }
                        else if(charger==2)
                            {changes[i][0]="Eliminando ";
                        };
                        changes[i][1]="Jefe De Cajas";
                        changes[i][2]=aggID;
                 break;
                 }
            }

        break;
    case 'C':
    case 'c':
        for(int i=0;i<9;i++)
            {
                 if(changes[i][0]=="0"){
                        if(charger==1)
                            {
                                changes[i][0]="Añadiendo ";
                            }
                        else if(charger==2)
                            {changes[i][0]="Eliminando ";
                        };
                        changes[i][1]="Cajero";
                        changes[i][2]=aggID;
                 break;
                 }
            }

        break;
        }


}
void delUser(){
    system("cls");
    aggID="0";
cout << "*-*-*-*-Eliminar Usuario*-*-*-*-" << endl << endl;
         aggID="0";
 cout << "Rango de Usuario"<< endl;
 cout << "(J=Jefe De Cajas , C= Cajero): ";
    cin  >> aggrank;
 cout << "Ingrese ID: ";
 cin >> aggID;

    switch (aggrank){

            case 'J':
            case 'j':
                 for (int i = 0; i < 3; i++) {
                if (almac[i][0] == aggID) {
                        almac[i][0] = "0"; // Llenar ID en la primera columna
                        almac[i][1] = "0"; // Llenar nombre de usuario en la segunda columna
                        almac[i][2] = "0"; // Llenar contraseña en la tercera columna
                        charger=2;


                    cout << "Usuario eliminado de la fila " << i + 1 << endl; system("pause"); break;
            break; // Salir del ciclo al encontrar una fila vacía y llenarla

    }else{cout<<"Usuario no encontrado"<<endl;  system("pause");}

  }
 changer(charger,aggrank);
    break;

            case 'C':
            case 'c':
                 for (int i = 0; i < 3; i++) {
                if (cajer[i][0] == aggID) {
                        cajer[i][0] = "0"; // Llenar ID en la primera columna
                        cajer[i][1] = "0"; // Llenar nombre de usuario en la segunda columna
                        cajer[i][2] = "0"; // Llenar contraseña en la tercera columna
                        charger=2;

                    cout << "Usuario Eliminado de la fila " << i + 1 << endl; system("pause"); break;
            break; // Salir del ciclo al encontrar una fila vacía y llenarla
    }else{cout<<"Usuario no encontrado"<<endl;  system("pause"); }
  }
changer(charger,aggrank);



    break;
}



}
void aggUser(){
system("cls");
            aggID="0";
            cout << "*-*-*-*-Agregar Usuario*-*-*-*-" << endl << endl;
            cout << "Agregar Rango de Usuario"<< endl;
            cout << "(J=Jefe De Cajas , C= Cajero): ";
            cin  >> aggrank;
            switch (aggrank){
            case 'J':
            case 'j':
                cout << "ID del usuario: ";
                cin  >> aggID;
                cout << "Nombre de Usuario: ";
                cin  >> aggname;
                cout << "Contraseña de Usuario: ";
                cin  >> aggpass;
                 for (int i = 0; i < 3; i++) {
                if (almac[i][0] == "0") {
                        almac[i][0] = aggID; // Llenar ID en la primera columna
                        almac[i][1] = aggname; // Llenar nombre de usuario en la segunda columna
                        almac[i][2] = aggpass; // Llenar contraseña en la tercera columna
                        charger=1;

                    cout << "Usuario agregado en la fila " << i + 1 << endl;
                       system("pause");
                     system("cls");

            break; // Salir del ciclo al encontrar una fila vacía y llenarla
    }
  }
    changer(charger,aggrank);
                break;
            case 'C':
            case 'c':
                cout << "ID del usuario: ";
                cin  >> aggID;
                cout << "Nombre de Usuario: ";
                cin  >> aggname;
                cout << "Contraseña de Usuario: ";
                cin  >> aggpass;
                 for (int i = 0; i < 3; i++) {
                if (cajer[i][0] == "0") {
                        cajer[i][0] = aggID; // Llenar ID en la primera columna
                        cajer[i][1] = aggname; // Llenar nombre de usuario en la segunda columna
                        cajer[i][2] = aggpass; // Llenar contraseña en la tercera columna
                        charger=1;

                    cout << "Usuario agregado en la fila " << i + 1 << endl;
                    system("pause");
                     system("cls");


            break; // Salir del ciclo al encontrar una fila vacía y llenarla
    }

  }
  changer(charger,aggrank);
                break;
            }

}
/* Zona de Mecanismos de Visualizacion*/
void login() {//Zona de Logins
    cout << "Bienvenido al portal de usuarios de MacroStasis" << endl;
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

  // Validación de administrador
  if (usu.compare(admin[i][0]) == 0 && pass.compare(admin[i][1]) == 0) {
    codex = 1;
  }

  // Búsqueda en array de almacenistas
  for (int i = 0; i < 5; i++) {
    if (usu.compare(almac[i][1]) == 0 && pass.compare(almac[i][2]) == 0) {
      codex = 2;
      break;
    }
  }

  // Búsqueda en array de cajeros
  for (int i = 0; i < 5; i++) {
    if (usu.compare(cajer[i][1]) == 0 && pass.compare(cajer[i][2]) == 0) {
      codex = 3;
      break;
    }
  }
  break;
  case 2:
 system("cls");
 cout << "GoodBye...."<<endl<<endl<<endl<<endl;
 system("pause");
 exit(0);
 break;
}
}
void admins(){//Zona de Administradores
    system("cls");
    while (meta=true){cout<<"Zona de Admins"<< endl;
    meta=true;
        cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "1. Agregar Usuario" << endl;
        cout << "2. Eliminar Usuario" << endl;
        cout << "3. Revisar" << endl;
        cout << "4. Cambios" << endl;
        cout << "5. Volver al inicio" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Entrada: ";
        cin >> opc;






            switch(opc){
        case 1: //Agregar Usuario
                aggUser();
                system("cls");
                cout<<"Añadido correctamente"<<endl<<"volviendo atras"<<endl;
                system("pause");
                system("cls");
            meta=false;
            break;
        case 2: //Eliminar Usuario
            delUser();
            system("cls");
            cout<<"Eliminado Correctamente"<<endl<<"volviendo atras"<<endl;
                system("pause");
                system("cls");
                meta=false;
            break;
        case 3: //Revisar Usuarios
            system("cls");
            cout << "\n// Jefes de Almacen\n";
  cout << "[ User ID ] [ Usuario ] [ Password]\n";
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[ " << setw(8) << almac[i][j] << "] ";
    }
    cout << endl;
  }

  // Tabla Cajeros
  cout << "\n// Cajeros\n";
  cout << "[ User ID ] [ Usuario ] [ Password]\n";
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[ " << setw(8) << cajer[i][j] << "] ";
    }
    cout << endl;
  }
  cout << endl << endl ;
  system("pause");
  system("cls");
            break;
    case 4:
        system("cls");
        cout << "\n// Cambios Recientes\n";
  cout << "[ Motivo ] [ Rango ] [ UserID]\n";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[ " << setw(8) << changes[i][j] << "] ";
    }
    cout << endl;
  }
   cout << endl << endl ;
  system("pause");
  system("cls");
        break;
        case 5:return; break;

            }}
}
void almacen(){//Zona de Jefes de Almacen

    system("cls");
    while (meta=true){
    cout<<"Zona de Jefes de Almacen" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "1. Modulo de Mercancia" << endl;
        cout << "2. Modulo de Proovedores" << endl;
        cout << "3. Modulo de Ofertas" << endl;
        cout << "4. Volver al inicio" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Entrada: ";
        cin >> opc;

        if (opc==4){
            return;
        }

        switch(opc){
    case 1://Modulo de Mercancias
        system("cls");
modMerc();
        cout<<"Proceso Finalizado Correctamente"<<endl<<"volviendo atras"<<endl;
        system("pause");
        system("cls");
        meta=false;
        break;
    case 2://Modulo de Provedores
        system("cls");
modProv();
        cout<<"Proceso Finalizado Correctamente"<<endl<<"volviendo atras"<<endl;
        system("pause");
        system("cls");
        meta=false;
        break;
    case 3://Modulo de Ofertas
        system("cls");
modSale();
         cout<<"Proceso Finalizado Correctamente"<<endl<<"volviendo atras"<<endl;
        system("pause");
        system("cls");
        meta=false;
        break;
        }

    }
}
void cajeros(){//Zona de Cajeros
      system("cls");
      while (meta=true){
            cout<<"Zona de Cajeros" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "1. Alta de Ticket" << endl;
        cout << "2. Baja de Ticket" << endl;
        cout << "3. Cambios de Ticket" << endl;
        cout << "4. Consulta de Ticket" << endl;
        cout << "5. Volver al inicio" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Entrada: ";
        cin >> opc;

        if (opc==5){
            return;
        }
        switch(opc){

    case 1:
        system("cls");
        addTick();
         cout<<"Proceso Finalizado Correctamente"<<endl<<"volviendo atras"<<endl;
        system("pause");
        system("cls");
        meta=false;
        break;
    case 2:
        system("cls");
        delTick();
         cout<<"Proceso Finalizado Correctamente"<<endl<<"volviendo atras"<<endl;
        system("pause");
        system("cls");
        meta=false;
        break;
    case 3:
        system("cls");
        editTick();
         cout<<"Proceso Finalizado Correctamente"<<endl<<"volviendo atras"<<endl;
        system("pause");
        system("cls");
        meta=false;
        break;
    case 4:
        system("cls");
        checkTick();
         cout<<"Proceso Finalizado Correctamente"<<endl<<"volviendo atras"<<endl;
        system("pause");
        system("cls");
        meta=false;
        break;

        }

        }
}

int main(){
while (fanylu == true) {
login();
  switch (codex) {
    case 1:
        system("cls");
        admins();
        system("cls");
      break;
    case 2:
      system("cls");
        almacen();
        system("cls");
      break;
    case 3:
        system("cls");
        cajeros();
        system("cls");
      break;
    case 0:
        system("cls");
        cout<<"usuario no encontrado o incorrecto, intente nuevamente"<<endl;
        system("pause");
        system("cls");

      break;
  }
}

//endless Code v1.0
}

