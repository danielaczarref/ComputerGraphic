# Computer Graphic 

My name is Daniela Carvalho and I'm a brazilian student of computer engineering. This project is the result of the beginning of my understanding in Computer Graphics with OpenGL. In this project, I had to develop 4 basic activities: region filling, geometric transformations, animations and lighting.

## Getting Started

Requirements for each activity:

- Region Filling: to create a new fill pattern, change colors and fill patterns only from the inner area of the selected square, correct the rectangle area when the user resizes the window through the glutReshapeFunc function.

- Geometric Transformations: to create an object whose parts can be controlled by the keyboard

- Animations: to use the object created in the geometric transformation and control it by the animation function.

- Lighting: to create a scene that contains lighting.

### Prerequisites

I used Visual Code to develop my programs, but you can use the IDE or Text Editor of your choice.

To use the OpenGL library, you must run the following command lines:

- sudo apt-get install freeglut3 freeglut3-dev

- sudo ln -s /usr/lib/x86_64-linux-gnu/libglut.a /usr/lib/libglut.a

- sudo ln -s /usr/lib/x86_64-linux-gnu/libglut.so /usr/lib/libglut.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libGL.so /usr/lib/libGL.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libglapi.so /usr/lib/libglapi.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/libGLU.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libGLU.a /usr/lib/libGLU.a

## Region Filling

The Region Filling file ("preenchimento.cpp", in brazilian portuguese) is made with a 32-bits image of a dinosaur. I made it on Excel because it's easier to count the bits and transform them to hexadecimal. By the way, you can do the same with whatever image you wanna create, just remember to start the GLUbyte vector from the bottom of the image!

I used variables to define the colors and coordinates of my region. Also created variables for scaling the region as the user extends the window. 

In the mouse function, is defined that, when the user clicks INSIDE the region, it will randomly change the color of the region. 

## Geometric Transformations

Here, I created a pacman controlled by the keyboard direction keys. Pretty nice imo.

## Animations

Here, I used the pacman I've created before to walk all by himself.

## Lighting

Ngl, this one is particularly difficult. But I basically created a 3D rectangle in which you can control the lighting through the keys 'a' and 'b'.
