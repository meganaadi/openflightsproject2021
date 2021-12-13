# sjamma2-madiga2-mhu26-zeyut2
Final Project for sjamma2-madiga2-mhu26-zeyut2

General Notes:

-Airports are referred to through IATA code, which is a 3 letter code that is unique to each airport. A link for IATA codes is through their website https://www.iata.org/en/publications/directories/code-search/ if you’d like to search for a specific airport. 

-IATA codes must be all capital (input ORD, not ord) when inputting an IATA code into the user executable program. 

-There is an assumption in BFS traversal that the traversal will be used on an undirected graph, so when routes are added for BFS, routes are treated as undirected edges. 

1. Location of major code, data, and results 

  Code: 
  
    -All code and data is stored in folder called mp_flight
  Skeleton Code: 
  
    Airport.cpp and .h (sets up airport class and lets us get airport parameters and details, like iata code, latitude, and longitude)
    Route.cpp and .h (sets up route class and lets us get route details like distance, departure iata code, and arrival iata code)
    Graph.cpp and .h (graph class which enables airports and routes to be added as vertices and edges, respectively)
    FileHelper.cpp and .h (Parsing and Loading data: found in util folder)
    
Traversal/Algorithms are ALL found under search folder

    BFS Traversal: search_BFS.cpp and .h 
    Dijkstra: search_dijkstra.cpp and .h
    Iterative deepening depth first search: search_IDDFS.cpp and .h
    
Test Cases: ALL found under tests folder (Further instruction under the tests section of readme)

UserCommand program: under util in .cpp and .h (This code is what we used for the command line executable program, discussed in instruction section of readme)

Data:

The openflights data is under a subfolder called “data”. Locations and descriptions below.

    Airports_small.dat: Small dataset used for testing loading data and algorithms quickly 
    Routes.dat: Dataset with all flight routes 
    airportsUSA.dat: Medium large dataset of all USA airports, used in testing for bfs and iddfs
    airports.dat: Large dataset with all airports
    
DATA FORMAT: Data was taken from https://openflights.org/data.html

The data includes the following identifiers: 

    Airport ID   Unique OpenFlights identifier for this airport.
    * Name Name of airport. May or may not contain the City name.
    * City Main city served by airport. May be spelled differently from Name.
    * Country  Country or territory where airport is located. See Countries to cross-reference to ISO 3166-1 codes.
    * IATA 3-letter IATA code. Null if not assigned/unknown.
    * ICAO 4-letter ICAO code. Null if not assigned.
    * Latitude Decimal degrees, usually to six significant digits. Negative is South, positive is North.
    * Longitude    Decimal degrees, usually to six significant digits. Negative is West, positive is East.
    * Altitude In feet.
    * Timezone Hours offset from UTC. Fractional hours are expressed as decimals, eg. India is 5.5.
    * ST   Daylight savings time. One of E (Europe), A (US/Canada), S (South America), O (Australia), Z (New Zealand), N (None) or U (Unknown). See also: Help: Time
    * Tz database time zone    Timezone in "tz" (Olson) format, eg. "America/Los_Angeles".
    * Type Type of the airport. Value "airport" for air terminals, "station" for train stations, "port" for ferry terminals and "unknown" if not known. In airports.csv, only type=airport is included.
    * Source   Source of this data. "OurAirports" for data sourced from OurAirports, "Legacy" for old data not matched to OurAirports (mostly DAFIF), "User" for unverified user contributions. In airports.csv, only source=OurAirports is included.


Results:

Our goals were to find the shortest flight paths between airports to optimize air travel. We succeeded at this through dijkstra's algorithm, where the flight path needed to be taken was displayed. For example, from Chicago, USA to Mangalore, India, on the smaller data set (which is a constraint if people only want to visit popular airports with large international scale), the route goes from Chicago, London, Bangalore, Mangalore. 
    
For BFS, our results showed how we marked on the graph edges as cross, discovery, or undiscovered. Through this, we accomplished our goal of understanding how graph traversals on larger datasets work and how quickly runtime can be in real life on large datasets provided the code is efficient. 

For IDDFS, our results showed whether or not a specific airport was found at a certain depth from a starter airport. In context, this checks to see whether or not we can connect to the desired airport within a certain amount of connections. Through this, we learned more about how graph algorithms can determine whether or not connections to a specific node are possible.   

2. INSTRUCTIONS 

First, open the command line and change directory to mp_flight. 

    cd mp_flight 
Then, execute make

    make 
Then, in order to run the user program we created, launch find_green_route

    ./find_green_route
You will be presented with a menu of options. (looks like below)

    Starting ...please enter a command:
    menu     - prints this menu 
    exit     - exit the program 
    load     - load data 
    search   - search for flights 
    BFS      - run BFS 
    IDS      - Iterative deepening depth-first search 
    
First, you must load the dataset in

    type in “load”
You will then be prompted to enter in the location of the datasets you would like to run the program on. (do not use airports.dat because the file is so big that the runtime is expected to be long)

    EXAMPLE: type in “data/airportsUSA.dat”, then “data/routes.dat”
    
Then, the menu will appear again. This time, you will be able to run any of the functions after loading data. If you try to run these functions without loading data, you will get a message to load the data first. (call menu to print menu after running algorithm)

search (Dijkstra’s Algorithm)

    When running this function, you will be prompted to enter the IATA code of the departure airport in the dataset. All capital letters. 
    Example: “ORD”
    You then will be prompted to enter the IATA code of the arrival airport. 
    Example: “IXE”
    Note: if the airport does not exist, you will receive an error message and be prompted to enter the IATA code again, correctly. 
    The algorithm will be called and the results of the shortest path will be displayed on the screen. 
    
BFS (bfs traversal)

    When running this, you will be prompted to enter the IATA code of the airport (vertex) you would like to start the BFS from. 
    Then, the traversal will print out which edges are cross and which are discovered. 
    
IDS (iterative deepening depth first search)

    When running this function, you will be prompted to enter the IATA codes of the departure and arrival airports just like in the search (dijkstra’s) function. 
    You will also be asked to input a max depth integer which will be used in the function as the limiting depth. 
    Example: “15”
    The algorithm will be called and return whether or not the arrival airport was found within the IDDFS from the departure airport. 
    The algorithm will return the current depth limit and whether or not the arrival airport has been found in the graph. If it was not found, it will print 0. If it is, it will print 1. 
    
3.TEST SUITE
We took the test harness from the catch framework used within the mps and labs in this class. 
In order to run the tests, you must:

    make test
    ./test
Description of tests:

bfs_tests.cpp:

    Creates an undirected graph with routes and airports
    Makes sure that the labels of cross, discovery, and unexplored are correct through test assertions
    
Search_tests.cpp

    For dijkstra’s algorithm 
    Creates directed graph with routes and airports
    Through test assertions, makes sure that the shortest path routes match the paths given
    
Search_iddfs.cpp

    Creates undirected graph with routes and airports
    Through assertions, makes sure that the output matches whether or not the node would actually be found at that depth. 

****NOTE: We know these test cases are correct because we performed the test operations ourselves by drawing out the graphs and also through this website.
https://www.cs.usfca.edu/~galles/visualization/Algorithms.html 


