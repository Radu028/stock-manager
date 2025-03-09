class Material
{
   public:
    int getQuantity() const { return m_quantity; }
    void setQuantitys(int quantity) { m_quantity = quantity; }

   private:
    int m_id, m_quantity;
    float m_price;
    char m_name[10], m_description[10];
};