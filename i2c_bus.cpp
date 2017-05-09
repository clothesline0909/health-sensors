#include "i2c_bus.h"
#include "ti/drivers/I2C.h"

using namespace std;

/**
  Public methods of the I2CBus class.
*/

I2CBus::I2CBus(I2CConfiguration config, int index) : config(config), index(index) {}

void I2CBus::open() {
  // Create the I2C_Params object for compatibility.
  I2C_Params i2c_params = {
    transferMode: this->config.get_transfer_mode(),
    bitRate: this->config.get_bit_rate()
  };

  // Set I2C_Params defaults.
  I2C_Params_init(&i2c_params);

  // Get a handle to the I2C bus.
  I2C_Handle bus_handle = I2C_Open(this->index, &i2c_params);
}
