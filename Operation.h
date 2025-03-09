#include "Material.h"

enum OperationType
{
    IN,
    OUT
};

class Operation
{
   public:
    void apply(Material &material)
    {
        if (m_type == IN)
        {
            material.setQuantitys(material.getQuantity() + m_quantity);
        }
        else if (m_type == OUT)
        {
            material.setQuantitys(material.getQuantity() - m_quantity);
        }
    }

   private:
    int m_materialId;      // The ID of the material involved in the operation
    int m_quantity;        // The quantity of material involved in the operation
    OperationType m_type;  // The type of operation (IN or OUT)
    char m_date[10];       // The date of the operation in the format YYYY-MM-DD
};