# Building

Z3Wolfram uses a Wolfram Language kernel to generate code at build time and a C++ compiler to compile a native library.

Z3Wolfram uses C++11 features and requires a compiler that can support at least C++11.

Z3Wolfram uses CMake to generate build scripts.

Here is an example transcript using the default make generator to build Z3Wolfram:
```
cd z3-wolfram
mkdir build
cd build
cmake -DZ3_DIR=/Users/brenton/development/github/z3/build ..
cmake --build .
```

The result is a directory named `paclet` that contains the WL package source code and a built Z3 `.paclet` file for installing.

Inside a kernel session you may then install the paclet by evaluating:
```
PacletInstall["/path/to/build/paclet/Z3-0.1.paclet"]
```

Specify `MATHEMATICA_INSTALL_DIR` if you have Wolfram System installed in a non-default location:
```
cmake -DMATHEMATICA_INSTALL_DIR=/Applications/Mathematica.app/Contents/ ..
cmake --build .
```

On Windows:
```
cmake -DMATHEMATICA_INSTALL_DIR="C:/Program Files/Wolfram Research/Mathematica/12.3" ..
cmake --build .
```

## Installing

You can install the paclet from CMake:
```
cmake --install .
```

This starts a kernel and calls `PacletInstall` with the built .paclet file.
