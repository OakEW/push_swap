*This project has been created as part of the 42 curriculum by <login1>[ywang2]*

# Push_Swap

## Description
### Objectives

Sorting algorithms and their complexities are common topics in job interviews. Now is a great time to explore these concepts, as you will likely encounter them in the future. The learning objectives of this project are rigor, proficiency in C, and the application of basic algorithms, with a particular focus on their complexity.

### Goal
Writing an efficient sorting algorithm `push_swap` that sort a list of numbers in ascending order with 2 stacks and 11 operations (sa sb ss pa pb ra rb rr rra rrb rrr).

## Instructions
### Compile
Run `make` for push_swap<br />Run `make bonus` for checker

### Test

- `push_swap` takes as an argument the stack a formatted as a list of integers, display the shortest sequence of instructions needed to sort stack a with the smallest number at the top. 
  - If no parameters are specified, the program must not display anything and should return to the prompt.
  - In case of error, it must display "Error" followed by an ’\n’ on the standard error.
Errors include, for example: some arguments not being integers, some arguments
exceeding the integer limits, and/or the presence of duplicates<br />
- `checker`takes as an argument the stack a formatted
as a list of integers. If no argument is given, it stops and displays nothing.
  - It will then wait and read instructions from the standard input, with each instruction followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
  - In every other case, it must display "KO" followed by a ’\n’ on the standard output.
  - In case of error, you must display "Error" followed by a ’\n’ on the standard error. 


#### Benchmark

For **maximum project validation (100%)** and eligibility for bonuses, you must:<br />Sort 100 random numbers in fewer than **700** operations.<br />Sort 500 random numbers in no more than **5500** operations.

#### Tester

See links below

## Resources

Regarding **AI** : I did not use any AI assistant at all for the entire project.

>[**Push Swap — A journey to find most efficient sorting algorithm**](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) *by A. Yigit Ogun*

>[**push_swap_tester**](https://github.com/SimonCROS/push_swap_tester/tree/v2) *by SimonCROS*

>[**push_swap_visualizer**](https://github.com/o-reo/push_swap_visualizer) *by o-reo*

>[**Basic writing and formatting syntax**](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax) *(for Readme file)*
