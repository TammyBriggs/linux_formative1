#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sync_files(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        printf("Error: Could not open source file.\n");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        printf("Error: Could not open destination file.\n");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    printf("Synchronization complete: %s -> %s\n", source, destination);

    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    printf("Initializing data_sync tool...\n");
    
    // Simulating the sync of a hardcoded file for the sake of the analysis
    sync_files("local_data.dat", "backup_data.dat");
    
    return 0;
}
