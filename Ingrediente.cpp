// Ingrediente.cpp

#include "Ingrediente.h"
#include <iostream>

Ingrediente::Ingrediente (const std::string& nombre, unsigned int& IDitem, unsigned int& cantidad, const std::string& proveedor, const Fecha& ingreso, 
double& precio, double& precioU, const std::string& medida, const Fecha& caducidad)
  : Item(nombre, IDitem, cantidad, proveedor, ingreso, precio, precioU), medida(medida), caducidad(caducidad) {}

// Setters

void Ingrediente::setMedida(const std::string& medida) 
{
  this -> medida = medida;
}

void Ingrediente::setCaducidad(const Fecha& caducidad) 
{
  this -> caducidad = caducidad;
}

// Getters

std::string Ingrediente::getMedida() const 
{
  return medida;
}

Fecha Ingrediente::getCaducidad() const 
{
  return caducidad;
}

void Ingrediente::display() const 
{
  Item::display();
  std::cout << "Medida: " << medida << std::endl;
  std::cout << "Caducidad: " ;
  caducidad.display() ;
  std::cout << std::endl;
}

void Ingrediente::deleteIngrediente() 
{
  std::cout << "Eliminando el ingrediente." << std::endl;
}
