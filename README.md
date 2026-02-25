*This project has been created as part of the 42 curriculum by jdiaz-ec*
# get_next_line
---
## DESCRIPTION
#### get_next_line() is function that lets you read a text file pointed to by the file descriptor, **one line at a time**.
#### The functions returns the string the line read from the text, including the new line character '`\n`'.
### The goals of this project are:
- #### Learn about static variable in C language. A static variable has the property of retaining its value between multiple function calls, it is initialized once and it isn't destroyed when the function returns a value. Its lifetime is till the end of the program.
- #### Strengthen my habilities to correctly manage memory allocations and frees, avoiding any possible leak.
### The prototype of this functions is:
```c
char	*get_next_line(int fd);
```
#### I've used some useful functions from my library project "LIBFT":
- #### `ft_strlen`: to calculate and return the length of a string.
- #### `ft_strchr`: to find a '`\n`' character in a string and return the pointer to it.
- #### `ft_strdup`: to allocate memory for same size as a string passed as parameter and copy it.
- #### `ft_strjoin`: it receives two strings, allocate memory in a new string for same size as the two strings, and copy both strings in the new string.
- #### `ft_substr`: copy a substring from a string passed as parameter start from a choosen point.

#### My `get_next_line()` includes three different functions to store the stash and return the actual line:

- #### `read_buf()`: it basically loops the `read()` function and joins the buffer into the stash until it finds a `\n` in the same stash.
- #### `extract_line()`: it finds the position of `\n` and returns a sub string of the stash until the `\n`.
- #### `get_next_stash()`: it finds the position of `\n` and returns a sub string of the stash after the `\n` until the end of string `\0`.

## INSTRUCTIONS

#### Firstly, we create or add a `text.txt` (name doesn't matter) file of with lines of any size or empty lines:



```
This is a text file
Where

the lines can be of any size,
even the longest line that you have ever seen, written or read can be included in this text

And this function will be able to read the entire line (if memory available is enough).

a

42
```

#### Then, we include a `main.c` with the main function to test our function:

```c
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int	fd = open("text.txt", O_RDONLY);

	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
}
```



## RESOURCES

#### `Reading the f****** manual` is the first resource that is used to understand, learn and study how `open()`, `read()` and `close()` functions work, as well as their limitations and bugs.
#### When reading the manual wasn't enough or when I needed more information regarding `read()`, static variables or how to fix some bugs, the 42 peer-to-peer method was a huge helpful resource; the willingness of 42 students to help and support one another is truly amazing.
#### Some other helpful resources were: stackoverflow.com, youtube.com, geekforgeeks.org