// Trabajador.h

#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include "Persona.h"

class Trabajador : public Persona 
{
  public:
    Trabajador(unsigned int* dni, std::string* nombres, std::string* apellidos, unsigned int* telefono, int* dia, int* mes, int* anio, std::string* direccion, std::string* email, unsigned int id, std::string* puesto, double* tarifa, double* horas);

    ~Trabajador(); 

     void display() const;

  private:
    unsigned int id;
    std::string* puesto;
    double* tarifa;
    double* horas;
    static unsigned int ultimoIDt;
};

#endif // TRABAJADOR_H
