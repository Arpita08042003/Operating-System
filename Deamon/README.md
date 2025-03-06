# Facts About Daemon Processes in OS

1. Background Execution

> - A daemon is a background process that runs independently of the user.
> - It typically starts at boot time and runs indefinitely.
2. No Controlling Terminal

> - Daemons detach from the terminal to avoid interruption by user input.
>- Standard input/output/error (stdin, stdout, stderr) are closed.
3. Created via Forking

> - A daemon is usually created by calling fork() twice to:
> > -Prevent being a session leader (avoiding terminal reattachment).
> > -Ensure it runs in the background.
4. Session & Process Group

> - The parent exits after forking, making the child process an orphan.
> - It is then adopted by init/systemd, ensuring independence.
 
5. Logging

> - Since daemons do not have a terminal, they log messages to files (/var/log/) or syslog.
6. Daemon Management Systems

> - *Linux:* Uses systemd, SysVinit, and upstart to manage daemons.
> - *Windows:* Uses Windows Services for daemon-like processes.

### Examples of Daemons

> - cron (Schedules tasks)
> - sshd (SSH server daemon)
> - httpd (Apache web server)
> - dbus-daemon (Message bus for IPC)
## Interview Questions on Daemon Processes
#### Basic Questions
1. What is a daemon process?
2. How is a daemon different from a regular process?
3. Why do daemons run in the background?
4. Give examples of common daemon processes in Linux.
5. How can you check if a daemon is running?
6. What is the purpose of setsid() in a daemon?
#### Intermediate Questions
1. How do you create a daemon process in C/C++?
2. Why do we use fork() twice to create a daemon?
3. What is umask(0), and why is it used in a daemon?
4. Why does a daemon change its working directory to /?
5. How does a daemon handle logging?
6. How do daemons communicate with other processes?
7. What happens if a daemon crashes?
8. How do you restart a daemon in Linux?
#### Advanced Questions
1. How does systemd manage daemon processes in Linux?
2. What is the difference between a daemon and a service?
3. How can a daemon process detect system shutdown?
4. How can a daemon be configured to restart automatically after failure?
5. How do you secure a daemon process?
6. What is the difference between a daemon and a zombie process?
7. Can a daemon process have child processes?
8. How do you kill a daemon process safely?

>- to check pid of running deamon
> > pgrep <nameOfDeamon>

>- to kill process
> > pkill <nameOfDeamon>



