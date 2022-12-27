jh msgs
==========
This package generates all the custom message types needed for livot system.

### Note
Whenever a custom message type is needed either for a existing package or for a new package,
it should be defined here, not inside of the package.

### Purpose
The purpose of this dedicated message generation package is to maintain the build process less
dependent to the existence of a specific package, making the entire framework become plug-and-play
in terms of individual package even from the build time.

### Usage
If a package need to refer the custom message type defined in 'jh_msgs',
add the following lines to 'CMakeLists.txt' of that package:

```
catkin_package(
   CATKIN_DEPENDS jh_msgs
)
```

and add the following line to 'package.xml' (inside \<package\>):

```
<run_depend>jh_msgs</run_depend>
```