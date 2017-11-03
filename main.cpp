#include <iostream>
#include <sstream>

int producto (int x, int y);
int suma (int x, int y);
int sucesor (int x);

int main (int argc, char* argv[]) {
    int a = 0;
    do {
        int x = 0, y = 0;
        if (argc == 1) {
            std::cout << "Introduzca los numeros a multiplicar: ";
            std::cin >> x >> y;
        } else {
            std::istringstream s1(argv[1]);
            std::istringstream s2(argv[2]);
            if (!(s1 >> x) && !(s2 >> y)) {
                std::cerr << "Numeros mal introducidos." << std::endl;
                return 1;
            } else {
                s1 >> x;
                s2 >> y;
            }
            argc = 1;
        }
        std::cout << std::endl << "El resultado es: " << producto(x, y) << std::endl << std::endl;
        std::cout << "0.- Salir" << std::endl;
        std::cout << "1.- Realizar mas multiplicaicones" << std::endl;
        std::cout << "-> ";
        std::cin >> a;
    } while (a != 0);
    return 0;
}

int producto (int x, int y) {
    if (x != 0 && y != 0) {
        return suma(producto(x, --y), x);
    }
    else {
      return 0;
    }
}

int suma (int x, int y) {
    if (x != 0 && y != 0) {
        return sucesor(suma(x, --y));
    }
    else {
        if (x == 0) {
            return y;
        }
        else {
            return x;
        }
    }
}

int sucesor (int x) {
    return ++x;
}

