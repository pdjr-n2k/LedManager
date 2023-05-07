# class `LedManager` 

Class providing the logic for operating one or more virtual LEDs.

[LedManager](#classLedManager) relieves a host application from implementing the logic required to switch on, switch off, flash and apply patterns to multiple virtual LED-type devices.

A callback function in the host application is invoked at a configured interval with the current virtual LED states as its argument: it is the responsibility of the callback function to perform the actions necessary to drive connected physical devices so that they reflect the virtual states notified by [LedManager](#classLedManager).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`LedManager`](#classLedManager_1aadf9b05e96cb63a1dac4acf6e5447e87)`(void(*)(unsigned int status) callback,unsigned long interval)` | Construct a new [LedManager](#classLedManager) instance.
`public void `[`setStatus`](#classLedManager_1a82ccd1a568933b058f6b16e18e03e31e)`(unsigned int status)` | Set the Mode of each LED in the contro group to ON or OFF.
`public void `[`setLedState`](#classLedManager_1a9f0d7cdaa44dc0552b53b68cd6031d7e)`(unsigned int led,`[`LedManager::Mode`](#classLedManager_1a6f4de90d7619e5cb9b40ec23a1730ab0)` mode)` | Set the state of particular LED.
`public void `[`update`](#classLedManager_1ae549d2947bc00d5ebc85ed6e6b34c368)`()` | Perform a mode transition on all LEDs in the control group at the specified update interval.
`enum `[`Mode`](#classLedManager_1a6f4de90d7619e5cb9b40ec23a1730ab0) | Enum defining possible LED control modes.

## Members

#### `public  `[`LedManager`](#classLedManager_1aadf9b05e96cb63a1dac4acf6e5447e87)`(void(*)(unsigned int status) callback,unsigned long interval)` 

Construct a new [LedManager](#classLedManager) instance.

#### Parameters
* `callback` - function to operate a physical output device. 

* `interval` - equiphase heartbeat interval in milliseconds.

Instantiates a new control group with the state of all LEDs initialised to OFF.

Every interval milliseconds the callback function is invoked with its status argument set to represent the current state of the control group: a 0 bit value says 'off'; a 1 bit value says 'on'.

#### `public void `[`setStatus`](#classLedManager_1a82ccd1a568933b058f6b16e18e03e31e)`(unsigned int status)` 

Set the Mode of each LED in the contro group to ON or OFF.

#### Parameters
* `status` - Set the [LedManager::Mode](#classLedManager_1a6f4de90d7619e5cb9b40ec23a1730ab0) of the LED group.

If a bit in is 1, the corresponding LED Mode is set ON; a 0 bit sets the corresponding LED Mode to OFF.

#### `public void `[`setLedState`](#classLedManager_1a9f0d7cdaa44dc0552b53b68cd6031d7e)`(unsigned int led,`[`LedManager::Mode`](#classLedManager_1a6f4de90d7619e5cb9b40ec23a1730ab0)` mode)` 

Set the state of particular LED.

#### Parameters
* `led` - index of the LED to be updated. 

* `mode` - the Mode to be assigned.

#### `public void `[`update`](#classLedManager_1ae549d2947bc00d5ebc85ed6e6b34c368)`()` 

Perform a mode transition on all LEDs in the control group at the specified update interval.

This method should be called from the host loop().

#### `enum `[`Mode`](#classLedManager_1a6f4de90d7619e5cb9b40ec23a1730ab0) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
ON            | Steady state on.
FLASH            | Isophase flashing (start on)
ONCE            | Flash once.
TWICE            | Flash twice.
THRICE            | Flash three times.
OFF            | Steady state off.
FLASH_OFF            | Internal use.
TWICE_OFF            | Internal use.
THRICE_OFF            | Internal use.

Enum defining possible LED control modes.

Generated by [Moxygen](https://sourcey.com/moxygen)