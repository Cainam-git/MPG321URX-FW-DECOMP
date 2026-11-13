! irq_entry_part1  (FUN_a00603ac)
!
! Copy the trap PC to %l5 on interrupt entry (trap types 0x11..0x1F).
! Note: Ghidra piece 1 of the routine 0xA00603AC..0xA006048B, not callable on its own; vector table 0xA8076040
!   holds the level 1..15 service routines (0xA00608F8, 0xA00609FC, ...).
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a00603ac @ 0xa00603ac  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603ac
	.type FUN_a00603ac, #function
FUN_a00603ac:
! Common entry of every external interrupt (trap types 0x11..0x1F), from the slots
! trap_interrupt_level_1_entry..15_entry. On arrival %l0 = PSR and %l3 = TBR (from the slot), %l1 and
! %l2 = PC and nPC of the interrupted instruction (from the trap). Steps: mask all interrupts and turn
! traps on; keep TBR, PC and nPC at 0xA807FF60; make sure the trap window is a usable register window;
! save the global registers and Y; call the level's service routine from the vector table at
! 0xA8076040; put everything back and return to the interrupted instruction. On the way out the
! interrupt level is set to 0, not to the level the interrupted code had.
	mov  %l1, %l5                     ! keep the interrupted PC in %l5
	.size FUN_a00603ac, .-FUN_a00603ac
