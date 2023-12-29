/**
 * Notes
 * .hh is like .hpp, .hxx, another convention for C++
 * This gazebo plugin subclasses WorldPlugin, where you can load a world models
 * To build:
 * 1. create build in the package folder
 * 2. cmake .. & make -j4 
 * cmake generates build system files. make generates a Makefile

 * Gazebo macro GZ_REGISTER_WORLD_PLUGIN requires public: function. 
 * A single access specifier public: is not good enough

 * To make this working, you need to:
    1. paste <plugin name="hello_plugin" filename="libhello.so"/> to world file, under <world name="default">
    2. export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$PWD
    3. gazebo myworld.world --verbose # verbose is to print out more

 * To troubleshoot:
    - gazebo 

 * General notes about using gazebo:
    - Not recommended to create a car model in Gazebo. Once saved in a world, it's regarded as a static entity
    - It is hard to edit them in the GUI again. So, CREATE YOUR ROBOT in URDF
    - You must have a ground plane. Otherwise, the robot will fall
 */
#include "gazebo/gazebo.hh"

namespace gazebo
{
    class HelloWorld: public WorldPlugin{
        // calling parent class ctor
        public: HelloWorld() : WorldPlugin(){
            printf("Launching Hello World!\n");
        }

        public: void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/){
            // Dummy placeholder
        }
    };
    GZ_REGISTER_WORLD_PLUGIN(HelloWorld)
}