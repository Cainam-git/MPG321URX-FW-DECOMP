/* hdmi_rx21_set_frl_clock  (FUN_a009ea34)
 *
 * Set the HDMI 2.1 receiver clock for the FRL rate (3, 6, 8, 10 or 12 GHz).
 *   receiver: receiver 0/1
 *   frl_rate: FRL rate 1..6
 * Name basis: proven - prints 'HRX FRL CLK 3GHz' .. '12GHz'; writes a nibble of register 0xCF01474C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009ea34 @ 0xa009ea34, flags -mcpu=v8 -Os -g.
 * Source form: one case per rate with the two register steps written out (and-mask, then or) as separate
 * statements; rates 2 and 3 share one case, which gives the firmware's jump table (index rate - 1).
 */

/* Texts printed for each clock (green "HRX FRL CLK <n>GHz"). */
extern unsigned int DAT_a006af70;               /* "HRX FRL CLK 3GHz" */
extern unsigned int DAT_a006af90;               /* "HRX FRL CLK 6GHz" */
extern unsigned int DAT_a006afb0;               /* "HRX FRL CLK 8GHz" */
extern unsigned int DAT_a006afd0;               /* "HRX FRL CLK 10GHz" */
extern unsigned int DAT_a006aff0;               /* "HRX FRL CLK 12GHz" */
extern int dbg_printf();

/* Clock select register of the two HDMI 2.1 receivers: one nibble per receiver. */
#define RX21_FRL_CLOCK_REG   (*(volatile unsigned int *)0xcf01474c)
#define RX21_0_CLOCK_KEEP    0xf0               /* receiver 0 owns bits 0..3: keep the other bits */
#define RX21_1_CLOCK_KEEP    0x0f               /* receiver 1 owns bits 4..7 */
#define RX21_1_CLOCK_SHIFT   4

/* Value of the nibble for each clock, in the order of the printed texts. */
enum frl_clock_code {
  FRL_CLOCK_3GHZ  = 0,
  FRL_CLOCK_6GHZ  = 1,
  FRL_CLOCK_8GHZ  = 2,
  FRL_CLOCK_10GHZ = 3,
  FRL_CLOCK_12GHZ = 4
};

/*
 * Select the receive clock of one HDMI 2.1 receiver for an FRL rate.
 *
 *   receiver  0 or 1: which nibble of RX21_FRL_CLOCK_REG is written; any other value only prints
 *   frl_rate  FRL rate 1..6 (only the low byte counts): 1 = 3 GHz, 2 and 3 = 6 GHz, 4 = 8 GHz, 5 = 10 GHz,
 *             6 = 12 GHz; any other value changes nothing and prints nothing
 *
 * Prints the chosen clock, clears the receiver's nibble and writes the clock code into it (for 3 GHz the code
 * is 0, so the clear alone sets it). Only caller: hdmi_rx21_set_frl_clock_wrapper.
 */
void hdmi_rx21_set_frl_clock(unsigned char receiver, unsigned int frl_rate)
{
  switch (frl_rate & 0xff)
  {
  case 1:
    dbg_printf(&DAT_a006af70);
    if (receiver == 0)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_0_CLOCK_KEEP;
    }
    else if (receiver == 1)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_1_CLOCK_KEEP;
    }
    break;
  case 2:
  case 3:
    dbg_printf(&DAT_a006af90);
    if (receiver == 0)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_0_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_6GHZ;
    }
    else if (receiver == 1)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_1_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_6GHZ << RX21_1_CLOCK_SHIFT;
    }
    break;
  case 4:
    dbg_printf(&DAT_a006afb0);
    if (receiver == 0)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_0_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_8GHZ;
    }
    else if (receiver == 1)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_1_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_8GHZ << RX21_1_CLOCK_SHIFT;
    }
    break;
  case 5:
    dbg_printf(&DAT_a006afd0);
    if (receiver == 0)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_0_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_10GHZ;
    }
    else if (receiver == 1)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_1_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_10GHZ << RX21_1_CLOCK_SHIFT;
    }
    break;
  case 6:
    dbg_printf(&DAT_a006aff0);
    if (receiver == 0)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_0_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_12GHZ;
    }
    else if (receiver == 1)
    {
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG & RX21_1_CLOCK_KEEP;
      RX21_FRL_CLOCK_REG = RX21_FRL_CLOCK_REG | FRL_CLOCK_12GHZ << RX21_1_CLOCK_SHIFT;
    }
    break;
  }
}
