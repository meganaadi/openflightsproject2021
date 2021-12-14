Final Project Report
Swarna, Molly, Megana, James



GOALS

Leading Question 
Our goal is to study how to optimize flight routes for people traveling around the globe, and learn more about the real life applications of making the trip as efficient as possible. This could potentially solve the problem of excessive traveling, which not only wastes consumers time and money, but is also detrimental to the environment since airplanes consume excessive amounts of fuel. Given global warming and increased emissions across the world, through optimizing travel time, we can help mitigate those emissions and help reduce some of the negative impacts of modern transportation on the environment. We hope to solve the specific problem of not having efficient transportation, and search for the most optimal routes as possible. If someone wants to travel from one city to another, given the standard flight routes, how can we combine different planes and flight routes to get the passenger to the destination covering as little land/time as possible?


Dataset Acquisition and Processing 
We decided to use the OpenFlights database provided by the CS225 course staff. When it comes to specific datasets within the database, we chose to use the routes dataset which contains airplane routes and airports. The way that the dataset works is through specific airline and airport codes. The data stopped updating in 2014, so it is historical. However, by looking at the past routes, we can come up with an algorithm that could optimize the current data . Even though the data is from 2014, the code would still be relevant for today as routes are being constantly optimized. We download the data by pulling the data and importing it into github, which we then take into VScode for parsing. Data is stored locally in the data folder. To ensure data is correctly imported into vscode, we transfer the data into an excel file, and then put it into code. We plan to filter through the data to have airports be potential nodes for the graph, and use the routes as edges, then calculate the nearest neighbors while checking the distance between nodes by calculating the numerical length and value of edges. This can also be done by examining the height of the graph. We also deleted missing data or unknown entries because we decided not to work with incomplete data entries, when it comes to accuracy while solving essential questions and finding optimal travel routes, to ensure consistency across the board. In order to handle potential errors, we set regulations for the data through code when we parse through it to make sure that we can catch any incomplete entries, and that those will not be included in the data of the algorithms.
The final deliverable would include a programme which allows users to choose which data to load (large or small) and which algorithm to commit. The result would be a string of airport’s iata code connected with arrows (i.e. ORD -> LAX -> LHR ...) 


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




DEVELOPMENTAL LOG

11/13/2021
We are working on fixing the Project proposal for our mentor to approve. Since the landmark algorithm isn’t a viable option, we are replacing it with the Iterative deepening depth-first search algorithm for our complex option. We are implementing a DFS for our traversal and adding it’s runtime, input and output. In addition, we are adding our runtimes for our other algorithms, as we had forgotten to do so earlier. We will be using Dijkstra's Algorithm for our shortest path algorithm. The weights in our graph will be representing distance between the airports in the graph.


11/22/2021: 
We have completed the initial skeleton for the project, where we have created classes for airports and routes to represent the vertices and edges. We also wrote helper and utility classes to read the data files regarding the airports and routes. We also developed several test cases for making sure the code compiles and the file is loaded properly.


11/26/2021
We added graph class implementations, with Graph.h and Graph.cpp, implemented user handling commands in UserCommand.h and UserCommand.cpp, and added minor changes for airports and routes (in Airport.h, Airport.cpp, Route.h, and Route.cpp)


11/28/2021
Doing our weekly meeting/progress report for the week. Possibly making minor changes in the Airport class and Route class, maybe adding an operator, and adding a function to check if the airports are the same (but not a definite change). We are also changing up our traversal to BFS. We will be getting started on our BFS implementation and it will be completed by the end of the week, and also starting on Dijkstra's algorithm.


12/06/2021 
We finished working on the template for our individual parts at this point. During the meeting we went over our individual parts. This includes BFS, Dijkstra's algorithm, and the IDDFS algorithm. We clarified a few implementations as well as worked together to resolve any issues that came up. The algorithms are now working, so we are working on test cases.


