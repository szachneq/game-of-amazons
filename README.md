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
Navigate to the `Source` folder.
Then use the command `make && make clean`

Executable file called `a.exe` will appear.
Use command `./a.exe` to run it
