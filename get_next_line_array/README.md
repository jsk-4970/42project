*This project has been created as part of the 42 curriculum by jyamada.*

# get_next_line

## Description

A function that reads text from a file descriptor one line at a time. Even when `read()` is called repeatedly, it correctly returns the next line each time. Useful for sequential reading from standard input or files.

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```

`BUFFER_SIZE` is the buffer size specified at compile time. Defaults to 42 if not specified.

### Usage Example

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm

Uses a static variable `stash` to hold data that has been read but not yet returned.

1. `ft_getfile`: Reads from the file using `read()` and appends to `stash`. Stops when a newline is found or EOF is reached.
2. `ft_extract_line`: Extracts and returns from the beginning of `stash` up to and including the newline.
3. `ft_clean_stash`: Removes the returned portion from `stash` and retains the remainder.

Why this approach was chosen:
- Static variables allow buffer state to persist between function calls
- Reading stops when a newline is found, avoiding unnecessary memory consumption
- Memory is dynamically allocated regardless of line length, supporting lines of any size

## Resources

- [read(2) - Linux manual page](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)

### About AI Usage

AI was used to create this README. It was not used for the code implementation.
