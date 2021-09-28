# Orbis native

Java 3D Engine native implementation.
Sub project of [Orbis](https://github.com/szclsb/orbis).


## jni headers

To create the jni header files, build the `orbis_generate_header` target.
This target executes the `javac -h` command and saves the header files into `./header/<header_name>.h`.

## build dll

To create the dynamic link library implement the header files in `./source/<header_name>.cpp` first
and execute the `orbis_native` target afterwards.