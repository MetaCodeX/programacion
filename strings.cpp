#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
string convertirATexto(int numero) {


string unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve","diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete","dieciocho", "diecinueve"};

string decenas[] = {"", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};

string centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos","setecientos", "ochocientos", "novecientos"};

    if (numero == 0) {
        return "cero";
    }
   string texto;

     if (numero >= 1000 && 1000 <= 1999) {
        texto += " mil " + centenas[numero / 100];
        numero %= 1000;
    }
    else if(numero >=2000) {
         texto += unidades[numero] + " mil " + centenas[numero / 100];
        numero %= 1000;
    }

    if (numero >= 100) {
        texto += centenas[numero / 100] + "  ";
        numero %= 100;
    }

    if (numero >= 20) {
        texto += decenas[numero / 10] + " y ";
        numero %= 10;
    }

    if (numero > 0) {
        texto += unidades[numero];
    }

    return texto;
}

int main() {
    int numero;
    std::cout << "Ingrese un número en decimal: ";
    std::cin >> numero;

    if (numero < 0 || numero > 19999) {
        std::cout << "El número debe estar entre 0 y 19999." << std::endl;
        return 1;
    }

    // Convertir el número a su forma textual
    std::string texto = convertirATexto(numero);

    // Imprimir el resultado
    std::cout << "El número " << numero << " en texto es: " << texto << std::endl;

    return 0;
}
