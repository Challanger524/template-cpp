# Template C++ CMake

`CMake` `CMakePresets` `Ninja` `EditorConfig`  `VS Code` `PCH` `app`

Feel free to pick any part or snippet you find interesting.

### Examples

- **`.editocronfig`** - _"must have"_, rules: file encoding, end of lines, trailing spaces, final newline, ..
- **`.gitignore`** - _"must have"_
- **CMake**
  - `CMakeLists.txt` - single-file build-gen description for the project _`<-- the most interesting part`_
  - `CMakePresets.json` - define configurations for `MSVC` `GCC` `Clang` (debug), used by _CMake_ implicitly and _CMakeLists.txt_ explicitly via `cacheVariables` to configure the build
- **project structure**
  - `src/`
    - `config.hpp` - (optional) precompiled header with project-wide c++ defines
    - `main.cpp`
  - possible folders/files: `include/`, `src/<int|internal>/` `dep/`, `doc/`, `res/`, `misc/`, `misc/<cmake|script|other>`, `(UN)LICNESE`, `changelog.md`
  - possible tools: `Tests`, `CI/CD`, `Git Hooks`, `Git Submodules`, `Linters`, `Package Managers`
- **VS Code** - IDE
  - `.vscode/c_cpp_properties.json` - config `vscode-cpptools`: language server, ..
  - `.vscode/extensions.json` - list of extensions used in the project
  - `.vscode/settings.json` - folder settings, works when opened as _folder_ (not as _workspace_)
  - `./*.code-workspace` - user settings, overtakes `.vscode/settings.json`
    - `"files.readonlyInclude":{` - prevent accidental editing
    - `"files.associations:{"` - prevent constant growth from opening C++ extension-less STL header files
    - `"cmake.parallelJobs": 4` - `0` defaults to wrong `6` on 4-threaded CPU and slows configuration (in my case)
    - `"files.trimTrailingWhitespace": false` - stop racing with EditorConfig extension

### Branches (diff)

- [std/c++_gnu++](https://github.com/Challanger524/template-cpp/compare/main..std/c%2B%2B_gnu%2B%2B); ([?](https://github.com/Challanger524/template-cpp/compare/main...std/c++_gnu++))

Campare anything here: https://github.com/Challanger524/template-cpp/compare

### Other C++ examples

> Remark: I did not find any sane and useful C++ starting templates - they simply  don't exist.
> For comparison, just take a look on what Golang community pulled out:
> - [Organizing a Go module](https://go.dev/doc/modules/layout) - official layout guide, o-ff-i-c-i-a-l !!1
> - https://github.com/golang-standards/project-layout - big detailed repo and layout showcase
> - https://github.com/evrone/go-clean-template - same + readme contains pretty images, oh wow

<details><summary>Projects and libraries</summary>

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

##### Avoid this:
- https://github.com/pvanhoof/dir-examples - the most ugly project layout example on the net - `Meson` `qmake` `GNU Make` `CMake` (4 levels of nestiness)
</details>
