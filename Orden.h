// OrdenMenu.h

#ifndef ORDENMENU_H
#define ORDENMENU_H

#include "Cliente.h"
#include "Trabajador.h"
#include "ItemMenu.h"
#include "Mesa.h"
#include <iostream>
#include <vector>

using namespace std;

class Orden
{
public:
    Orden(Cliente* cliente, Trabajador* trabajador, Mesa* mesa);

    // Getters
    Cliente* getCliente() const;
    Trabajador* getTrabajador() const;
    Mesa* getMesa() const;
    size_t getItemsN() const;
    string getEspecificaciones() const;
    double getTotal() const;

    // Setters
    void setCliente(Cliente* cliente);
    void setTrabajador(Trabajador* trabajador);
    void setMesa(Mesa* mesa);
    void setItemsN();
    void setEspecificaciones(string& especificaciones);
    void setTotal();

    // Displays
    void displayOrden() const;
    void displayRecibo() const;

    // Metodos para añadir y eliminar objetos ItemMenu a la orden
    void addItemMenu(const ItemMenu& itemMenu);
    void removeItemMenu(const ItemMenu& itemMenu);

    ~Orden(); // Destructor

private:
    Cliente* cliente;
    Trabajador* trabajador;
    Mesa* mesa;
    vector<ItemMenu> orden;
    size_t itemsN;
    string especificaciones;
    double total;
    unsigned int IDorden;
    static unsigned int ultimoIDorden;
};

#endif // ORDENMENU_H
