// Persona.cpp

#include <string>
#include <iostream>

#include "Persona.h"

Persona::Persona(unsigned int* dni, std::string* nombres, std::string* apellidos, unsigned int* telefono, int* dia, int* mes, int* anio, std::string* direccion, std::string* email)
  : dni(new unsigned int(*dni)), nombres(new std::string(*nombres)), apellidos(new std::string(*apellidos)), telefono(new unsigned int(*telefono)), direccion(new std::string(*direccion)), email(new std::string(*email)) {
  cumpleanos = new Fecha(*dia, *mes, *anio);
}


// Getter methods
unsigned int Persona::getDni() const 
{
  return *dni;
}

std::string Persona::getNombres() const 
{
  return *nombres;
}

std::string Persona::getApellidos() const 
{
  return *apellidos;
}

unsigned int Persona::getTelefono() const 
{
  return *telefono;
}

std::string Persona::getDireccion() const 
{
  return *direccion;
}

std::string Persona::getEmail() const 
{
  return *email;
}

// Setter methods
void Persona::setDni (unsigned int* dni) 
{
  this -> dni = dni;
}

void Persona::setNombres (std::string* nombres) 
{
  this -> nombres = nombres;
}

void Persona::setApellidos (std::string* apellidos) 
{
  this -> apellidos = apellidos;
}

void Persona::setTelefono (unsigned int* telefono) 
{
  this -> telefono = telefono;
}

void Persona::setDireccion (std::string* direccion) 
{
  this -> direccion = direccion;
}

void Persona::setEmail (std::string* email) 
{
  this->email = email;
}

// Destructor
Persona::~Persona() 
{
  delete cumpleanos;

}

// Display method
void Persona::display() const 
{
  std::cout << "Persona Info:" << std::endl;
  std::cout << "DNI: " << getDni() << std::endl;
  std::cout << "Nombres: " << getNombres() << std::endl;
  std::cout << "Apellidos: " << getApellidos() << std::endl;
  std::cout << "Telefono: " << getTelefono() << std::endl;
  std::cout << "Cumpleanos: ";
  cumpleanos->display(); 
  std::cout << "Direccion: " << getDireccion() << std::endl;
  std::cout << "Email: " << getEmail() << std::endl;
}
