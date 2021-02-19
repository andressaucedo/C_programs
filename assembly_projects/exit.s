#PURPOSE: Simple program that exits and returns a
#         status coe back to the linux kernel
#

#INPUT:   none
#

#OUTPUT:  returns a status code.  This can be viewed
#         by typing
#
#         echo $?
#
#         after running the program
#

#VARIABLES:
#           %eax holds the system call number
#           (this is always the case)
#
#           %ebx holds the return status
#
.section  .data

.section  .text
.globl _start
_start:
 movl $1, %eax      # this is the linux kernel command
                    # number (system call) for exiting
                    # a program

 movl $3, %ebx      # this is the status number we will
                    # return to the operating system.
                    # Change this around and it will
                    # return different things to
                    # echo $?

int $0x80           # this wakes up the kernel to run
                    # the exit command

# to assemble the code type 'as exit.s -o exit.o'
# the -o option tells assembler to output to exit.o (object file)
# once assembled, we must run the linker to link object files and run
# the program.
# to link the file type 'ld exit.o -o exit'
# this outputs the linked object files as an executable program
