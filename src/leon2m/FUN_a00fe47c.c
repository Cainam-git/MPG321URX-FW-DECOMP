/* leon2m FUN_a00fe47c @ 0xa00fe47c-0xa00fe4a4 (10 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf; reads the two hardware registers 0xcf009bb4 (high byte) and 0xcf009bb8 (low byte), in that
 * order, and returns (bb4 << 8) | bb8 as a 16-bit value. Called from the OLED power / sensing state machine
 * FUN_a0127c78 (four times), FUN_a0080490 (APPSetPowerOff), FUN_a012cfac, FUN_a012d554. What the value means is
 * not shown by this code. volatile only on the two real hardware registers. Aids: none.
 */
unsigned short FUN_a00fe47c(void)
{
    return (*(volatile unsigned int *)0xcf009bb4 << 8) | *(volatile unsigned int *)0xcf009bb8;
}
