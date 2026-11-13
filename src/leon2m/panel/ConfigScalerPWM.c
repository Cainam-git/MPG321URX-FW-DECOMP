/* ConfigScalerPWM  (FUN_a011d748)
 *
 * Set a PWM channel's clock source, prescaler and divider for a frequency and route it to a pin.
 * Note: Pin 0..27 is switched to its PWM function, any other number leaves the pins alone. A channel without
 *   registers (7) writes nothing; System_Initialize calls it that way.
 * Name basis: proven - prints 'ConfigScalerPWM only support MPLLCLK_96MHz and REFCLK_12MHz' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011d748 @ 0xa011d748-0xa011dd9c (1620 bytes), flags -mcpu=v8 -O3 -g.
 * Jump tables of the two channel switches at 0xa011d304 (read) and 0xa011d214 (write), of the pin switch at
 * 0xa011d294 (pin 16 is listed last).
 * Source forms the exact build depends on:
 *  - K&R definition (channel and pin are masked at each use);
 *  - divider is an unsigned short (the 'and 0x510' over the three divider values); prescale_word is an
 *    unsigned char;
 *  - the error flag failed is reused for the low byte of the period after the read switch;
 *  - the case order of both channel switches (as listed) decides the register names in the case blocks.
 */
#define REG(a) (*(volatile unsigned int *)(a))

extern int dbg_printf(const char *, ...);
extern void gpio_set_pin_function(unsigned char, unsigned char, unsigned int);

/* The two clock sources, by the firmware's own text. */
#define PWM_CLOCK_REFCLK_12MHZ  0
#define PWM_CLOCK_MPLLCLK_96MHZ 1
#define PWM_CLOCK_SOURCE_MASK   3       /* bits 0..1 of the control register */

/* PWM channels with their own clock registers: 1..6, 25 and 26. Channels 16..24 and 31 share one set. */
#define PWM_GROUP_FIRST 0x10
#define PWM_GROUP_COUNT 9               /* channels 16..24 */
#define PWM_GROUP_EXTRA 0x1f            /* channel 31, also in the group */
#define PWM_CH25        0x19
#define PWM_CH26        0x1a

/* Register set of a channel: three words. */
#define PWM_BLOCK(n)    (0xcf016120 + 0x18 * ((n) - 1))  /* channels 1..6 */
#define PWM_GROUP_BLOCK 0xcf016400
#define PWM_CH25_BLOCK  0xcf016494
#define PWM_CH26_BLOCK  0xcf0164c0
#define PWM_CONTROL     0x0             /* bits 0..1 clock source (bit 7 on/off, bits 4..5 mode: other routines) */
#define PWM_PRESCALE    0x4             /* bits 0..3 prescaler shift, bits 4..5 period bits 8..9, bits 6..7 kept */
#define PWM_PERIOD      0x8             /* period bits 0..7 */
#define PWM_CONTROL_KEEP_MASK  0xfc     /* everything but the clock source */
#define PWM_PRESCALE_KEEP_MASK 0xc0
#define PWM_PERIOD_MAX         0x3ff    /* the period has 10 bits */
#define PWM_PRESCALE_SHIFT_MAX 0xf

/*
 * Set up the clock of one PWM channel so that it runs at the given frequency, and route it to an output pin.
 *
 *   channel       1..6, 16..24, 31, 25 or 26; any other number is left alone (only the clock check runs)
 *   pin           0..27: output pin to switch to the PWM function; 0xff (passed by SetPSMMixMode and the blur reduction routines)
 *                 or any number above 27 leaves the pins alone
 *   frequency_hz  PWM frequency in hertz
 *   clock_source  PWM_CLOCK_MPLLCLK_96MHZ or PWM_CLOCK_REFCLK_12MHZ (only bits 0..1 count); channels 16..24 and
 *                 31 always use the 12 MHz clock
 *
 * Callers: System_Initialize, sys_mode_set_pwm7_and_continue, SetPSMMixMode and the panel_blurfree_* routines.
 * System_Initialize and sys_mode_set_pwm7_and_continue pass channel 7, which has no registers here: for that
 * channel nothing is written and no pin is changed.
 *
 * Phases, in order:
 *   1. pick the input clock: 96 MHz or 12 MHz; any other source prints an error and returns;
 *   2. pick a first prescaler (1/1024, 1/256 or 1/16, by the undivided period) and compute the period: the
 *      number of prescaled clock ticks per PWM cycle, rounded, minus 1;
 *   3. while the period does not fit in 10 bits, halve the prescaled clock once more (up to 1/32768);
 *   4. read the bits of the prescaler register that are kept (bits 6..7); an unknown channel returns here;
 *   5. write the clock source (not for the shared group), the prescaler with period bits 8..9, and period
 *      bits 0..7;
 *   6. switch the chosen output pin to its PWM function.
 */
