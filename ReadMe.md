Implement PageRank in Simit lang, adapted from [pagerank.sim](https://github.com/simit-lang/simit/blob/210716475e8d41a199b8ad14bd6972eafdfa9bf1/test/input/program/pagerank.sim) and [program-pagerank-test.cpp
](https://github.com/simit-lang/simit/blob/210716475e8d41a199b8ad14bd6972eafdfa9bf1/test/program-pagerank-test.cpp).

Point the cmake build system to Simit like so:

    export SIMIT_INCLUDE_DIR=<path to simit src dir>
    export SIMIT_LIBRARY_DIR=<path to simit lib dir>

Build the springs example like so:

    mkdir build
    cd build
    cmake ..
    make

Run it with a net file:

    ./pagerank ../pagerank.sim ../pages.net

or with `twitter_rv_15066953.net`

The algorithm runs 10 iterations.

With `twitter_rv_15066953.net`:

````
Command being timed: "./pagerank ../pagerank.sim ../twitter_rv_15066953.net"
	User time (seconds): 763.62
	System time (seconds): 3.40
	Percent of CPU this job got: 99%
	Elapsed (wall clock) time (h:mm:ss or m:ss): 12:48.59
	Average shared text size (kbytes): 0
	Average unshared data size (kbytes): 0
	Average stack size (kbytes): 0
	Average total size (kbytes): 0
	Maximum resident set size (kbytes): 11559356
	Average resident set size (kbytes): 0
	Major (requiring I/O) page faults: 133
	Minor (reclaiming a frame) page faults: 2754459
	Voluntary context switches: 514
	Involuntary context switches: 1064
	Swaps: 0
	File system inputs: 1627536
	File system outputs: 0
	Socket messages sent: 0
	Socket messages received: 0
	Signals delivered: 0
	Page size (bytes): 4096
	Exit status: 0
````