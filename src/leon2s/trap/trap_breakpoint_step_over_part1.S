! trap_breakpoint_step_over_part1  (FUN_a00604e0)
!
! Copy the instruction at the breakpoint into a RAM slot.
! Note: Ghidra piece 1 of the routine 0xA00604E0..0xA00604FB, not callable on its own; entered from trap-table
!   slot 0xB, and 0xA8076090 holds 'jmp %g1'.
! Name basis: proven - trap-table slot 0xB jumps to 0x4E0; trap-name table: 'Hardware breakpoint match'
!
! Matching notes
! --------------
! leon2s FUN_a00604e0 @ 0xa00604e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00604e0
	.type FUN_a00604e0, #function
FUN_a00604e0:
! Handler of trap type 0x0B, watchpoint_detected (slot trap_type_0b_entry; the trap-name table calls it
! 'Hardware breakpoint match'). It copies the trapped instruction to RAM 0xA807608C and runs it there.
! The next two RAM words hold 'jmp %g1' (start value 0x81C04000) and a nop (0x01000000), so after the
! copy the processor jumps to the old nPC, which the handler puts in %g1 (the trapped code's %g1 is lost).
	ld  [ %l1 ], %l5                  ! load the trapped instruction word (at the trapped PC, %l1)
	sethi  %hi(0xa8076000), %l6       ! upper bits of the RAM slot
	or  %l6, 0x8c, %l6                ! %l6 = RAM slot 0xA807608C
	st  %l5, [ %l6 ]                  ! store the instruction word there
	.size FUN_a00604e0, .-FUN_a00604e0
