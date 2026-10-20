/* leon2m FUN_a0107bac @ 0xa0107bac  GPIO pin set-up (hand; -mcpu=v8 -O3 -g)
 *
 * FUN_a0107bac(grp, pin, oe, lvl): pin 15 = none (returns at once). Pin-mux word 0xCF03C348 (grp 0) or 0xCF03C2B8
 * (grp != 0): bits 2..4 = pin, bit 1 = oe, bit 0 = lvl (three read-modify-writes). 0xCF03C294 bit 'pin' cleared for
 * grp 0, set (grp << pin) for grp 1. Output enable: oe != 0 -> 0xCF03C3F8 |= 1 << pin and shadow 0xA8027A87 &= ~bit;
 * oe == 0 -> shadow |= bit and 0xCF03C3F8 &= ~bit. Per pin 0..6 one more enable bit set (oe) or cleared: pin 0/1 ->
 * 0xCF03C348 bit 6/7, pin 2..6 -> 0xCF03C34C bits 3..7. Then 0xCF03C1A8 = shadow and 0xCF03C354 |= 0x80.
 * Called by FUN_a00bf110 (UartSetI2CEnable) as FUN_a0107bac(0, FUN_a0125124(0xA802E14A), 0, 0): it switches the
 * update UART's pads (UART command path).
 * Matching notes. 54.8 % at -O3 -g: the mux word chosen with one ?: expression makes it a leaf function like the
 *   firmware (an if-assignment needed a register window: 5 %). Left: block layout of the pin cases.
 * 84.9 %: 0xCF03C294 is read once, modified under the grp test and always written back (v = R;
 *   if (grp == 0) v &= ...; R = v), and with oe == 0 the hardware register is cleared before the shadow is set.
 * the three mux read-modify-writes are written out twice, once per group register inside
 *   if (grp == 0) {...} else {...}; gcc merges the identical tails (cross-jumping) and the else branch re-loads its
 *   address before jumping back, exactly as the firmware does. A pointer chosen by ?: or if shares the %hi part.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char DAT_a8027a87;
void FUN_a0107bac(unsigned char grp, unsigned char pin, unsigned char oe, unsigned char lvl)
{
    unsigned int v;
    if (pin == 15) return;
    if (grp == 0) {
        R(0xcf03c348) = (R(0xcf03c348) & ~0x1c) | ((pin << 2) & 0x1c);
        R(0xcf03c348) = (R(0xcf03c348) & ~2) | ((oe << 1) & 2);
        R(0xcf03c348) = (R(0xcf03c348) & ~1) | (lvl & 1);
    } else {
        R(0xcf03c2b8) = (R(0xcf03c2b8) & ~0x1c) | ((pin << 2) & 0x1c);
        R(0xcf03c2b8) = (R(0xcf03c2b8) & ~2) | ((oe << 1) & 2);
        R(0xcf03c2b8) = (R(0xcf03c2b8) & ~1) | (lvl & 1);
    }
    v = R(0xcf03c294);
    if (grp == 0) v &= ~(1 << pin);
    R(0xcf03c294) = v;
    v = R(0xcf03c294);
    if (grp == 1) v |= grp << pin;
    R(0xcf03c294) = v;
    if (oe != 0) {
        R(0xcf03c3f8) |= 1 << pin;
        DAT_a8027a87 &= ~(1 << pin);
    } else {
        R(0xcf03c3f8) &= ~(1 << pin);
        DAT_a8027a87 |= 1 << pin;
    }
    if (pin == 0) { if (oe) R(0xcf03c348) |= 0x40; else R(0xcf03c348) &= ~0x40; }
    else if (pin == 1) { if (oe) R(0xcf03c348) |= 0x80; else R(0xcf03c348) &= ~0x80; }
    else if (pin == 2) { if (oe) R(0xcf03c34c) |= 0x08; else R(0xcf03c34c) &= ~0x08; }
    else if (pin == 3) { if (oe) R(0xcf03c34c) |= 0x10; else R(0xcf03c34c) &= ~0x10; }
    else if (pin == 4) { if (oe) R(0xcf03c34c) |= 0x20; else R(0xcf03c34c) &= ~0x20; }
    else if (pin == 5) { if (oe) R(0xcf03c34c) |= 0x40; else R(0xcf03c34c) &= ~0x40; }
    else if (pin == 6) { if (oe) R(0xcf03c34c) |= 0x80; else R(0xcf03c34c) &= ~0x80; }
    R(0xcf03c1a8) = DAT_a8027a87;
    R(0xcf03c354) |= 0x80;
}
