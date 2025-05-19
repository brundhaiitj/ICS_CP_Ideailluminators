##Mini Voting Machine Program - README

Introduction

This is a simple console-based voting machine program written in C. The program allows users to add candidates, display candidate information, vote, and view the election results.

Environment Setup

To execute the program, make sure you have the following:

GCC (GNU Compiler Collection) installed on your system. You can download it here.
Compilation

Open a terminal in the directory where the program file (B23CH1015_B23ME1002_B23EE1040_B23CY1007.c) is located. Use the following command to compile the program:

gcc B23CH1015_B23ME1002_B23EE1040_B23CY1007.c -o voting_machine
This command will generate an executable file named voting_machine.

Execution

After successful compilation, run the program using the following command:

./voting_machine
This will start the program, and you will be prompted with a menu to choose from different options.

Usage

Adding Candidates (Option 1):

Enter the number of candidates.
For each candidate, provide a name and choose a symbol from the available options.
Showing Candidates (Option 2):

Displays the list of candidates with their names and symbols.
Voting (Option 3):

Enter the number of voters.
For each voter, provide a name and age.
Choose a candidate by entering the corresponding number.
Viewing Results (Option 4):

Displays the winner or indicates if there is no majority.
Exiting the Program (Option 5):

Terminates the program.
Note

Ensure that the symbols array (char symbols[25]) and the number of symbols in the loop (for (int j = 0; j < 13; j++)) are consistent. If you add more symbols, adjust these values accordingly.

The program may need adjustments based on your system's C compiler or any specific requirements.

Example

$ ./voting_machine
1. Add candidates.
2. Show candidates.
3. Vote.
4. Result.
5. Exit.
Enter choice number: 1

Enter the number of candidates: 3
Enter name of candidate 1: Alice
Available Symbols:
1. !
2. @
3. #
4. $
5. %
6. ^
7. &
8. *
9. +
10. =
11. |
12. ~
13. ?
Enter the symbol number of candidate 1: 1

...

Enter choice number: 3
Enter the number of voters: 2
Enter name of voter 1: Hiro
Enter age: 25

Name of candidate number 1: Alice
Symbol of candidate number 1: !

Name of candidate number 2: Elsa
Symbol of candidate number 2: $

Name of candidate number 3: Ana
Symbol of candidate number 3: ~
Voter 1, please enter your choice (1-3): 2

...

Enter choice number: 4
Candidate Elsa with symbol $ won with 1 votes

...

Enter choice number: 5
Exiting the program. Thank you!
