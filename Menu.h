// Menu.h
#include <iostream>

// ...

void Menu::addMenuItem(const ItemMenu& item, const std::string& category) 
{
    // ... Agregar la lógica para agregar el elemento al menú en la categoría especificada
    for (auto& menuCategory : fullMenu) 
    {
        if (menuCategory.getCategory() == category) 
        {
            menuCategory.addItem(item);
            break;
        }
    }
}

void Menu::removeMenuItem(const std::string& itemName, const std::string& category) 
{
    // ... Agregar la lógica para eliminar el elemento del menú en la categoría especificada
    for (auto& menuCategory : fullMenu) 
    {
        if (menuCategory.getCategory() == category) 
        {
            menuCategory.removeItem(itemName);
            break;
        }
    }
}

void Menu::display() const 
{
    std::cout << "Menu:" << std::endl;
    for (const auto& menuCategory : fullMenu) 
    {
        std::cout << menuCategory.getCategory() << ":" << std::endl;
        for (const auto& item : menuCategory.getItems()) 
        {
            std::cout << item.getName() << " - " << item.getDescription() << " - $" << item.getPrecio() << std::endl;
        }
    }
}