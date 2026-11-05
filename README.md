*This project has been created as part of the 42 curriculum by amalaini.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum. The goal is to build, from scratch, a personal C library that re-implements a set of standard C library functions, adds a collection of useful utility functions, and (as a bonus) provides a small linked-list toolbox. The result is a static library, `libft.a`, that can be reused in every later project of the curriculum.

Writing these functions by hand is a way to understand how they really behave, including their edge cases: empty strings, zero sizes, overlapping buffers, integer limits, and failing allocations. Along the way the project trains:

- pointers, strings and raw memory handling,
- dynamic memory management (`malloc` / `free`) and leak-free error handling,
- function pointers (callbacks),
- singly linked lists,
- writing a `Makefile` that builds a static library.

The project has three parts:

1. **Part 1 - libc functions**: re-implementations of standard functions, with the same prototypes and behavior as the originals (prefixed with `ft_`).
2. **Part 2 - additional functions**: functions that are not in the standard library, or that exist in a different form.
3. **Part 3 - linked lists**: the `t_list` type and the functions to create, add, count, iterate over, map and delete list nodes.

Only the authorized external functions are used: `malloc`, `free` and `write`.

## Instructions

### Requirements

- A C compiler (`cc`, `gcc` or `clang`)
- `make`
- `ar` (to create the static library)

### Compilation

The library is compiled with the flags `-Wall -Wextra -Werror`.

```bash
make all      # builds libft.a
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # fclean, then rebuilds everything
```

### Using the library in your own program

Include the header and link against `libft.a`:

```c
#include "libft.h"

int main(void)
{
	char	**words;
	int		i;

	words = ft_split("the quick brown fox", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o app
./app
```

(`make` must have been run first so that `libft.a` exists in the current directory. Add `-I<path>` if `libft.h` is in another directory.)

## Library description

All functions are declared in `libft.h`. The library never uses a function outside `malloc`, `free` and `write`.

### General conventions

- Functions that allocate memory return `NULL` if the allocation fails, and do not leak anything that was already allocated.
- Every pointer returned by an allocating function is meant to be released with `free`.
- Functions that mirror a standard function follow its documented behavior (see the man pages, section 3).

### Part 1 - Libc functions

