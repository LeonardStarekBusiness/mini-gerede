*This project has been created as part of the 42 curriculum by lstarek*

# MINITALK by lstarek
This readme will concern only the evaluator in the context of a 42 school peer-evaluation.  

# DESCRIPTION
The purpose of this project is to code a small data exchange program using UNIX signals.  
The subject can be found [here](https://cdn.intra.42.fr/pdf/pdf/194907/en.subject.pdf)  
Text gets sent by the client bitwise using only the signals SIGUSR1 and SIGUSR2 and is recomposed by the server.  
Signals are not delayed per default, which is why the server acknowledges each signal by sending SIGUSR1 back everytime it recieves a signal, effectively completing the bonus.  
  
### IMPORTANT NOTE: The program may break in VSCode.  
it may work it may not. Please do not fail me if it works flawlessly with regular terminal windows.  

# INSTRUCTIONS
## Installation  
```bash
git clone <link_in_eval_sheet> <eval-"your_login">
```
## Compilation
Makefile is present.  
In root directory, run:  
```bash
make
```
## Execution
Server must be started first  
```bash
./server
```
It will print its PID (process id)  
Client must be run like:
```bash
./client <PID> <MESSAGE>
```

# RESOURCES
## Documentation  
(none)  

## Manual  
```bash
man sigaction
man siginfo_t
man kill
```

## Tutorials  
[Introduction to Unix Signals](https://youtu.be/83M5-NPDeWs?si=XYbqc5pwipAU8HNN)  

## AI?  
AI was passed my code and analysed it.  
It gave advice on where the issue may lie but was wrong in the end, little to no of the advice made it into my project.  
Using the handshake technique renders most of the concerns about data corruption obsolete.  
No code was directly written by AI.  