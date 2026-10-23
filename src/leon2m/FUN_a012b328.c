/* leon2m FUN_a012b328 @ 0xa012b328 (-mcpu=v8 -O2)
 * Stores the low byte of v in byte +3 of the 22-byte entry (p & 0xff) of the table at 0xA802D8AE, then returns
 * FUN_a0137aec(p & 0xff, v & 0xff) (tail call). Source form: FUN_a0137aec (void, two unsigned char parameters) is
 * declared here with unsigned int parameters; the caller masks both arguments itself (and 0xff), as the firmware does.
 */
typedef struct {
    unsigned char _pad[3];
    unsigned char val;
    unsigned char _pad2[18];
} elem_t;

extern elem_t DAT_a802d8ae[]; /* 0xa802d8ae */
extern void FUN_a0137aec(unsigned int, unsigned int); /* 0xa0137aec */

void FUN_a012b328(unsigned int param_1, unsigned int param_2)
{
    DAT_a802d8ae[param_1 & 0xff].val = param_2;
    FUN_a0137aec(param_1 & 0xff, param_2 & 0xff);
}
