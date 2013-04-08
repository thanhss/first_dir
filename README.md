## Overview

This project is an example of a cross-platform project to
build executables for Windows and OS X using cocos2d-x.

This project organization allows you to pull changes to
cocos2d-x and then build your project against these.

I created this project from _samples/Cpp/HelloCpp_.

## Setup

Clone cocos2d-x into the same folder that will contain this project (multiproj).
The following shows how to do this within a folder named _git_ under your
home directory (~).

    cd ~/git
    git clone https://github.com/cocos2d/cocos2d-x.git
    git clone https://github.com/csusbdt/multiproj.git
 

## Under Xcode

Start Xcode and load the multiproj project.  Try to build and run.
In my case, the project would compile but not launch.  I needed to do the following.

Check that Multiproj is the currently selected scheme.

- Select Product ... Scheme ... Multiproj

If that isn't enough, try the following.

- Select Product ... Scheme ... Edit Scheme.
- Select the Info tab.
- Set the Executable to Multiproj.app.

Also, you need to set the working directory to the Resource folder.
Do the following.

- Select Product ... Scheme ... Edit Scheme.
- Select the Options tab.
- Check the box to set a custom working directory.
- Set the working directory to ``$(SRCROOT)/../Resources``.


## Under Visual Studio 2010 (Express or Professional)

- Open the solution file under win32.vs2010 in Visual Studio 2010 Express (or Professional).
- Right click the proj.win32 project and select _Set as Startup Project_.
_ Click the green icon to build and run the the startup project (set to proj.win32 in the previous step). 


## Project Creation Notes

These are my notes on how I set up the project.  You don't need to do these
if you are working from the multiproj project.

Set the search path for include files to the following.

    "$(SDKROOT)/usr/include/libxml2/" "$(SRCROOT)/../../cocos2d-x/cocos2dx/include" "$(SRCROOT)/../../cocos2d-x/cocos2dx" "$(SRCROOT)/../../cocos2d-x/cocos2dx/platform/mac" "$(SRCROOT)/../../cocos2d-x/cocos2dx/kazmath/include"

## The Tiled Map Editor

The project depends on the map editor called Tiled.  
You will need to install the Tiled editor to create and modify maps.
We will be useing the Qt-version of Tiled, so install that.

