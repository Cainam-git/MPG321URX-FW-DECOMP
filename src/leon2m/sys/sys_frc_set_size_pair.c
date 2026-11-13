/* sys_frc_set_size_pair  (FUN_a01099fc)
 *
 * Write a size pair of converter channel 0..3.
 * Name basis: descriptive - register pair at 0xCF011DE0 + 0x10 * channel; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01099fc @ 0xa01099fc, flags -mcpu=v8 -O3 -g.
 * Source form: a switch over index; the second call of each case is in tail position.
 */
extern void reg_write16_bytes(volatile unsigned int *r, unsigned int v);

/*
 * Write two 16-bit values to the register pair chosen by `index`: 0 = 0xCF011DE0 / 0xCF011DE8,
 * 1 = 0xCF011DF0 / 0xCF011DF8, 2 = 0xCF011E00 / 0xCF011E08, 3 = 0xCF011E10 / 0xCF011E18 (`value_a` to the first,
 * `value_b` to the second). Other values do nothing. Nothing in the image calls it.
 */
void sys_frc_set_size_pair(unsigned char index, unsigned short value_a, unsigned short value_b)
{
    switch (index) {
    case 0:
        reg_write16_bytes((volatile unsigned int *)0xcf011de0, value_a);
        reg_write16_bytes((volatile unsigned int *)0xcf011de8, value_b);
        break;
    case 1:
        reg_write16_bytes((volatile unsigned int *)0xcf011df0, value_a);
        reg_write16_bytes((volatile unsigned int *)0xcf011df8, value_b);
        break;
    case 2:
        reg_write16_bytes((volatile unsigned int *)0xcf011e00, value_a);
        reg_write16_bytes((volatile unsigned int *)0xcf011e08, value_b);
        break;
    case 3:
        reg_write16_bytes((volatile unsigned int *)0xcf011e10, value_a);
        reg_write16_bytes((volatile unsigned int *)0xcf011e18, value_b);
        break;
    }
}
