# get_next_line

A function that reads a file line by line, written in C for 42 School.

## What it does

`get_next_line` reads a text file one line at a time. Each time you call it, it returns the next line. When there are no more lines, it returns NULL.

The function handles files of any size without loading everything into memory at once - it reads in chunks and keeps track of where it left off.

## Files

- `get_next_line.c` - Main function
- `get_next_line.h` - Header file
- `get_next_line_utils.c` - Helper functions (strlen, strchr, strjoin, etc.)
- `get_next_line_bonus.c` - Bonus version that can handle multiple files at once
- `get_next_line_bonus.h` - Bonus header
- `get_next_line_utils_bonus.c` - Bonus helper functions

## How to use it

```c
#include "get_next_line.h"

int fd = open("your_file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);  // Don't forget to free each line
}
close(fd);
```

## Compile

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can change `BUFFER_SIZE` to whatever you want. Smaller = more read() calls, bigger = more memory usage.

## Bonus

The bonus version can read from multiple files simultaneously:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Notes

- Returns the line including the `\n` character (except for the last line if it doesn't end with `\n`)
- Uses static variables to remember state between calls
- Handles edge cases like empty files, files without newlines, etc.
- No global variables, no libft allowed (42 rules)

This was a pain to debug but pretty satisfying once it worked.
