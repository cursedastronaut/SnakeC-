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
/<br/>
│   .gitignore<br/>
│   Makefile<br/>
│   README.md<br/>
│<br/>
├───externals<br/>
│   ├───include<br/>
│   │   ├───GLFW<br/>
│   │   │       glfw3.h<br/>
│   │   │       glfw3native.h<br/>
│   │   │<br/>
│   │   └───imgui<br/>
│   │       │   imconfig.h<br/>
│   │       │   imgui.cpp<br/>
│   │       │   imgui.h<br/>
│   │       │   imgui_demo.cpp<br/>
│   │       │   imgui_draw.cpp<br/>
│   │       │   imgui_internal.h<br/>
│   │       │   imgui_tables.cpp<br/>
│   │       │   imgui_widgets.cpp<br/>
│   │       │   imstb_rectpack.h<br/>
│   │       │   imstb_textedit.h<br/>
│   │       │   imstb_truetype.h<br/>
│   │       │   LICENSE.txt<br/>
│   │       │<br/>
│   │       └───backends<br/>
│   │               imgui_impl_glfw.cpp<br/>
│   │               imgui_impl_glfw.h<br/>
│   │               imgui_impl_opengl3.cpp<br/>
│   │               imgui_impl_opengl3.h<br/>
│   │               imgui_impl_opengl3_loader.h<br/>
│   │<br/>
│   └───libs<br/>
│       └───windows-mingw64-13.2.0<br/>
│               libglfw3.a<br/>
│<br/>
├───objects<br/>
│<br/>
└───src<br/>
        constants.hpp<br/>
        main.cpp<br/>
        snake.cpp<br/>
        snake.h<br/>

## Credits
- [ImGui](https://github.com/ocornut/imgui)
- [GLFW3](https://github.com/glfw/glfw)