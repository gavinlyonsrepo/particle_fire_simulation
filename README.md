
Overview
--------------------------------------------
* Title: particle fire simulation
* Description : particle fire simulation C++ graphics program. 
The program creates a SDL API driven graphic display in a window.


Installation
-----------------------------------------------
For local install on Linux based OS 

* Download github directory
* extract tarball
* 'cd' into same path as Makefile
* run 'make'  to build
* Exe file made at ./Bin/pfsim 
* run 'make help' for all options. 

Usage
------------------------------------------

```
pfsim  [arguments]
pfsim 800 600 7 5000 1000
```

Arguments list

| Number | Name | Default value | Notes  | 
| -------- | ----------- | ----------- | ----------- |
| 1 | width Resolution | 800 | width of SDL window | 
| 2 | height Resolution| 600 | height of SDL window | 
| 3 | number Of Particles |  5000 |  | 
| 4 | RGB bits | 7 | 1 - 6 to turn off red green or blue color , b100 = Red only | 
| 5 | Number of loop counts | 1000 |  

Dependencies
--------------------
[SDL2](https://en.wikipedia.org/wiki/Simple_DirectMedia_Layer)

A library for portable low-level access to a video framebuffer, audio output, mouse, and keyboard 
