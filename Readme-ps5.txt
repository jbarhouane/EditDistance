# PS5: DNA Alignment

## Contact
Name: Jessica Barhouane
Section: 11AM
Time to Complete: 9-10 hours

## Description
Explain what the project does.
It matches up DNA as much as it can with the least amount of "cost" when modifying the DNA sequences in order to find genetic similarities between people with certain conditions.  I couldn't find ps5-readme on blackboard so I just copied the one from 4a and filled it in. 

### Features
Describe what your major decisions were and why you did things that way.
I started with using a 2D array and when I finally got he program working it would not load ecoli28284.txt so I swapped it out for a 1D array in an attempt to reduce memory being used and it ended up working for the larger files. I decided to write everything down and take it step by step following the ps5.pdf as a guide for how to use Needleman and Wunsch method. I decided the best way to work my way back through the list was to subtract the current element in the matrix starting from (0, 0) from the lower + 2, lower-right + the penalty (0/1) and right elements + 2 and see which one is equals 0 to see where the next step will be. From this I was able to determine where to enter in '_'.

### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.
I used a lambda function to record the cost of each character comparison of the strings and std::min to get the minimum of three integers

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
Everything appeared to work on my end.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
I used a lambda function to calculate to record the cost of each character comparison of the strings.

### Valgrind Analysis
My program did not have any leaks when I ran valgrind on it.


## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.
