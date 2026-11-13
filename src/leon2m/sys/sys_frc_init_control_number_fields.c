/* sys_frc_init_control_number_fields  (FUN_a0108f70)
 *
 * Write n into bits 4-5 of FRC control register n (0..3) and clear bits 0-2 of registers 1..3.
 * Note: Registers 0xCF011AA0..AC; bit 7 of the first is the bit sys_frc_is_active reads.
 * Name basis: descriptive - bits 4-5 = register number, bits 0-2 cleared; called by
 *   startup_init_converter_sources
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0108f70 @ 0xa0108f70-0xa0109110, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: each register has its own case in a switch inside each loop; every
 * field update is two accesses, a clear and then an or (the or with 0 where the field stays 0), kept as written.
 */
/* The four FRC control registers, one word each. Bit 7 of FRC_CONTROL_0 tells whether the frame-rate converter is
   active (sys_frc_is_active). Bits 4..5 of each register are set to its own number here; bits 0..2 of registers 1..3 are cleared. */
#define FRC_CONTROL_0 0xcf011aa0
#define FRC_CONTROL_1 0xcf011aa4
#define FRC_CONTROL_2 0xcf011aa8
#define FRC_CONTROL_3 0xcf011aac
#define FRC_NUMBER_MASK 0x30      /* bits 4..5 */
#define FRC_LOW_BITS_MASK 7     /* bits 0..2 */
#define R(a) (*(volatile unsigned int *)(a))

/*
 * Write its own number into bits 4..5 of each of the four FRC control registers and clear bits 0..2 of registers 1..3.
 *
 * Register n (n = 0..3, FRC_CONTROL_0 + 4 * n) gets n in bits 4..5. Registers 1..3 also get bits 0..2 cleared;
 * register 0 keeps its low bits. Every field is changed by a clear followed by an or. No parameters, no result.
 * Called by startup_init_converter_sources.
 */
void sys_frc_init_control_number_fields(void)
{
    unsigned char i;

    /* Bits 4..5 of register n := n. */
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            R(FRC_CONTROL_0) &= ~FRC_NUMBER_MASK;
            R(FRC_CONTROL_0) |= 0 << 4;
            break;
        case 1:
            R(FRC_CONTROL_1) &= ~FRC_NUMBER_MASK;
            R(FRC_CONTROL_1) |= 1 << 4;
            break;
        case 2:
            R(FRC_CONTROL_2) &= ~FRC_NUMBER_MASK;
            R(FRC_CONTROL_2) |= 2 << 4;
            break;
        case 3:
            R(FRC_CONTROL_3) &= ~FRC_NUMBER_MASK;
            R(FRC_CONTROL_3) |= 3 << 4;
            break;
        }
    }
    /* Registers 1..3: bits 0..2 := 0. */
    for (i = 1; i < 4; i++) {
        switch (i) {
        case 1:
            R(FRC_CONTROL_1) &= ~FRC_LOW_BITS_MASK;
            R(FRC_CONTROL_1) |= 0;
            break;
        case 2:
            R(FRC_CONTROL_2) &= ~FRC_LOW_BITS_MASK;
            R(FRC_CONTROL_2) |= 0;
            break;
        case 3:
            R(FRC_CONTROL_3) &= ~FRC_LOW_BITS_MASK;
            R(FRC_CONTROL_3) |= 0;
            break;
        }
    }
}
