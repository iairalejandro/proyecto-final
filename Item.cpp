// Item.cpp

#include "Item.h"
#include <iostream>
#include <fstream>




Item::Item(const std::string& nombre, unsigned int& IDitem, unsigned int& cantidad, 
const std::string& proveedor, const Fecha& ingreso, double& precio, double& precioU)
  : nombre(nombre), IDitem(IDitem), cantidad(cantidad), proveedor(proveedor), 
ingreso(ingreso), precio(precio)
{
  if (cantidad > 0) 
  {
    precioU = precio / cantidad;
  } 
  else 
  {
    std::cout << "Cantidad < a 0." << std::endl ;
  }
}


// Setters

void Item::setNombre(const std::string& nombre) 
{
  this -> nombre = nombre;
}

void Item::setIDitem(unsigned int& IDitem) 
{
  this -> IDitem = IDitem;
}

void Item::setCantidad(unsigned int& cantidad) 
{
  this -> cantidad = cantidad;
}

void Item::setProveedor(const std::string& proveedor) 
{
  this -> proveedor = proveedor;
}

void Item::setPrecio(double& precio) 
{
  this -> precio = precio;
}

void Item::setPrecioU (double& precioU) 
{
  this -> precioU = precioU;
}

void Item:: saveseters():
{
  std::ofstream archivo("Item.txt");
  if(archivo,is_open()){
    archivo << nombre << std::endl;
    archivo << IDitem << std::endl;
    archivo << cantidad << std::endl;
    archivo << proveedor << std::endl;
    archivo << ingreso << std::endl;
    archivo << precio << std::endl;
    archivo << precioU << std::endl;
    archivo.close();
    std::cout << "Archivo guardado" << std::endl;
  }
  else
  {
    std::cout << "Error al abrir el archivo" << std::endl;  
  }
}

// Getters

std::string Item::getNombre() const 
{
  return nombre;
}
unsigned int Item::getIDitem() const 
{
  return IDitem;
}

unsigned int Item::getCantidad() const 
{
  return cantidad;
}

std::string Item::getProveedor() const 
{
  return proveedor;
}

Fecha Item::getIngreso() const 
{
  return ingreso;
}

double Item::getPrecio() const 
{
  return precio;
}

double Item::getPrecioU() const 
{
  return precioU;
}


//Display

void Item::display() const 
{
  std::cout << "Item ID: " << IDitem << std::endl;
  std::cout << "Nombre: " << nombre << std::endl;
  std::cout << "Cantidad: " << cantidad << std::endl;
  std::cout << "Proveedor: " << proveedor << std::endl;
  std::cout << "Ingreso: ";
  ingreso.display();  
  std::cout << std::endl;
}


// Add

void Item::addCantidad(unsigned int& cantidad) 
{
  this -> cantidad += cantidad;
  
  this -> precioU = precio / cantidad;

  std::ofstream archivo("miArchivo.txt");

  if (archivo.is_open()) {

      archivo << cantidad << std::endl;

      archivo.close();

      std::cout << "La variable se ha guardado en el archivo." << std::endl;

  } else {
      std::cerr << "No se pudo abrir el archivo." << std::endl;
  }
}


// Substract

void Item::subsCantidad(unsigned int& cantidad) 
{
  if (this -> cantidad >= cantidad) 
  {
    this -> cantidad -= cantidad;
  } else 
  {
    std::cout << "No hay cantidad suficiente." << std::endl;
  }

  this -> precioU = precio / cantidad;
}


// Validar

bool Item::validar() const 
{
  return cantidad > 0 && precio > 0;
}

Item& Item::operator=(const Item& other) 
{
  if (this != &other) 
  {
    // copy data members from other to this
    this -> nombre = other.nombre;
    this -> precio = other.precio;
    this -> cantidad = other.cantidad;
    this -> proveedor = other.proveedor;
    this -> ingreso = other.ingreso;
    this -> precioU = other.precioU;
  }
  return *this;
}

void Item::deleteItem() 
{
  std::cout << "Eliminando el item: " << nombre << std::endl;
  // Puedes realizar acciones adicionales de eliminación aquí
}


