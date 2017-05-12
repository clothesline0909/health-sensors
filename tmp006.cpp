#include "tmp006.h"
#include "cmath"
#include "iostream"

using namespace std;

/**
  Constants of the TMP006 class.
*/

static const int SENSOR_VOLTAGE_REGISTER = 0x00;
static const int DIE_TEMP_REGISTER = 0x01;
static const int CONFIG_REGISTER = 0x02;

/**
  Public methods of the TMP006 class.
*/

TMP006::TMP006(I2CBus* bus, int address, double constant) : I2CSensor(bus, address), constant(constant) {}

double TMP006::get_reading(void) {
  //double sensor_voltage = get_sensor_voltage();
  double die_temperature = get_die_temperature();

  //double object_temp = get_object_temperature(sensor_voltage, die_temperature);

  //return object_temp;
  return die_temperature;
}

/**
  Private methods of the TMP006 class.
*/

double TMP006::get_sensor_voltage(void) {
  return 3.5;
}

double TMP006::get_die_temperature(void) {
  uint8_t         txBuffer[1];
  uint8_t         rxBuffer[2];

  // Create I2C Transaction.
  I2C_Transaction i2c_transaction;
  txBuffer[0] = 0x01;
  i2c_transaction.slaveAddress = this->get_address();
  i2c_transaction.writeBuf = txBuffer;
  i2c_transaction.writeCount = 1;
  i2c_transaction.readBuf = rxBuffer;
  i2c_transaction.readCount = 2;

  I2C_Handle handle = this->get_bus()->get_handle();

  I2C_transfer(handle, &i2c_transaction);

  double temperature = (rxBuffer[0] << 6) | (rxBuffer[1] >> 2);

  temperature /= 32;

  return temperature;
}

double TMP006::get_object_temperature(double sensor_voltage, double die_temperature) {
  double object_temp_power_4 = pow(die_temperature, 4) + (sensor_voltage / this->constant);

  // Handle negative reading.
  if (object_temp_power_4 < 0) {
    return NULL;
  }

  return pow(object_temp_power_4, 1.0 / 4);
}
