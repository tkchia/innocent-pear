> "*A popular tourist attraction of the region, the biting pear lives off low-flying birds, hand-outs, and the occasional unwary sightseer.*" --&nbsp;[ursulav](http://ursulav.deviantart.com/art/The-Biting-Pear-of-Salamanca-29677500)

[![(build status)](https://travis-ci.org/tkchia/innocent-pear.svg?branch=master)](https://travis-ci.org/tkchia/innocent-pear)

## Synopsis

#### Installation

> `git clone --recursive https://github.com/tkchia/innocent-pear.git`

> [*source-path*`/`]`configure` [`--prefix=`*install-path*] [`--target=`*target-arch*] [`--target-dir=`*target-install-path*] [...]

> `make check`

> `make install`

#### Use

> [*install-path*`/bin/`]`innocent-pear-c++` [`-Xinnocent-pear -doge`] [...] [*g++-options*...]

## Description

`innocent-pear-c++` is a wrapper around the GNU C++ compiler (`g++`(1)) or `clang++` compiler which tries to obscure the code of compiled programs.

If `-Xinnocent-pear -doge` is specified, it scrambles the text sections of a program and adds constructor routines to unscramble them.

There is also a rather undocumented C++ API for various code obfuscation subtasks.

## Bugs

The scrambling of text and data is probably not yet very strong.

The C++ API should really be documented.

If `innocent-pear` is explicitly set up to compile target-side programs

  * using `clang++`
  * with `libstdc++` linked in dynamically
  * where the programs handle exceptions,

the programs may fail with a runtime error on certain platforms:

> `./test/test-doge-eh.debug: error while loading shared libraries: unexpected reloc type 0x18`

This is because I have not found a clean way to break up the absolute relocations referring to RTTI structures in `libstdc++` (`_ZTIi`, etc.), or to separate the relocations from the scrambled data.
