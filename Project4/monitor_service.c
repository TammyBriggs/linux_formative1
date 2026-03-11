#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// This is the custom function that runs when a signal is received
void signal_handler(int signum) {
    switch (signum) {
        case SIGINT:
            // Triggered by Ctrl+C
            printf("\nMonitor Service shutting down safely.\n");
            exit(0);
            
        case SIGTERM:
            // Triggered by the default kill command
            printf("\nEmergency shutdown signal received.\n");
            exit(0);
            
        case SIGUSR1:
            // Triggered by kill -SIGUSR1
            printf("\nSystem status requested by administrator.\n");
            break; 
            // We use break here instead of exit() so the program keeps running
    }
}

int main() {
    // 1. Setup the sigaction structure
    struct sigaction sa;
    sa.sa_handler = signal_handler; // Point to our custom handler
    sigemptyset(&sa.sa_mask);       // Don't block any other signals during handling
    sa.sa_flags = SA_RESTART;       // Automatically restart interrupted system calls (like sleep)

    // 2. Register the handlers with the OS
    if (sigaction(SIGINT, &sa, NULL) == -1 ||
        sigaction(SIGTERM, &sa, NULL) == -1 ||
        sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error registering signal handlers");
        return 1;
    }

    // Print the Process ID (PID) so you know exactly where to send the kill commands!
    printf("Starting Monitor Service. Process ID (PID): %d\n", getpid());
    printf("Waiting for signals... Use another terminal to send commands.\n\n");

    // 3. The continuous background loop
    while (1) {
        printf("[Monitor Service] System running normally...\n");
        sleep(5);
    }

    return 0;
}
