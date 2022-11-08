#!/bin/bash

configs_dir=ChosenConfigs/

for config in "$configs_dir"*
do
	name="${config/.json/}"
	name="${name/$configs_dir/}"
	name+=".csv"
	echo "$config"
	echo "$name"
	# ./RandStrobes.out "$config" "$name"
	echo "RandStrobes are created"
	# sleep 1
	# R -e "path_kmer_file='$name'; path_output_file='$name'; rmarkdown::render('EvaluationWithR/MetricsEvaluation.Rmd')"
	g++ -std=c++11 EvaluationWithC++/MetricCalculator.cpp -o metric.out
	./metric.out "$name"
	echo "Metrics are created"
done
R -e "rmarkdown::render('EvaluationWithR/PlotMaker.Rmd')"