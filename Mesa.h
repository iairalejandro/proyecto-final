// Mesa.h

#ifndef MESA_H
#define MESA_H

#include "Trabajador.h"
#include "Orden.h"

class Mesa 
{
  private:
    int numero;
    int capacidad;
    bool disponible;
    Trabajador mesero;

  public:
    Mesa(int numero, int capacidad, bool disponible, const Trabajador& mesero);


    // Setters

    void setNumero(int numero);
    void setCapacidad(int capacidad);
    void setDisponible(bool disponible);
    void setMesero(const Trabajador& mesero);


    // Getters

    bool getDisponible() const;
    int getCapacidad() const;
    int getNumero() const;
    Trabajador getMesero() const;


    // Display

    void display() const;
};

#endif
