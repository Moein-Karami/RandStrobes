#!/bin/bash

configs_dir=ChosenConfigs/

for config in "$configs_dir"*
do
	name="${config/.json/}"
	name="${name/$configs_dir/}"
	./RandStrobes.out "$config" "./BenchMarkResults/$name"
	sleep 2
	name+=".csv"
	Rscript EvaluationWithR/MetricsEvaluation.Rmd "$name" "$name"
done