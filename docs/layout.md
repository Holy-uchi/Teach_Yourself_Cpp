# Repository Layout

This repository organizes all study code by **chapter** and **purpose**.
The structure is designed to make exercises independent, easy to run, and easy to extend.

Each chapter directory follows the same structure.

---

# Chapter Structure

Each chapter contains four main categories:

```text
ChapXX/
  samples/
  drills/
  end_of_chapter/
  extra/
```

Meaning:

| Directory         | Purpose                                                        |
| ----------------- | -------------------------------------------------------------- |
| `samples/`        | Code examples from the book text                               |
| `drills/`         | Practice exercises appearing inside the chapter                |
| `end_of_chapter/` | Problems at the end of the chapter                             |
| `extra/`          | Additional exercises generated with AI or personal experiments |

---

# Executable Rule

This repository uses an automatic CMake discovery rule:

> **A directory containing `main.cpp` becomes an executable.**

Example:

```text
Chap01/drills/q01/01/main.cpp
```

Build target name:

```text
Chap01_drills_q01_01
```

Each exercise therefore becomes an independent program.

---

# Sample Code Layout

Samples correspond to code examples appearing in the book.

Structure:

```text
samples/
  01_topic_name/
    main.cpp
```

Example:

```text
Chap02/
  samples/
    01_variables/
      main.cpp
    02_type_deduction/
      main.cpp
```

Naming rule:

```
NN_short_description
```

Example:

```
01_hello_world
02_basic_cout
```

---

# Practice Exercises (`drills/`)

Practice exercises are structured as:

```text
drills/
  q01/
    01/
      main.cpp
    02/
      main.cpp
```

Meaning:

| Name            | Meaning            |
| --------------- | ------------------ |
| `q01`           | exercise number    |
| `01`, `02`, ... | subquestion number |

Example:

```text
Chap03/
  drills/
    q01/
      01/
        main.cpp
      02/
        main.cpp
    q02/
      01/
        main.cpp
```

Each subquestion is implemented as a separate executable.

---

# End-of-Chapter Problems

End-of-chapter problems follow the same structure as drills.

```text
end_of_chapter/
  q01/
    01/
      main.cpp
    02/
      main.cpp
```

Example:

```text
Chap05/
  end_of_chapter/
    q01/
      01/
        main.cpp
      02/
        main.cpp
```

---

# Extra Exercises

`extra/` contains exercises not directly from the book.

Examples include:

- additional practice problems
- experiments
- AI-generated exercises
- deeper exploration of a topic

Structure:

```text
extra/
  01_topic_name/
    main.cpp
```

Example:

```text
extra/
  01_vector_drill/
    main.cpp
  02_algorithm_find/
    main.cpp
```

---

# Example Chapter Layout

Example of a complete chapter directory:

```text
Chap07/
  samples/
    01_vector_intro/
      main.cpp
    02_range_for/
      main.cpp

  drills/
    q01/
      01/
        main.cpp
      02/
        main.cpp

  end_of_chapter/
    q01/
      01/
        main.cpp
      02/
        main.cpp

  extra/
    01_vector_sum/
      main.cpp
    02_algorithm_find/
      main.cpp
```

---

# Optional Files

Exercise directories may include additional files when necessary.

Example:

```text
01/
  main.cpp
  notes.md
  test.cmake
  data/
    input.txt
    expected.txt
```

Description:

| File         | Purpose                        |
| ------------ | ------------------------------ |
| `notes.md`   | personal notes or explanations |
| `test.cmake` | CTest definitions              |
| `data/`      | input/output files for testing |

---

# Skipping a Program

To temporarily disable building an exercise, add the following comment inside `main.cpp`:

```cpp
// CMAKE_SKIP_EXE
```

The directory will be ignored by the CMake build system.

---

# Design Philosophy

This layout is designed to ensure:

- each exercise is **independent**
- exercises can be **built automatically**
- code is **easy to navigate later**
- experiments can be added without restructuring

It also works naturally with the repository's automatic CMake discovery rules.
