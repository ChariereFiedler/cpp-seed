# Cpp seed

## About

A CPP Project scaffold with a modular architecture.
Feel free to use, edit, share fixes ;)


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

- Docker Build
- Docker Doxygen
- Gitlab CI
- Gitlab Pages for generated artifacts (UT, Docs...)



## Build

There are currently two ways to compile the sources. The first one requires
several externals tools to install: that is a local build.

The second one is based on Docker and is currently in progress.

### Local Build

#### CMake

In the source dir, create a build directory with:

```sh
    $mkdir cmake-build-debug
```

Go in and run cmake:

```sh
    $cd cmake-build-debug && cmake .. -DBUILD_CONFIG_TYPE=Debug
```
#### Install external dependencies

You can now install the external dependencies,
a Cmake Target has been defined to install all the external dependencies (currently, `Catch` and `SpdLog`).
This target is not in the default cmake command. You need to call it to install them:


```sh
    $make install-all
```

#### Run Tests


```sh
    $ctest
```

TODO: The artifacts are available in the ***cmake-build-debug/Testing*** folder.
