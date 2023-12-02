// Cliente.cpp

#include <algorithm>
#include "Cliente.h"

unsigned int Cliente::ultimoIdMiembro = 0;

Cliente::Cliente(unsigned int* dni, std::string* nombres, std::string* apellidos, unsigned int* telefono, int* dia, int* mes, int* anio, std::string* direccion, std::string* email, unsigned int idMiembro, unsigned int puntos)
  : Persona(dni, nombres, apellidos, telefono, dia, mes, anio, direccion, email), idMiembro(++ultimoIdMiembro), puntos(0)
{
  categoria = new std::string();
  ordenes = new std::vector<Orden>();
}

Cliente::~Cliente()
{
  // Desasignar memoria para punteros
  delete categoria;
  delete ordenes;
}

unsigned int Cliente::getIdMiembro() const
{
    return idMiembro;
}

unsigned int Cliente::getPuntos() const
{
    return puntos;
}

std::string Cliente::getCategoria() const
{
    return *categoria;
}

void Cliente::agregarPuntos(unsigned int puntos)
{
    this->puntos += puntos;
    establecerCategoria();
}

void Cliente::establecerCategoria()
{
  // Lógica para establecer la categoría según la cantidad de puntos

}

void Cliente::addOrden(const Orden& OrdenMenu)
{
  ordenes->push_back(OrdenMenu);
}

void Cliente::removeOrden(const Orden& OrdenMenu)
{
  auto it = std::find(ordenes->begin(), ordenes->end(), OrdenMenu);
  if (it != ordenes->end())
  {
    ordenes->erase(it);
  }
}

void Cliente::display()
{
    // Mostrar información del cliente
    std::cout << "ID Miembro: " << idMiembro << std::endl;
    std::cout << "Puntos: " << puntos << std::endl;
    std::cout << "Categoría: " << *categoria << std::endl;
}
