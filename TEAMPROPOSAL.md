									Swarna, James, Molly, Megana
TEAM PROPOSAL


Leading Question 
One of our goals is to learn how to understand to optimize travel routes for people traveling the globe, and learn more about the real life applications of making a route as efficient as possible. This is to solve the problem of excessive travel times, which not only hurt consumers through lost time and money, but are also detrimental to the environment because airplanes consume high amounts of fuel. Given global warming and increased emissions across the world, through optimizing travel time, we can help mitigate those emissions and help reduce some of the negative impacts of modern transportation on the environment. Overall, we hope to solve the specific problem of not having efficient transportation, and search for the most optimal routes as possible. If someone wants to travel from one city to another, given the standard flight routes, how can we combine different planes and flight routes to get the passenger to the destination covering as little land/time as possible? This is the essential question that we are trying to solve. 


Dataset Acquisition and Processing 
For our final project, we have decided to use the OpenFlights database provided by the CS225 course staff. When it comes to specific datasets within the database, we think that using the routes dataset which contains airplane routes and airports. The way the dataset works is through specific airline and airport codes. The routes stopped updating in 2014, so it is historical data. However, by looking to the past routes, we can optimize on the present and learn from the past. This is because by accessing the routes directly, we think that we can find the most effective pathways by also taking location into account, and even though the data is from 2014, it still is relevant for today as routes are constantly being optimized. We will download the data by pulling the data and importing it into github, which we will then take into VScode for parsing. Data can be stored locally. To ensure that the data is able to be imported into vscode, we will first import the data into an excel file, and then put it in vscode if vscode can’t support the original file type. This is our backup plan to ensure that we can use the data and write code to parse through it. We plan to filter through the data and have airports be potential nodes for the graph, and use the routes as edges, and then calculate the nearest neighbors and check the distance between nodes by calculating the numerical length and value of edges. This can also be done by examining the height of the graph. In the case of missing data or unknown entries, we will delete those entries. We decided to not work with incomplete data entries to ensure consistency across the board when it comes to ensuring that we have accuracy when solving our essential question and finding the most optimal travel routes. In order to handle potential errors, we will set regulations for the data through code when we parse through it to ensure that we can catch any incomplete entries, and that those will not be included in the data for use in the algorithms.  


Graph Algorithms 
Shortest Path algorithm to find preferred routes
Input: Graph, starting vertex
Algorithm: Dijkstra’s Algorithm
Output: Shortest path length
Runtime: O((|V|+|E|)log|V|) (|V| number of nodes,|E| number of edges)
Weight: Distance between two nodes
Traversal 
Input: Graph, starting vertex, result
Algorithm: DFS
Output: Node for result
Runtime: O(|V|+|E|) (|V| is the number of nodes,|E| is the number of edges)
Complex Algorithm
Input: Root, depth
Algorithm: Iterative deepening depth-first search
Output: Boolean for whether the node is found at that depth or not
Runtime: O(d)  (d is depth of the shallowest solution)
Weight: Distance between two nodes

Timeline 
Data processing and cleaning done by 11/23 at the latest
At least one algorithm done by the midpoint check in date with our project mentor. (Preferably already started on the second algorithm and traversal) by 11-29/12-1
Written report done by 12/4 (Possibly pushed back a bit bc of 225 midterm) 
Presentation and video written and/or recorded by 12/11 (2 day buffer in case) 

WEEKLY!  Write a paragraph explaining what was accomplished or attempted that week. 



