/* FUN_a00d64ec (leon2s, 0xa00d64ec-0xa00d6560, 29 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void(void). Up to 10 passes (u8 counter 9 down to 0): set bit 0 of the hardware register 0xcf013204, func_0xa0fc1794(5), st = 0,
 r = func_0xa0f9639c(0, 0x90, 0x2c0, &st) (u8 return); a failed read (r != 0) clears st; stop when bit 1 of st is set.
 Fixes vs draft: 9639c returns u8 and result is unsigned char (fw btst 0xff; a signed char result gives sll 24); the decrement sits in the
 loop condition ('while (counter-- != 0)', fw keeps the old value live and moves the new one into %l0; '--counter != 0xff' is also exact);
 void (the draft returned 0). Aids: none.
 */
#define REG_CF013204 (*(volatile unsigned int *)0xcf013204)

extern unsigned char func_0xa0f9639c(int, int, int, void *);
extern int func_0xa0fc1794(int);

void FUN_a00d64ec(void)
{
    unsigned char local_9;
    unsigned char counter = 9;
    unsigned char result;
    
    do {
        REG_CF013204 |= 1;
        func_0xa0fc1794(5);
        local_9 = 0;
        result = func_0xa0f9639c(0, 0x90, 0x2c0, &local_9);
        if ((result) != 0) {
            local_9 = 0;
        }
        if ((local_9 & 2) != 0) {
            break;
        }
    } while (counter-- != 0);

}
