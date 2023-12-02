// Inventario.h

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include "Ingrediente.h"

#include <vector>
#include <fstream>


class Inventario 
{
  private:
    std::vector<Item> restaurante;
    std::vector<Item> items;
    std::vector<Ingrediente> ingredientes;
    unsigned int inventarioN;
    unsigned int itemsN;
    unsigned int ingredientesN;

  public:
    Inventario (); // Constructor sin argumentos
    Inventario (const std::vector<Item>& restaurante, const std::vector<Item>& items, const std::vector<Ingrediente>& ingredientes, unsigned int& restauranteN, unsigned int itemsN, unsigned int ingredientesN); 

    void remove();
    Item* findByID(unsigned int& ID) const;
    std::vector<Item*> findByNombre (const std::string& nombre) const;
    std::vector<Item*> findByProv(const std::string& proveedor) const;
    std::vector<Item*> findByIngreso(const Fecha& ingreso) const;
    std::vector<Ingrediente*> findByCad(const Fecha& caducidad) const;
    unsigned int getN() const;
    unsigned int getStock(const std::string& nombre) const;
    void addItemRestaurante(const Item& restaurante);
    void addItem(const Item& item);
    void setItemsN(const std::vector<Item>& items);
    void setIngredientesN(const std::vector<Ingrediente>& ingredientes);
    void setN (unsigned int& itemsN, unsigned int& ingredientesN);
};

#endif // INVENTARIO_H

