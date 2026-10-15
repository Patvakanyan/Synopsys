# C++ Practice

Small, independent C++ exercises covering data structures, algorithms, and
HackerRank problems. Most examples have their own `main` function, so build and
run them separately rather than linking the whole repository together.

## Repository layout

- `list/` — doubly linked list implementation and demo program.
- `vector/` — `vector2` dynamic-array implementation, demo, and tests.
- `algorithms/merge/` — merge sort implementation and demo.
- `HackerRank/Arrays/` — array challenge solutions.
- `HackerRank/LinkedLists/` — linked-list challenge solutions.
- `HackerRank/WarmUpChallenges/` — warm-up challenge solutions.
- `test/` — small language-feature examples, including inline variables.

## Build and run

The `list` and `vector` directories have Makefiles and require a C++17 compiler.

```sh
make -C list
./list/list

make -C vector
./vector/vec
```

Run the vector test executable with:

```sh
make -C vector test
```

The Makefiles also provide `clean`, `fclean`, and `re` targets. For example,
`make -C vector fclean` removes its generated objects and executables.

Compile the merge sort demo directly from the repository root:

```sh
c++ -std=c++17 -Wall -Wextra -Werror \
    algorithms/merge/main.cpp algorithms/merge/merge.cpp -o /tmp/merge
/tmp/merge
```

The remaining examples are standalone practice files. Compile the source file
you want to work on with a C++17 compiler; HackerRank solutions may expect the
platform's input format or provided data structures.
