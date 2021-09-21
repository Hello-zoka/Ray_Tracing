#  Ray Tracing

Hello! You can find there my implementation of ray tracing for simple geometry objects. It currently supports phong lighting, shadows, reflections, refractions, objects: spheres and planes. 

# Basic Ray Tracing
The basic ray tracing model is as follows. A camera is placed in the scene and rays are cast from the camera's position to points on an imaginary image plane. A ray is used to determine what light would be going towards the camera at that point and direction. In our case each ray represents a pixel in the output image and the resulting color of the ray determines the color output for the pixel.

# Intersections

For each ray we find the closest point of intersection with objects, it is this object that the camera will see at this point

# Diffuse

Diffuse lighting is determined by computing the intensity of the light at a point on the sphere. If the angle is close to the normal at that point then the intensity will be increased. The intensity determines how much of the object's color to contribute.

<img width="511" alt="Снимок экрана 2021-09-21 в 14 42 44" src="https://user-images.githubusercontent.com/77232884/134180124-c421fa6f-40e9-404e-bd73-9a90921cda3c.png">

# Shadows 

Shadows are incorporated into lighting. To determine if a light source should contribute to the lighting at an intersection point a shadow ray is cast from the intersection point to the light source. If there is an intersection before the light source then this point is in the shadow of that light source.
<img width="673" alt="Снимок экрана 2021-09-21 в 16 37 00" src="https://user-images.githubusercontent.com/77232884/134180826-efeda344-b715-4568-8ac8-0a964f8a03db.png">


# Specular 

Specular lighting is calculated by computing a reflection ray by reflecting the light vector about the normal at the intersection point. The view ray is compared to the reflection ray to determine how much specular lighting to contribute. The more parallel the vectors are the more specular lighting will be added.
<img width="911" alt="Снимок экрана 2021-09-21 в 14 33 43" src="https://user-images.githubusercontent.com/77232884/134163872-aba4b412-33ee-4adb-8e4a-24693c575c96.png">


# Reflections 

Reflections are performed by casting rays originating from the intersection point directed along the reflection vector. A portion of the reflected ray's color will be contributed to the original intersection point based on how reflective the surface is. Fortunately this is fairly easy given the a recursive approach for casting rays. There is an arbitrary limit on how many reflections a ray can perform before stopping to improve performance and eliminate potential infinite loops.
<img width="1193" alt="Снимок экрана 2021-09-20 в 12 15 07" src="https://user-images.githubusercontent.com/77232884/134067103-0ef6e974-4448-480d-b166-6266b7b03f33.png">

# Retractions 
Reflections are performed by casting rays originating from the intersection point directed along the reflection vector. A portion of the reflected ray's color will be contributed to the original intersection point based on how reflective the surface is. Fortunately this is fairly easy given the a recursive approach for casting rays. There is an arbitrary limit on how many reflections a ray can perform before stopping to improve performance and eliminate potential infinite loops.

# Materials
Each object has its indices of refraction and reflection, which allows you to create different materials for objects.

<img width="1198" alt="Снимок экрана 2021-09-20 в 12 28 32" src="https://user-images.githubusercontent.com/77232884/134067242-cfc98ad0-d27e-4165-8fda-8279be46545f.png">

# Making Scene
You can make your scene from the proposed set of objects(light source, sphere, and plane) and materials(base of 20 variants in file `materials.cpp`) using a convenient interface to add objects by specifying their coordinates. Also, you can add objects by calling their constructor and adding them into `MainScene` using operator `<<`.

# Adding new type of objects
You can easily add a new type of object by making a new class, which inhirets `shade` class. For everything to work, it is enough to write the functions for obtaining the normal at a point and finding the point of intersection of the object with the ray(see `sphere.h` file as example)
