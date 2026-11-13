/* ddc_tool_set_factory_flag_14  (FUN_a00d2884)
 *
 * Tool command: store a 0/1 flag in the factory record and save it.
 * Note: Writes the EEPROM.
 * Name basis: descriptive - byte 0x14 of the record at 0xA802D274; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d2884 @ 0xa00d2884-0xa00d28d4 (20 words), flags -mcpu=v8 -O2 -g.
 * Source form: SYSAPI_WriteEEPROM is declared without a prototype, as in ddc_tool_set_level_percent.
 */
extern unsigned char factory_record[];
extern int SYSAPI_WriteEEPROM();

#define TOOL_RESULT_DONE      0xe0              /* the command was carried out */
#define EEPROM_AREA_SETTINGS  0x30              /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define FACTORY_RECORD_OFFSET 0x2e0             /* docs/DATA.md: where the factory record is saved */
#define FACTORY_RECORD_SIZE   0x1c
#define FACTORY_BYTE_0x14     0x14              /* factory record +0x14 (docs/RECORDS.md) */

/*
 * Factory tool command 0x74 (TOOL_CMD_FACTORY_BYTE_14): request byte 7 = 1 sets factory record byte +0x14, 0
 * clears it, any other value leaves it. The factory record is saved in every case.
 *
 *   param_1  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_factory_flag_14(unsigned char *param_1)
{
    if (param_1[7] == 1)
        factory_record[FACTORY_BYTE_0x14] = 1;
    else if (param_1[7] == 0)
        factory_record[FACTORY_BYTE_0x14] = 0;
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    return TOOL_RESULT_DONE;
}
