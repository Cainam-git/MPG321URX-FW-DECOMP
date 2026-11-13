/* dp_ack_link_events  (FUN_a00856fc)
 *
 * Acknowledge the two event bits of a DP receiver and update register 0xAF.
 *   param_1: port
 * Name basis: descriptive - bit 1 of 0x4B1 / 0x4B2 written 2 then 0, then 0xB4 or 0x94 to 0xAF by bit 5 of
 *   0x409
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00856fc @ 0xa00856fc (-mcpu=v8 -Os -g)
 * Source form: the port is masked before and after dp_map_port, which gives the first two instructions. The
 * routine is declared with six parameters and the second and third are used as locals for the register
 * number 0xaf and the value 0x94 of the last write (a tail call).
 */
extern int dp_map_port(int);
extern int dp_paged_reg_read8(int, int);
extern void dp_paged_reg_write8(int, int, int);

/*
 * Acknowledge the event bits of a DP receiver. For each of the registers 0x4b1 and 0x4b2: when bit 1 is set,
 * write 2 and then 0 to it. After the 0x4b1 acknowledge, register 0xaf gets 0xb4 if bit 5 of register 0x409
 * is set; after the 0x4b2 acknowledge it gets 0x94 if that bit is clear.
 *   port: DP port, mapped to its receiver by dp_map_port
 * The other parameters are not used as inputs (the second and third hold 0xaf and 0x94 for the last write).
 */
void dp_ack_link_events(unsigned char port, int reg, int value,
                  int unused_4, int unused_5, int unused_6)
{
    unsigned int block;
    unsigned int status;

    block = dp_map_port(port & 0xff) & 0xff;

    status = dp_paged_reg_read8(block, 0x4b1);
    if ((status & 2) != 0) {
        dp_paged_reg_write8(block, 0x4b1, 2);
        dp_paged_reg_write8(block, 0x4b1, 0);
        status = dp_paged_reg_read8(block, 0x409);
        if ((status & 0x20) != 0) {
            dp_paged_reg_write8(block, 0xaf, 0xb4);
        }
    }

    status = dp_paged_reg_read8(block, 0x4b2);
    if ((status & 2) != 0) {
        reg = 0xaf;
        dp_paged_reg_write8(block, 0x4b2, 2);
        dp_paged_reg_write8(block, 0x4b2, 0);
        status = dp_paged_reg_read8(block, 0x409);
        if ((status & 0x20) == 0) {
            value = 0x94;
            dp_paged_reg_write8(block, reg, value);
        }
    }
}
