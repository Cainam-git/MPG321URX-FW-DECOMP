/* gpio_set_aux_bit3_pattern  (FUN_a0125cb4)
 *
 * Ask for two writes to pin 3 of GPIO port number 0xFF by mode 0..3; no pin changes (ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so both calls write nothing; called by APPSetPowerOff.
 * Name basis: descriptive - two gpio_write_pin(0xFF, 8, level) calls, level per bit of the mode; port number
 *   0xFF is not among the ports 1..17
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125cb4 @ 0xa0125cb4-0xa0125d58 (41 words, including the unreachable ret/restore tail at 0xa0125d50),
 * flags -mcpu=v8 -O2 -g.
 * Source form: an if/else-if chain with both calls written in every arm; GCC merges the call pairs into one shared
 * tail and keeps the argument moves in front of each compare.
 */
extern void gpio_write_pin(int port, int pin_mask, int level);

#define GPIO_PORT_AUX 0xff                      /* not one of the ports 1..17 that gpio_write_pin handles */
#define GPIO_LEVEL_HIGH 1                       /* only bit 0 of the level counts */
#define GPIO_LEVEL_LOW 0xfe

/*
 * Write two levels, one after the other, to pin mask 0x08 of port 0xff. Bit 1 of the mode gives the first level
 * and bit 0 the second (1 = high, 0 = low): mode 0 = low, low; 1 = low, high; 2 = high, low; 3 = high, high.
 * Any other mode writes nothing. Port 0xff is not one of the ports 1..17 that gpio_write_pin handles, so the
 * calls change nothing. Called by APPSetPowerOff.
 */
void gpio_set_aux_bit3_pattern(unsigned char mode)
{
    if (mode == 0) {
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_LOW);
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_LOW);
    } else if (mode == 1) {
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_LOW);
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_HIGH);
    } else if (mode == 2) {
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_HIGH);
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_LOW);
    } else if (mode == 3) {
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_HIGH);
        gpio_write_pin(GPIO_PORT_AUX, 8, GPIO_LEVEL_HIGH);
    }
}
