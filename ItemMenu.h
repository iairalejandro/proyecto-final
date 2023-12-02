// ItemMenu.h
#ifndef ITEMMENU_H
#define ITEMMENU_H

#include "Ingrediente.h"
#include <string>
#include <vector>

class ItemMenu 
{
  private:
    std::string nombre;
    std::string descripcion;
    double precio;
    std::vector<Ingrediente> ingredientes;

  public:
    ItemMenu();
    ItemMenu(const std::string& nombre, const std::string& descripcion, double& precio, const std::vector<Ingrediente>& ingredientes);

    std::string getNombre() const;
    void setNombre(const std::string& nombre);
    std::string getDescripcion() const;
    void setDescripcion(const std::string& descripcion);
    double getPrecio() const;
    void setPrecio(double& precio);

    void addIngrediente(const Ingrediente& ingrediente);
    void removeIngrediente(const std::string& nombreIngrediente);

    void display() const;
    void deleteItemMenu();
};

#endif // ITEMMENU_H
