/* pq_window_write_coordinates  (FUN_a0101d9c)
 *
 * Write four 13-bit window coordinates after clearing the control register.
 * Name basis: descriptive - registers 0xCF00EC04..0xCF00EC24; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101d9c @ 0xa0101d9c-0xa0101e24 (34 words), flags -mcpu=v8 -O3 -g.
 */
/* Window coordinate registers: control, then low byte and high bits (8-12) for each of four coordinates. */
#define WINDOW_COORD_CTRL   (*(volatile unsigned int *)0xcf00ec04)
#define WINDOW_COORD0_LOW   (*(volatile unsigned int *)0xcf00ec08)
#define WINDOW_COORD0_HIGH  (*(volatile unsigned int *)0xcf00ec0c)
#define WINDOW_COORD1_LOW   (*(volatile unsigned int *)0xcf00ec10)
#define WINDOW_COORD1_HIGH  (*(volatile unsigned int *)0xcf00ec14)
#define WINDOW_COORD2_LOW   (*(volatile unsigned int *)0xcf00ec18)
#define WINDOW_COORD2_HIGH  (*(volatile unsigned int *)0xcf00ec1c)
#define WINDOW_COORD3_LOW   (*(volatile unsigned int *)0xcf00ec20)
#define WINDOW_COORD3_HIGH  (*(volatile unsigned int *)0xcf00ec24)

/*
 * Write four 13-bit window coordinates to the window coordinate registers.
 * The control register is cleared first, then each coordinate is split into
 * a low byte (bits 0-7) and a high part (bits 8-12) written to separate registers;
 * bits 13..15 are dropped.
 *
 * Nothing calls this routine.
 */
void pq_window_write_coordinates(unsigned short coord0, unsigned short coord1, unsigned short coord2, unsigned short coord3)
{
    WINDOW_COORD_CTRL = 0;
    WINDOW_COORD0_LOW = coord0 & 0xff;
    WINDOW_COORD0_HIGH = (coord0 >> 8) & 0x1f;
    WINDOW_COORD1_LOW = coord1 & 0xff;
    WINDOW_COORD1_HIGH = (coord1 >> 8) & 0x1f;
    WINDOW_COORD2_LOW = coord2 & 0xff;
    WINDOW_COORD2_HIGH = (coord2 >> 8) & 0x1f;
    WINDOW_COORD3_LOW = coord3 & 0xff;
    WINDOW_COORD3_HIGH = (coord3 >> 8) & 0x1f;
}
