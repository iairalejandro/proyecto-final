// Inventario.cpp

#include <vector>

#include "Inventario.h"

#include <fstream>

Inventario::Inventario (const std::vector<Item>& restaurante, const std::vector<Item>& items, const std::vector<Ingrediente>& ingredientes, unsigned int& inventarioN, unsigned int itemsN, unsigned int ingredientesN)
  : restaurante(restaurante), items(items), ingredientes(ingredientes), inventarioN(inventarioN), itemsN(itemsN), ingredientesN(ingredientesN) {}

void Inventario::remove() 
{

  // Eliminar un elemento del vector de restaurantes (solo un ejemplo)
    if (!restaurante.empty()) 
    {
      restaurante.erase(restaurante.begin());  // Elimina el primer elemento
    }

    // Eliminar un elemento del vector de items (solo un ejemplo)
    if (!items.empty()) 
    {
      items.erase(items.begin());  // Elimina el primer elemento
    }

    // Eliminar un elemento del vector de ingredientes (solo un ejemplo)
    if (!ingredientes.empty()) 
    {
      ingredientes.erase(ingredientes.begin());  // Elimina el primer elemento
    }
}

Item* Inventario::findByID (unsigned int& ID) const 
{
  for (const Item& item : restaurante) 
  {
    if (item.getIDitem() == ID) 
    {
      return const_cast<Item*>(&item);  // Devuelve un puntero no constante para permitir modificaciones
    }
  }

  return nullptr;
}

std::vector<Item*> Inventario::findByNombre(const std::string& nombre) const 
{
 std::vector<Item*> temporalItems;

 for (const Item& item : restaurante) 
 {
    if (item.getNombre() == nombre) 
    {
      temporalItems.push_back(const_cast<Item*>(&item));
    }
 }

 return temporalItems;
}

std::vector<Item*> Inventario::findByProv(const std::string& proveedor) const 
{
  std::vector<Item*> temporalItems;
  
  for (const Item& item : restaurante) 
  {
    if (item.getProveedor() == proveedor) 
    {
      temporalItems.push_back(const_cast<Item*>(&item));
    }
  }

  return temporalItems;
}

std::vector<Item*> Inventario::findByIngreso(const Fecha& ingreso) const 
{
  std::vector<Item*> temporalItems;
  
  for (const Item& item : restaurante) 
  {
    if (item.getIngreso() == ingreso) 
    {
      temporalItems.push_back(const_cast<Item*>(&item));
    }
  }

  return temporalItems;
}

std::vector<Ingrediente*> Inventario::findByCad(const Fecha& caducidad) const 
{
  std::vector<Ingrediente*> temporalIngredientes;

  for (const Ingrediente& ingrediente : restaurante) 
  {
    if (ingrediente.getCaducidad() == caducidad) 
    {
      temporalIngredientes.push_back(const_cast<Ingrediente*>(&ingrediente));
    }
  }

  return temporalIngredientes;
}

void Inventario::addItemRestaurante(const Item& item) 
{
  // Agrega un item al inventario del restaurante
  restaurante.push_back(item);
}

void Inventario::addItem(const Item& item) 
{
  // Agrega un item al inventario exclusivo de items
  items.push_back(item);
}

void Inventario::setItemsN (const std::vector<Item>& items)
{
  this->itemsN = items.size();
}

void Inventario::setIngredientesN (const std::vector<Ingrediente>& ingredientes)
{
  this->ingredientesN = ingredientes.size();
}

void Inventario::setN (unsigned int& itemsN, unsigned int& ingredientesN)
{
  this->inventarioN = itemsN + ingredientesN;
}

unsigned int Inventario::getN() const 
{
  return inventarioN;
}

unsigned int Inventario::getStock(const std::string& nombre) const 
{
 unsigned int stockTotal = 0;

  std::vector<Item> temporalItems;
  for (const auto& itemPtr : findByNombre(nombre)) 
  {
    temporalItems.push_back(*itemPtr);
  }

 for (const Item& item : temporalItems) 
 {
  stockTotal += item.getCantidad();
 }

 return stockTotal;
}


