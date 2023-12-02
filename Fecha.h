// Fecha.h

#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <vector>
#include <stdexcept>

class Fecha 
{
  private:
    int* dia;
    int* mes;
    int* año;

    // Punteros para manejar memoria dinamica
    static std::vector<int>* diasxmes;
    static std::vector<int>* diasxmesB;

  public:
    Fecha() : dia(new int(1)), mes(new int(1)), año(new int(2000)) {}

    // Constructor 
    Fecha(int Dia, int Mes, int Año);

    // Destructor para desasignar memoria
    ~Fecha();

    // Constructor copia
    Fecha(const Fecha& other);

    // Operador copia
    Fecha& operator=(const Fecha& other);

    // Move constructor
    Fecha(Fecha&& other) noexcept;

    // Move assignment operator
    Fecha& operator=(Fecha&& other) noexcept;

    // Equality operator
    bool operator==(const Fecha& otra) const;

    // Setters
    void setFecha(int Dia, int Mes, int Año);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAño() const;

    // Display
    void display() const;

    private:
    // Año Bisiesto
    bool evaluarAñoBiciesto(int Año);
};

#endif // FECHA_H
