# get_next_line

*This project has been created as part of the 42 curriculum by yhamdaou.*

## Description

The `get_next_line` project implements a function that reads one line at a time from a file descriptor. This project teaches static variables in C and efficient file reading through buffer management. The function handles multiple file descriptors in the bonus version.

## Instructions

### Compilation
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

For bonus:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

### Usage
```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Resources

- **Man pages**: read, open, close, malloc, free
- **[GeeksforGeeks - Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)**: Understanding static variable behavior and scope
- **Concepts**: Static variables in C, file descriptors, buffer management

### AI Usage
- Understanding static variable behavior and scope
- Helped structure this README.md

AI was NOT used for writing the core algorithm or any function logic.

## Library Description

### Files
- **get_next_line.c**: Main function implementation
- **get_next_line_utils.c**: Helper functions (ft_strlen, ft_strchr, ft_strjoin, ft_substr)
- **get_next_line.h**: Header with prototypes and definitions
- **Bonus files**: Same structure with `_bonus` suffix for multiple fd support

### Main Function
```c
char *get_next_line(int fd);
```
Returns one line from fd including `\n`, or NULL at EOF/error.

## Algorithm

### Static Buffer with Read-Append-Extract

The algorithm uses a static variable to store leftover data between calls:

1. **Read**: Load BUFFER_SIZE bytes into temporary buffer
2. **Append**: Add read data to static buffer until `\n` is found or EOF
3. **Extract**: Return line up to `\n` and update static buffer with remainder
4. **Clean**: Free and manage memory appropriately

### Justification

**Why this approach:**
- Minimizes system calls by reading in chunks
- Static variable naturally preserves state between calls
- Simple and maintainable code structure

**Alternatives considered:**
- Byte-by-byte reading: Too many system calls (rejected)
- Circular buffer: Unnecessary complexity (rejected)

This approach balances efficiency with simplicity, teaching practical buffer management while meeting all project requirements.

