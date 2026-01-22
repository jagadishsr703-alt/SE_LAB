SE_LAB TASK 1

In the code the input is taken as the roll number then the name of the student and the subject names and then along with that the minor and major marks of that subject.
then the code reads that and process the information parsing it from the file, the file name is taken from the user itself , the output is written to the file only
which is created by the program itself. 

the initial strucute is created with 8 members in the structure, for simplicity purspose only a single structure is used. then the validation checks are performed.

the specifications like :
	- student id must be unique
	- name must be only having the alphabets
	- marks of all 5 subjects were read.
	- rejection of invalid ids
	- rejection of names with symbols
	- reject marks outside range of 0 to 100.


the output consists of:
	- a table showing the id , name of the students , subject_1 minor subject-1 major subject1 total subject1 grade and so on for all 5 subjects and cgpa and percentage
	- after the table , class avg percentage , highest percentage, lower percentage are displayed.
	- then the grade distributions are displayed , showing how many students falls in what grade ranges.

error handles are handled with suitable messages.

