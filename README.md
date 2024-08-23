
# Chaos Game Generator

This project allows the user to generate different fractal tests based on the chaos game, and the results can be saved to a PPM to visualize them.



## About the Chaos Game

The chaos game first involves using a polygon — let's say an isosceles triangle. Next, a random point is selected and plotted within this triangle (let's call this the current point). A random vertex of the triangle is also chosen. The midpoint between the random vertex and the current point is half the distance between them. This point midpoint can be plotted and now becomes the new current point. If you continue this process, not just 10, 100, but 1,000 or more times, you will begin to see "order emerge from chaos!"

Below is an example of the above situation simulated using this project over the course of 1,000,000 iterations:

![Screenshot 2024-08-23 143111](https://github.com/user-attachments/assets/37799bbe-36f1-45c0-9502-17a6129ea3db)

*The Sierpiński Triangle*

Other polygons can be used to create different fractals, as shown below:

![Screenshot 2024-08-23 144450](https://github.com/user-attachments/assets/0eba7bce-3988-4ecd-8f9b-107fb8858a88)

*Hexagonal fractal, created using this project*


Further information about the chaos game can be found on its Wikipedia article: https://en.wikipedia.org/wiki/Chaos_game





## Build Instructions

You can download the project files, ensure CMake is setup on your system/IDE, and edit the CMakePresets.json file if needed. 
