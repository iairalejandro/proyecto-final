// Cliente.h

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>

#include "Fecha.h"
#include "Orden.h"
#include "Persona.h"

class Orden;

class Cliente : public Persona
{
private:
    unsigned int idMiembro;
    unsigned int puntos;
    std::string* categoria;
    static unsigned int ultimoIdMiembro;

    std::vector<Orden>* ordenes;

public:
    Cliente(unsigned int* dni, std::string* nombres, std::string* apellidos, unsigned int* telefono,
    int* dia, int* mes, int* anio, std::string* direccion, std::string* email, unsigned int idMiembro, unsigned int puntos);

    ~Cliente(); // Destructor para desasignar memoria para punteros

    unsigned int getIdMiembro() const;
    unsigned int getPuntos() const;
    std::string getCategoria() const;

    void setDireccion(const std::string& direccion);
    void agregarPuntos(unsigned int puntos);
    void establecerCategoria();

    void addOrden(const Orden& OrdenMenu);
    void removeOrden(const Orden& OrdenMenu);

    void display();
};

#endif // CLIENTE_H
