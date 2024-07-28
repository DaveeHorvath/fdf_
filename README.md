# FDF

First Graphics Project at HIVE HELSINKI, an introduction to graphics programming.

## Description

This is a school project that made me learn the most this far. This is an ismetric renderer, which creates a wireframe representation of the given heightvalues in a file. It combines the beauty of math and the simplicity of a wireframe. The project uses the MLX42 library, which is an OpenGL based library used for developing simple grapics projects. 

## Getting Started

### Dependencies

* either Linux or MacOS for the best experience.
* For windows a Linux subsystem work the best with Xlaunch

### Installing

* just clone the repo
* if make doesnt work: check https://github.com/codam-coding-college/MLX42 for installation
```
git clone https://github.com/codam-coding-college/MLX42.git
#linux
sudo apt update
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
#mac
brew install glfw
brew install cmake
```

### Executing program

* just clone the repo and run make
* just run the created executable with one of the maps in the maps/ folder
```
make && ./fdf maps/42.fdf
```

## Help

Virtual machines without GPU passthroug don't really like this project.
The docker compatible version is in the making.

## Authors

Contributors names and contact info

David Horvath
dhorvath@student.hive.fi

## Acknowledgments

Big thanks to @heikkiseppanen for helping me with porting it to MLX42 and generally being awesome
