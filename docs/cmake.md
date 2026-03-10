# CMake Build System

This repository uses a **self-discovering CMake configuration** designed for learning C++.
Exercises automatically become build targets without manually editing `CMakeLists.txt`.

The goals are:

- Zero maintenance when adding exercises
- Easy execution of individual programs
- Optional static analysis and sanitizers
- Optional unit-style testing using CTest

---

# Directory Structure

Exercises follow a simple rule:

> **One directory = one executable**

Example:

```text
SelfCpp/
  CMakeLists.txt
  common/
    util.cpp
    util.hpp

  Chap01/
    ex01/
      main.cpp
    ex02/
      main.cpp

  Chap12/
    lisp/
      main.cpp
      reader.cpp
      eval.cpp
      printer.cpp
      lisp.hpp
```

Rules:

- If a directory contains **`main.cpp`**, it becomes an executable.
- All `.cpp` files in the same directory are compiled into that executable.
- The executable name is derived from the path.

Example:

```
Chap01/ex01/main.cpp → Chap01_ex01
Chap12/lisp/main.cpp → Chap12_lisp
```

---

# Building

Configure the build directory:

```bash
cmake -S . -B build -G Ninja
```

Build everything:

```bash
cmake --build build
```

---

# Running Programs

Each executable automatically gets a **run target**.

Example:

```bash
cmake --build build --target run_Chap01_ex01
```

This will:

1. Build the program if needed
2. Run the executable

This is the recommended workflow while learning.

---

# Skipping an Exercise

Sometimes an exercise is incomplete or experimental.

Add the following comment to `main.cpp`:

```cpp
// CMAKE_SKIP_EXE
```

The directory will be ignored by CMake.

---

# Shared Code (`common/`)

Code inside `common/` is automatically compiled as a static library.

Example:

```text
common/
  util.cpp
  util.hpp
```

It is linked into every executable automatically.

Usage:

```cpp
#include "util.hpp"
```

---

# Compiler Warnings

The build enables strict warnings:

```
-Wall
-Wextra
-Wpedantic
```

This is intentional for learning purposes.

---

# Sanitizers

By default the build enables:

- AddressSanitizer
- UndefinedBehaviorSanitizer

These help detect:

- memory errors
- undefined behavior
- invalid pointer usage

Disable them if necessary:

```bash
cmake -S . -B build -G Ninja -DENABLE_SANITIZERS=OFF
```

---

# clang-tidy (Static Analysis)

`clang-tidy` can be enabled to run static analysis during compilation.

Enable:

```bash
cmake -S . -B build -G Ninja -DENABLE_CLANG_TIDY=ON
```

This may produce many warnings depending on the code.

---

# Tests (CTest)

CTest is enabled automatically when `ENABLE_TESTING` is ON.

To run all tests:

```bash
cd build
ctest --output-on-failure
```

---

# Adding Tests to an Exercise

Tests are optional and defined per exercise.

Add a file:

```text
Chap05/ex03/test.cmake
```

Example:

```cmake
add_test(
  NAME ${TARGET_NAME}_output
  COMMAND ${TARGET_PATH}
)

set_tests_properties(${TARGET_NAME}_output PROPERTIES
  PASS_REGULAR_EXPRESSION "^42$"
)
```

Variables available in `test.cmake`:

| Variable      | Meaning                     |
| ------------- | --------------------------- |
| `TARGET_NAME` | Executable name             |
| `TARGET_PATH` | Full path to the executable |

---

# Optional fmt Library

The repository can optionally enable the `fmt` formatting library.

Enable:

```bash
cmake -S . -B build -G Ninja -DENABLE_FMT=ON
```

Example usage:

```cpp
#include <fmt/core.h>

int main() {
    fmt::print("value = {}\n", 42);
}
```

For learning purposes, prefer:

```
std::cout
```

unless convenient formatting is required.

---

# Available Configuration Options

| Option              | Default                    | Description                  |
| ------------------- | -------------------------- | ---------------------------- |
| `ENABLE_SANITIZERS` | ON                         | Enable ASan/UBSan            |
| `ENABLE_CLANG_TIDY` | ON/OFF depending on config | Enable clang-tidy            |
| `ENABLE_TESTING`    | ON                         | Enable CTest                 |
| `ENABLE_FMT`        | OFF                        | Fetch and enable fmt library |

Example:

```bash
cmake -S . -B build -G Ninja \
  -DENABLE_CLANG_TIDY=ON \
  -DENABLE_FMT=ON
```

---

# Typical Workflow

Recommended workflow while studying:

```
edit code
↓
build
↓
run target
```

Example:

```bash
cmake --build build --target run_Chap03_ex02
```

Run tests when needed:

```bash
ctest --output-on-failure
```

---

# Why This Build System Exists

This configuration is designed for learning:

- exercises can be added without editing CMake
- each exercise builds independently
- errors are easy to isolate
- static analysis and sanitizers are available

The goal is to make experimentation easy while keeping the environment close to real C++ development practices.
