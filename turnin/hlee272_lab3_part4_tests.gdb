# Test file for "Lab3"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x47 =>PORTB: 0x04 PORTC: 0x70"
# Set inputs
setPINA 0x47
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0x04
expectPORTC 0x70
# Check pass/fail
checkResult

# Add tests below
test "PINA: 0xFF => PORTB:0x0F  PORTC: 0xF0" 
setPINA 0xFF
continue 2
expectPORTB 0x0F
expectPORTC 0xF0
checkResult

test "PINA: 0x8A => PORTB: 0x08 PORTC: 0xA0"
setPINA 0x8A
continue 2
expectPORTB 0x08
expectPORTC 0xA0
checkResult

test "PINA: 0x3E => PORTB: 0x03  PORTC: 0xE0"
setPINA 0x3E
continue 2
expectPORTB 0x03
expectPORTC 0xE0
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
