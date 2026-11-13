/* SYSAPI_GetPowerOnType  (FUN_a0148868)
 *
 * Return why the monitor started (power-on type).
 * Returns: power-on type
 * Name basis: proven - prints 'SYSAPI_GetPowerOnType %02x' and 'SYSAPI_GetPowerOnType = %d' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148868 @ 0xa0148868-0xa0148974 (31 words), flags -mcpu=v8 -O3 (no -g: the firmware has no nop after
 * the final call).
 * Source form: the default arm first stores the masked word in a local (stored_bit = device_settings &
 * 0x80000000) and then tests that local; this keeps the firmware's and/cmp/subx sequence (a test written on the
 * expression itself, or as 'device_settings >> 31', is compiled as a shift of the sign bit).
 */
extern unsigned int device_settings;
extern unsigned char sys_get_status_byte(void);
extern int dbg_printf(const char *fmt, ...);

/*
 * Translate the status byte (sys_get_status_byte) into the power-on type the start-up code works with.
 *
 *   status byte 2, 3, 4     -> type 1, 2, 3
 *   status byte 5 .. 11     -> type 0x31 .. 0x37
 *   status byte 12          -> type 0x30
 *   status byte 13 .. 18    -> type 0x21 .. 0x26
 *   status byte 19          -> type 5
 *   any other value         -> type 4 when bit 31 of the first word of the device settings is clear,
 *                              type 0 when it is set
 *
 * Returns the power-on type; the values are the POWER_ON_TYPE_* list of the start-up routine. Both the status
 * byte and the result are printed on the debug port. Called by the start-up routine and by APPOnSystemAfterNvramInit.
 */
unsigned char SYSAPI_GetPowerOnType(void)
{
    unsigned char status, type;
    unsigned int stored_bit;

    status = sys_get_status_byte();
    dbg_printf("SYSAPI_GetPowerOnType %02x\r\n", status);
    switch (status) {
    case 2:
        type = 0x1;
        break;
    case 3:
        type = 0x2;
        break;
    case 4:
        type = 0x3;
        break;
    case 5:
        type = 0x31;
        break;
    case 6:
        type = 0x32;
        break;
    case 7:
        type = 0x33;
        break;
    case 8:
        type = 0x34;
        break;
    case 9:
        type = 0x35;
        break;
    case 10:
        type = 0x36;
        break;
    case 11:
        type = 0x37;
        break;
    case 12:
        type = 0x30;
        break;
    case 13:
        type = 0x21;
        break;
    case 14:
        type = 0x22;
        break;
    case 15:
        type = 0x23;
        break;
    case 16:
        type = 0x24;
        break;
    case 17:
        type = 0x25;
        break;
    case 18:
        type = 0x26;
        break;
    case 19:
        type = 0x5;
        break;
    default:
        stored_bit = device_settings & 0x80000000;
        type = stored_bit ? 0 : 4;
        break;
    }
    dbg_printf("SYSAPI_GetPowerOnType = %d \r\n", type);
    return type;
}
