#include <iostream>
#include <vector>
#include <string>


void inizialiceProcess(std::vector<std::vector<std::string>>& lista, char opc, std::istream& scanner, bool val, std::vector<std::vector<std::string>>& products) {
    bool activeProcess = true;
    while (activeProcess){
        if(!lista.empty()){
            // Do something with the list
        }
        std::cout << "\nIngrese la Opcion a ejecutar: \n";
        std::cout << "1 agregar\n";
        std::cout << "2 eliminar\n";
        std::string opcSellorBuild;
        std::cin >> opcSellorBuild;
        std::cout << "\nIngrese la referencia del producto: ";
        std::string product;
        std::cin >> product;
        std::cout << "\nIngrese la cantidad del producto: ";
        std::string count;
        std::cin >> count;
        if (opcSellorBuild == "1") {
            std::cout << "\nIngrese el nombre del producto: ";
            std::string name;
            std::cin >> name;
            lista.push_back({product, count, name});
        } else if (opcSellorBuild == "2") {
            // Do something
        } else {
            std::cout << "\nOpción no valida: " << opcSellorBuild;
        }
        std::cout << "\nsi desea cerrar la operación digite la opción: (1)";
        std::cout << "\nde lo contrario marque (0)";
        std::string terminate;
        std::cin >> terminate;
        if(terminate == "1"){
            activeProcess = false;
        };
    }
}

void modifyStock(std::vector<std::vector<std::string>>& lista, std::vector<std::vector<std::string>>& products) {
    if(!lista.empty()){
        for(auto& s : lista) {
            bool addProduct = true;
            for(auto& product : products){
                if (product[0] == s[0]) {
                    addProduct = false;
                    int newQuantity = std::stoi(product[2]) + std::stoi(s[1]);
                    product[2] = std::to_string(newQuantity);
                    break;
                }
            }
            if (addProduct) {
                products.push_back({s[2], s[0], s[1]});
            }
        }
    }
}

void validateExistProduct(std::vector<std::vector<std::string>>& products, const std::string& count, const std::string& product) {
    for(auto& productInfo : products) {
        if (productInfo[1] == product) {
            int availableQuantity = std::stoi(productInfo[2]);
            if (availableQuantity > std::stoi(count)) {
                std::cout << "\nproducto procesado";
            } else {
                std::cout << "\nCantidad no disponible";
                //ingresar de nuevo el producto
            }
            return;
        }
    }
    std::cout << "\nProducto no valido: ";
    //ingresar de nuevo el producto
}

void productBase(std::vector<std::vector<std::string>>& products) {
    products.push_back({"cepillo", "1", "5"});
    products.push_back({"enjuague bucal", "2", "5"});
    products.push_back({"crema", "3", "5"});
    products.push_back({"shampoo", "4", "5"});
    products.push_back({"bloqueador", "5", "5"});
}

void clearScreen() {
    std::cout << "\033[H\033[2J";
    std::cout.flush();
}

int main() {
    char opc;
    bool val = false;
    bool active = true;
    std::vector<std::vector<std::string>> products;
    std::vector<std::vector<std::string>> lista;
    productBase(products);

    while (active) {
        clearScreen();
        std::cout << "\nMenu Principal";
        std::cout << "\n................\n";
        std::cout << "1 Articulos del Inventario\n";
        std::cout << "2 Ordenes de Compras\n";
        std::cout << "3 Facturas de Ventas\n";
        std::cout << "4 Reportes del Sistema\n";
        std::cout << "5 Salida del Sistema\n";

        std::cout << "\nIngrese la Opcion a ejecutar: ";
        std::cin >> opc;

        val = isdigit(opc) && opc >= '1' && opc <= '5';
        if (val) {
            int opcInt = opc - '0';

            if (opcInt >= 1 && opcInt <= 5) {
                if (opcInt == 1) {
                    if (val) {
                        std::cout << "\nInventario";
                        std::cout << "\n___________________________________";
                        int numProdut = 0;
                        for (auto& product : products) {
                            numProdut++;
                            std::cout << "\nproducto nro: " << numProdut;
                            std::cout << "\nNombre: " << product[0];
                            std::cout << "\nReferencia: " << product[1];
                            std::cout << "\nCantidad: " << product[2];
                        }
                        std::cout << "\n___________________________________";
                    }
                } else if (opcInt == 2) {
                    std::cout << "2 Ordenes de Compras";
                    inizialiceProcess(lista, opc, std::cin, val, products);
                } else if (opcInt == 3) {
                    std::cout << "3 Facturas de Ventas";
                    inizialiceProcess(lista, opc, std::cin, val, products);
                } else if (opcInt == 4) {
                    std::cout << "4 Reportes del Sistema";
                } else if (opcInt == 5) {
                    std::cout << "Salida exitosa del sistema";
                    active = false;
                }
            } else {
                std::cout << "la opción ingresada no es valida: " << opcInt;
                active = true;
            }
        }
    }

    return 0;
}
