! trap_window_overflow_entry  (FUN_a0028050)
!
! Trap table slot 0x05 (window overflow): reads %psr and %tbr and jumps to the handler at 0xa0029278.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028050 @ 0xa0028050  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028050
	.type FUN_a0028050, #function
FUN_a0028050:
! Slot of trap type 0x05, window_overflow. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! the window-overflow handler in trap_handle_faults (0xA0029278), which writes the
! next register window to its stack so that the SAVE can be retried.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA0029278
	jmp  %l4 + 0x278                  ! jump to 0xA0029278: window-overflow handler
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0028050, .-FUN_a0028050
