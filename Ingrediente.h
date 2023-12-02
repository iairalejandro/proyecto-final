// Ingrediente.h
#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include "Fecha.h"
#include "Item.h"
#include <string>

class Ingrediente : public Item
{
  private:
    std::string medida;
    Fecha caducidad;

  public:
    Ingrediente(); 
    Ingrediente(const std::string& nombre, unsigned int& IDitem, unsigned int& cantidad, const std::string& proveedor, const Fecha& ingreso, double& precio, double& precioU, const std::string& medida, const Fecha& caducidad); 

    // Setters

    void setMedida(const std::string& medida);
    void setCaducidad(const Fecha& caducidad);

    // Getters

    std::string getMedida() const;
    Fecha getCaducidad() const;

    // Display

    virtual void display() const override;

    // Delete

    void deleteIngrediente();

};

#endif // INGREDIENTE_H


