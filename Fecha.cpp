// Fecha.cpp

#include "Fecha.h"

std::vector<int>* Fecha::diasxmes = nullptr;
std::vector<int>* Fecha::diasxmesB = nullptr;

// Constructor con memoria dinamica
Fecha::Fecha(int Dia, int Mes, int Año) : dia(new int(1)), mes(new int(1)), año(new int(2000)) {
  if (!diasxmes) 
  {
    diasxmes = new std::vector<int>{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  }

  if (!diasxmesB) 
  {
    diasxmesB = new std::vector<int>{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  }

  // Validar
  setFecha(Dia, Mes, Año);
}

// Destructor 
Fecha::~Fecha() 
{
  delete dia;
  delete mes;
  delete año;
}

// Constructor copia
Fecha::Fecha(const Fecha& other) : dia(new int(other.getDia())), mes(new int(other.getMes())), año(new int(other.getAño())) {}

// Operador copia
Fecha& Fecha::operator=(const Fecha& other) 
{
  if (this != &other) 
  {
    // Copy data and release old memory
    *dia = other.getDia();
    *mes = other.getMes();
    *año = other.getAño();
  }
  return *this;
}

// Constructor Move
Fecha::Fecha(Fecha&& other) noexcept : dia(other.dia), mes(other.mes), año(other.año) 
{
  // Reset other object
  other.dia = nullptr;
  other.mes = nullptr;
  other.año = nullptr;
}

// Operador move
Fecha& Fecha::operator=(Fecha&& other) noexcept 
{
  if (this != &other) 
  {
    // Libera Memoria
    delete dia;
    delete mes;
    delete año;

    // Asigna datos y libera memoria 
    dia = other.dia;
    mes = other.mes;
    año = other.año;
    other.dia = nullptr;
    other.mes = nullptr;
    other.año = nullptr;
  }
  return *this;
}

// Operator de igualdad
bool Fecha::operator==(const Fecha& otra) const 
{
  return *dia == otra.getDia() && *mes == otra.getMes() && *año == otra.getAño();
}

// Año Bisiesto
bool Fecha::evaluarAñoBiciesto(int Año) 
{
  return Año % 4 == 0 && (Año % 100 != 0 || Año % 400 == 0);
}

void Fecha::setFecha(int Dia, int Mes, int Año) 
{
    bool esBisiesto = evaluarAñoBiciesto(Año);

    // Valida el mes
    if (Mes >= 1 && Mes <= 12) 
    {
      *mes = Mes;
    } 
    else 
    {
      std::cerr << "Mes invalido. Asignando mes por defecto." << std::endl;
      *mes = 1;
    }

    // Validar dependiendo del mes y del año
    if (esBisiesto && Dia >= 1 && Dia <= diasxmesB->at(*mes)) 
    {
      *dia = Dia;
    } 
    else if (!esBisiesto && Dia >= 1 && Dia <= diasxmes->at(*mes)) 
    {
      *dia = Dia;
    } 
    else 
    {
      std::cerr << "Dia invalido. Asignando dia por defecto" << std::endl;
      *dia = 1;
    }

    // Valida el año
    if (Año >= 1) 
    {
      *año = Año;
    } 
    else 
    {
      std::cerr << "Año invalido. Asignando año por defecto" << std::endl;
      *año = 2000;
    }
}

// Getters
int Fecha::getDia() const 
{
  return *dia;
}

int Fecha::getMes() const 
{
  return *mes;
}

int Fecha::getAño() const 
{
  return *año;
}

// Display
void Fecha::display() const 
{
  std::cout << "Fecha: " << *dia << "/" << *mes << "/" << *año << std::endl;
}
