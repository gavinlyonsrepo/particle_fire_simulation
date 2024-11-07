
Overview
--------------------------------------------
* Title: particle fire simulation
* Description : particle fire simulation C++ graphics program. 
The program creates a SDL API driven graphic display in a window. For Linux based OS .

Download
-----------------------------------------------

```sh
cd ~/Downloads
curl -L -O https://github.com/gavinlyonsrepo/particle_fire_simulation/archive/master.zip 
unzip master.zip  
cd particle_fire_simulation-master
```

Build
--------------------------------------

* run 'make'  to build
* Exe file made at ./Bin/pfsim 
* run 'make help' for all the other options in make file including in install. 

Usage
------------------------------------------

```
pfsim  [arguments]
pfsim 800 600 5000 7 1000
```

Arguments list

| Number | Name | Default value | Notes  | 
| -------- | ----------- | ----------- | ----------- |
| 1 | width Resolution | 800 | width of SDL window | 
| 2 | height Resolution| 600 | height of SDL window | 
| 3 | number Of Particles |  5000 |  | 
| 4 | RGB bits | 7 | 1 - 6 to turn off red green or blue color , b100 = Red only | 
| 5 | Number of loop counts | 1000 |  | 

Dependencies
--------------------
[SDL2](https://en.wikipedia.org/wiki/Simple_DirectMedia_Layer)

A library for portable low-level access to a video framebuffer, audio output, mouse, and keyboard 
