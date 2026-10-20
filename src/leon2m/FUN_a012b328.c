/* leon2m FUN_a012b328 @ 0xa012b328 (-mcpu=v8 -O2)
 */
typedef struct {
    unsigned char _pad[3];
    unsigned char val;
    unsigned char _pad2[18];
} elem_t;

extern elem_t DAT_a802d8ae[]; /* 0xa802d8ae */
extern int FUN_a0137aec(unsigned int, unsigned int); /* 0xa0137aec */

int FUN_a012b328(unsigned int param_1, unsigned int param_2)
{
    DAT_a802d8ae[param_1 & 0xff].val = param_2;
    return FUN_a0137aec(param_1 & 0xff, param_2 & 0xff);
}
