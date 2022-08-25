#!/bin/bash

configs_dir=ChosenConfigs/

for config in "$configs_dir"*
do
	name="${config/.json/}"
	name="${name/$configs_dir/}"
	./RandStrobes.out "$config" "./BenchMarkResults/$name"
	sleep 2
	input_name = "$name"
	name+=".csv"
	R -e "\"input_name=\'$input_name\'; output_name=\'$name\'; rmarkdown::render(\'EvaluationWithR/MetricsEvaluation.Rmd\')\""
done