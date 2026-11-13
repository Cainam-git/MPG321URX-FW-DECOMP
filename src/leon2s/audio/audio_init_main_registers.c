/* audio_init_main_registers  (FUN_a008a470)
 *
 * Load the start values of the main audio control registers.
 * Name basis: descriptive - fixed writes to 0xCF011000..0xCF011080; caller audio_configure
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. Leaf. In each of the four blocks 0xcf011058 is written before 0xcf01105c;
 * 0xcf011018 gets one read-modify-write only.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

extern char audio_config;

#define _DAT_cf011000 (*(volatile unsigned int *)0xcf011000)
#define _DAT_cf011004 (*(volatile unsigned int *)0xcf011004)
#define reg_audio_main_control (*(volatile unsigned int *)0xcf011008)
#define _DAT_cf01100c (*(volatile unsigned int *)0xcf01100c)
#define _DAT_cf011010 (*(volatile unsigned int *)0xcf011010)
#define _DAT_cf011014 (*(volatile unsigned int *)0xcf011014)
#define _DAT_cf011018 (*(volatile unsigned int *)0xcf011018)
#define _DAT_cf011048 (*(volatile unsigned int *)0xcf011048)
#define _DAT_cf011058 (*(volatile unsigned int *)0xcf011058)
#define _DAT_cf01105c (*(volatile unsigned int *)0xcf01105c)
#define _DAT_cf011080 (*(volatile unsigned int *)0xcf011080)
#define _DAT_cf0114b0 (*(volatile unsigned int *)0xcf0114b0)

/*
 * Put the main audio register block (0xCF011000..0xCF011080) into its start state. No parameters, no
 * return value. audio_configure (mailbox command 0x90) calls it once during the fixed start-up and again
 * when bit 0 of its configuration byte 2 is set.
 *
 * Order: clear bit 2 of 0xCF0114B0; write the registers 0x00, 0x04, 0x08, 0x0C, 0x10, 0x58, 0x5C four
 * times in a row with changing values, so the last values stay (0x04 = 0xEE, 0x08 = 1, 0x0C = 0,
 * 0x10 = 0xFC); then, when bit 0 of audio_config[0] is set, set bit 5 of 0xCF011008; at the end write
 * 0xCF011014 = 0xFF and set bits in 0xCF011048 (0x60), 0xCF011080 (0x30) and 0xCF011018 (0x0C).
 */
void audio_init_main_registers(void)
{
  /* Block values of 0x04, 0x08, 0x0C, 0x10: (0,0,0x12,1), (0xEE,0,0x12,0), (0xEE,1,2,0xFC), (0xEE,1,0,0xFC).
     0x00 is 0 and 0x58 / 0x5C are 0xC6 in every block. */
  _DAT_cf0114b0 = _DAT_cf0114b0 & 0xfffffffb;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0;
  reg_audio_main_control = 0;
  _DAT_cf01100c = 0x12;
  _DAT_cf011010 = 1;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0xee;
  reg_audio_main_control = 0;
  _DAT_cf01100c = 0x12;
  _DAT_cf011010 = 0;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0xee;
  reg_audio_main_control = 1;
  _DAT_cf01100c = 2;
  _DAT_cf011010 = 0xfc;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0xee;
  reg_audio_main_control = 1;
  _DAT_cf01100c = 0;
  _DAT_cf011010 = 0xfc;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  /* audio_config is the first of the three configuration bytes kept by audio_configure */
  if ((audio_config & 1) != 0) {
    reg_audio_main_control = reg_audio_main_control | 0x20;
  }
  _DAT_cf011014 = 0xff;
  _DAT_cf011048 = _DAT_cf011048 | 0x60;
  _DAT_cf011080 = _DAT_cf011080 | 0x30;
  _DAT_cf011018 = _DAT_cf011018 | 0xc;
}