12/11/2021 
We discussed our progress, and we discovered some bugs within Dijkstra's algorithm. It works for the small dataset, but the runtime is too long for the large dataset. For the BFS and IDDFS algorithms, we haven't worked with the test cases yet and don't know yet what the runtime is or if the code will pass the test cases. We worked on our user command line for BFS and IDDFS, but they're not done yet. At the moment, the airport code inputs can only be all capital letters.


12/12/2021
We finished the project presentation and the readME file. We recorded our video of our presentation and it's linked below. We are finishing up the project report, just tidying some things up in the results section. We have fixed our issues with the test cases and with the user command line, so now all algorithms are fully functional. We still have long runtimes with the full dataset, but that is to be expected with how many lines it has.
https://drive.google.com/file/d/1uPXKaRj1xxi9BCT8GeR-t0kW-8-Dh0He/view?usp=sharing



RESULTS

We finished our project on time with few changes to our initial goal. We discovered that depth first search can lead to taking up too much memory when running on the computer, so we switched to BFS. Replacing it with BFS cut down the runtime significantly without changing the result. While implementing IDDFS, we discovered that there were many similarities to traversals, by going through the graphs. However, since it iteratively increases the depth while traversing through the graph the runtime is drastically reduced compared to DFS. In addition, through dijkastra’s algorithm we learned that algorithms that run fast for small datasets doesn’t guarantee similar results for large datasets.

The project is stored in a large folder called mp_flight. The OpenFlights dataset is stored in the data folder within mp_flight. The data is separated into 3 different datasets. One with a smaller dataset named airports_small.dat, another with all of the data in the CSV, called airports.dat, and the last one containing the routes of the airplanes, which are the edges in our project. The search algorithms are stored in a folder within mp_flight called search. Dijkstra's algorithm and implementation are in the search_dijkstra.h and search_dijkstra.cpp files. The BFS Traversal implementation is contained within search_BFS.h and search_BFS.cpp. And finally the Iterative Deepening Depth First Search is implemented in search_IDDFS.h and search_IDDFS.cpp.

Our final deliverables for our project is presented as a user program in which the user can type commands after being presented with a menu of options. Called UserCommand, first ./find_green_route must be called after make has run in the terminal. The menu first presents the user with the following options: menu, exit, load, search, BFS, and IDS. In order to be able to begin running any algorithms of your choice, the user must first load the dataset. To present a faster solution, the smaller airplane dataset is recommended, as for certain functions, the runtime is very long due to how large the dataset is. If an acceptable dataset is loaded in, the menu appears again and the user can finally choose to either search for the shortest route using Dijkstra’s Algorithm, run a BFS traversal, or an Iterative Deepening Depth First Search. When the user runs search, they will be prompted to enter the departure airport's IATA code which consists of three unique letters that attach a certain airport to its corresponding code. Then, the user will be prompted to enter an arrival airport code. If either airport’s IATA code does not exist, an error message will show and ask for a valid IATA code. If both are valid, the shortest path to get from the departure airport to the destination airport will be printed. If the user wishes to run a BFS traversal, the user command line will request an IATA code as the start of the traversal through the graph. The traversal will print which airport it is currently at and will label each edge or route as cross or discovered. For the IDDFS, or IDS in the menu, the user is again prompted for 2 inputs. First, the departure airport, then the destination airport. However, UserCommand will also ask for a max depth that will be used to limit the depth of the search. IDDFS will be called and will return whether or not the arrival airport is in the graph. If found, it will return 1, 0 otherwise.  

Our initial goal is to find a way to find the best route to travel from one airport to another. The dijkstra’s algorithm successfully accomplishes this goal. In addition, the BFS and IDDFS we used provides quick traversal through the entire graph which helps us understand how to go through entries in the data. Ultimately, we know that the code is working as intended not just through our test cases, but also because when we run on a smaller dataset we can trace the flight path and know which one is the shortest, and if there is a connection or not. On the target dataset, we can see shortest paths between prominent airports and the routes connecting them, and can also determine how many potential connections it will take to get to an airport in the network.




