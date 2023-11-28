// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <csignal>
#include <random>
#include <string>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <PID>" << std::endl;
        return 1;
    }

    char *end;
    long pid_long = strtol(argv[1], &end, 10);

    // Check for conversion errors and range
    if (*end != '\0' || pid_long <= 0 || pid_long > std::numeric_limits<pid_t>::max()) {
        std::cerr << "Invalid PID." << std::endl;
        return 1;
    }

    auto pid = static_cast<pid_t>(pid_long);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    int count = dist(gen);

    for (int i = 0; i < count; ++i) {
        kill(pid, SIGUSR1);
        // Sleep for a second between signals
        sleep(1);
    }

    kill(pid, SIGUSR2);

    return 0;
}
