/* FUN_a0061450 (leon2s 0xa0061450-0xa00614b8, 104 bytes, leaf), flags -mcpu=v8 -Os -g.
 * When bit 0 of register 0xc00c0014 is set: reads register 0xc00c0000 and appends its low byte to the
 * 128-byte ring buffer DAT_a80788e8 (bytes 0..0x7f, write index +0x80, read index +0x81) unless the next
 * write index (index + 1, 0 from 0x80 on) equals the read index; the register is read before that test.
 * Address word at 0xa00b87c0. Hardware registers are volatile.
 */
struct RxBuf { unsigned char d[0x80]; unsigned char head; unsigned char tail; };
extern struct RxBuf DAT_a80788e8;
#define RXSTAT (*(volatile unsigned int *)0xc00c0014)
#define RXDATA (*(volatile unsigned int *)0xc00c0000)

void FUN_a0061450(void)
{
    unsigned char h, n, c;

    if (RXSTAT & 1) {
        h = DAT_a80788e8.head;
        n = h + 1;
        if (n >= 0x80)
            n = 0;
        c = RXDATA;
        if (n != DAT_a80788e8.tail) {
            DAT_a80788e8.d[h] = c;
            DAT_a80788e8.head = n;
        }
    }
}
