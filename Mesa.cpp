// Mesa.cpp

#include "Mesa.h"
#include <iostream>

Mesa::Mesa(int numero, int capacidad, bool disponible, const Trabajador& mesero)
  : numero(numero), capacidad(capacidad), disponible(disponible), mesero(mesero) {}


// Setters

void Mesa::setNumero(int numero) 
{
  this -> numero = numero;
}

void Mesa::setCapacidad(int capacidad) 
{
  this -> capacidad = capacidad;
}

void Mesa::setDisponible(bool disponible) 
{
  this -> disponible = disponible;
}

void Mesa::setMesero(const Trabajador& mesero) 
{
  this -> mesero = mesero;
}


// Getters

int Mesa::getNumero() const 
{
  return numero;
}

int Mesa::getCapacidad() const 
{
  return capacidad;
}

bool Mesa::getDisponible() const 
{
  return disponible;
}

Trabajador Mesa::getMesero() const 
{
  return mesero;
}


// Display
void Mesa::display() const 
{
  std::cout << "Mesa : " << numero << std::endl;
  std::cout << "Capacidad: " << capacidad << std::endl;
  std::cout << "Disponible: " << (disponible ? "Sí" : "No") << std::endl;
  std::cout << "Mesero asignado: " << mesero.getNombres() << " " << mesero.getApellidos() << std::endl;
}
