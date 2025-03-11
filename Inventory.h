#pragma once
#include "Material.h"
#include "Operation.h"

#include <vector>

// This will be the "manager" class that handles the materials and operations
class Inventory
{
   public:
    // Add a new material to the inventory
    void addMaterial(const Material &material) { m_materials.push_back(material); }

   private:
    std::vector<Material> m_materials;    // List of materials in the inventory
    std::vector<Operation> m_operations;  // List of operations performed on the materials
};