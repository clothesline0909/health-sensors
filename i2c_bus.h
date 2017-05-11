/**
  i2c_bus.h
  Purpose: Represents an I2C bus.

  @author Brett Clark
  @version 1.0
  @date 3/5/2017
*/

#ifndef _I2C_BUS_H_
#define _I2C_BUS_H_

#include "i2c_configuration.h"
#include "ti/drivers/I2C.h"

/**
  I2CBus class.

  This describes the I2C configuration.
*/
class I2CBus {

/**
  Public members of the I2CBus class.
*/
public:

  /**
    I2CBus constructor.

    @param config The I2CConfiguration used by the bus.
    @param index The index of the I2C bus on the board.
    @return The I2CBus object.
  */
  I2CBus(I2CConfiguration config, int index);

  /**
    Function that opens the I2C bus.
  */
  void open(void);

  /**
    Function that closes the I2C bus.
  */
  void close(void);

  /**
    Function that returns a handle to the open I2C bus. Must be called after the I2C_Bus::open method.

    @return The I2C_Handle.
  */
  I2C_Handle get_handle(void);

/**
  Private members of the I2CBus class.
*/
private:

  /**
    Member variables of the I2CBus class.
  */

  /**
    The I2C configuration for the bus.
  */
  I2CConfiguration config;

  /**
    The index of the IC bus on the board.
  */
  int index;

  /**
    The handle to the open I2C bus.
  */
  I2C_Handle handle;
};

#endif // _I2C_BUS_H_
