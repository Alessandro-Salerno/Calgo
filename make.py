from os import system, name


source = [
    "src\\string.c",
    "src\\token.c",
    "src\\core.c"
]

string = "gcc main.c"

for src in source:
    string += f" {src}"

string += f" -o Calgo.{'exe' if name == 'nt' else 'out'}"
system(string)
