// Item.h
#ifndef ITEM_H
#define ITEM_H

#include "Fecha.h"
#include <string>


class Item 
{
  private:
    std::string nombre;
    unsigned int IDitem;
    unsigned int cantidad;
    std::string proveedor;
    Fecha ingreso;
    double precio;
    double precioU;

  public:
    Item(const std::string& nombre, unsigned int& IDitem, unsigned int& cantidad, const std::string& proveedor, const Fecha& ingreso, double& precio, double& precioU); 

    // Setters

    void setNombre(const std::string& nombre);
    void setIDitem(unsigned int& IDitem);
    void setCantidad(unsigned int& cantidad);
    void setProveedor(const std::string& proveedor);
    void setIngreso(const Fecha& ingreso);
    void setPrecio(double& precio);
    void setPrecioU(double& precioU);

    // Getters

    std::string getNombre() const;
    unsigned int getIDitem() const;
    unsigned int getCantidad() const;
    std::string getProveedor() const;
    Fecha getIngreso() const;
    double getPrecio() const;
    double getPrecioU() const;

    // Display

    virtual void display() const;

    // Add y Substract

    void addCantidad(unsigned int& cantidad);
    void subsCantidad(unsigned int& cantidad);

    // Validar

    bool validar() const;

    // 
    Item& operator=(const Item& other);
    void deleteItem();
};

#endif // ITEM_H

