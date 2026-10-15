# C++ Practice

A collection of small C++ exercises and experiments, including data structures,
algorithms, and language feature examples. Each folder is intended to be
explored independently.

## Contents

- `list/` — doubly linked list implementation and a small driver program.
- `vector/` — vector-related C++ exercise with a Makefile.
- `algorithms/merge/` — merge sort implementation and related files.
- `test/` — standalone practice examples.
- `HackerRank/` — space for HackerRank exercises.

## Build examples

The `list` and `vector` directories include Makefiles. Build and run them with:

```sh
make -C list
./list/list

make -C vector
./vector/vec
```

Clean generated files with `make -C list fclean` or `make -C vector fclean`.

The other exercises may be compiled individually with a C++17 compiler, for
example:

```sh
c++ -std=c++17 -Wall -Wextra -Werror algorithms/merge/main.cpp \
    algorithms/merge/merge.cpp -o /tmp/merge
```

Build commands can vary depending on which source files each exercise uses.
