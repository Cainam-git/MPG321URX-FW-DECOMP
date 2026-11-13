! irq_service_level6_part1  (FUN_a0060cbc)
!
! Enter the level-6 interrupt service routine.
! Note: Ghidra piece 1 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own; sources: status
!   0x9F120084 minus mask 0x9F12004C; handlers in 0xA8079388[0..4]; upper half of the mask word selects
!   acknowledge-after-call; handler table lies outside the initialised data (filled at run time).
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060cbc @ 0xa0060cbc  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060cbc
	.type FUN_a0060cbc, #function
FUN_a0060cbc:
! Service routine of interrupt level 6 (entry 6 of the vector table at 0xA8076040),
! called by irq_entry. It masks the level and marks it active in 0x9F120028, then looks at its
! five sources one by one: a source that is signalling, not masked and has a handler in
! the table at 0xA8079388 is acknowledged and its handler run, in the order the upper half
! of the source mask register sets for it. At the end it writes the level bit to 0x9F120034 and to
! the LEON2 interrupt clear register, drops the active bit and unmasks the level.
	save  %sp, -104, %sp              ! open a stack frame of 104 bytes (a new register window)
	.size FUN_a0060cbc, .-FUN_a0060cbc
