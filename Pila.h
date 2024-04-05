//
// Created by teddyyeferson.poveda on 04/04/2024.
//

#ifndef UNTITLED1_PILA_H
#define UNTITLED1_PILA_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Pila {
private:
    int tope;
    int size;
    std::vector<std::string*> lista;
    std::string type;

public:
    Pila(int s, std::string types) : tope(0), size(s), type(types) {}

    std::string getType() {
        return type;
    }

    void addProduct(std::string nombre, std::string referecia, std::string cantidad) {
        if (tope < size) {
            if (!addValidation(referecia, cantidad)) {
                std::string* nuevo = new std::string[3];
                nuevo[0] = referecia;
                nuevo[1] = cantidad;
                nuevo[2] = nombre;
                lista.push_back(nuevo);
            }
            tope++;
        } else {
            std::cout << "La Pila de " << type << " se Encuentra llena" << std::endl;
        }
    }

    bool addValidation(std::string referecia, std::string cantidad) {
        for (auto& product : lista) {
            if (product[0] == referecia && product[1] == cantidad) {
                return true;
            }
        }
        return false;
    }

    std::string removeOrEditProduct(std::string referecia, std::string cantidad) {
        std::string state = "";
        if (isEmpty()) {
            std::cout << "No existen Facturas de " << type << " a Ejecutar" << std::endl;
        } else {
            if (cantidad != "") {
                lista.erase(std::remove_if(lista.begin(), lista.end(),
                                           [&](std::string* product) { return product[0] == referecia; }),
                            lista.end());
            } else {
                procesar(referecia, cantidad);
            }
            tope--;
        }
        return state;
    }

    void procesar(std::string referecia, std::string cantidad) {
        for (auto& product : lista) {
            if (product[0] == referecia) {
                product[1] = cantidad;
            }
        }
    }

    bool isEmpty() {
        return tope == 0;
    }

    virtual void getOrden() = 0;
};



#endif //UNTITLED1_PILA_H
