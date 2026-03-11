#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    const char *log_message = "[LOG] Backup process initiated successfully.\n";
    char read_buffer[128];

    // 1. File Creation and Writing Logs
    // O_CREAT creates the file if it doesn't exist, O_WRONLY opens for writing, O_TRUNC clears it.
    fd = open("backup_log.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Failed to create log file");
        exit(EXIT_FAILURE);
    }
    
    // Write the log message to the file
    write(fd, log_message, strlen(log_message));
    
    // Close the file after writing
    close(fd);

    // 2. Reading Files
    // Open the same file for reading only
    fd = open("backup_log.txt", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open log file for reading");
        exit(EXIT_FAILURE);
    }

    // Read the contents back into our buffer
    ssize_t bytes_read = read(fd, read_buffer, sizeof(read_buffer) - 1);
    if (bytes_read >= 0) {
        read_buffer[bytes_read] = '\0'; // Null-terminate the string
    }

    // Close the file after reading
    close(fd);

    return 0;
}
