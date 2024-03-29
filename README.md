## Run Benchmark

### Initialize

```
./Scripts/InitializeNeededFolders.sh
```

### Complie

```
cmake .
make
```

### Create configurations for randstorbes

To create randstrobes, you can set a variety of comparator, linking, and hashing functions.

The configurations can be set in Src/ConfigGenerator/ConfigGenerator.cpp. You can set the hash function in the "add_hasher_config" function, the comparator in the "add_comparator_config" function, and the link function in the "add_seed_creator_config" function.

Using this file, you will be able to generate all the configuration files that appear in the paper. We recommend you don't make any changes to this file and just generate all the configuration files and delete any that you do not want.

To generate the configs run this code:

```
./config.out
```

inputs:
- $Directory:$ path which you want to place the configs. (add slash to the end of your directory)

comment: For runnig the create and evaluation randstrobes code you have to copy your selected configs to "./ChosenConfigs".

We suggest to set this to "./ChosenConfigs/" and delete unwanted configs.

- $kmer\ len:$ length of each strobe

- $w_{min}\ and\ w_{max}:$ boundries of the window

- $n:$ number of strobes in strobmers

- $mask:$ this is for spaced kmers as strobes, just write -1.

- $number\ of\ samples:$ number of sequence which you want to run code for

- $DataGenerator:$ Write "FromFile" or "Random"

comment: In this input, if you select "Random", the sequences that are used for creating randstrobes will be generated randomly, and you must set their length in the next input.

In other case, if you choose "FromFile", the sequences that are used for creating randstrobes will be retrieved from a file which you should put in "Data" folder and write its fullname as input for the next field.

The 'datafile' must have sequences separated by '>' symbols. This allows you to split your input into multiple lines, with each sequence ending with a '>'. For instance, the following input:

ATTCG

ATT

CCG

\>

AAT

will be considered as two sequences: 'ATTCGATTCCG' and 'AAT'.
It is important to note that any line starting with the '>' symbol will be disregarded.

If you have three sequences in your file and set "number of samples" equal to 5, after creating randstrobes for all three sequences, the code will read the data from the beginning and create strobes for the first two sequences again.

### Create and evaluate randstrobes

For sequential execution run:
```
./Scripts/SequentialCreateAndEvaluate.sh
```
For parallel execution run:
```
./Scripts/ParallelCreateAndEvaluate.sh
```

You can see the figures in "EvaluationResults/Figures".

For clearing the results and run code again you can use:

```
./Scripts/ClearResult.sh
```
