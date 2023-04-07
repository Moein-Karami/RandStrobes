#!/bin/bash

configs_dir=ChosenConfigs/
# g++ -std=c++11 ./EvaluationWithC++/MetricCalculator.cpp -o metric.out

for config in "$configs_dir"*
do
	name="${config/.json/}"
	name="${name/$configs_dir/}"
	name+=".csv"
	echo "$config" "$name"
	./RandStrobes.out "$config" "$name"
	echo "RandStrobes are created"
	# sleep 1
	# R -e "path_kmer_file='$name'; path_output_file='$name'; rmarkdown::render('EvaluationWithR/MetricsEvaluation.Rmd')"
	./metric.out "$name"
	echo "Metrics are created"
done

wait
R -e "rmarkdown::render('EvaluationWithR/PlotMaker.Rmd')"