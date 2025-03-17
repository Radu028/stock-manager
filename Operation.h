#pragma once
#include <string>

#include "Material.h"

enum OperationType
{
    IN,
    OUT
};

// This class represents an operation performed on a material in the inventory
class Operation
{
   public:
    void apply(Material &material)  // Apply the operation to the material
    {
        if (m_type == IN)
        {
            material.addQuantity(m_quantity);
        }
        else if (m_type == OUT)
        {
            material.subtractQuatity(m_quantity);
        }
    }

   private:
    // factura
    int m_materialId;      // The ID of the material involved in the operation
    int m_quantity;        // The quantity of material involved in the operation
    OperationType m_type;  // The type of operation (IN or OUT)
    std::string m_date;    // The date of the operation in the format YYYY-MM-DD
};