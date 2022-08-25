#!/bin/bash

configs_dir=ChosenConfigs/

for config in "$configs_dir"*
do
	name="${config/.json/}"
	name="${name/$configs_dir/}"
	name+=".csv"
	echo "$name"
	./RandStrobes.out "$config" "$name"
	sleep 1
	R -e "path_kmer_file='$name'; path_output_file='$name'; rmarkdown::render('EvaluationWithR/MetricsEvaluation.Rmd')"
done