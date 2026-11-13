/* dp_clear_status_event  (FUN_a00ab964)
 *
 * Clear one numbered status event of a DP receiver.
 *   port: DP receiver
 *   event: event 0..9
 * Name basis: descriptive - events 0..9 -> bit of status register 5 or registers 0x4E0/0x4E1; caller
 *   dp_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab964 @ 0xa00ab964, flags -mcpu=v8 -Os -g. Leaf.
 * Source form: every case ends in a tail call, each masking the port to its low byte; case 0 is written after
 * case 6, where the firmware places its block.
 */
extern void dp_status_reg_write8(unsigned char, unsigned short, unsigned int);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned int);

/*
 * Write the bit of one numbered status event of a DP receiver (called "clear" because that is what the
 * caller uses it for: dp_run_link_state calls it for events 0..9 when the port leaves the READY state).
 *
 * Event 0: bit 3, events 1 and 2: bit 4, event 3: bit 6, event 9: bit 2, all in status register 5.
 * Event 6: bit 2 of register 0x4E1, event 7: bit 3 of register 0x4E0, event 8: bit 0 of register 0x4E1.
 * Events 4, 5 and above 9 do nothing.
 *   port: DP receiver
 *   event: event number
 */
void dp_clear_status_event(unsigned int port, unsigned char event)
{
    switch (event) {
    case 1:
    case 2:
        dp_status_reg_write8(port, 5, 0x10);
        break;
    case 3:
        dp_status_reg_write8(port, 5, 0x40);
        break;
    case 6:
        dp_reg_write8(port, 0x4e1, 4);
        break;
    case 0:
        dp_status_reg_write8(port, 5, 8);
        break;
    case 7:
        dp_reg_write8(port, 0x4e0, 8);
        break;
    case 8:
        dp_reg_write8(port, 0x4e1, 1);
        break;
    case 9:
        dp_status_reg_write8(port, 5, 4);
        break;
    }
}
