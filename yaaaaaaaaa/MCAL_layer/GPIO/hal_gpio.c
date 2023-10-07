/*
 * hal_gpio.c
 *
 * Created: 10/6/2023 11:31:30 PM
 *  Author: Home™
 */ 
#include "hal_gpio.h"
/**
 * @brief make the direction input or output 
     by using DDRB :This register is used to select the direction of the pin.
	  If a bit in DDRx is written to ‘1’,the pin is configured as an output pin. 
	  If it is written to ‘0’, the pin is configured as an input pin
 * @param  _pin_config
 * @return  RETURN E_OK if the function is done
 *           return E_NOK if the function is failed 
 */
Std_ReturnType gpio_pin_direction_init(const pin_config_t *pin_config){
	Std_ReturnType ret=E_OK;
	if(NULL==pin_config){
		ret =E_NOK;
}else{
	switch(pin_config->direction){
		case GPIO_DIRECTION_INPUT:
		clear_bit(DDRB,pin_config->pin);
		break;
		case GPIO_DIRECTION_OUTPUT:
		set_bit(DDRB,pin_config->pin);
		break;
		default:
		ret =E_NOK;
	}
}
return ret ;
}
/**
 * @brief : get the direction  of any pin whether input or output 
     by using DDRB :This register is used to select the direction of the pin.
	  If a bit in DDRx is written to ‘1’,the pin is configured as an output pin. 
	  If it is written to ‘0’, the pin is configured as an input pin
 * @param  _pin_config
 * @return  RETURN E_OK if the function is done
 *           return E_NOK if the function is failed 
 */

Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config,direction_t *direction){
	Std_ReturnType ret =E_NOK;
	if((NULL == pin_config) || (NULL == direction)){
		ret =E_NOK;
	}else{
		*direction=read_bit(DDRB,pin_config->pin);
	}
	return ret;
}
/**
 * @brief write the logic in any pin whether 0v or 5v
    by using  PORTx (Pin Output Register): 
	This register has two functions. It can control the output state of a pin 
	and the setup of an input pin.
     As an Output: If a ‘1’ is written to a bit when the pin is configured as an output pin, the port pin is driven high. 
	 If a ‘0’ is written, the port pin is driven low.
     As an Input: If a ‘1’ is written to a bit when the pin is configured as an input pin,
	  the pull-up resistor is activated. If a ‘0’ is written, the port pin is tri-stated.
 * @param  _pin_config
 * @return  RETURN E_OK if the function is done
 *           return E_NOK if the function is failed 
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config ,uint8 logic){
	Std_ReturnType ret =E_NOK;
	if(NULL == pin_config){
		ret =E_NOK;
		}else{
		switch(logic){
			case GPIO_LOW:
			clear_bit(PORTB,pin_config->pin);
			break;
			case GPIO_HIGH:
			set_bit(PORTB,pin_config->pin);
			default:
			ret =E_NOK;
		}
	}
	return ret;
}
/**
 * @brief read  the logic of any pin whether 0v or 5v
    by using  PORTx (Pin Output Register): 
	This register has two functions. It can control the output state of a pin 
	and the setup of an input pin.
     As an Output: If a ‘1’ is written to a bit when the pin is configured as an output pin, the port pin is driven high. 
	 If a ‘0’ is written, the port pin is driven low.
     As an Input: If a ‘1’ is written to a bit when the pin is configured as an input pin,
	  the pull-up resistor is activated. If a ‘0’ is written, the port pin is tri-stated.
 * @param  _pin_config
 * @return  RETURN E_OK if the function is done
 *           return E_NOK if the function is failed 
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config,uint8 *logic){
	Std_ReturnType ret =E_NOK;
	if((NULL == pin_config) || (NULL == logic)){
		ret =E_NOK;
		}else{
		*logic =read_bit(PINB,pin_config->pin);
	}
	return ret;
}
/**
 * @brief toggle  the logic of any pin if 0v will be 5v and vice versa
    by using  PORTx (Pin Output Register): 
	This register has two functions. It can control the output state of a pin 
	and the setup of an input pin.
     As an Output: If a ‘1’ is written to a bit when the pin is configured as an output pin, the port pin is driven high. 
	 If a ‘0’ is written, the port pin is driven low.
     As an Input: If a ‘1’ is written to a bit when the pin is configured as an input pin,
	  the pull-up resistor is activated. If a ‘0’ is written, the port pin is tri-stated.
 * @param  _pin_config
 * @return  RETURN E_OK if the function is done
 *           return E_NOK if the function is failed 
 */
Std_ReturnType gpio_pin_toggle(const pin_config_t *pin_config){
	Std_ReturnType ret =E_NOK;
	if((NULL == pin_config)){
		ret =E_NOK;
		}else{
		toggle_bit(PORTB,pin_config->pin);
	}
	return ret;
}

	
