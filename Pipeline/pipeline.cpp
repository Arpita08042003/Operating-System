#include <iostream>
#include <unistd.h>
using namespace std;

void pipeline(const char* process1, const char* process2) {
    int fd[2];
    pipe(fd);
    if (fork() != 0) { // parent process
        close(fd[0]); // Close the read end of the pipe
        dup2(fd[1], STDOUT_FILENO); // Redirect standard output to the write end of the pipe
        close(fd[1]); // Close the write end of the pipe

        // Execute process1
        execlp("/bin/cat", "cat", "test.txt", nullptr);
        cerr << "Failed to execute " << process1 << std::endl;
    } else {
        close(fd[1]); // Close the write end of the pipe
        dup2(fd[0], STDIN_FILENO); // Redirect standard input to the read end of the pipe
        close(fd[0]); // Close the read end of the pipe

        // Execute process2
        execlp("/usr/bin/grep", "grep", "hello", nullptr);
        cerr << "Failed to execute " << process2 << std::endl;
    }
}

int main() {
    pipeline("cat test.txt", "grep hello");
    return 0;
}