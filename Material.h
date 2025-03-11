#pragma once
#include <string>

// It represents a material in a warehouse management system.
class Material
{
   public:
    // Constructor
    Material(const std::string& name) { m_name = name; }

    // Get the quantity of material
    int getQuantity() const { return m_quantity; }

    // Set the quantity of material
    void setQuantity(int quantity) { m_quantity = quantity; }

    void addQuantity(int value) { m_quantity += value; }
    void subtractQuatity(int value)
    {
        if (m_quantity < value)
        {
            return;
        }

        m_quantity -= value;
    }

   private:
    int m_id;                   // The ID of the material
    int m_quantity;             // The quantity of material in stock
    float m_price;              // The price of the material
    std::string m_name;         // The name of the material
    std::string m_description;  // The description of the material
};