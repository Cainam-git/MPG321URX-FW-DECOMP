/* pq_block_set_mode1_and_value  (FUN_a0104b2c)
 *
 * Set a picture block to mode 1 and write a value to its unit register.
 * Name basis: descriptive - register 0x54 = 1, then a register at 0xCF013800 / 0xCF01B000 by block; part of
 *   the shut-down sequence
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0104b2c @ 0xa0104b2c-0xa0104c34 (66 words), flags -mcpu=v8 -O3 -g.
 * Source form: one switch on the block (the firmware's jump table); block 0 shares the default arm.
 */

#define BLK_BLANK_MODE 0x54                     /* picture block register: 0 = show, 2 = blank */
#define ALL_PQ_BLOCKS  8                        /* block number that pq_block_write8 takes as "all eight blocks" */

/* Register 0 of the four port blocks (the bases in pq_port_reg_bases). */
#define PORT0_BLOCK_REG0 (*(volatile unsigned int *)0xcf013800)
#define PORT1_BLOCK_REG0 (*(volatile unsigned int *)0xcf013900)
#define PORT2_BLOCK_REG0 (*(volatile unsigned int *)0xcf013a00)
#define PORT3_BLOCK_REG0 (*(volatile unsigned int *)0xcf013b00)
/* The register pairs used for picture blocks 6 and 7: a value register and a control register at +0x7C. */
#define BLOCK6_UNIT_REG  (*(volatile unsigned int *)0xcf01b000)
#define BLOCK6_UNIT_CTRL (*(volatile unsigned int *)0xcf01b07c)
#define BLOCK7_UNIT_REG  (*(volatile unsigned int *)0xcf01b100)
#define BLOCK7_UNIT_CTRL (*(volatile unsigned int *)0xcf01b17c)

extern void pq_block_write8(unsigned char block, unsigned char reg, unsigned char value);

/*
 * Put a picture block into mode 1 (BLK_BLANK_MODE = 1) and write value to the unit register that belongs to it.
 *
 *   block  picture block 0..7, or ALL_PQ_BLOCKS (8) for all of them
 *   value  the byte written to the unit register(s)
 *
 * Blocks 1..3 write register 0 of port block 1..3; blocks 6 and 7 write the register at 0xCF01B000 / 0xCF01B100
 * and set bit 7 of the control register next to it. Block 8 does all six writes and sets both bits. Block 0,
 * blocks 4 and 5 and every other number write register 0 of port block 0.
 *
 * Its only caller is sys_shut_down_blocks, as the first step of the shut-down sequence, with block 8 and value
 * 0xB0.
 */
void pq_block_set_mode1_and_value(unsigned char block, unsigned char value)
{
    pq_block_write8(block, BLK_BLANK_MODE, 1);
    switch (block) {
    case 0:
    default:
        PORT0_BLOCK_REG0 = value;
        break;
    case 1:
        PORT1_BLOCK_REG0 = value;
        break;
    case 2:
        PORT2_BLOCK_REG0 = value;
        break;
    case 3:
        PORT3_BLOCK_REG0 = value;
        break;
    case 6:
        BLOCK6_UNIT_REG = value;
        BLOCK6_UNIT_CTRL |= 0x80;
        break;
    case 7:
        BLOCK7_UNIT_REG = value;
        BLOCK7_UNIT_CTRL |= 0x80;
        break;
    case ALL_PQ_BLOCKS:
        PORT0_BLOCK_REG0 = value;
        PORT1_BLOCK_REG0 = value;
        PORT2_BLOCK_REG0 = value;
        PORT3_BLOCK_REG0 = value;
        BLOCK6_UNIT_REG = value;
        BLOCK7_UNIT_REG = value;
        BLOCK6_UNIT_CTRL |= 0x80;
        BLOCK7_UNIT_CTRL |= 0x80;
        break;
    }
}
