/* oled_power_get_state  (FUN_a012792c)
 *
 * Return the state of the OLED power state machine.
 * Returns: state
 * Name basis: derived - byte at 0xA802D896, the state the machine switches on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012792c, flags -mcpu=v8 -O2.
 */
extern unsigned char oled_power_state;

/*
 * Return the state of the OLED power state machine, the byte oled_power_task switches on: 0 recover from off,
 * 1 EL sensing, 2 off sensing, 3 QSM, 4 power off sequence.
 */
unsigned char oled_power_get_state(void)
{
    return oled_power_state;
}
