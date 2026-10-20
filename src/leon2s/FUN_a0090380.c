/* leon2s FUN_a0090380 @ 0xa0090380-0xa0090498 (280 bytes, 70 words)
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: void (u8 port, u8 sel, u8 *buf). A switch on sel (signed tree, root 0x83). It reads 0x1c bytes
 * with FUN_a00a657c(port, i + base) into buf[i], u8 counter i (it reuses sel's register %i1). The bases are
 * 0x82 -> 0x144, 0x83 -> 0x164, 0x84 -> 0x184, 0x87 -> 0x1b0. Any other sel does nothing.
 * BEHAVIOUR fixes against the draft: in case 0x83 the draft stored the port instead of the read result, and
 * the function is void. No aids.
 */
extern unsigned char FUN_a00a657c(unsigned char, unsigned short);

void FUN_a0090380(unsigned char port, unsigned char sel, unsigned char *buf)
{
    unsigned char i;

    switch (sel) {
    case 0x82:
        for (i = 0; i < 0x1c; i++)
            buf[i] = FUN_a00a657c(port, i + 0x144);
        break;
    case 0x83:
        for (i = 0; i < 0x1c; i++)
            buf[i] = FUN_a00a657c(port, i + 0x164);
        break;
    case 0x84:
        for (i = 0; i < 0x1c; i++)
            buf[i] = FUN_a00a657c(port, i + 0x184);
        break;
    case 0x87:
        for (i = 0; i < 0x1c; i++)
            buf[i] = FUN_a00a657c(port, i + 0x1b0);
        break;
    }
}
