1. Implement the generic Box class discussed in the videos/pdfs. Copying and pasting from the slide is fine.

2. Implement the findBox function discussed in the videos/pdfs. Instead of an array of Boxes containing strings, i.e. Box<string>, however, we want to search an array of Boxes containing ints, i.e. Box<int>.

3. Each box contains an int representing a social security number, and thus cannot be negative. Throw another logic_error exception if the user tries to search for a negative number.

4. Write a main() function to set up a small array of Box<int> elements, and use your findBox function inside of a try-catch block. Test out your catch block by entering invalid inputs, i.e. negative numbers and numbers that aren't in your Box array.

5. Note: to get this to work on hills, you will need to #include <stdexcept>