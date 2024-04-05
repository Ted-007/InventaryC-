//
// Created by teddyyeferson.poveda on 04/04/2024.
//

#ifndef UNTITLED1_PILAVENTAS_H
#define UNTITLED1_PILAVENTAS_H


#include "Pila.h"

class PilaVentas : public Pila {
public:
    PilaVentas(int s) : Pila(s, "Ventas") {}

    void getOrden() override {
        std::cout << "Factura de venta generada: \n";
        std::cout << "___________________________________\n";
        int numProducto = 0;
        for (const auto& s : this->lista) {
            numProducto++;
            std::cout << "producto nro: " << numProducto << "\n";
            std::cout << "*********************\n"
                      << "Nombre: " << s[2] << "\n"
                      << "Referencia: " << s[0] << "\n"
                      << "Cantidad: " << s[1] << "\n"
                      << "**********************\n";
        }
        std::cout << "___________________________________\n";
    }
};

#endif //UNTITLED1_PILAVENTAS_H
