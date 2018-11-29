# finalproject

1. **Algorithm Purpose:** 
We need a data structure that can store items in order  (nature of tree self sorts and sort time is just O(n), search is cut down compared to a traditional list to log(n) ). 

2. **Algorithm:** Describe the basic idea of the algorithm; show and describe pseudo-code. Your pseudo-code should be
in the style of the text book, should be extremely neat and clear, and should use enough abstraction so that it fits on
one or two slides.

3. **Algorithm Analysis:** What are the interesting features of the algorithm? What is its time complexity, and why?

4. **Problem Statement:** Using a regular non self balancing BST operations can vary in time complexity. While the best case of a search will take O( log n ) time, it is possible to insert the same elements in a different order and cause a search to take linear O( n ) time.  A Red Black tree is essentially a BST with a self balancing mechanism implemented. This self balancing nature will ensure O( log n ) time regardless of insertion order. Given the added memory and time necessary to mantain a Red Black Tree's balancedness, certain data sets and applications may not profit from a RBT implementation compared to a BST.

5. **Implementation:** C++, BST, Red-Black Tree

6.~~**Demo:** A short demonstration of your program. Have this ready to go; do not waste time “setting up.” You may
decide to provide static screen shots and sample output instead of running your program “live”, to ensure a smooth
presentation.~~ 

7. **Experimental Plan:** Integers, in order, reverse order, randomized,and with varying input size. Describe the dataset that you used to test the algorithm. How did you generate it? What
characteristics does it have, and why? What did you decide to vary in the input set, and why?

8. **Results:** What did you learn from testing your algorithm?

9. **Limitations and Future Work:** What limitations does your project currently exhibit? If you had another month to
work on the project, how would you improve your project? What additional tests would you run?