void ConfigScalerPWM(channel, pin, frequency_hz, clock_source)
unsigned char channel;
unsigned char pin;
unsigned int frequency_hz;
unsigned int clock_source;
{
  unsigned int clock_hz;
  unsigned int period;
  unsigned int kept_bits;
  unsigned char prescale_word;
  unsigned short divider;
  unsigned char prescale_shift;     /* the clock is divided by 2 to the power of this */
  unsigned char failed;

  /* 1. Input clock. The shared group has no clock source bits of its own. */
  if ((((unsigned char) (channel - PWM_GROUP_FIRST)) < PWM_GROUP_COUNT) || (((unsigned char) channel) == PWM_GROUP_EXTRA))
  {
    clock_source = PWM_CLOCK_REFCLK_12MHZ;
  }
  clock_source &= PWM_CLOCK_SOURCE_MASK;
  if (clock_source == PWM_CLOCK_MPLLCLK_96MHZ)
  {
    clock_hz = 96000000;
  }
  else
    if (clock_source == PWM_CLOCK_REFCLK_12MHZ)
  {
    clock_hz = 12000000;
  }
  else
  {
    dbg_printf("ConfigScalerPWM only support MPLLCLK_96MHz and REFCLK_12MHz\r\n");
    return;
  }

  /* 2. First prescaler, chosen by the undivided period; divider = 2 ** prescale_shift. The 'times 10, minus 5,
     divided by 10' rounds the tick count and takes 1 off. */
  period = (((clock_hz * 10) / frequency_hz) - 5) / 10;
  prescale_shift = 10;
  divider = 0x400;
  if (period < 0x400)
  {
    prescale_shift = 8;
    divider = 0x100;
    if (period < 0x100)
    {
      prescale_shift = 4;
      divider = 0x10;
    }
  }
  period = ((((clock_hz * 10) / divider) / frequency_hz) - 5) / 10;

  /* 3. Make the period fit in 10 bits. */
  while (prescale_shift < PWM_PRESCALE_SHIFT_MAX)
  {
    if (period <= PWM_PERIOD_MAX)
    {
      break;
    }
    prescale_shift++;
    period >>= 1;
  }

  /* 4. Bits 6..7 of the prescaler register are kept. */
  failed = 0;
  switch ((unsigned char) channel)
  {
    case PWM_CH26:
      kept_bits = REG(PWM_CH26_BLOCK + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    case 6:
      kept_bits = REG(PWM_BLOCK(6) + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    case 3:
      kept_bits = REG(PWM_BLOCK(3) + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    case PWM_CH25:
      kept_bits = REG(PWM_CH25_BLOCK + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    case 1:
      kept_bits = REG(PWM_BLOCK(1) + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    case 2:
      kept_bits = REG(PWM_BLOCK(2) + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case PWM_GROUP_EXTRA:
      kept_bits = REG(PWM_GROUP_BLOCK + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    case 4:
      kept_bits = REG(PWM_BLOCK(4) + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
    default:
      kept_bits = 0;
      failed = 1;
      break;
    case 5:
      kept_bits = REG(PWM_BLOCK(5) + PWM_PRESCALE) & PWM_PRESCALE_KEEP_MASK;
      break;
  }

  if (failed)
  {
    return;
  }

  /* 5. Program the channel. failed now carries the low byte of the period. */
  prescale_word = ((period >> 4) & 0x30) | (kept_bits | prescale_shift);
  failed = period;
  switch ((unsigned char) channel)
  {
    case 5:
      REG(PWM_BLOCK(5) + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_BLOCK(5) + PWM_CONTROL) |= clock_source;
      REG(PWM_BLOCK(5) + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_BLOCK(5) + PWM_PERIOD) = failed & 0xff;
      break;
    case 4:
      REG(PWM_BLOCK(4) + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_BLOCK(4) + PWM_CONTROL) |= clock_source;
      REG(PWM_BLOCK(4) + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_BLOCK(4) + PWM_PERIOD) = failed & 0xff;
      break;
    case 1:
      REG(PWM_BLOCK(1) + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_BLOCK(1) + PWM_CONTROL) |= clock_source;
      REG(PWM_BLOCK(1) + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_BLOCK(1) + PWM_PERIOD) = failed & 0xff;
      break;
    case 6:
      REG(PWM_BLOCK(6) + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_BLOCK(6) + PWM_CONTROL) |= clock_source;
      REG(PWM_BLOCK(6) + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_BLOCK(6) + PWM_PERIOD) = failed & 0xff;
      break;
    case 3:
      REG(PWM_BLOCK(3) + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_BLOCK(3) + PWM_CONTROL) |= clock_source;
      REG(PWM_BLOCK(3) + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_BLOCK(3) + PWM_PERIOD) = failed & 0xff;
      break;
    case 2:
      REG(PWM_BLOCK(2) + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_BLOCK(2) + PWM_CONTROL) |= clock_source;
      REG(PWM_BLOCK(2) + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_BLOCK(2) + PWM_PERIOD) = failed & 0xff;
      break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case PWM_GROUP_EXTRA:
      /* The group's clock source bits are cleared and not set. */
      REG(PWM_GROUP_BLOCK + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_GROUP_BLOCK + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_GROUP_BLOCK + PWM_PERIOD) = failed & 0xff;
      break;
    case PWM_CH25:
      REG(PWM_CH25_BLOCK + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_CH25_BLOCK + PWM_CONTROL) |= clock_source;
      REG(PWM_CH25_BLOCK + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_CH25_BLOCK + PWM_PERIOD) = failed & 0xff;
      break;
    case PWM_CH26:
      REG(PWM_CH26_BLOCK + PWM_CONTROL) &= PWM_CONTROL_KEEP_MASK;
      REG(PWM_CH26_BLOCK + PWM_CONTROL) |= clock_source;
      REG(PWM_CH26_BLOCK + PWM_PRESCALE) = prescale_word & 0xff;
      REG(PWM_CH26_BLOCK + PWM_PERIOD) = failed & 0xff;
      break;
  }

  /* 6. Output pin: gpio_set_pin_function(pin group, pin bit, function code); pins 0..15 get function code 5,
     pins 16..27 function code 10. */
  switch ((unsigned char) pin)
  {
    case 0:  gpio_set_pin_function(0xb, 1, 5); break;
    case 1:  gpio_set_pin_function(0xf, 4, 5); break;
    case 2:  gpio_set_pin_function(0xa, 1, 5); break;
    case 3:  gpio_set_pin_function(0xb, 2, 5); break;
    case 4:  gpio_set_pin_function(0xf, 8, 5); break;
    case 5:  gpio_set_pin_function(0xa, 2, 5); break;
    case 6:  gpio_set_pin_function(5, 4, 5); break;
    case 7:  gpio_set_pin_function(0xb, 4, 5); break;
    case 8:  gpio_set_pin_function(0xf, 0x10, 5); break;
    case 9:  gpio_set_pin_function(5, 8, 5); break;
    case 10: gpio_set_pin_function(0xb, 8, 5); break;
    case 11: gpio_set_pin_function(0xf, 0x20, 5); break;
    case 12: gpio_set_pin_function(0xf, 0x40, 5); break;
    case 13: gpio_set_pin_function(0xd, 0x40, 5); break;
    case 14: gpio_set_pin_function(0xf, 0x80, 5); break;
    case 15: gpio_set_pin_function(0xd, 0x80, 5); break;
    case 17: gpio_set_pin_function(0xb, 1, 0xa); break;
    case 18: gpio_set_pin_function(9, 2, 0xa); break;
    case 19: gpio_set_pin_function(0xb, 2, 0xa); break;
    case 20: gpio_set_pin_function(9, 4, 0xa); break;
    case 21: gpio_set_pin_function(0xb, 4, 0xa); break;
    case 22: gpio_set_pin_function(9, 8, 0xa); break;
    case 23: gpio_set_pin_function(0xb, 8, 0xa); break;
    case 24: gpio_set_pin_function(9, 0x10, 0xa); break;
    case 25: gpio_set_pin_function(9, 0x20, 0xa); break;
    case 26: gpio_set_pin_function(9, 0x40, 0xa); break;
    case 27: gpio_set_pin_function(9, 0x80, 0xa); break;
    case 16: gpio_set_pin_function(9, 1, 0xa); break;
  }
}
