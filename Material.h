
// It represents a material in a warehouse management system.
class Material
{
   public:
    int getQuantity() const  // Get the quantity of material
    {
        return m_quantity;
    }
    void setQuantity(int quantity)  // Set the quantity of material
    {
        m_quantity = quantity;
    }

   private:
    int m_id;                // The ID of the material
    int m_quantity;          // The quantity of material in stock
    float m_price;           // The price of the material
    char m_name[10];         // The name of the material
    char m_description[10];  // The description of the material
};