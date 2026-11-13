/* ddc_tool_write_factory_record  (FUN_a00d2334)
 *
 * Store 13 bytes from the factory tool in the factory record and save it.
 *   param_1: request
 * Returns: 0xE0
 * Note: Factory record 0xA802D274 + 3, EEPROM 0x2E0.
 * Name basis: proven - SYSAPI_WriteEEPROM(0x30, 0xA802D274, 0x2E0, 0x1C)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d2334 @ 0xa00d2334 (-mcpu=v8 -O2 -g)
 * Source form: the copy is a do-while over an unsigned char index and a separate unsigned int count; the record
 * address is formed again inside the loop.
 */

extern int SYSAPI_WriteEEPROM(int, unsigned int *, int, int);
extern unsigned int factory_record;

#define TOOL_RESULT_DONE      0xe0              /* the command was carried out */
#define EEPROM_AREA_SETTINGS  0x30              /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define FACTORY_RECORD_OFFSET 0x2e0             /* docs/DATA.md: where the factory record is saved */
#define FACTORY_RECORD_SIZE   0x1c
#define FACTORY_SERIAL        3                 /* factory record +3: the serial characters */
#define TOOL_SERIAL_FIRST_BYTE 6                /* request byte of the first serial character */
#define SERIAL_COMMAND_LENGTH 0xd               /* serial characters the request carries */

/*
 * Factory tool command 0x6B (TOOL_CMD_SERIAL): copy the 13 serial characters of the request (bytes 6..18) to
 * factory record bytes 3..15 and save the factory record.
 *
 *   param_1  the request, passed as an address
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_write_factory_record(int param_1)
{
  unsigned int count;
  unsigned char index;
  unsigned char *src;
  unsigned char *dst;
  count = 0;
  index = 0;
  src = (unsigned char *) param_1;
  do
  {
    count = count + 1;
    dst = (unsigned char *) (&factory_record);
    dst[index + FACTORY_SERIAL] = src[index + TOOL_SERIAL_FIRST_BYTE];
    index = count & 0xff;
  }
  while (index < SERIAL_COMMAND_LENGTH);
  SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
  return TOOL_RESULT_DONE;
}
