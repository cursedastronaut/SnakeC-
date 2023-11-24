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
/__
│   .gitignore__
│   Makefile__
│   README.md__
│__
├───externals__
│   ├───include__
│   │   ├───GLFW__
│   │   │       glfw3.h__
│   │   │       glfw3native.h__
│   │   │__
│   │   └───imgui__
│   │       │   imconfig.h__
│   │       │   imgui.cpp__
│   │       │   imgui.h__
│   │       │   imgui_demo.cpp__
│   │       │   imgui_draw.cpp__
│   │       │   imgui_internal.h__
│   │       │   imgui_tables.cpp__
│   │       │   imgui_widgets.cpp__
│   │       │   imstb_rectpack.h__
│   │       │   imstb_textedit.h__
│   │       │   imstb_truetype.h__
│   │       │   LICENSE.txt__
│   │       │__
│   │       └───backends__
│   │               imgui_impl_glfw.cpp__
│   │               imgui_impl_glfw.h__
│   │               imgui_impl_opengl3.cpp__
│   │               imgui_impl_opengl3.h__
│   │               imgui_impl_opengl3_loader.h__
│   │__
│   └───libs__
│       └───windows-mingw64-13.2.0__
│               libglfw3.a__
│__
├───objects__
│__
└───src__
        constants.hpp__
        main.cpp__
        snake.cpp__
        snake.h__

## Credits
- [ImGui](https://github.com/ocornut/imgui)
- [GLFW3](https://github.com/glfw/glfw)