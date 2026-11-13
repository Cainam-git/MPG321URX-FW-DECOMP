/* ddc_tool_clear_factory_counters  (FUN_a00d2994)
 *
 * Tool command: clear a byte and a 16-bit counter of the factory record and save it.
 * Note: Writes the EEPROM.
 * Name basis: descriptive - bytes 0x15..0x17 of the record at 0xA802D274; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d2994 @ 0xa00d2994 (-mcpu=v8 -O2 -g)
 * Source form: SYSAPI_WriteEEPROM is declared without a prototype.
 */
typedef unsigned char uchar;
typedef unsigned short ushort;

/* The factory record up to the two fields used here (docs/RECORDS.md). */
struct factory_record_layout {
    uchar pad[0x15];                            /* +0x00..0x14 */
    uchar oled_error_count;                     /* +0x15: shown after "Panel ERR Count" in the factory menu */
    ushort oled_error_reg10;                    /* +0x16: the OLED register 0x10 value saved with that count */
};

extern struct factory_record_layout factory_record;
extern int SYSAPI_WriteEEPROM();

#define TOOL_RESULT_DONE      0xe0              /* the command was carried out */
#define EEPROM_AREA_SETTINGS  0x30              /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define FACTORY_RECORD_OFFSET 0x2e0             /* docs/DATA.md: where the factory record is saved */
#define FACTORY_RECORD_SIZE   0x1c

/*
 * Factory tool command 0xC4 (TOOL_CMD_CLEAR_OLED_ERRORS): clear the OLED error count and the register value
 * saved with it, and save the factory record.
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_clear_factory_counters(void)
{
    factory_record.oled_error_count = 0;
    factory_record.oled_error_reg10 = 0;
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    return TOOL_RESULT_DONE;
}
