# Cpp seed

## About

Init your CPP project faster with this seed.

## Roadmap

- Conan package manager
- Unit testing
- Gherkin support for BDD
- Doxygen

## Requirements

- Cpp compiler with Cpp 14 support
- [Conan](http://conanio.readthedocs.io/en/latest/installation.html)
- [Cmake](https://cmake.org/)

## Init your project

Create a build folder and install the packages

    $mkdir build && cd build
    $conan install ..
    
> This install command will download the binary package 
required for your configuration (detected the first time 
that you ran the conan command), together with other required 
libraries, like OpenSSL and Zlib. It will also create the 
conanbuildinfo.cmake file in the current directory,
 in which you can see the cmake defined variables, and 
 a conaninfo.txt where information about settings,
  requirements and options is saved. cf. [Conan Doc](http://conanio.readthedocs.io/en/latest/getting_started.html)
  
## Build
 
 To build your project
 
    (win)
    $ cmake .. -G "Visual Studio 14 Win64"
    $ cmake --build . --config Release
    
    (linux, mac)
    $ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    $ cmake --build .
    ...