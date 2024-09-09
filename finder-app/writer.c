// includes
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


// Main Function
int main(int argc, char *argv[]) {
    // Open the syslog
    openlog("writer", LOG_PID | LOG_NDELAY, LOG_USER);

    // Check if the number of arguments is not equal to 2
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments required - a file path and a text string.\n");
        return 1;
    }

    // Directory creation not needed for this assignment

    // Open the file
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Error: Could not create or write to the file %s\n", argv[1]);
        return 1;
    }

    // Write to the file
    if (write(fd, argv[2], strlen(argv[2])) == -1) {
        syslog(LOG_ERR, "Error: Could not write to the file %s\n", argv[1]);
        return 1;
    }

    // Close the file
    close(fd);

    // Log the success
    syslog(LOG_INFO, "Success: Wrote \"%s\" to the file %s\n", argv[2], argv[1]);
    
    // Close the syslog
    closelog();

    return 0;
}