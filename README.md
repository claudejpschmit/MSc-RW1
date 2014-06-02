MSc-RW1
===========

Random Walk Exercise @ Edinburgh University, 2014

## Programming Style

We are generally following the [kernel style guide](https://www.kernel.org/doc/Documentation/CodingStyle), with the exception of indenting by 4, **not** 8, spaces.

## Building

We are using [CMake](http://www.cmake.org/) to govern the build process, the only supported platform is Linux/gcc. Others can be added in CMakeLists.txt
### Building the application

In order to build the code, you need to create a build directory, generate the makefile and build:

    mkdir build
    cd build
    cmake ..
    make -j3

which should produce a 'MCSimulation' executable for you.

### Building the documentation

To do that you need to be inside the build directory and make doc:

    cd build
    make doc


## Documentation

Using Doxygen. So write the documentation using [markdown](http://daringfireball.net/projects/markdown/syntax), which will enable easy HTML code generation. You can also find it helpful to [look at the Doxygen specific markdown docs](http://www.stack.nl/~dimitri/doxygen/manual/markdown.html).


