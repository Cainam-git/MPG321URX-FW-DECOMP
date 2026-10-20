/* leon2m FUN_a01085f8 @ 0xa01085f8-0xa01086fc (65 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/65.
 * What it does: converter lock mode of channel ch (bit = 1 << ch) in three hardware registers
 * A = 0xcf011a84, B = 0xcf011a88, C = 0xcf011a8c (volatile, each a separate read-modify-write):
 *   mode 1:     A |= bit, B &= ~bit, C = ok ? C | bit : C & ~bit;
 *   mode 2:     A |= bit, B |= bit,  C = ok ? C | bit : C & ~bit;
 *   other mode: A, B and C &= ~bit (the channel is taken out of all three).
 * dc6c state 10 calls it as (port_code(0), 2 or 1, ok & 1) and (port, 0, 0): so the 'rate OK' flag
 * only decides the C bit; mode 0 clears the channel from all three.
 * ch is an int (no 'and 0xff' on %i0), mode and ok are u8 (fw 'and %i1,0xff', 'btst 0xff').
 * Lever: a SWITCH with the DEFAULT arm first in the source ('default: clear; case 1; case 2').
 * The case dispatch makes the mode-2 test block the fall-through of the mode-1 test (no label between),
 * so postreload's reload_cse removes that block's repeated sethi/A/B address set-up (fw 'mov %g1,%i3'
 * and no A/B 'or's there), while the arm order (default first) gives the fw register allocation
 * (if/else chains reach only one of the two conditions).
 * The fw 'sll %i1,%i0' for the mode-1 bit is cse using mode (known 1 there) for the constant 1.
 * volatile only on the real hardware registers. Aids: none.
 */
#define FRC_A (*(volatile unsigned int *)0xcf011a84)
#define FRC_B (*(volatile unsigned int *)0xcf011a88)
#define FRC_C (*(volatile unsigned int *)0xcf011a8c)

void FUN_a01085f8(int ch, unsigned char mode, unsigned char ok)
{
    switch (mode) {
    default:
        FRC_A &= ~(1 << ch);
        FRC_B &= ~(1 << ch);
        FRC_C &= ~(1 << ch);
        break;
    case 1:
        FRC_A |= 1 << ch;
        FRC_B &= ~(1 << ch);
        if (ok)
            FRC_C |= 1 << ch;
        else
            FRC_C &= ~(1 << ch);
        break;
    case 2:
        FRC_A |= 1 << ch;
        FRC_B |= 1 << ch;
        if (ok)
            FRC_C |= 1 << ch;
        else
            FRC_C &= ~(1 << ch);
        break;
    }
}
