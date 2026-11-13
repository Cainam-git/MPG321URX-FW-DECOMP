/* hdmi_rx21_init_reg2d_bits  (FUN_a00a2b08)
 *
 * Set the start-up bits of control register 0x2D of both HDMI 2.1 receivers.
 *   mode
 * Name basis: descriptive - bit 0xE always, bit 0xA by mode, bit 8 cleared in mode 0; caller
 *   _hdmi21_Initialize
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2b08 @ 0xa00a2b08 (-mcpu=v8 -Os -g)
 * Source forms the exact build depends on: the byte counter is masked with & 0xff at each use, the loop is a
 * do-while ending at rx <= 1, and the routine returns int 0.
 */
/* Two rows of 0x34 bytes, one per HDMI 2.1 receiver: the addresses of the receiver's register blocks. Word 0
   of a row is the block that holds control register 0x2D. */
extern unsigned char hdmi_rx21_reg_blocks;
extern void reg_set_bit(unsigned int bit, int address);
extern void reg_clear_bit(unsigned int bit, int address);

#define RX21_COUNT          2
#define RX21_ROW_SIZE       0x34
#define RX21_FIRST_BLOCK(rx) (*(int *)(&hdmi_rx21_reg_blocks + ((rx) & 0xff) * RX21_ROW_SIZE))
#define RX21_REG_2D         (0x2d * 4)      /* byte offset of control register 0x2D in its block */

/*
 * Set the start-up state of three bits of control register 0x2D of both HDMI 2.1 receivers.
 *
 *   mode  1: set bits 14 and 10; 0: set bit 14, clear bits 8 and 10; any other value: set bit 14 only
 *
 * Returns 0. Called once by _hdmi21_Initialize, with mode 1.
 */
int hdmi_rx21_init_reg2d_bits(unsigned char mode)
{
    unsigned char rx;

    rx = 0;
    do {
        reg_set_bit(14, RX21_FIRST_BLOCK(rx) + RX21_REG_2D);
        if (mode == 1) {
            reg_set_bit(10, RX21_FIRST_BLOCK(rx) + RX21_REG_2D);
        }
        else if (mode == 0) {
            reg_clear_bit(8, RX21_FIRST_BLOCK(rx) + RX21_REG_2D);
            reg_clear_bit(10, RX21_FIRST_BLOCK(rx) + RX21_REG_2D);
        }
        rx++;
    } while ((rx & 0xff) <= RX21_COUNT - 1);
    return 0;
}
