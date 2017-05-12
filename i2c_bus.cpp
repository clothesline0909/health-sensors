#include "i2c_bus.h"
#include "ti/drivers/I2C.h"

using namespace std;

/**
  Public methods of the I2CBus class.
*/

I2CBus::I2CBus(I2CConfiguration* config, int index) : config(config), index(index) {}

void I2CBus::open() {
  int transfer_mode = this->config->get_transfer_mode();
  int bit_rate = this->config->get_bit_rate();

  // Create the I2C_Params object for compatibility.
  I2C_Params i2c_params = {
    transferMode: static_cast<I2C_TransferMode>(transfer_mode),
    bitRate: static_cast<I2C_BitRate>(bit_rate)
  };

  // Set I2C_Params defaults.
  I2C_Params_init(&i2c_params);

  // Get a handle to the I2C bus.
  this->handle = I2C_open(this->index, &i2c_params);
}

void I2CBus::close() {
    I2C_close(this->handle);
}

I2C_Handle I2CBus::get_handle() {
  return this->handle;
}
