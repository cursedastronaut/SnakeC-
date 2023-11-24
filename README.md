# Snake C++
It's a simple snake game in C++, using ImGui.
It currently only works in **Linux**.

## Options
Using command line arguments, you can easily change the program's behavior.

- `--loop` | Allows player to loop around borders instead of having a game over.
- `--x [width]` | Allows player to choose their horizontal grid size. Default is 40.

- `--y [height]` | Allows player to choose their vertical grid size. Default is 30.

- `--skip` | Allows player to skip the main menu.

## Compilation
First, you need to create an `objects`folder where all the `.o`files will be placed:
```bash
mkdir objects
```
Then, you can compile using `make`:
```bash
make -j
```

## Folder tree
/
│   .gitignore
│   Makefile
│   README.md
│
├───externals
│   ├───include
│   │   ├───GLFW
│   │   │       glfw3.h
│   │   │       glfw3native.h
│   │   │
│   │   └───imgui
│   │       │   imconfig.h
│   │       │   imgui.cpp
│   │       │   imgui.h
│   │       │   imgui_demo.cpp
│   │       │   imgui_draw.cpp
│   │       │   imgui_internal.h
│   │       │   imgui_tables.cpp
│   │       │   imgui_widgets.cpp
│   │       │   imstb_rectpack.h
│   │       │   imstb_textedit.h
│   │       │   imstb_truetype.h
│   │       │   LICENSE.txt
│   │       │
│   │       └───backends
│   │               imgui_impl_glfw.cpp
│   │               imgui_impl_glfw.h
│   │               imgui_impl_opengl3.cpp
│   │               imgui_impl_opengl3.h
│   │               imgui_impl_opengl3_loader.h
│   │
│   └───libs
│       └───windows-mingw64-13.2.0
│               libglfw3.a
│
├───objects
│
└───src
        constants.hpp
        main.cpp
        snake.cpp
        snake.h

## Credits
- [ImGui](https://github.com/ocornut/imgui)
- [GLFW3](https://github.com/glfw/glfw)