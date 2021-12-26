# SeaShell

       _____               _____ __         ____
      / ___/___  ____ _   / ___// /_  ___  / / /
      \__ \/ _ \/ __ `/   \__ \/ __ \/ _ \/ / / 
    ___/ /  __/ /_/ /   ___/ / / / /  __/ / /  
    /____/\___/\__,_/   /____/_/ /_/\___/_/_/   
                                            

                                 Version 1.0

            Jose Reyes : jreyes@mail.umw.edu



## Introduction 

This is a shell I wrote in C, hence it's name, Sea Shell. It's 
implementation consists of 3 parts. 
    
1. The Parser
2. The Executer
3. The Shell Subsystems

## The folder structure
The main sea.c file in the root. Everything inside term consists of getting the terminal running.
The loop prompt, and the existing commands part of the unix shell. Such as ps, ls, exit, help, etc.
run folder holds the code responsible for runnign the command. Line is everything required to parse
the input text from the terminal line.

    sea.c

    line -+

          |-- sea_read_line.h
          |-- sea_split_line.h

    run  -+

          |-- sea_execute.h

    term -+

          |-- sea_lopp.h
          |-- existing.h 


# 1. The Parser

sea_read_line.h as well as sea_split_line.h are the parsers. Read
saves the line from user input and sends it to split for processing.
The algorithm in both of these header files is the same. 

1. Create buffer
2. Allocate memory for buffer
3. Read input one char or one token at a time.
4. If we find EOF or \n then we've found the end and can terminate it.
5. Else we keep reading. 
6. If we reach the buffer limit, we must reallocate more memory.
7. return what we have accumilated in our buffer or token array.

Both programs work the same. Except read line returns a buffer and split
returns a array of tokens. 

# 2. The Executer
Now that we have all the information we need, we can use fork() to spawn
these new processes as needed to run commands. Exec() will spawn a brand 
new process instead of a copy. Then it returns wether it was successful
or not back to the calling process.

If it was successfull the child runs the command along with the arguments
given.

# 3. The Shell Subsytems
This section contains the existing calls that make everything sort of possible.
Commands liek exit(), help(), and so on. They are defined under existing.h 
sea_execute() decides wether or not to run the existing system call, or one
of my own functions built.
