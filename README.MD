# 42 Core Curriculum
 
My projects from the core curriculum at [42 Berlin](https://42berlin.de/), a peer-to-peer coding school with no teachers or lectures. You learn by building projects in C and C++ to strict specifications, and your fellow students review and grade the code.
 
## Highlights
 
| Project | Language | What it does |
|---|---|---|
| [Minishell](round_3/Minishell) | C | A Bash-like shell with pipes, redirections, heredocs, environment variables, signals, built-ins, and `&&` / `\|\|` with parentheses and `*` wildcards (bonus). Built in a team of two. |
| [cub3D](round_4/cub3d) | C | A Wolfenstein-style first-person 3D renderer using raycasting, textured walls, map parsing and validation, and a minimap. Built in a team of two. |
| [Philosophers](round_3/philosophers) | C | The dining philosophers problem, solved with threads and mutexes, plus a bonus version with processes and semaphores. |
 
## All projects
 
✅ Done · 🚧 In progress · 📝 Exam practice
 
| Project | Language | Status | What it does |
|---|---|---|---|
| [Libft](round_0/Libft) | C | ✅ | My own C standard library: string, memory, and conversion functions, used in later projects. |
| [ft_printf](round_1/ft_printf) | C | ✅ | A reimplementation of `printf` with variadic arguments and format conversions. |
| [get_next_line](round_1/get_next_line) | C | ✅ | Reads a file descriptor one line at a time, using a static buffer. |
| [push_swap](round_2/push_swap) | C | ✅ | Sorts integers using two stacks and a limited set of operations, with the fewest possible moves. |
| [pipex](round_2/pipex) | C | ✅ | Recreates the shell pipe `< in cmd1 \| cmd2 > out` with `fork`, `pipe`, `dup2`, and `execve`. |
| [fract-ol](round_2/fractol) | C | ✅ | An interactive fractal explorer (Mandelbrot / Julia) rendered with MiniLibX. |
| [Minishell](round_3/Minishell) | C | ✅ | See highlights above. |
| [Philosophers](round_3/philosophers) | C | ✅ | See highlights above. |
| [cub3D](round_4/cub3d) | C | ✅ | See highlights above. |
| [CPP Modules 01–04](round_4) | C++ | ✅ | Exercises on memory allocation, references, operator overloading, fixed-point numbers, inheritance, and polymorphism. |
| [CPP Modules 05–09](round_5) | C++ | ✅ | Exceptions, type casts, templates, STL containers and algorithms, ending with a Bitcoin exchange-rate lookup, an RPN calculator, and a merge-insertion sort. |
| [Arachnida](SecurityPiscine/arachnida) | Python | 🚧 | Cybersecurity piscine: `spider`, a recursive image scraper, and `scorpion`, an image metadata (EXIF) extractor. |
| [ft_otp](SecurityPiscine/ft_otp) | Python | 🚧 | Cybersecurity piscine: a one-time password generator based on HOTP / TOTP (RFC 4226 / 6238). |
| [Exam practice](ExamPractice) | C / C++ | 📝 | Practice exercises for the timed 42 exams. |
 
## What I took away
 
- **How a computer actually works underneath.** Managing memory by hand, handling file descriptors, and creating processes and threads with system calls taught me what higher-level languages normally hide.
- **Debugging without a safety net.** Tracking down memory leaks, race conditions, and undefined behavior with tools like Valgrind and GDB.
- **Working with other people's code.** Every project gets reviewed by fellow students, and the larger projects were built in pairs. So explaining my design choices, and reading code I didn't write, became part of daily work.
- **Learning on my own.** With no lectures, each project began with reading man pages and specifications and working out the approach myself.
