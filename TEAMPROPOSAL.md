TEAM PROPOSAL

Even if you choose to use an example project goal, as a team you are responsible for submitting a project proposal of no more than two pages that contains the following information:

Leading Question 
One of our goals is to learn how to understand to optimize travel routes for people traveling the globe, and learn more about the real life applications of making a route as efficient as possible. This is to solve the problem of excessive travel times, which not only hurt consumers through lost time and money, but are also detrimental to the environment because airplanes consume high amounts of fuel. Given global warming and increased emissions across the world, through optimizing travel time, we can help mitigate those emissions and help reduce some of the negative impacts of modern transportation on the environment. Overall, we hope to solve the specific problem of not having efficient transportation, and search for the most optimal routes as possible. If someone wants to travel from one city to another, given the standard flight routes, how can we combine different planes and flight routes to get the passenger to the destination covering as little land/time as possible? This is the essential question that we are trying to solve. 

Dataset Acquisition and Processing 
For our final project, we have decided to use the OpenFlights database provided by the CS225 course staff. When it comes to specific datasets within the database, we think that using the routes dataset which contains airplane routes and airports. The way the dataset works is through specific airline and airport codes. The routes stopped updating in 2014, so it is historical data. However, by looking to the past routes, we can optimize on the present and learn from the past. This is because by accessing the routes directly, we think that we can find the most effective pathways by also taking location into account, and even though the data is from 2014, it still is relevant for today as routes are constantly being optimized. We will download the data by pulling the data and importing it into github, which we will then take into VScode for parsing. Data can be stored locally. To ensure that the data is able to be imported into vscode, we will first import the data into an excel file, and then put it in vscode if vscode can’t support the original file type. This is our backup plan to ensure that we can use the data and write code to parse through it. We plan to filter through the data and have airports be potential nodes for the graph, and use the routes as edges, and then calculate the nearest neighbors and check the distance between nodes by calculating the numerical length and value of edges. This can also be done by examining the height of the graph. In the case of missing data or unknown entries, we will delete those entries. We decided to not work with incomplete data entries to ensure consistency across the board when it comes to ensuring that we have accuracy when solving our essential question and finding the most optimal travel routes. In order to handle potential errors, we will set regulations for the data through code when we parse through it to ensure that we can catch any incomplete entries, and that those will not be included in the data for use in the algorithms.  

Graph Algorithms -Your final project must implement at least two graph data algorithms as well as a graph traversal from the list of example goals or you must propose an algorithm or set of graph algorithms that represent an equivalent amount of coding development. Accordingly, your proposal should clearly state what algorithms you will complete by the projects end. When describing your choices, be sure to include the following: What are the inputs you expect each method to take in? What output are you expecting for each method? If there are multiple ways to implement an algorithm, what is your target big O or efficiency benchmark? For the more complex algorithms, be sure to include as part of the input any additional information you might need. For example, A* search requires a heuristic. If you choose to do A*, what are some possible heuristics you might use?


Any Shortest Path algorithm to find preferred routes
Input: initial location, final location
Algorithm: 
               1. Push item into stack
               2. Update distance and neighbor
               3. Accumulate shortest path
Output: shortest path
Landmark Path
Input:
Algorithm:
               1. Choose vertex between nodes as landmark
               2. Calculate shortest path between vertex
Output: 

Timeline - As a team, identify a list of tasks such as data acquisition, data processing, completion of each individual algorithm, production of final deliverables, etc… and write a proposed timeline for the completion of these tasks. You are not required to adhere strictly to this timeline but it should represent a reasonable set of benchmarks to strive for. For example, stating that you will finish all graph algorithms over the span of a single week is not reasonable. You will be expected to accomplish at least some of these tasks by the mid-project check-in.

Data processing and cleaning done by 11/20 at the latest
At least one algorithm done by the midpoint check in date with our project mentor. (Preferably already started on the second algorithm) by 11-29/12-1
Written report done by 10/4 (Possibly pushed back a bit bc of 225 midterm) 
Presentation and video written and/or recorded by 10/11 (2 day buffer in case) 

WEEKLY!  Write a paragraph explaining what was accomplished or attempted that week. 
