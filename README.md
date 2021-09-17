# CREDITS TO AMA6NEN ORIGINAL REPO: https://github.com/ama6nen/INZERNAL

# INZERNAL

## INZERNAL has been discontinued for public usage and a private version that is much better will only continue existing for SM members.
## I will not remove existing features and keep everything as is for now, but no more updates will come from now on.

#### Growtopia internal cheat focused around clean code, random features, and framework/sdk


# 

#### Screenshots
![Cheats](https://i.imgur.com/yh8QNUT.png)
![Framework](https://i.imgur.com/P3oPaJQ.png)

# 

### Setup tutorial
[![INZERNAL setup tutorial](https://i.ytimg.com/vi/0408qVbICEI/hqdefault.jpg)](https://www.youtube.com/watch?v=0408qVbICEI "INZERNAL setup tutorial")
* **F2 opens the menu**
* **For some people, patched exe will instantly exit on start, opt to use injector if this is the case**

# 

### Building yourself
1. Download project
1. Make sure you are using Release x64
1. (Optional) Modify source if you want to
1. Build all projects
1. Choose your method of injection
   * injector (See below)
   * patcher (See below)
   * Any custom injector
   * Both injector and patcher

# 

### Using the injector
* Keep INZERNAL.dll in the same directory
* F1 will inject INZERNAL to Growtopia
* F3 will uninject INZERNAL and restore everything (Built into INZERNAL)
* F4 will quit injector
* Requires admin permissions due to growtopia changing token permissions
* Also should work with any other injector of your choice

# 

### Using the patcher
* Drag any unpatched Growtopia file into patcher
* Put INZERNAL.dll into same directory as Growtopia
* When you launch Growtopia, INZERNAL.dll is automatically loaded
* Does not require admin perms like injector
* **You can use injector with patched file too**

# 

### Verified compatible Growtopia versions
* Some patterns might be outdated for some versions
* For now going to stick to **V3.51** with spoofing to latest version
* Find version binaries [here](https://github.com/ama6nen/INZERNAL/tree/main/gt)
* Verified working Growtopia versions are
  * V3.51 (Recommended version)

# 

### Downloads
* No need to build anything yourself
* **No support for custom settings right now (will support later)**
* [Downloads here](https://github.com/ama6nen/INZERNAL/releases)

# 

### Debugging
1. Set build to Debug x64
1. Rebuild to be sure everything is correct
1. Inject debug dll to Growtopia
1. INZERNAL will disable Growtopia's token protection automatically, so admin will not be needed for debugging
1. On visual studio go to  Debug -> Attach to Process -> Find Growtopia
1. All done, it should be attached. If it asks for admin perms then you did not inject the dll properly.
* Now you can set breakpoints and trace, etc.
* You can also keep it attached and unload the library, and then reload it.

# 

### Acknowledgments
* This is not **internal**, the first internal ever made for growtopia, that was developed by atipls, me, and tero. 
* That is our private internal and will not be released or sold.
* INZERNAL uses some small parts from internal
* Patcher made by ness
* Otherwise this project is fully made by me

# 

### Dependencies used in this project 
#### Note that none of these need to be downloaded, they are included in the project
* [libpebliss](https://github.com/asinbow/libpebliss)
* [minhook](https://github.com/TsudaKageyu/minhook)
* [json](https://github.com/nlohmann/json)
* [miniz](https://github.com/richgel999/miniz)
* [proton](https://github.com/SethRobinson/proton) (small parts + modified)
* [imgui](https://github.com/ocornut/imgui) (modified)
