/* FSM_EQSCAN_DONE (leon2s 0xa0079460-0xa00795a0, 320 bytes), flags -mcpu=v8 -Os -g.
 * Returns unless the low byte of FUN_a0078fe8(port) is 1, the low byte of FUN_a00735e8(port) is 0 and byte +6
 * of the 0x18-byte record ARR_a807cc64[port] is 1. Then calls the state function DAT_a00b3a20[w0](port), w0 =
 * word 0 of the 12-byte record ARR_a807ccc4[port], again as long as it returns a non-zero byte. When w0 is
 * then 0x10: prints "finish FSM_EQSCAN_DONE %d\r\n" with 99, calls FUN_a0079054(port, 1), prints the CH0, CH1
 * and CH2 RVGA lines with bytes +9, +0xa, +0xb of the 0x898-byte record ARR_a807a9f0[port] and their entries
 * in the byte table DAT_a00b3ac8, and sets byte +1 of ARR_a807cc64[port] to 1.
 */
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char b[4];
    unsigned char b6;
    unsigned char _7[0x18 - 7];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct sel_rec ARR_a807cc64[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char ARR_a807a9f0[][0x898];
extern unsigned char (*const DAT_a00b3a20[])(unsigned char);
extern const unsigned char DAT_a00b3ac8[];
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a0078fe8(unsigned char);
extern unsigned int FUN_a00735e8(unsigned char);
extern void FUN_a0079054(unsigned char, unsigned char);

void FSM_EQSCAN_DONE(unsigned char port)
{
    if ((unsigned char)FUN_a0078fe8(port) != 1)
        return;
    if ((unsigned char)FUN_a00735e8(port))
        return;
    if (ARR_a807cc64[port].b6 != 1)
        return;
    while (DAT_a00b3a20[ARR_a807ccc4[port].w0](port))
        ;
    if (ARR_a807ccc4[port].w0 != 0x10)
        return;
    FUN_a0073044("finish FSM_EQSCAN_DONE %d\r\n", 99);
    FUN_a0079054(port, 1);
    FUN_a0073044("Port%c, CH0, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), ARR_a807a9f0[port][9], DAT_a00b3ac8[ARR_a807a9f0[port][9]]);
    FUN_a0073044("Port%c, CH1, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), ARR_a807a9f0[port][0xa], DAT_a00b3ac8[ARR_a807a9f0[port][0xa]]);
    FUN_a0073044("Port%c, CH2, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), ARR_a807a9f0[port][0xb], DAT_a00b3ac8[ARR_a807a9f0[port][0xb]]);
    ARR_a807cc64[port].b1 = 1;
}
