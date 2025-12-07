# PPM Image Generator - Reflection

### 1. What was the hardest part about prompting for C++ code?
The hardest part was dealing with compilation errors and viewing the generated image. Initially, I tried to view the image through jumpshare but it wouldn't display on my computer. I had to download IfranView. I didn’t have a working compiler set up, and I tried opening the `.cpp` file in IrfanView instead of the `.ppm` output, which caused confusion before I understood the workflow. I eventually figured out I had to download MSYS2 MinGW 64-bit since my command prompt wasnt able to handle the task.

### 2. How did you verify that the AI-generated code was correct?
I compiled the code in MSYS2 MinGW 64-bit, ran it to generate the `.ppm` file. I then opened it in IrfanView to check the visual output. I confirmed the patterns and colors matched what I described in the prompt.

### 3. What would you do differently next time you prompt for code?
Next time, I would include specific RGB values, dimensions, and pixel math from the start to avoid multiple iterations. Being precise about patterns (stripes, gradient direction, size) helps the AI produce accurate code immediately. I now understand how to compile the file and how to view it in IfranView so I feel more confident about using PPM images.

### 4. Which line(s) of the generated code took you the longest to understand?
The line that calculates stripe or gradient colors using `(y / stripeHeight) % 2` took the longest to understand. It was important to realize this formula determines which color each pixel should be in alternating patterns.
