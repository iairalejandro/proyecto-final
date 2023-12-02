// Main.h
#ifndef MAIN_H
#define MAIN_H

#include "Fecha.h"
#include "Item.h"
#include "Ingrediente.h"
#include "Inventario.h"
#include "Menu.h"
#include "ItemMenu.h"
#include "Mesa.h"
#include "Cliente.h"
#include "Trabajador.h"
#include "Persona.h"
#include "Orden.h"


using namespace std;

int main() {
  Fecha cumpleaños(17,12,2005);
  Fecha fechatomate(28,11,2023);
  Fecha caducidadtomate(02,12,2023);
  cumpleaños.display();

  Ingrediente tomate("tomate", 0000, 50, "Proveedor A", fechatomate , 10.5, 1.5, "7cm", 
    caducidadtomate);
  tomate.display();

  Trabajador Gabriel(02403021, "Gabriel Dagner", "Pérez Alvela", 995803022, 12, 12, 2005, "San 
    Petersburgo", "gabo", 000001, "cocinero", 1199, 40);
  Gabriel.display();
  
  Mesa Mesa5(5, 4, Gabriel);
  Mesa5.display();

  Cliente Adrian(02403023, "Adrian Gilberto", "Perez Juarez", 991883922, 22, 1, 1968,"Los manzanales", "adrian@ucsp.edu.pe", 0000004, 250);
  Adrian.display();

  OrdenMenu Orden1(Gabriel, Adrian, Mesa5, 000025) ;
  Orden1.diplay();

#endif // MAIN_H

