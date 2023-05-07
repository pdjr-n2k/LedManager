/**********************************************************************
 * LedManager.h - manage an arbitrary number of virtual LEDs.
 * 2020 (c) Paul Reeve <preeve@pdjr.eu>
 */

#ifndef LEDMANAGER_H
#define LEDMANAGER_H

/**
 * @brief Class providing the logic for operating one or more virtual
 * LEDs.
 *
 * LedManager relieves a host application from implementing the logic
 * required to switch on, switch off, flash and apply patterns to
 * multiple virtual LED-type devices.
 * 
 * A callback function in the host application is invoked at a
 * configured interval with the current virtual LED states as its
 * argument: it is the responsibility of the callback function to
 * perform the actions necessary to drive connected physical devices
 * so that they reflect the virtual states notified by LedManager.
 */
class LedManager {

  public:
    /**
     * @brief Maximum number of LEDs to be controlled.
     *
     * LED state is output as an unsigned integer, so this value has a
     * maximum equal to the number of bits in an integer on the host
     * platform.
     */
    static const unsigned int LED_COUNT = 16;

    /**
     * @brief Enum defining possible LED control modes.
     */
    enum Mode {
      /// Steady state on
      ON,
      /// Isophase flashing (start on)
      FLASH,
      /// Flash once
      ONCE,
      ///Flash twice
      TWICE,
      /// Flash three times
      THRICE,
      /// Steady state off
      OFF,
      /// Internal use
      FLASH_OFF,
      /// Internal use
      TWICE_OFF,
      /// Internal use
      THRICE_OFF
    };

    /**
     * @param callback - function to operate a physical output device.
     * @param interval - equiphase heartbeat interval in milliseconds.
     *
     * @brief Construct a new LedManager instance.
     * 
     * Instantiates a new control group with the state of all LEDs
     * initialised to OFF.
     * 
     * Every @ref interval milliseconds the @ref callback function is
     * invoked with its @ref status argument set to represent the
     * current state of the control group: a 0 bit value says 'off'; a
     * 1 bit value says 'on'.
     */
    LedManager(void (*callback)(unsigned int status), unsigned long interval = 200);

    /**
     * @param status - Set the LedManager::Mode of the LED group.
     *
     * @brief Set the Mode of each LED in the contro group to ON or
     * OFF. 
     * 
     * If a bit in @ref is 1, the corresponding LED Mode is set ON; a 0
     * bit sets the corresponding LED Mode to OFF.
     */
    void setStatus(unsigned int status);

    /**
     * @param led - index of the LED to be updated.
     * @param mode - the Mode to be assigned.
     * 
     * @brief Set the state of particular LED.
     */
    void setLedState(unsigned int led, LedManager::Mode mode);
    
    /**
     * @brief Perform a mode transition on all LEDs in the control
     * group at the specified update interval.
     * 
     * This method should be called from the host loop().
     */
    void update();

  private:
    void (*callback)(unsigned int status);
    unsigned int interval;
    int *modes;
    unsigned long deadline;
};

#endif
