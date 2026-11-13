/* SYSAPI_SetPowerStatus  (FUN_a0148aa8)
 *
 * Store the power status bit and save the settings record.
 * Note: Writes the EEPROM.
 * Name basis: proven - prints 'SYSAPI_SetPowerStatus %x' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148aa8, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the decompiler's form is kept: the argument is an unsigned char that
 * is shifted left by 31 inside an int expression; the second parameter is declared and unused.
 */
extern unsigned int device_settings;
extern int dbg_printf();
extern void nvram_write_settings_record();

#define DEVICE_SETTING_POWER_STATUS_SHIFT 31    /* power status is bit 31 of the first word of the record */

/*
 * Store the power status (bit 0 of power_status) as bit 31 of the first word of the device settings record and
 * write the record to the EEPROM. The other bits of that word are kept.
 */
void SYSAPI_SetPowerStatus(unsigned char power_status,unsigned int unused)

{
  dbg_printf("SYSAPI_SetPowerStatus %x\r\n",power_status & 0xff);
  device_settings = device_settings & 0x7fffffff | power_status << DEVICE_SETTING_POWER_STATUS_SHIFT;
  nvram_write_settings_record(&device_settings,1);
  return;
}
