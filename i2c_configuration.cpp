#include "i2c_configuration.h"
#include "iostream"

using namespace std;

I2CConfiguration::I2CConfiguration(int transfer_mode, int bit_rate) : transfer_mode(transfer_mode), bit_rate(bit_rate) {}