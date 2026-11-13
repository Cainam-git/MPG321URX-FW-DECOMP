! irq_entry_part2  (FUN_a00603b0)
!
! Copy the trap nPC and raise the interrupt level to 15.
! Note: Ghidra piece 2 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a00603b0 @ 0xa00603b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603b0
	.type FUN_a00603b0, #function
FUN_a00603b0:
! Part 2 of irq_entry (0xA00603AC..0xA006048B).
	mov  %l2, %l6                     ! keep the interrupted nPC in %l6
	rd  %psr, %l0                     ! %l0 = PSR
	or  %l0, 0xf00, %l0               ! interrupt level 15: mask all maskable interrupts
	mov  %l0, %psr                    ! write PSR (traps still off)
	.size FUN_a00603b0, .-FUN_a00603b0
