# DescIndex
**D**escriptive **I**ndex generator

## Building

To build this application, just either run `make` in the source dir or use CMake.

## How to use
Well it's really simple:
For every file you have, add a file with equal name + `.txt` appended and fill it like this:

    This is the title
    This is a multi-line
    description!

Also place a file named `desc.txt` with the same syntax in each folder. It's what describes the folder itself.

Then, pass the root folder to the application and it'll create `index.html` files.
