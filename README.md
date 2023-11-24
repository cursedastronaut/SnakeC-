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
[![Image](https://i.goopics.net/9jowc3.png)](https://goopics.net/i/9jowc3)

## Credits
- [ImGui](https://github.com/ocornut/imgui)
- [GLFW3](https://github.com/glfw/glfw)