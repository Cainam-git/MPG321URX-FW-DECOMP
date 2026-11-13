! startup_reset_entry_part5  (FUN_a0060300)
!
! Call sys_main; the 'ta 1' loop behind the call is never reached.
! Note: Ghidra piece 5 of the routine 0xA00602C0..0xA0060313, not callable on its own. Sits in the trap table
!   slot of type 0x30.
! Name basis: proven - trap-table slot 0 (reset) jumps to 0x2C0; trap-name table says 'Power-on reset'; part 5
!   calls main 0xA0060864
!
! Labels used below:
!   FUN_a0060864 = sys_main_part1
!
! Matching notes
! --------------
! leon2s FUN_a0060300 @ 0xa0060300  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060300
	.type FUN_a0060300, #function
FUN_a0060300:
! This slot (trap type 0x30) holds part 5 of the reset start-up, not a trap handler: it calls the
! main routine. sys_main ends in an endless loop, so the two instructions after the call are not reached.
! If they were: 'ta 1' is trap type 0x81, whose slot (0xA0060810) lies inside trap_save_crash_state.
	call FUN_a0060864                 ! call the main routine sys_main (0xA0060864)
	nop                               ! delay slot: nothing
.La0060308:
	ta  1                             ! raise software trap 1 (trap type 0x81)
	b .La0060308                      ! and again, for ever (delay slot: the nop at 0xA0060310)
	.size FUN_a0060300, .-FUN_a0060300
