/* leon2m FUN_a01243dc @ 0xa01243dc..0xa0124448 (27 words): start-up step 7 of FUN_a015266c, after the display
 * start-up FUN_a0141964. Sets up the 8051's I2C service ports from a fixed mask
 * (byte-exact: -mcpu=v8 -O3 -g, jf 100.00 match=True, rawcmp 0/27).
 * Plain words: for port i = 0..7: if bit i of 0x55 is set (i = 0, 2, 4, 6) it sends 8051 command 7 with the port
 * mask (1 << i) and the slave byte DAT_a802a428[i] (FUN_a0133e7c; the same command UartSetI2CEnable FUN_a00bf110
 * sends with slave 0x6E), otherwise (i = 1, 3, 5, 7) 8051 command 8 with the mask (FUN_a0133e58).
 * Can it wait or fail? Both go through FUN_a002f3f4 in mode 1: up to 100 polls for a free mailbox slot, a
 * busy slot after 100 polls drops that command silently; once sent, it waits WITHOUT a timeout until the 8051 has
 * cleared the slot. So 8 Big -> 8051 commands, each can wait for ever on a stuck 8051.
 * Exact-form lever: the shifted mask is a local 'int bit = 1;' declared at the top of the
 * loop body. gcc 3.4's loop pass hoists loop-invariant sets in the order it meets them in the body; with '1 << i'
 * the constant 1 is first met inside the arms, after the test's 0x55, so 'mov 0x55' is hoisted first (2 words
 * swapped). With 'bit' set at the top of the body, 'bit = 1' is met first and hoisted first, as in the firmware.
 * The variable is real code (its value is the shifted mask), no volatile, no asm, no dummy data. A similar
 * 'int one = 1' before the loop also moves the constant ahead of 'i = 0' and is not exact.
 */
extern unsigned char DAT_a802a428[];
extern void FUN_a0133e7c(unsigned char, unsigned char);
extern void FUN_a0133e58(unsigned char);

void FUN_a01243dc(void)
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        int bit = 1;
        if ((0x55 >> i) & 1)
            FUN_a0133e7c(bit << i, DAT_a802a428[i]);
        else
            FUN_a0133e58(bit << i);
    }
}
