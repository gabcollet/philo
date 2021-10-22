# philo

**Philo project school 42**

<p align="center">
  <img width="820" height="180" src="https://i.ibb.co/j6WfC1m/Screen-Shot-2021-10-22-at-2-43-05-PM.png">
</p>

One or more philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping. 
While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.
The philosophers sit at a circular table with a large bowl of spaghetti in the center. There are some forks on the table.<br/>

To launch :
```
make && ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>
```
OR
```
make && ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>
```
# The rules are : <br/>
• As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.<br/>
• The philosophers must never be starving.<br/>
• Every philosopher needs to eat.<br/>
• Philosophers don’t speak with each other.<br/>
• Philosophers don’t know when another philosopher is about to die.<br/>
• Each time a philosopher has finished eating, he will drop his forks and start sleeping.<br/>
• When a philosopher is done sleeping, he will start thinking.<br/>
• The simulation stops when a philosopher dies.<br/>
• Each program should have the same options: <br/>
&nbsp;&nbsp;&nbsp;◦ **number_of_philosophers:** is the number of philosophers and also the number of forks<br/>
&nbsp;&nbsp;&nbsp;◦ **time_to_die:** is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies <br/>
&nbsp;&nbsp;&nbsp;◦ **time_to_eat:** is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.<br/>
&nbsp;&nbsp;&nbsp;◦ **time_to_sleep:** is in milliseconds and is the time the philosopher will spend sleeping.<br/>
&nbsp;&nbsp;&nbsp;◦ **number_of_times_each_philosopher_must_eat:** argument is optional, if all philosophers eat at least number_of_times_each_philosopher_must_eat the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.<br/>
• Each philosopher should be given a number from 1 to ’number_of_philosophers’.<br/>
• Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with the number N is seated between philosopher N - 1 and philosopher N + 1 <br/>
• Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds) <br/>
  &nbsp;&nbsp;&nbsp;◦ timestamp_in_ms X has taken a fork 
  &nbsp;&nbsp;&nbsp;◦ timestamp_in_ms X is eating <br/>
  &nbsp;&nbsp;&nbsp;◦ timestamp_in_ms X is sleeping<br/>
  &nbsp;&nbsp;&nbsp;◦ timestamp_in_ms X is thinking<br/>
  &nbsp;&nbsp;&nbsp;◦ timestamp_in_ms X died<br/>
• The status printed should not be scrambled or intertwined with another philosopher’s status.<br/>
• You can’t have more than 10 ms between the death of a philosopher and when it will print its death.<br/>
• Again, philosophers should avoid dying!<br/>
• One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.<br/>
• To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.<br/>
• Each philosopher should be a thread.<br/>

# Bonus rules :<br/>
• All the forks are in the middle of the table.<br/>
• They have no states in memory but the number of available forks is represented by a semaphore.<br/>
• Each philosopher should be a process and the main process should not be a philosopher.<br/>

```
make && ./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>
```
OR
```
make && ./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>
```
