from os import system, name


source = [
    "src/string.c",
    "src/core.c",
    "src/calgo.c",
    "src/table.c",
    "src/render.c"
]

string = "gcc main.c"

for src in source:
    string += f" {src}"

string += f" -o Calgo.{'exe' if name == 'nt' else 'out'} -O3"
system(string)
