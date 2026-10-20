/* FUN_a00cf9e8 (leon2s, 0xa00cf9e8-0xa00cfab8, 208 bytes, 52 words).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/52 mismatches.
 * Code facts: port = (u8)param_1; reads reg 0x201 (func_0xa0f9639c(port, 0x90, 0x201, &b)); when bit 2
 * of b is set: func_0xa0f96360(port, 0x80, 0x201, 4), then reads 0x68029 (result bit 2 or 3 set ->
 * flag = 1) and 0x69493 (bit 3 or 4 set -> flag = 1), each only when the read call returns 0.
 * Returns the flag as a u8 (fw: 'and %l0,1,%i0' = u8 return extension narrowed by nonzero-bits).
 * Fix vs draft: u8 return type and u8 flag returned as is (the draft's int flag with 'return l0 & 1'
 * gives a different exit block). Aids: none.
 */
extern int func_0xa0f96360(int, int, int, int);
extern int func_0xa0f9639c(int, int, int, void *);

unsigned char FUN_a00cf9e8(unsigned char param_1)
{
    unsigned char local_a;
    unsigned char local_9;
    unsigned char l0 = 0;

    param_1 = param_1 & 0xff;
    local_9 = 0;
    func_0xa0f9639c(param_1, 0x90, 0x201, &local_9);

    if ((local_9 & 4) != 0) {
        func_0xa0f96360(param_1, 0x80, 0x201, 4);

        if ((func_0xa0f9639c(param_1, 0x90, 0x68029, &local_a) & 0xff) == 0) {
            if ((local_a & 4) != 0)
                l0 = 1;
            if ((local_a & 8) != 0)
                l0 = 1;
        }

        if ((func_0xa0f9639c(param_1, 0x90, 0x69493, &local_a) & 0xff) == 0) {
            if ((local_a & 8) != 0)
                l0 = 1;
            if ((local_a & 0x10) != 0)
                l0 = 1;
        }
    }

    return l0;
}
