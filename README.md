#RapMap Transcriptome Aligner v0.1.0

To build RapMap, you need a C++11 compliant compiler (g++ >= 4.7 and clang >= 3.4) and CMake. Steps to set the environment for build and run are given below:

```
[path_to_rapmap] > mkdir build && cd build
[path_to_rapmap/build] > cmake ..
[path_to_rapmap/build] > make
[path_to_rapmap/build] > make install
[path_to_rapmap/build] > cd ../bin
[path_to_rapmap/bin] > ./rapmap -h
```
=====================================

There are currently 4 RapMap subcommands
```
    pseudoindex   --- builds a k-mer-based index
    pseudomap     --- map reads using a k-mer-based index
    quasiindex --- builds a suffix array-based (SA) index
    quasimap   --- map reads using the SA-based index
```
Run a corresponding command "rapmap <cmd> -h" for
more information on each of the possible RapMap
commands.

After successful setup, following commands are used to execute:

./rapmap quasiindex -t transcripts.filtered.fa -i index -k 31
./rapmap quasimap -i index -o output -r 10M.1.fastq

quasiindex: mode used for indexing, this option prepares necessary hash table and suffix array required for mapping and ultimately for alignment. The option -k specifies the k-mer size to be used for mapping. The required transcript database is sourced from file transcripts.filtered.fa.

quasimap: this mode is used to perform mapping followed by alignment using the indexing database built in previous step. The sequence read which are to be mapped are sourced from file 10M.1.fastq. These are the example used for illustration purpose and user are encouraged to explore on various genome reads database.

#Test Files Used

We have used the database provided by Professor Rob Patro at Computational Biology laboratory at Computer Science Department, Stony Brook University for the aligner testing and development. Sample genome read and transcriptome are available in repository for quick usage.