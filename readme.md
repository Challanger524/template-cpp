# Template C++ CMake

`С++` `CMake` `CMakePresets` `Ninja` `EditorConfig` `VS Code` `PCH` `app`

Feel free to pick any part or snippet you find interesting.

- `CMakeLists.txt`- [CMake overview](https://cgold.readthedocs.io/en/latest/overview/cmake-can.html) - decent examples and information source
- [`CMakePresets.json`](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) - build configure **presets** used in `CMakeLists.txt` via `cacheVariables`
  - `msvc-dbg`: MSVC - debug
  - `gcc-dbg`: GCC - debug
  - `clang-dbg`: Clang - debug
  - some conditional presets with sanitizers (like: `gcc-san`, `clang-san-addr`, `clang-san-mem`)
- `src/` - place for project' source `.cpp` files that are recursively globbed in [`CMakeLists.txt:26`](CMakeLists.txt#L26)
  - `config.hpp` - (optional) precompiled header with source-wide C++ defines
- `.code-workspace` - useful VS Code settings

### Branches (diff):

Compare branches: https://github.com/Challanger524/template-cpp/compare

- [std/c++_gnu++](https://github.com/Challanger524/template-cpp/compare/main..std/c%2B%2B_gnu%2B%2B) ([?](https://github.com/Challanger524/template-cpp/compare/main...std/c++_gnu++))


> GitHub compares for branch names with slash `/` may be ill-formed, as shown in (?) link

### Other C++ examples

> Remark: I did not find any sane and useful C++ starting templates - they simply  don't exist.
> For comparison, just take a look on what Golang community pulled out:
> - [Organizing a Go module](https://go.dev/doc/modules/layout) - **official** golang project layout guideline
> - https://github.com/golang-standards/project-layout - big detailed repo and layout showcase
> - https://github.com/evrone/go-clean-template - same + readme contains pretty images

<details><summary>Projects and libraries (unfinished section)</summary>

Since there no useful templates outside - real projects are the only source of examples.

- https://github.com/nlohmann/json - `Lib` `json` `c++` `readme.md`(very decent)
- ...

https://www.reddit.com/r/cpp_questions/comments/n73n32/presenting_a_c_project_on_github_elegantly/

</details>

<details><summary>Templates examples and demos</summary>

- https://github.com/TheCherno/ProjectTemplate - `Premake` `"Core/App" architecture`
- https://github.com/edumentab/cpp-project-example - `CMake` `JetBrains` `GTest`
- https://github.com/fnl/cpp-project-template - `CMake`(nested) `gitmodules` `Catch2` `cxxopts`
- https://github.com/erayaydin/cpp-structure  - `GNU Make` `project layout`
- https://github.com/karvozavr/multi-module-cpp-project-example - `CMake` `multi-project` `Catch2`
- https://github.com/jblort/cpp-project-template - `CMake` `Conan` `lib`+`app` `Catch2`
- https://github.com/ssciwr/cpp-project-template - `CMake` `CI/CD` `Doxygen` `Catch2`
- https://github.com/Jamagas/CMake - `CMake` `GTest`

##### Avoid this BS:
- https://github.com/pvanhoof/dir-examples - the most ugly project layout example on the net - `Meson` `qmake` `GNU Make` `CMake`(4 levels of nestiness)
</details>
