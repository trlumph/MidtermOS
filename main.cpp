// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <csignal>
#include <unistd.h>

// Signal handler for SIGUSR1
void handle_sigusr1(int signal) {
    if (signal == SIGUSR1) {
        std::cout << "Hello!" << std::endl;
    }
}

// Signal handler for SIGUSR2
void handle_sigusr2(int signal) {
    if (signal == SIGUSR2) {
        exit(0);
    }
}

int main() {
    // Register signal handlers
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    while (true) {
        // Wait for signals
        pause();
    }

    return 0;
}
