## Run Benchmark

### Initialize

```
./Scripts/InitializeNeedidFolders.sh
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
$Directory:$ path which you want to place the configs. (add slash to the end of your directory)

comment: For runnig the create and evaluation randstrobes code you have to copy your selected configs to "./ChosenConfigs".

We suggest to set this to "./ChosenConfigs/" and delete unwanted configs.

$kmer\ len:$ length of each strobe

$w_{min}\ and\ w_{max}:$ boundries of the window

$n:$ number of strobes in strobmers

$mask:$ this is for spaced kmers as strobes, just write -1.

$number\ of\ samples:$ number of sequence which you want to run code for

$DataGenerator:$ Write "FromFile" or "Random"

In this input, if you select "Random", the sequences that are used for creating randomstrobes will be generated randomly, and you must set their length in the next input.

This input will be read from a file named "data" in the "Data" folder if you write "FromFile" for this input. You must place your data in that directory and rename it to 'data'.

Each line from the file will be used to create randstrobes, so please don't add any characters to your input. If you set "number of samples" to 3 and you have 5 lines in your file, only the first 3 lines will be seeded.

If you have three lines in your file and set "number of samples" equal to 5, after creating randstrobes for all three lines, the code will read the data from the beginning and create strobes for the first two lines again.

### Create and evaluate randstrobes

```
./Scripts/CreateAndEvaluate.sh
```

You can see the figures in "EvaluationResults/Figures".

For clearing the results and run code again you can use:
```
./Scripts/ClearResult.sh
```
