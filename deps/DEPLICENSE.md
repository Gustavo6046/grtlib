# Dependency License
The dependencies above were copied with **no** substantial modifications to their code or internal structure, only folder structure adaptations for the *CMake* meta build system. They are used in the program; do **NOT** distribute these folders with the binaries when compiling `grtlib`!

They are included with `grtlib` to make the life of those compiling it easier. Their licenses are included inside their folders as `<dependency>/LICENSE.*`. Please follow that license too!

Only the `CMakeLists.txt` found in this folder and the one in the folder above are included as part of `grtlib` (and therefore in the MIT license, and of Gustavo6046's authorship). ANY `CMakeLists.txt` files found inside dependency folders are left INTACT and included to avoid duplicating dependency compiling code in CMake.

## Dependencies Included:
* `sfml-*`