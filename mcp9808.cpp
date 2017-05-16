#include "mcp9808.h"

const int MCP9808::TEMP_REGISTER = 0x05;

MCP9808::MCP9808(I2CBus* bus, int address, double constant) : I2CSensor(bus, address), constant(constant) {}

double MCP9808::get_reading() {
  uint8_t         txBuffer[1];
  uint8_t         rxBuffer[2];

  // Create I2C Transaction.
  I2C_Transaction i2c_transaction;
  txBuffer[0] = MCP9808::TEMP_REGISTER;
  i2c_transaction.slaveAddress = this->get_address();
  i2c_transaction.writeBuf = txBuffer;
  i2c_transaction.writeCount = 1;
  i2c_transaction.readBuf = rxBuffer;
  i2c_transaction.readCount = 2;

  I2C_Handle handle = this->get_bus()->get_handle();

  I2C_transfer(handle, &i2c_transaction);

  double temperature = ((rxBuffer[0] & ~(7 << 5)) << 8) | (rxBuffer[1]);

  temperature /= 16;

  return temperature;
}
