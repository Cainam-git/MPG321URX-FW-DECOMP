/* leon2m FUN_a0148868 @ 0xa0148868-0xa0148974 (31 words), flags -mcpu=v8 -O3 (no -g: the firmware has no nop after
 * the final call).
 * t = FUN_a0152f70(); prints "SYSAPI_GetPowerOnType %02x\r\n" with t, then maps t with a switch (jump table
 * 0xe3450, values 0..19): 2 -> 1, 3 -> 2, 4 -> 3, 5..11 -> 0x31..0x37, 12 -> 0x30, 13..18 -> 0x21..0x26, 19 -> 5;
 * any other value gives 4 when bit 31 of the word DAT_a802e1a0 is clear and 0 when it is set. Prints
 * "SYSAPI_GetPowerOnType = %d \r\n" with the result and returns it.
 * Source form: the default arm first stores the masked word in a local (w = DAT_a802e1a0 & 0x80000000) and then
 * tests w; this keeps the firmware's and/cmp/subx sequence (a test written on the expression itself, or as
 * 'DAT_a802e1a0 >> 31', is compiled as a shift of the sign bit).
 */
extern unsigned int DAT_a802e1a0;
extern unsigned char FUN_a0152f70(void);
extern int FUN_a00df170(const char *fmt, ...);

unsigned char FUN_a0148868(void)
{
    unsigned char t, r;
    unsigned int w;

    t = FUN_a0152f70();
    FUN_a00df170("SYSAPI_GetPowerOnType %02x\r\n", t);
    switch (t) {
    case 2:
        r = 0x1;
        break;
    case 3:
        r = 0x2;
        break;
    case 4:
        r = 0x3;
        break;
    case 5:
        r = 0x31;
        break;
    case 6:
        r = 0x32;
        break;
    case 7:
        r = 0x33;
        break;
    case 8:
        r = 0x34;
        break;
    case 9:
        r = 0x35;
        break;
    case 10:
        r = 0x36;
        break;
    case 11:
        r = 0x37;
        break;
    case 12:
        r = 0x30;
        break;
    case 13:
        r = 0x21;
        break;
    case 14:
        r = 0x22;
        break;
    case 15:
        r = 0x23;
        break;
    case 16:
        r = 0x24;
        break;
    case 17:
        r = 0x25;
        break;
    case 18:
        r = 0x26;
        break;
    case 19:
        r = 0x5;
        break;
    default:
        w = DAT_a802e1a0 & 0x80000000;
        r = w ? 0 : 4;
        break;
    }
    FUN_a00df170("SYSAPI_GetPowerOnType = %d \r\n", r);
    return r;
}
