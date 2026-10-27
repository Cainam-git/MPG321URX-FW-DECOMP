/* FUN_a012b39c (leon2m 0xa012b39c-0xa012b3f0, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When on is non-zero sets bit n of the byte DAT_a802caf8; otherwise stores 1 to DAT_a802cb00[n & 0xff] and clears
 * bit (n & 0xff) of DAT_a802caf8. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a012b394 and FUN_a012b3f0. Source form: the clear mask is computed into its own local
 * before the array store.
 */
extern unsigned char DAT_a802caf8;
extern unsigned char DAT_a802cb00[];

void FUN_a012b39c(unsigned int n, unsigned char on)
{
    if (on)
        DAT_a802caf8 |= 1 << n;
    else {
        unsigned char k = n;
        unsigned int m = 1 << k;

        DAT_a802cb00[k] = 1;
        DAT_a802caf8 &= ~m;
    }
}
