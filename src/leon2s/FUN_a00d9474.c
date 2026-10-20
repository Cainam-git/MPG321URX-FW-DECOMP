/* leon2s FUN_a00d9474 @ 0xa00d9474-0xa00d9524 (44 words).
 * Builds a 19-byte packet and sends it with FUN_a00d791c(packet, 2, 1, 0xf, 0x13): byte 0 has bit 7 set and the
 * 7-bit id in bits 0..6 (bit-fields of the first word), bytes 1..16 are the low bytes of the 16 registers at +0xd00
 * of the register block selected by byte 0xa8078832 in the pointer table 0xa80760a4, byte 17 is a and byte 18 is b.
 * Afterwards bit 5 of the block's first register is set.
 */
union Pkt {
    struct {
        unsigned int b31 : 1;
        unsigned int id : 7;
        unsigned int rest : 24;
    } h;
    unsigned char b[20];
};
extern unsigned char DAT_a8078832;
extern volatile unsigned int *DAT_a80760a4[];
extern void FUN_a00d791c(void *, int, int, int, int);

void FUN_a00d9474(unsigned char id, unsigned char a, unsigned char b)
{
    union Pkt p;
    unsigned char i;

    p.h.b31 = 1;
    p.h.id = id;
    for (i = 0; i < 16; i++)
        p.b[i + 1] = DAT_a80760a4[DAT_a8078832][0xd00 / 4 + i];
    p.b[17] = a;
    p.b[18] = b;
    FUN_a00d791c(&p, 2, 1, 0xf, 0x13);
    DAT_a80760a4[DAT_a8078832][0] |= 0x20;
}
