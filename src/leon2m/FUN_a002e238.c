/* leon2m FUN_a002e238 @ 0xa002e238-0xa002e2a4 (27 words).
 * Installed by FUN_a00dedc8 through func_0x4008a880(4, 0x20, FUN_a002e238). When bit 0 of FUN_a002c250(0xc00b0014)
 * is set, c = FUN_a002c250(0xc00b0000) is stored at byte 0xa802b0ec + head and head (byte 0xa802b16c) advances by
 * one, wrapping from 128 to 0, unless the advanced head equals byte 0xa802b16d; then c is dropped.
 */
struct Ring { unsigned char buf[0x80]; unsigned char head; unsigned char tail; };
extern struct Ring DAT_a802b0ec;
extern unsigned int FUN_a002c250(unsigned int addr);

void FUN_a002e238(void)
{
    unsigned char c, next;

    if (FUN_a002c250(0xc00b0014) & 1) {
        c = FUN_a002c250(0xc00b0000);
        next = DAT_a802b0ec.head + 1;
        if ((signed char)next < 0)
            next = 0;
        if (next != DAT_a802b0ec.tail) {
            DAT_a802b0ec.buf[DAT_a802b0ec.head] = c;
            DAT_a802b0ec.head = next;
        }
    }
}
