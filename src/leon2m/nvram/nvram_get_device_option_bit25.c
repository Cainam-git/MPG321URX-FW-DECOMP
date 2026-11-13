/* nvram_get_device_option_bit25  (FUN_a012ad6c)
 *
 * Return option bit 25 of the device settings.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 25 of the word at 0xA802E1A0; ten callers: startup_reset_input_table gives
 *   port entries 2 / 3 the bus ids 5 / 6 or 6 / 5 by it, the others order or pick input ports by it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012ad6c @ 0xa012ad6c (-mcpu=v8 -O2 -g)
 * Source form: the plain shift and mask on the first word of the record.
 */
#define DEVICE_OPTION_BIT 25                    /* bit of the first word of the device settings record */

/* The first word of the device settings record (0xA802E1A0, loaded from the EEPROM at start-up). */
extern unsigned int device_settings;

/*
 * Return bit 25 of the first word of the device settings record, 0 or 1. Callers use it to decide which of the
 * bus ids 5 and 6 belong to port entries 2 and 3 (see startup_reset_input_table) and which input row is
 * set up first (see startup_init_input_ports).
 */
unsigned int nvram_get_device_option_bit25(void)
{
  return device_settings >> DEVICE_OPTION_BIT & 1;
}
