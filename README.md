## alphaben 
# cub3D - My First RayCaster with miniLibX

## Overview

**cub3D** is a 3D graphical representation project inspired by the legendary first-person shooter, **Wolfenstein 3D**. Developed using the ray-casting technique, this project allows players to navigate through a maze from a first-person perspective. 

## Table of Contents
- [Introduction](#introduction)
- [Goals](#goals)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [File Format](#file-format)
- [Bonus Features](#bonus-features)
- [Contributing](#contributing)
- [License](#license)

## Introduction

**Wolfenstein 3D**, created by Id Software, revolutionized the gaming industry as the first true first-person shooter. The objective of this project is to explore ray-casting techniques and provide a dynamic maze exploration experience reminiscent of the original game.

## Goals

The primary goals of this project are:
- Improve C programming skills.
- Implement basic algorithms and information research.
- Explore graphics programming and mathematical applications in game development.

## Requirements

- C programming knowledge.
- Familiarity with the [miniLibX](https://github.com/42School/minilibx) graphics library.
- Makefile for project compilation.
- A `.cub` scene description file to run the program.

## Installation

1. Clone the repository:
```bash
   git clone https://github.com/yourusername/cub3D.git
   cd cub3D
```
2. Compile the project using the provided Makefile:
```bash  
  make
```

 >    Ensure that you have the necessary libraries installed, including miniLibX and its dependencies.

Usage

To run the project, provide a .cub file as an argument:

```bash

./cub3D path_to_your_map.cub
``` 
Controls

    Arrow Keys: Look left and right.
    W: Move forward.
    A: Move left.
    S: Move backward.
    D: Move right.
    ESC: Exit the game.
    Red Cross: Close the window and quit the program.

File Format

The map must be in .cub format and consist of the following components:

    Wall and empty space definitions (1 for walls, 0 for empty spaces).
    Player starting position indicated by N, S, E, or W.
    Texture paths and floor/ceiling colors defined as follows:

```bash

    NO ./path_to_north_texture
    SO ./path_to_south_texture
    WE ./path_to_west_texture
    EA ./path_to_east_texture
    F R,G,B  # Floor color
    C R,G,B  # Ceiling color
```
Bonus Features

If the mandatory part is completed successfully, bonus features can include:
```text 
    Wall collision detection.
    A minimap system.
    Doors that can open and close.
    Animated sprites.
    Mouse rotation for the point of view.
```
