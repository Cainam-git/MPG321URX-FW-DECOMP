/* pq_set_port_fill_color  (FUN_a010aae8)
 *
 * Write the three fill colour bytes of a port.
 * Name basis: derived - colour registers at 0xCF011FC4..; colour-fill path
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010aae8 @ 0xa010aae8-0xa010abd4 (59 words), flags -mcpu=v8 -O3 -g.
 * Source form: switch on port with four cases; no fall-through.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define PORT0_FILL_COLOR_0 0xcf011fc4
#define PORT0_FILL_COLOR_1 0xcf011fc8
#define PORT0_FILL_COLOR_2 0xcf011fcc
#define PORT1_FILL_COLOR_0 0xcf011fd0
#define PORT1_FILL_COLOR_1 0xcf011fd4
#define PORT1_FILL_COLOR_2 0xcf011fd8
#define PORT2_FILL_COLOR_0 0xcf011fdc
#define PORT2_FILL_COLOR_1 0xcf011fe0
#define PORT2_FILL_COLOR_2 0xcf011fe4
#define PORT3_FILL_COLOR_0 0xcf011fe8
#define PORT3_FILL_COLOR_1 0xcf011fec
#define PORT3_FILL_COLOR_2 0xcf011ff0

/*
 * Write the three fill colour bytes of a port.
 * Ports 0-3 have fixed hardware registers; other port numbers do nothing.
 *
 *   colour0..2  pq_api_set_fill_color passes its red, green and blue values in this order
 *
 * Callers: pq_api_set_fill_color (the port of the channel record) and sys_mode_restart_channel (0, 0, 0).
 */
void pq_set_port_fill_color(unsigned char port, unsigned char colour0, unsigned char colour1, unsigned char colour2)
{
    switch (port) {
    case 0: R(PORT0_FILL_COLOR_0) = colour0; R(PORT0_FILL_COLOR_1) = colour1; R(PORT0_FILL_COLOR_2) = colour2; break;
    case 1: R(PORT1_FILL_COLOR_0) = colour0; R(PORT1_FILL_COLOR_1) = colour1; R(PORT1_FILL_COLOR_2) = colour2; break;
    case 2: R(PORT2_FILL_COLOR_0) = colour0; R(PORT2_FILL_COLOR_1) = colour1; R(PORT2_FILL_COLOR_2) = colour2; break;
    case 3: R(PORT3_FILL_COLOR_0) = colour0; R(PORT3_FILL_COLOR_1) = colour1; R(PORT3_FILL_COLOR_2) = colour2; break;
    }
}
