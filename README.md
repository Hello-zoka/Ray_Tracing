#  Ray Tracing

Hello! You can find there my implementation of ray tracing for simple geometry objects. Tracing, reflection, refraction, and shades of light have been implemented. 
<img width="1193" alt="Снимок экрана 2021-09-20 в 12 15 07" src="https://user-images.githubusercontent.com/77232884/134067103-0ef6e974-4448-480d-b166-6266b7b03f33.png">


Each object has its indices of refraction and reflection, which allows you to create different materials for objects.

<img width="1198" alt="Снимок экрана 2021-09-20 в 12 28 32" src="https://user-images.githubusercontent.com/77232884/134067242-cfc98ad0-d27e-4165-8fda-8279be46545f.png">

You can make your scene from the proposed set of objects(light source, sphere, and plane) and materials(base of 20 variants in file `materials.cpp`) using a convenient interface to add objects by specifying their coordinates. Also, you can add objects by calling their constructor and adding them into `MainScene` using operator `<<`.

You can easily add a new type of object by making a new class, which inhirets `shade` class. For everything to work, it is enough to write the functions for obtaining the normal at a point and finding the point of intersection of the object with the ray(see `sphere.h` file as example)
