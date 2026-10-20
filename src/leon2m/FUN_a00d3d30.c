/*
 * FUN_a00d3d30: maps the byte setting DAT_a802d29a to an output value through float math:
 *   v > 70: (v - 70) * 22 / 30 + 128, else v * 100 / 70 + 28 (truncated to unsigned char).
 * Real neighbour in the same source unit as FUN_a00d6054 (APP_ConfigDispSize); its six float
 * constants are the first .rodata.cst4 entries at 0x198748. Flags: -mcpu=v8 -O3 -g -msoft-float.
 * No compiler aids.
 */
extern unsigned char DAT_a802d29a;
unsigned char FUN_a00d3d30(void)
{
    unsigned char v = DAT_a802d29a;
    float f;
    if (v > 70)
        f = (float)(v - 70) * 22.0f / 30.0f + 128.0f;
    else
        f = (float)(int)v * 100.0f / 70.0f + 28.0f;
    return f;
}
