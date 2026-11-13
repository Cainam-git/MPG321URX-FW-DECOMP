/* audio_init_ctrl_registers  (FUN_a008a6f4)
 *
 * Load fixed values into the audio control registers.
 * Name basis: descriptive - fixed writes to 0xCF0110C0..0xCF011100 and 0xCF0114B4; caller audio_configure
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008a6f4 @ 0xa008a6f4 (-mcpu=v8 -Os -g)
 * Each register is accessed through a volatile 32-bit macro named by its address.
 */
#define REG_cf0110c0 (*(volatile unsigned int *)0xcf0110c0)
#define REG_cf0110c4 (*(volatile unsigned int *)0xcf0110c4)
#define REG_cf0110d4 (*(volatile unsigned int *)0xcf0110d4)
#define REG_cf0110d8 (*(volatile unsigned int *)0xcf0110d8)
#define REG_cf0110dc (*(volatile unsigned int *)0xcf0110dc)
#define REG_cf0110e0 (*(volatile unsigned int *)0xcf0110e0)
#define REG_cf0110e4 (*(volatile unsigned int *)0xcf0110e4)
#define REG_cf0110c8 (*(volatile unsigned int *)0xcf0110c8)
#define REG_cf0110cc (*(volatile unsigned int *)0xcf0110cc)
#define REG_cf011024 (*(volatile unsigned int *)0xcf011024)
#define REG_cf011100 (*(volatile unsigned int *)0xcf011100)
#define REG_cf0114b4 (*(volatile unsigned int *)0xcf0114b4)

/*
 * Load fixed values into the audio control registers. Called by audio_configure.
 *
 * Nine registers from 0xCF0110C0 to 0xCF0110E4 get constants, in the order of the code below (0xCF0110E4 is
 * the register audio_write_level_high_byte writes later). Then bits 6..7 of 0xCF011024 are set to 01 (bits
 * 0..5 kept), bits 5..7 of 0xCF011100 to 111 (bits 0..4 kept) and bit 7 of 0xCF0114B4 is cleared.
 */
void audio_init_ctrl_registers(void)
{
    REG_cf0110c0 = 0xf4;
    REG_cf0110c4 = 4;
    REG_cf0110d4 = 0;
    REG_cf0110d8 = 0x18;
    REG_cf0110dc = 0x50;
    REG_cf0110e0 = 0xf0;
    REG_cf0110e4 = 0x54;
    REG_cf0110c8 = 0;
    REG_cf0110cc = 0x3f;
    REG_cf011024 = (REG_cf011024 & 0x3f) | 0x40;
    REG_cf011100 = (REG_cf011100 & 0x1f) | 0xe0;
    REG_cf0114b4 = REG_cf0114b4 & ~0x80;
}
