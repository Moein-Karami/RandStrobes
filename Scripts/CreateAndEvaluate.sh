#!/bin/bash

chmod +x ./Scripts/Job.sh
configs_dir=ChosenConfigs/

for config in "$configs_dir"*
do
	name="${config/.json/}"
	name="${name/$configs_dir/}"
	name+=".csv"
	./Scripts/Job.sh "$config" "$name" &
done

wait
R -e "rmarkdown::render('EvaluationWithR/PlotMaker.Rmd')"