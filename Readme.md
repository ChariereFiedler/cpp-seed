# Cpp seed

## About

A CPP Project scaffold with a modular architecture.
Feel free to use, edit, purpose some fixes ;)


## Features

The current work is in progress.

Now, the main `CMakelists.txt` is based on the concatenation of several small projects.
Each project can be built separately, has its own documentation and unit tests.



The current stack use the following tools:
- Catch: unit testing
- gcov and lcov: code coverage
- SpdLog: logging
- Doxygen: documentation generation

## Roadmap

-

## Requirements

- CMake >= 3.8
- gcov
- lcov
- Doxygen


## Install the dependencies

A Cmake Target has been defined to install all the external dependencies (currently, `Catch` and `SpdLog`).
This target is not in the default cmake command. You need to call it to install them:

    $ make install-all

