/* FUN_a00a03c8 (leon2s 0xa00a03c8-0xa00a0478, 176 bytes, leaf), flags -mcpu=v8 -Os -g.
 * port (u8). Takes the register pointer at offset +0x2c of the 0x34-byte record ARR_a807db00[port] and tests
 * the first two words it points to: returns 1 when word 0 has bits 4-5 clear, byte 2 of word 0 is 1,
 * (byte 3 of word 0) * 0x100 + byte 0 of word 1 is 2, (byte 1 of word 1) * 0x100 + byte 2 of word 1 is not 0
 * and byte 3 of word 1 is not 0; otherwise returns 0. Every test reads the words again.
 * Source form: all five failure tests in one '||' chain before 'return 0' (separate ifs give other delay
 * slots). The pointed-to words are volatile: the firmware reloads the word for every test.
 */
struct Port34 { unsigned char pad[0x2c]; volatile unsigned int *regs; unsigned char rest[0x34 - 0x30]; };
extern struct Port34 ARR_a807db00[];

unsigned char FUN_a00a03c8(unsigned char port)
{
    volatile unsigned int *r = ARR_a807db00[port].regs;

    if (r[0] & 0x30
        || ((r[0] >> 16) & 0xff) != 1
        || (r[0] >> 24) * 0x100 + (r[1] & 0xff) != 2
        || ((r[1] >> 8) & 0xff) * 0x100 + ((r[1] >> 16) & 0xff) == 0
        || (r[1] >> 24) == 0)
        return 0;
    return 1;
}
