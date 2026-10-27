/* FUN_a0137864 (leon2m 0xa0137864-0xa01378f0, 140 bytes), flags -mcpu=v8 -O3 -g.
 * Builds a 4-byte buffer {k, v, 0, 0} with k = 2, 3, 4 or 5 for c = 0..3 (0 for other c) and calls FUN_a01370dc(2,
 * 2, buffer, 0). Called by FUN_a0124244. Source form: an initialised local array {0} filled by a switch.
 */
extern void FUN_a01370dc(unsigned int cmd, unsigned char len, unsigned char *p, unsigned char wait);

void FUN_a0137864(unsigned char c, unsigned char v)
{
    unsigned char buf[4] = { 0 };

    switch (c) {
    case 0:
        buf[0] = 2;
        break;
    case 1:
        buf[0] = 3;
        break;
    case 2:
        buf[0] = 4;
        break;
    case 3:
        buf[0] = 5;
        break;
    }
    buf[1] = v;
    FUN_a01370dc(2, 2, buf, 0);
}
