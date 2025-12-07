# PPM Image Generator - Prompt Engineering Log

## Attempt 1
**Prompt**: "Write a C++ program that creates a 100x100 PPM image with a pink-to-red diagonal gradient. Use ofstream for file output and nested for loops to write the pixel data."
**Result**: The AI generated code compiled successfully in MSYS2, and the resulting `gradient.ppm` showed a diagonal gradient from pink to red.
**What I learned**: Being specific about the gradient direction and color helped the AI produce usable code. I also learned the importance of including nested loops to iterate over pixels.


## Attempt 2
**Prompt**: "Modify the program to create a 100x100 PPM image with horizontal stripes alternating pink (255,192,203) and purple (128,0,128), each stripe 10 pixels high."
**What I changed**: I specified stripe orientation, stripe height, and exact RGB values for both colors.
**Result**: The AI-generated code compiled successfully. `stripes.ppm` displayed alternating pink and purple horizontal stripes as intended.
**What I learned**: Providing exact RGB values and pixel math (using y / stripeHeight) makes the pattern predictable. Including a modulus operation (`% 2`) is crucial for alternating patterns.


## Attempt 3 (Optional: if you experimented further)
**Prompt**: "Create a checkerboard pattern 100x100, 10x10 pixel squares, black and white."
**What I changed**: Experimented with checkerboard pattern math: `(x / squareSize + y / squareSize) % 2`.
**Result**: Compiled successfully; `checkerboard.ppm` displayed correctly.
**What I learned**: Nested loops are flexible — changing the condition formula changes the pattern entirely. It's important to clearly describe the mathematical relationship for the pattern.


## Final Reflection
- Total attempts: 4-6
- Most helpful prompt technique: **Being specific about pixel math and RGB values**, and describing stripe or square sizes. Asking the AI to explain the process of compiling the file. Asking AI to explain what the errors mean.
- Biggest prompting mistake: Initially, I used vague prompts like "make a gradient" which produced code but not exactly what I wanted visually. I also wasn't using a platform that would display the images so I had to figure out which application to download, then set up the application to be able to compile the files.
- How I verified the code works: Compiled the program in **MSYS2 MinGW 64-bit**, ran it to generate `.ppm` files, and opened them in **IrfanView** to check the visual output. Each iteration, I adjusted the prompt if the colors or pattern weren’t correct.
