! irq_service_level5_part1  (FUN_a0060bb8)
!
! Enter the level-5 interrupt service routine.
! Note: Ghidra piece 1 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060bb8 @ 0xa0060bb8  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060bb8
	.type FUN_a0060bb8, #function
FUN_a0060bb8:
! Service routine of interrupt level 5 (entry 5 of the vector table at 0xA8076040),
! called by irq_entry. It masks the level and marks it active in 0x9F120028, then looks at its
! fourteen sources one by one: a source that is signalling, not masked and has a handler in
! the table at 0xA8078770 is acknowledged and its handler run, in the order the upper half
! of the source mask register sets for it. At the end it writes the level bit to 0x9F120034 and to
! the LEON2 interrupt clear register, drops the active bit and unmasks the level.
	save  %sp, -104, %sp              ! open a stack frame of 104 bytes (a new register window)
	sethi  %hi(0x9f100000), %o5       ! %o5 = 0x9F100000 (LEON2 interrupt registers)
	.size FUN_a0060bb8, .-FUN_a0060bb8
