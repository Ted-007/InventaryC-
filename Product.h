//
// Created by teddyyeferson.poveda on 04/04/2024.
//

#ifndef UNTITLED1_PRODUCT_H
#define UNTITLED1_PRODUCT_H


#include <string>

class Product {
private:
    std::string nombre;
    std::string referencia;
    int cantidad;

public:
    Product(const std::string& nombre, const std::string& referencia, int cantidad)
            : nombre(nombre), referencia(referencia), cantidad(cantidad) {}

    // Getters
    std::string getNombre() const { return nombre; }
    std::string getReferencia() const { return referencia; }
    int getCantidad() const { return cantidad; }

    // Setters
    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    void setReferencia(const std::string& referencia) { this->referencia = referencia; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }

    // EqualsAndHashCode equivalent

    // ToString equivalent
    std::string toString() const {
        return "*********************\n"
               "Nombre:" + nombre + "\n" +
               "Referencia:" + referencia + "\n" +
               "Cantidad:" + std::to_string(cantidad) + "\n" +
               "**********************\n";
    }
};


#endif //UNTITLED1_PRODUCT_H
