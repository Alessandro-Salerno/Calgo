from os import system, name


slash = '\\' if name == "nt" else '/'

source = [
    f"src{slash}string.c",
    f"src{slash}token.c",
    f"src{slash}node.c",
    f"src{slash}core.c"
]

string = "gcc main.c"

for src in source:
    string += f" {src}"

string += f" -o Calgo.{'exe' if name == 'nt' else 'out'} -O3"
system(string)
