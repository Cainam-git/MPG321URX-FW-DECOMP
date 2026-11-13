/* startup_init_input_blocks  (FUN_a00f87dc)
 *
 * Clear the per-block offsets and write the start values of all eight input capture blocks.
 * Name basis: descriptive - called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f87dc @ 0xa00f87dc, flags -mcpu=v8 -O3 -g.
 * Source form: the clearing loop counts with an unsigned int i and takes j = i & 0xff as the index; the loop
 * runs while j <= 7. The two register writers are declared with int parameters.
 */
extern unsigned short input_block_offsets[];                 /* 0xa802b7d8 */
extern void input_capture_write8(int, int, int);       /* 0xa00f1ad4 */
extern void input_capture_write16(int, int, int);       /* 0xa00f1d48 */

/* Block number that makes the input capture writers write all eight blocks (any number above 7 does). */
#define INPUT_CAPTURE_ALL_BLOCKS 8
#define INPUT_BLOCK_COUNT        8

/*
 * Start-up step: clear the stored offset of each of the eight input blocks, then write the start values of
 * ten capture registers in all eight input capture blocks. Register 0xc is the capture width that
 * input_block_set_capture_reg0e writes, and register 0xe the width plus the stored offset (0 here); what the
 * other registers are for is not shown. Called once by System_Initialize.
 */
void startup_init_input_blocks(void)
{
    unsigned int i = 0;
    unsigned int j = 0;

    do {
        input_block_offsets[j] = 0;
        i++;
        j = i & 0xff;
    } while (j < INPUT_BLOCK_COUNT);

    input_capture_write8(INPUT_CAPTURE_ALL_BLOCKS, 0x42, 0);
    input_capture_write8(INPUT_CAPTURE_ALL_BLOCKS, 6, 0);
    input_capture_write16(INPUT_CAPTURE_ALL_BLOCKS, 0xc, 0x20);
    input_capture_write16(INPUT_CAPTURE_ALL_BLOCKS, 0xe, 0);
    input_capture_write16(INPUT_CAPTURE_ALL_BLOCKS, 0x10, 0x1e0);
    input_capture_write16(INPUT_CAPTURE_ALL_BLOCKS, 0x12, 0x88);
    input_capture_write16(INPUT_CAPTURE_ALL_BLOCKS, 0x14, 0x280);
    input_capture_write8(INPUT_CAPTURE_ALL_BLOCKS, 0x16, 0);
    input_capture_write8(INPUT_CAPTURE_ALL_BLOCKS, 0, 0xa1);
    input_capture_write8(INPUT_CAPTURE_ALL_BLOCKS, 3, 0x80);
}
