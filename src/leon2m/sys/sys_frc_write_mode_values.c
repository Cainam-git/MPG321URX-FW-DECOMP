/* sys_frc_write_mode_values  (FUN_a01136a0)
 *
 * Write one of two fixed value sets to the frame-rate converter registers.
 * Name basis: descriptive - chosen by the second stored index; called from GMDHEnableFRC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01136a0, flags -mcpu=v8 -O3 -g.
 * The stores are plain volatile writes in the order of the listing; the first two (0xc0 to 0xcf011a40 and
 * 0xcf011a44) are overwritten by the value sets that follow and stay in the source.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char sys_frc_config_index2;

/*
 * Write the fixed register values of the frame-rate converter's current mode.
 *
 * Two value sets exist, chosen by the second ROM index sys_frc_config_index2: set 0 when it is 0, the other set
 * for any other value. Both sets write the registers 0xcf011840..0xcf01184c, 0xcf011a40..0xcf011a5c, 0xcf011a70,
 * 0xcf011a74 and 0xcf011a7c; they differ in 0xcf011840, 0xcf011a40, 0xcf011a44, 0xcf011a70 and 0xcf011a74.
 * Called from GMDHEnableFRC right after sys_frc_switch_mode, when sys_return_zero_copy4 returns non-zero.
 * The meaning of the individual registers is not shown by the code.
 */
void sys_frc_write_mode_values(void)
{
    R(0xcf011a40) = 0xc0;
    R(0xcf011a44) = 0xc0;
    if (sys_frc_config_index2 == 0) {
        /* set for index 0 */
        R(0xcf011840) = 0x60;
        R(0xcf011844) = 0x60;
        R(0xcf011848) = 0x60;
        R(0xcf01184c) = 0x40;
        R(0xcf011a40) = 0x80;
        R(0xcf011a44) = 0xe0;
        R(0xcf011a48) = 0x60;
        R(0xcf011a4c) = 0xe0;
        R(0xcf011a50) = 0x80;
        R(0xcf011a54) = 0xff;
        R(0xcf011a58) = 0;
        R(0xcf011a5c) = 0xff;
        R(0xcf011a70) = 0xc;
        R(0xcf011a74) = 0xc;
        R(0xcf011a7c) = 0xf;
    } else {
        /* set for any other index */
        R(0xcf011840) = 0x40;
        R(0xcf011844) = 0x60;
        R(0xcf011848) = 0x60;
        R(0xcf01184c) = 0x40;
        R(0xcf011a40) = 0;
        R(0xcf011a44) = 0xff;
        R(0xcf011a48) = 0x60;
        R(0xcf011a4c) = 0xe0;
        R(0xcf011a50) = 0x80;
        R(0xcf011a54) = 0xff;
        R(0xcf011a58) = 0;
        R(0xcf011a5c) = 0xff;
        R(0xcf011a70) = 9;
        R(0xcf011a74) = 0xf;
        R(0xcf011a7c) = 0xf;
    }
}
