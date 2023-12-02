// OrdenMenu.cpp

#include "Orden.h"
#include <iostream>
#include <algorithm>


using namespace std;

unsigned int Orden::ultimoIDorden = 0;

// Constructor
Orden::Orden(Cliente* cliente, Trabajador* trabajador, Mesa* mesa)
    : cliente(cliente), trabajador(trabajador), mesa(mesa), IDorden(++ultimoIDorden) {}

// Getter methods
Cliente* Orden::getCliente() const
{
    return cliente;
}

Trabajador* Orden::getTrabajador() const
{
    return trabajador;
}

Mesa* Orden::getMesa() const
{
    return mesa;
}

size_t Orden::getItemsN() const
{
    return itemsN;
}

string Orden::getEspecificaciones() const
{
    return especificaciones;
}

double Orden::getTotal() const
{
    return total;
}

// Setter methods
void Orden::setCliente(Cliente* cliente)
{
    this->cliente = cliente;
}

void Orden::setTrabajador(Trabajador* trabajador)
{
    this->trabajador = trabajador;
}

void Orden::setMesa(Mesa* mesa)
{
    this->mesa = mesa;
}

void Orden::setItemsN()
{
    this->itemsN = orden.size();
}

void Orden::setEspecificaciones(string& especificaciones)
{
    this->especificaciones = especificaciones;
}

void Orden::setTotal()
{
    for (const auto& itemMenu : orden)
    {
        this->total += itemMenu.getPrecio();
    }
}

// Displays
void Orden::displayOrden() const
{
    cout << "Orden:" << IDorden << endl;
    cout << "Item Menus:" << endl;
    for (const auto& itemMenu : orden)
    {
        cout << itemMenu.getNombre() << ", ";
    }
    cout << "Especificaciones: " << especificaciones << endl;
    cout << "Mesa: " << mesa->getNumero() << endl;
}

void Orden::displayRecibo() const
{
    std::cout << "ID de Orden: " << IDorden << std::endl;
    std::cout << "Cliente: " << cliente->getNombres() << std::endl;
    std::cout << "Trabajador: " << trabajador->getNombres() << std::endl;
    std::cout << "Items de la Orden (" << itemsN << "):" << std::endl;
    for (const auto& itemMenu : orden)
    {
        std::cout << itemMenu.getNombre() << " , ";
    }
    cout << "Precio Total: " << total << endl;
    cout << "Mesa: " << mesa->getNumero() << endl;
}

// Metodos para añadir y eliminar objetos ItemMenu a la orden
void Orden::addItemMenu(const ItemMenu& itemMenu)
{
    orden.push_back(itemMenu);
}

void Orden::removeItemMenu(const ItemMenu& itemMenu)
{
    auto it = std::find(orden.begin(), orden.end(), itemMenu);
    if (it != orden.end())
    {
        orden.erase(it);
    }
}

// Destructor
Orden::~Orden()
{}
