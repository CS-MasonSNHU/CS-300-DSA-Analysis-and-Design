# CS-300-DSA-Analysis-and-Design

In the projects for this course, the primary problem was to design and implement a program to manage course data for ABC University, enabling users to select a data structure to store and retrieve course details efficiently. The solution involved building a menu-driven application where users could select between a vector, hash table, or binary search tree to store course information and then access the data by loading files, printing sorted course lists, or searching for specific courses and their prerequisites.

Problem Approach
Understanding the nature and advantages of different data structures was essential. Each structure—vector, hash table, and binary search tree—has unique strengths for data access, insertion, and retrieval. For example:

Vectors provide simple, contiguous storage but are slower for searches in large datasets.
Hash Tables offer average O(1) access time, making them ideal for quick lookups, which led to selecting it as the primary structure.
Binary Search Trees (BSTs) maintain data in sorted order, facilitating efficient access for range queries or ordered data retrieval.
The implementation allowed testing each data structure’s effectiveness based on the dataset size and operations needed. Choosing a data structure is critical for performance, as each structure affects memory use, speed, and scalability.

Overcoming Roadblocks
Encountering issues with file handling, data loading, and ensuring data structure-specific functions work consistently across structures were significant challenges. By debugging systematically and validating the data structure operations independently, I could address these roadblocks. Additionally, focusing on understanding each structure’s time complexity and limitations helped in designing effective solutions.

Expanding Software Design Approach
Working on this project provided insights into the importance of choosing data structures based on problem requirements and expected data operations. It reinforced how data structures impact the efficiency and flexibility of a program, broadening my approach to balancing performance with ease of use and maintenance.

Evolving Program Design for Maintainability, Readability, and Adaptability
This project emphasized the importance of writing modular code that can be extended or modified. Implementing separate functions for data structure selection, loading, printing, and searching enhanced readability and made the program adaptable to future changes or additional data structures. Clear documentation and adhering to naming conventions were also key to making the program easier to understand and maintain.
