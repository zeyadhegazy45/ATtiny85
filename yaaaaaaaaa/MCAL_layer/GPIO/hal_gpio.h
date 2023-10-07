/*
 * hal_gpio.h
 *
 * Created: 10/6/2023 11:31:49 PM
 *  Author: Home™
 */ 




/*..............include....*/
#include "std_types.h"


/*..........macro declaration......*/
#define PORT_PIN_MAX_NUMBER 8

/*.........macro function declaration......*/

#define set_bit(reg,bit_pos)                     (reg |= (1<<bit_pos) )
#define clear_bit(reg,bit_pos)                   (reg  &= ~(1<<bit_pos))
#define toggle_bit(reg,bit_pos)                  (reg  ^= (1<<bit_pos))
#define read_bit(reg,bit_pos)                    ((reg>>bit_pos) & 1)
/*.............data type declaration...........*/


typedef enum{
	GPIO_LOW=0,
	GPIO_HIGH
}logic_t;
typedef enum{
	GPIO_DIRECTION_INPUT=0,
	GPIO_DIRECTION_OUTPUT
}direction_t;

typedef struct {
	uint8 pin       :4 ;
	uint8 port      :1;
	uint8 logic     :1;
	uint8 direction :1 ;
}pin_config_t;


/*...........software interfaces declaration........*/
Std_ReturnType gpio_pin_direction_init(const pin_config_t *pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config,direction_t *direction);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config ,uint8 logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config,uint8 *logic);
Std_ReturnType gpio_pin_toggle(const pin_config_t *pin_config);



