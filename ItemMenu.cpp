// ItemMenu.cpp

#include "ItemMenu.h"
#include <iostream>

ItemMenu::ItemMenu() : nombre(""), descripcion(""), precio(0.0) {}

ItemMenu::ItemMenu (const std::string& nombre, const std::string& descripcion, double& precio, const std::vector<Ingrediente>& ingredientes)
  : nombre(nombre), descripcion(descripcion), precio(precio), ingredientes(ingredientes) {}

std::string ItemMenu::getNombre() const 
{
  return nombre;
}

void ItemMenu::setNombre(const std::string& nombre) 
{
  this->nombre = nombre;
}

std::string ItemMenu::getDescripcion() const 
{
  return descripcion;
}

void ItemMenu::setDescripcion(const std::string& descripcion) 
{
  this->descripcion = descripcion;
}

double ItemMenu::getPrecio() const 
{
  return precio;
}

void ItemMenu::setPrecio(double& precio) 
{
  this->precio = precio;
}

void ItemMenu::addIngrediente(const Ingrediente& ingrediente) 
{
  ingredientes.push_back(ingrediente);
}

void ItemMenu::removeIngrediente(const std::string& nombreIngrediente) 
{
  // Implementar la lógica para eliminar un ingrediente del vector
  // Puedes usar std::remove_if y un lambda para esto.
}

void ItemMenu::display() const 
{
  std::cout << "ItemMenu - Nombre: " << nombre << std::endl;
  std::cout << "Descripcion: " << descripcion << std::endl;
  std::cout << "Precio: " << precio << std::endl;
  std::cout << "Ingredientes:" << std::endl;
  
  for (const auto& ingrediente : ingredientes) 
  {
    std::cout << ingrediente.getNombre();
  }
}

void ItemMenu::deleteItemMenu() 
{
  std::cout << "Eliminando el ItemMenu: " << nombre << std::endl;
}
