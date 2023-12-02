// Persona.h

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

#include "Fecha.h"

class Persona 
{
  public:
    Persona(unsigned int* dni, std::string* nombres, std::string* apellidos, unsigned int* telefono, int* dia, int* mes, int* anio, std::string* direccion, std::string* email);

    virtual ~Persona();  // Destructor for proper memory cleanup

    // Getter methods
    unsigned int getDni() const;
    std::string getNombres() const;
    std::string getApellidos() const;
    unsigned int getTelefono() const;
    std::string getDireccion() const;
    std::string getEmail() const;

    // Setter methods
    void setDni(unsigned int* dni);
    void setNombres( std::string* nombres);
    void setApellidos(std::string* apellidos);
    void setTelefono(unsigned int* telefono);
    void setDireccion(std::string* direccion);
    void setEmail(std::string* email);

    // Display
    void display() const;

  private:
    unsigned int* dni;
    std::string* nombres;
    std::string* apellidos;
    unsigned int* telefono;
    Fecha* cumpleanos;
    std::string* direccion;
    std::string* email;
};

#endif // PERSONA_H
