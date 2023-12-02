// Trabajador.cpp

#include "Trabajador.h"

unsigned int Trabajador::ultimoIDt = 0;

Trabajador::Trabajador(unsigned int* dni, std::string* nombres, std::string* apellidos, unsigned int* telefono, int* dia, int* mes, int* anio, std::string* direccion, std::string* email, unsigned int id, std::string* puesto, double* tarifa, double* horas)
  : Persona(dni, std::move(nombres), std::move(apellidos), telefono, dia, mes, anio, std::move(direccion), std::move(email)), id(++ultimoIDt) 
{
  // Asigna memoria para cadenas y punteros dobles
  this -> puesto = new std::string(std::move(*puesto));
  this -> tarifa = new double(*tarifa);
  this -> horas = new double(*horas);
}

Trabajador::~Trabajador() 
{
  // Desasignar memoria para cadenas y punteros dobles
  delete puesto;
  delete tarifa;
  delete horas;
}

void Trabajador::display() const 
{
  // Utiliza el método de visualización de la clase base
  Persona::display();

  // Información adicional para Trabajador
  std::cout << "ID: " << id << std::endl;
  std::cout << "Puesto: " << *puesto << std::endl;
  std::cout << "Tarifa: " << *tarifa << std::endl;
  std::cout << "Horas: " << *horas << std::endl;
}
