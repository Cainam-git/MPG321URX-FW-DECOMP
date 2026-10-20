/* FUN_a00c9e44 (leon2s 0xa00c9e44-0xa00ca074, 560 bytes), flags -mcpu=v8 -Os -g.
 * Loads a 0x180-byte table into a port block and reads back 32 bytes. Pulses bit 1 of reg 0 (ROM register
 * routine func_0xa0fb7f1c), sets the mode byte DAT_a807d087 to 3 when DAT_a807d62c is set, else reads it from
 * address 0x734 with func_0xa0f9d2e0; clears the buffer DAT_a807cf08 (0x17f bytes) and sends it
 * (FUN_a00c99a4 mode 5); fills the buffer from the ROM table 0x9f1c1ca8 (DAT_a807d62c set) or with func_0xa0f9d2e0
 * from address 0x5b4, sends it (mode 3), runs FUN_a00c9b58 / FUN_a00c9de8, sets bits 6..7 of reg 0xf, writes regs 0/3,
 * waits for bit 5 of reg 2, writes reg 2 = 0x40, clears bit 0 of reg 3, reads back with FUN_a00c9d28,
 * counts an empty 0x180-step delay loop, copies 32 bytes from buffer offset 0x160 to DAT_a807cd88 and clears
 * bits 6..7 of reg 0xf. Loop counters are unsigned short.
 * Aid: the mode store is written in both arms of an 'if (port)' test from an int local; GCC merges the two
 * identical arms (no code for the test), and the extra block keeps the store's address computation out of
 * the code hoisting at -Os, as in the firmware.
 */
extern unsigned char DAT_a807d62c;
extern unsigned char DAT_a807d087;
extern unsigned char DAT_a807cf08[];
extern unsigned char DAT_a807cd88[];
extern const unsigned char DAT_9f1c1ca8[];
extern void func_0xa0fb7f1c(unsigned int, short, unsigned int, unsigned int);
extern void func_0xa0fb7ee0(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0xa0fb7fa0(unsigned int, unsigned int);
extern void func_0xa0f9d2e0(unsigned short, unsigned short, unsigned char *);
extern void FUN_a00c99a4(unsigned int, unsigned char *, unsigned char, unsigned char, unsigned short);
extern void FUN_a00c9b58(unsigned char, unsigned short);
extern void FUN_a00c9de8(unsigned int, unsigned short);
extern int FUN_a00c9d28(unsigned int, unsigned char *, unsigned char, unsigned short);

void FUN_a00c9e44(unsigned char port)
{
    unsigned short i;
    int mode;

    func_0xa0fb7f1c(port, 0, 2, 1);
    func_0xa0fb7f1c(port, 0, 2, 0);
    mode = 3;
    if (DAT_a807d62c != 0) {
        if (port)
            DAT_a807d087 = mode;
        else
            DAT_a807d087 = mode;
    } else
        func_0xa0f9d2e0(0x734, 1, &DAT_a807d087);
    for (i = 0; i < 0x17f; i++)
        DAT_a807cf08[i] = 0;
    FUN_a00c99a4(port, DAT_a807cf08, 5, 0, 0xc00);
    if (DAT_a807d62c != 0) {
        for (i = 0; i < 0x180; i++)
            DAT_a807cf08[i] = DAT_9f1c1ca8[i];
    } else {
        func_0xa0f9d2e0(0x5b4, 0x180, DAT_a807cf08);
    }
    FUN_a00c99a4(port, DAT_a807cf08, 3, 0, 0xc00);
    FUN_a00c9b58(port, 0xc00);
    FUN_a00c9de8(port, 0xc00);
    func_0xa0fb7f1c(port, 0xf, 0xc0, 1);
    func_0xa0fb7ee0(port, 0, 0);
    func_0xa0fb7ee0(port, 3, 1);
    while ((func_0xa0fb7fa0(port, 2) & 0x20) == 0)
        ;
    func_0xa0fb7ee0(port, 2, 0x40);
    func_0xa0fb7f1c(port, 3, 1, 0);
    FUN_a00c9d28(port, DAT_a807cf08, 6, 0xc00);
    for (i = 0; i < 0x180; i++)
        ;
    for (i = 0; i < 0x20; i++)
        DAT_a807cd88[i] = DAT_a807cf08[i + 0x160];
    func_0xa0fb7f1c(port, 0xf, 0xc0, 0);
}