| Function | Description |
|---|---|
| `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Character classification. |
| `ft_toupper`, `ft_tolower` | Convert a character to upper or lower case. |
| `ft_strlen` | Length of a string. |
| `ft_memset`, `ft_bzero` | Fill a memory area with a byte, or with zeros. |
| `ft_memcpy`, `ft_memmove` | Copy a memory area (`ft_memmove` handles overlapping areas). |
| `ft_memchr`, `ft_memcmp` | Search for a byte in memory, and compare two memory areas (as `unsigned char`). |
| `ft_strlcpy`, `ft_strlcat` | Size-bounded string copy and concatenation, returning the length they tried to create. |
| `ft_strchr`, `ft_strrchr` | First and last occurrence of a character in a string (the terminating `'\0'` is searchable). |
| `ft_strncmp` | Compare at most `n` characters of two strings (as `unsigned char`). |
| `ft_strnstr` | Locate a substring within the first `len` characters of a string. |
| `ft_atoi` | Convert the start of a string to an `int`: leading whitespace, optional sign, digits. |
| `ft_calloc` | Allocate zeroed memory for an array. Detects `nmemb * size` overflow. |
| `ft_strdup` | Duplicate a string into newly allocated memory. |

### Part 2 - Additional functions

| Function | Description |
|---|---|
| `ft_substr` | New string from `s`, starting at `start`, at most `len` characters. |
| `ft_strjoin` | New string that is the concatenation of two strings. |
| `ft_strtrim` | New string with the characters of a given set removed from both ends. |
| `ft_split` | Splits a string on a delimiter character into a `NULL`-terminated array of newly allocated strings. |
| `ft_itoa` | Converts an `int` to a newly allocated string. |
| `ft_strmapi` | New string made by applying a function `f(index, char)` to each character. |
| `ft_striteri` | Applies a function `f(index, char *)` to each character of a string, in place. |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a character, a string, a string followed by a newline, or an integer to a file descriptor. |

### Part 3 - Linked lists

The list node type is:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates a new node holding `content`, with `next` set to `NULL`. |
| `ft_lstadd_front`, `ft_lstadd_back` | Add a node at the beginning or at the end of a list (the head pointer is updated when needed). |
| `ft_lstsize` | Number of nodes in a list. |
| `ft_lstlast` | Last node of a list. |
| `ft_lstdelone` | Frees one node's content with the given `del` function, then the node itself. |
| `ft_lstclear` | Deletes and frees a node and all its successors, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Builds a new list from the results of applying a function to each node's content; on allocation failure, the partial new list is cleaned up with `del`. |

### Technical choices

- **Zero-size allocations.** `ft_calloc` returns a unique pointer that can be passed to `free` when `nmemb` or `size` is `0`, as the subject requires. It does this by requesting one byte, so it does not depend on whether the platform's `malloc(0)` returns `NULL`.
- **Overflow checks.** `ft_calloc` verifies that `nmemb * size` does not overflow `size_t` before allocating.
- **Integer limits.** `ft_atoi`, `ft_itoa` and `ft_putnbr_fd` handle `INT_MIN` without signed overflow, by doing the arithmetic in a wider type.
- **Cleanup on failure.** `ft_split` and `ft_lstmap` free everything they had already allocated when a later allocation fails, and return `NULL`.
- **Iterative cleanup.** The helpers that free arrays and lists use loops instead of recursion, so cleaning a very large structure cannot overflow the stack.
- **Empty results.** `ft_substr` and `ft_strtrim` return an allocated empty string (not `NULL`) when there is nothing left to return, so the caller can always `free` the result.

### How the library was tested

The functions were checked against the system implementations where one exists, and against hand-computed expected results otherwise. The checks covered edge cases (empty strings, zero sizes, `INT_MIN`/`INT_MAX`, high-bit bytes, very long inputs), were run with AddressSanitizer and UndefinedBehaviorSanitizer enabled, used leak detection, and simulated `malloc` failures to verify that error paths return `NULL` without leaking. These test programs are not part of the library.

## Resources

### References

- The Linux manual pages (`man 3 <function>`) for every re-implemented function, and `man 2 write` for the file-descriptor functions. These were the reference for the exact behavior and return values of each libc function.
- [W3Schools - C Function Pointers](https://www.w3schools.com/c/c_functions_pointers.php) - used to understand how to declare and call function pointers, needed for `ft_strmapi`, `ft_striteri`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter` and `ft_lstmap`.
- [GeeksforGeeks - Two's complement](https://www.geeksforgeeks.org/digital-logic/twos-complement/) - used to understand the integer representation behind `INT_MIN` and why its absolute value does not fit in an `int`, which matters for `ft_atoi`, `ft_itoa` and `ft_putnbr_fd`.

### Use of AI

AI (Claude, by Anthropic) was used as a study and review aid, following the 42 rules on AI. The library's source code was written by the author. The AI was not used to generate the implementation of any function.

It was used for:

- **Explaining the expected behavior of the functions.** Before writing several functions (for example `ft_strlcpy`, `ft_strlcat`, `ft_calloc`, `ft_split`, `ft_itoa` and `ft_strtrim`), the AI was asked to explain how the original function behaves and which edge cases to think about, without being given a finished implementation.
- **Producing test programs and running them.** The AI wrote throwaway test programs that compared the author's functions with the system ones (or with computed expected results), ran them with AddressSanitizer, UndefinedBehaviorSanitizer and leak detection, and simulated failing `malloc` calls. It reported which cases failed and why.
- **Pointing out problems.** When a function failed, the AI described what was observed and gave hints; the author then found and made the fixes. When code did not compile, only the compiler errors were reported.
- **Drafting this README**, which was then reviewed by the author.

Nothing generated by the AI was submitted as the author's code.