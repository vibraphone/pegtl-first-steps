# A Simple Introduction to PEGTL

This small set of examples is even more
simple than those which come with PEGTL.

```sh
git submodule update --init --recursive
mkdir build
(cd build; cmake -G Ninja ..; ninja)
./build/ex1 "{}"
./build/ex1 "{ }"
./build/ex2 "{a}"
./build/ex2 "{{}"
./build/ex3 "{___}"
```
