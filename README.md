# epfu20W-104-E-amazons

## Table of contents

- [Short description](#short-description)
- [Project Members](#project-members)
- [Reports](#reports)
- [Division into libraries](#division-into-libraries)
- [Typing Conventions](#typing-convention)
- [Running the code](#running-the-code)

## Short description

This is an extended version of board game "The Amazons".
The game is played on a chess-like board.
The goal of the players is collect as much treasure as they can by moving their amazons on the board.
Player which collects most treasure wins

## Project Members

- Tymon Żarski {- Project manager -}
- Jan Szachno {+ Guardian of the flock +}
- Mateusz Jakubowski {- Paymaster -}
- Cagla Kuleasan {- Master of the C language -}

## Reports

All meeting reports are available in [Docs](https://gitlab-stud.elka.pw.edu.pl/mjakubo3/epfu20w-104-E-amazons/-/tree/master/Docs 'Projets Docs')

Moreover, flowcharts can be found in this directory

## Division into libraries

All documentation on the division of functions into libraries is in the [Libs](https://gitlab-stud.elka.pw.edu.pl/mjakubo3/epfu20w-104-E-amazons/-/blob/master/Lib/libs.txt 'Projects Libs')

## Typing Convention

```
Struct              TitleCase
Struct Members      lower_case or lowerCase

Enum                ETitleCase
Enum Members        ALL_CAPS or lowerCase

Public functions    pfx_TitleCase (pfx = two or three letter module prefix)
Private functions   TitleCase
Trivial variables   i,x,n,f etc...
Local variables     lower_case or lowerCase
Global variables    g_lowerCase or g_lower_case (searchable by g_ prefix)
```

## Running the code

### For LinuxOS

1. Navigate to the `Source` folder.
   Then use the commands

```
1. make && make clean   // To generate compiled output file
2. ./a                  // To run compiled code
```

### For WindowsOS

1. Install make for windows [YT-Tutorial](https://www.youtube.com/watch?v=taCJhnBXG_w 'Projects Libs')

2. Navigate to the `Source` folder.
   Then use the commands

```
2. make && make clean   // To generate compiled output file
2. ./a.exe                  // To run compiled code
```
