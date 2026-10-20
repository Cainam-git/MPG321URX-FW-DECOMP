/* leon2m FUN_a00dffb4 @ 0xa00dffb4-0xa00dffcc (6 words).
 * Stores the three arguments in the words at 0xa802b530 (step), 0xa802b534 (phy) and 0xa802b538 (byte), the
 * values that FUN_a00df80c prints as "%s phy%d byte%d".
 */
struct Step {
    unsigned int step;
    unsigned int phy;
    unsigned int byte;
};
extern struct Step DAT_a802b530;

void FUN_a00dffb4(unsigned int step, unsigned int phy, unsigned int byte)
{
    DAT_a802b530.step = step;
    DAT_a802b530.phy = phy;
    DAT_a802b530.byte = byte;
}
