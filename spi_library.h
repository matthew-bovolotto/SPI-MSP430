#define SERIAL

class spi_Master{
  public: 
    spi_Master();
    void spi_Master_Setup();
    void spiSend_u16(unsigned int spi_data_out);
};

class spi_Slave{
  public:
    spi_Slave();
    void spi_Slave_Setup();
    unsigned int spiReceive_u16();
};
