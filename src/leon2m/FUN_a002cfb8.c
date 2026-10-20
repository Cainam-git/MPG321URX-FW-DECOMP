/* leon2m FUN_a002cfb8 @ 0xa002cfb8..0xa002d10c (85 words)  timer tick interrupt handler.
 * Installed by Timer_Init FUN_a00deb9c as an irq-4 handler at start-up step 2, before FUN_a0106d64; it runs
 * on every tick of timer 0xC00A0000 from then on.
 * What it does (code facts), once per tick: flag byte 0xA802D642 = 1; the countdown word 0xA802B0C0 - 1 if non-zero
 * (this is the word FUN_a002d1a0, the tick delay, sets and spins on: so every FUN_a002d1a0 wait, e.g. the 3-tick
 * one in FUN_a0112db0 at step 5, ends only while this handler runs); three dividers raise flag bytes and restart:
 * 0xA802D63C every 5 ticks -> 0xA802D64C = 1, 0xA802D650 every 50 -> 0xA802D640 = 1, 0xA802D644 every 500 ->
 * 0xA802D641 = 1; if byte 0xA802B0BC is set, 0xA802B0B8 every 128 -> 0xA802B0BD = 1; free-running counters
 * 0xA802D648, 0xA802B0C8 (+4 of the block 0xA802B0C4) and 0xA802B0B4 + 1; and, if the pointer 0xA802B0D0 (+0xC of
 * that block) is non-zero, it calls it with 0.
 * Can it wait or fail? It has no loop and no wait; the only call is the optional callback through
 * the pointer at +0xC of the block.
 * volatile: only the countdown word, declared 'extern volatile unsigned int _DAT_a802b0c0' exactly as in
 * src/leon2m/FUN_a002d1a0.c (the firmware loads it twice here, which a non-volatile object would not).
 */
struct Tick { unsigned int w0, count, w8; void (*hook)(int); };
extern unsigned char DAT_a802d642, DAT_a802d64c, DAT_a802d640, DAT_a802d641;
extern unsigned int DAT_a802d63c, DAT_a802d650, DAT_a802d644, DAT_a802d648;
extern volatile unsigned int _DAT_a802b0c0;
extern unsigned char DAT_a802b0bc, DAT_a802b0bd;
extern unsigned int DAT_a802b0b8, DAT_a802b0b4;
extern struct Tick DAT_a802b0c4;

void FUN_a002cfb8(void)
{
    DAT_a802d642 = 1;
    if (_DAT_a802b0c0 != 0)
        _DAT_a802b0c0 = _DAT_a802b0c0 - 1;
    if (++DAT_a802d63c > 4) {
        DAT_a802d64c = 1;
        DAT_a802d63c = 0;
    }
    if (++DAT_a802d650 > 0x31) {
        DAT_a802d640 = 1;
        DAT_a802d650 = 0;
    }
    if (++DAT_a802d644 > 0x1f3) {
        DAT_a802d641 = 1;
        DAT_a802d644 = 0;
    }
    if (DAT_a802b0bc != 0) {
        if (++DAT_a802b0b8 > 0x7f) {
            DAT_a802b0bd = 1;
            DAT_a802b0b8 = 0;
        }
    }
    DAT_a802d648++;
    DAT_a802b0c4.count++;
    if (DAT_a802b0c4.hook != 0)
        DAT_a802b0c4.hook(0);
    DAT_a802b0b4++;
}
