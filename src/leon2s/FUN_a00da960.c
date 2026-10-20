/* FUN_a00da960 (leon2s 0xa00da960-0xa00da9e8, 136 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Sets DAT_a807883c when DAT_a807883b is clear. When en is set, clears bit 4 (table byte
 * DAT_a8079c50[DAT_a80787fc - 1] == 0) or bit 5 (otherwise) of word 0x333 (byte 0xccc) of the register block
 * DAT_a80760a4[DAT_a8078832].
 * Source form: the table byte is read into a local first (the firmware loads it before the flag store).
 */
extern unsigned char DAT_a807883b;
extern unsigned char DAT_a807883c;
extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8079c50[];
extern volatile unsigned int *DAT_a80760a4[];

void FUN_a00da960(unsigned char en)
{
    unsigned char c = DAT_a8079c50[DAT_a80787fc - 1];

    if (DAT_a807883b == 0)
        DAT_a807883c = 1;
    if (en != 0) {
        if (c == 0)
            DAT_a80760a4[DAT_a8078832][0x333] &= ~0x10;
        else
            DAT_a80760a4[DAT_a8078832][0x333] &= ~0x20;
    }
}
