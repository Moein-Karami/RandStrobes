config=$1
name=$2
./RandStrobes.out "$config" "$name"
echo "RandStrobes of $config and $name are created"
# sleep 1
# R -e "path_kmer_file='$name'; path_output_file='$name'; rmarkdown::render('EvaluationWithR/MetricsEvaluation.Rmd')"
g++ -std=c++11 EvaluationWithC++/MetricCalculator.cpp -o metric.out
./metric.out "$name"
wait
echo "Metrics of $config and $name are created"