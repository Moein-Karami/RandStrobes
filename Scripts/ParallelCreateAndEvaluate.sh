#!/bin/bash

chmod +x ./Scripts/Job.sh
configs_dir=ChosenConfigs/
g++ -std=c++11 EvaluationWithC++/MetricCalculator.cpp -o metric.out

for config in "$configs_dir"*
do
	name="${config/.json/}"
	name="${name/$configs_dir/}"
	name+=".csv"
	./Scripts/Job.sh "$config" "$name" &
done

wait
R -e "rmarkdown::render('EvaluationWithR/PlotMaker.Rmd')"