/* FUN_a014ea54 (leon2m 0xa014ea54-0xa014eaa8, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Puts c into the first four-bit field of the halfword DAT_a802cc82 (lowest first) that is 0 (DAT_a802cc82 |= c <<
 * 4i). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a014e9d8 and FUN_a014eaa8. Source form: the global is read and updated inside the loop; GCC hoists the load
 * and sinks the store (written back on both exits).
 */
extern unsigned short DAT_a802cc82;
void FUN_a014ea54(unsigned char c)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
        if (((DAT_a802cc82 >> (i * 4)) & 0xf) == 0) {
            DAT_a802cc82 |= c << (i * 4);
            break;
        }
}
