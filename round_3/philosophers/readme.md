*This project has been created as part of the 42 curriculum by [rhoogend].*

**DESCRIPTION**
This readme file, offers a description of the philosophers and philosophers bonus project, this project challenges students to solve the classic pholosophers experiment created by Edsger Dijkstra. It is ment to teach you about the challenges/problems that can occur when you run concurrent processes. The goal is to keep an x number of philosophers alive by making them share food (limited resources) in such a way that none of them will starve. This is done by preventing all philosophers to try and use the same resource simultaneously and organizing your code in such a way that philosophers wait for there turn when needed, and having them take turns and wait in the most efficient manner. the main instruments used to manage this are mutexes or semaphores (to lock resources when they are at capacity) and the usleep function to temproarily pause execution and desynchronize processes in such a way that reaching for the same resource is minimized. 

**INSTRUCTIONS**
The program takes the following arguments in this order:
-number_of_philosophers 
-time_to_die 
-time_to_eat 
-time_to_sleep
-number_of_times_each_philosopher_must_eat (optional)

- you create the program by typing make in the terminal.
- you run it by typing ./philosophers [1] [2] [3] [4] [5] where the numbers represent the different arguments
-you press enter and the program will print updates on current states of the different philosophers. 

◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

*bonus*
the bonus works in a similar manner but the program will be names ./philo_bonus and thus to run it ./philo_bonus has to be typed in the terminal. 

**RESOURCES**
https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
https://www.geeksforgeeks.org/operating-systems/dining-philosopher-problem-using-semaphores/
https://en.wikipedia.org/wiki/Dining_philosophers_problem
https://www.geeksforgeeks.org/operating-systems/mutex-vs-semaphore/
https://www.youtube.com/watch?v=ZpRN3XQY4AA
https://chatgpt.com/


**Usage of AI**
-AI was used mostly to optimize parts of the code, strategic placements of Usleeps make a big difference and for this AI was very usefull. Furthermore, this project was made a period ago, AI was usefull for refreshing the recently attained knowledge about mutexes and semaphores.