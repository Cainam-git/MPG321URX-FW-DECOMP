/* hdmi_rx21_init_register_pointers  (FUN_a0096204)
 *
 * Fill the register block pointers of both HDMI 2.1 receivers.
 * Name basis: derived - 13 words per record 0xA807DB00 = 0xCE009000 / 0xCE00A000 + k * 0x100
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0096204 @ 0xa0096204-0xa00962ec (58 words), flags -mcpu=v8 -Os -g -msoft-float.
 * Source form: the 13 words are separate named members, stored in ascending order. With an array member the word-0
 * store ([base + i * 0x34]) is ordered against the other twelve stores and is scheduled early; as separate members
 * the stores are independent, which gives the firmware's register pressure and spill choices. -msoft-float gives
 * the firmware's set of constants moved out of the loop. The block address is written as (receiver << 12) plus a
 * constant that is folded first.
 */
/* Register block k of HDMI 2.1 receiver i: 0xCE009000 + k * 0x100, plus 0x1000 for receiver 1. */
#define RX21_BLOCK(i, k) (((i) << 12) + (0xce009000 + (k) * 0x100))

/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of its 13 register blocks. */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;
    unsigned int block1;
    unsigned int block2;
    unsigned int block3;
    unsigned int block4;
    unsigned int block5;
    unsigned int block6;
    unsigned int block7;
    unsigned int block8;
    unsigned int block9;
    unsigned int block10;
    unsigned int block11;
    unsigned int block12;
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Fill the table of register block addresses of both HDMI 2.1 receivers. The other HDMI 2.1 routines read their
 * registers through these addresses.
 */
void hdmi_rx21_init_register_pointers(void)
{
    unsigned char i;

    for (i = 0; i < 2; i++) {
        ARR_a807db00[i].block0 = RX21_BLOCK(i, 0);
        ARR_a807db00[i].block1 = RX21_BLOCK(i, 1);
        ARR_a807db00[i].block2 = RX21_BLOCK(i, 2);
        ARR_a807db00[i].block3 = RX21_BLOCK(i, 3);
        ARR_a807db00[i].block4 = RX21_BLOCK(i, 4);
        ARR_a807db00[i].block5 = RX21_BLOCK(i, 5);
        ARR_a807db00[i].block6 = RX21_BLOCK(i, 6);
        ARR_a807db00[i].block7 = RX21_BLOCK(i, 7);
        ARR_a807db00[i].block8 = RX21_BLOCK(i, 8);
        ARR_a807db00[i].block9 = RX21_BLOCK(i, 9);
        ARR_a807db00[i].block10 = RX21_BLOCK(i, 10);
        ARR_a807db00[i].block11 = RX21_BLOCK(i, 11);
        ARR_a807db00[i].block12 = RX21_BLOCK(i, 12);
    }
}
