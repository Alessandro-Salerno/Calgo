# Calgo
Calgo is a flowchart building program.
Currently, it is in the pre-alpha phase of development.

Calgo works by converting a string of text, placed inside a text file (Usually ending with `.calgo`), into a tree of nodes known as an AST (Abstract Syntax Tree), just like any normal language compiler, this can then be used as an abstract rapresentation of the flowchart. Keep in mind that CalgoAST is not mature yet and, due to its nature, it is much more basic than a normal language AST.
The resulting nodes are then used by the Calgo ASCII Renderer to display a concrete version f the diagram.

Calgo is written in C and uses no external libraries, all the memory management, table/diagram rendering, lexing, parsing, etc have been built from scratch.
So, given the young age of the project, memory leaks, bugs and inconsistent behaviour are the norm. Most issues are already known, some include:
* Heap memory leaks (Missing string and vector deallocation systems)
* String length has to be determined on the fly since charptr doesnt save it (Strings will soon be turned into a struct of some sort)
* Bad code in some newer areas (Such as table.c, calgo.c and main.c)
* Segfaults when the language lexer fails to recognize a keyword
* And much more

All these issues are in the process of being fixed, but the early stage of the project impose more focus on new features, rather than optimization.
Plans for future features incldue:
* Basic diagram rendering (Start, Input, Oputput, Declaration & Assignment, End)
* Advanced diagram rendering (Functions, If statements, loops)
* Diagram execution (Small VM)
* Diagram exporting

If you want to try Calgo anyway, you can do so by cloning this repository and running the make.py file. Keep in mind that you need the GNU Compiler Collection (GCC), on MS Windows, you can use MinGW, on macOS XCode Dev Tools and, for Linux, the built-in GCC installation.
A cmake replacement for make.py is coming, but keep in mind that you will still need a modern C Compiler (So forget Dev C).
WARNING: Calgo curently refuses to run on Replit!

Lnux/macOS:
```
> git clone https://github.com/tzyvoski/Calgo.git
> cd Calgo
> python3 make.py
> ./Calgo.out help
```

MS Windows:
```
> git clone https://github.com/tzyvoski/Calgo.git
> cd Calgo/
> make.py
> Calgo.exe help
```
