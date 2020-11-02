# Example game with SFML, imgui, older OpenGL, and Bullet Physics

## The oppgave

Implementer ferdig spillet der målet er å slippe ballen slik at boksene blir slått ned:

+ [x] Omstart av spillet
+ [x] Slipp ballen
+ [x] Horisontal og vertikal posisjonering av ballen som skal slippes

I utgangspunktet er det følgende klasser/klassemetoder som må endres:

+ Klassen World med metoder
+ Metoden Application::start()


## Prerequisites
The C++ IDE [juCi++](https://gitlab.com/cppit/jucipp) should be installed.

## Installing dependencies

### Debian based distributions
`sudo apt-get install libsfml-dev libglm-dev libbullet-dev`

### Arch Linux based distributions
`sudo pacman -S sfml glm bullet`

### MacOS
`brew install sfml glm bullet`

## Compiling and running
```sh
git clone --recursive https://gitlab.com/ntnu-iini4003/game
juci game
```

Choose Compile and Run in the Project menu.
