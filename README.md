# Introduction
This is a runnable and robust version of CH-benchmark  Hybrid Transactional/Analytical Workload

This work was originally published by



[The Mixed Workload CH-benCHmark.]: https://db.in.tum.de/research/projects/CHbenCHmark/?lang=en

We committed program optimization and solved several bugs related to memory leaks.

This current repo is now finely adapted to latest version of software and hardware systems.



## Getting Started

This implementation of the CH-benCHmark was created for the UNIX platform. It uses unixODBC 
and pthreads.
Additionally, it can handle different SQL dialects. 

To add a new dialect:
    - put a new dialect file in the "dialect" directory
    - implement the interface given in "dialect/Dialect.h"
    - see "dialect/HanaDialect.h" as example
    - modify the "DialectStrategy::getInstance()" function in "dialect/DialectStrategy.cpp"


To build it:
    requirements are: 
    - libodbc and libodbc-dev (Ubuntu 18.04 and above)
    - GNU make (version 3.81+)
    - c++11 compiler (gcc 4.7 and above)
    
```bash
1. Adjust "Makefile" if needed, for example:
- CC to appropriate c++11 compiler
- add -L/path/to/libodbc/directory to LDFLAGS

2. make
```



To run it:

```bash
1. Make sure all required libraries can be found, for example:
	- export LD_LIBRARY_PATH=/path/to/libodbc/directory
   
2. Make sure you can connect to the system under test using unixODBC's "isql":
	- isql yourDataSourceName yourDatabaseUser yourPassword

3. Create initial database as CSV files:
    chBenchmark
    -csv
    -wh <WAREHOUSE_COUNT>
    -pa <INITIAL_DB_GEN_PATH>

    example: chBenchmark -csv -wh 50 -pa /path/to/any/directory
    
4. Run test:
    chBenchmark
    -run
    -dsn <DATA_SOURCE_NAME>
    -usr <DBS_USER>
    -pwd <DBS_PASSWORD>
    -a <ANALYTICAL_CLIENTS>
    -t <TRANSACTIONAL_CLIENTS>
    -wd <WARMUP_DURATION_IN_S>
    -td <TEST_DURATION_IN_S>
    -pa <INITIAL_DB_CREATION_PATH>
    -op <OUTPUT_PATH>

    example: chBenchmark -run -dsn yourDataSourceName -usr yourDatabaseUser -pwd yourPassword 
             -a 5 -t 10 -wd 60 -td 300 -pa /path/to/any/directory -op /path/to/any/directory
```
