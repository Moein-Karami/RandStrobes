#include<bits/stdc++.h>

using namespace std;

struct Kmers
{
    uint32_t kmer[3];
};

struct Hashes 
{
    uint64_t hashes[3];
    uint64_t final_hash;
};

class CsvFile
{
    public:
        CsvFile(string file_name, bool is_result);
        ~CsvFile();
        void read();
        vector<Hashes*> input_hashes(int num_seeds);
        vector<Kmers*> input_kmers(int num_seeds);
        Hashes* get_new_hash();
        Kmers* get_new_kmer();
        vector<string> parse_new_line(string line);
        void print_col_name();
        vector< vector<string> > get_cols(vector<string> needed_cols);
    private:
        vector<string> get_col(int index);
        vector<string> col_name;
        vector< vector<string> > lines;
        ifstream file_stream;
};


class CsvWriter
{
    public:
        CsvWriter(string output_path);
        ~CsvWriter();
        void write_row(vector<string> vec_add);
        void write_word(string new_word, bool is_comma);
        void write_word(int new_word, bool is_comma);
        void write_word(double new_word, bool is_comma);
        void new_line();
    private:
        ofstream writer_csv;
};


class Sample 
{
    public:
        Sample(int inp_id, CsvFile* inp_csv_file);
        ~Sample();
        void print();
        void evaluate_sample();
        void init_header(vector< vector<string> > & col_seeds);
        void write_in_file(CsvWriter* csv_all_samples, bool is_median);
        int get_n();
        void add_all_data(vector< vector<double> >& all_data);
        string get_hash();
        string get_seed_method();
        void write_seeds(string path);
        void evaluate_hashes();
        void evaluate_kmers();
        void change_csv_file(CsvFile* inp_csv_file);

        void add_kmer(Kmers* new_kmer);
        void add_hash(Hashes* new_hash);


    private:
        double calculate_ehits_final_hashes();
        double calculate_ehits_kmers(int num_kmer);
        double calculate_ehits_distance(int num_kmer1, int num_kmer2);
        int calculate_unique_final_hashes();
        int calculate_unique_kmers(int num_kmer);
        int calculate_unique_hashes();
        double calculate_conflicts();
        double calculate_ehits_hashes();
        string get_hash(int indx);
        int cal_conf_two(int index1, int index2);
        vector<Kmers*> kmers;
        vector<Hashes*> hashes;
        int sample_id;
        int seq_len;
        vector<double> ehits_kmers;
        vector<double> ehits_distance;
        vector<int> unique_kmers;
        vector<double> ehits_hashes;
        int unique_hashes;
        int time_execution;
        int number_seeds;
        int n;
        int kmer_len;
        int w_min;
        int w_max;
        string mask;
        string seed_generator_method;
        string hash_method;
        double conflicts;
        double ehits_final_hash;
        double ratio_final_hash;
        int unique_final_hash;
        CsvFile* csv_file;
};


CsvFile::CsvFile(string file_name, bool is_result)
{
    file_stream = ifstream(file_name);
    string tmp;
    if(is_result)
        file_stream >> tmp;
}

void CsvFile::print_col_name()
{
    for(int i = 0; i < col_name.size(); i++)
    {
        cout << col_name[i] << " ";
    }
    cout << endl;
}

vector<string> CsvFile::parse_new_line(string file_name)
{
    vector<string> ans;
    string now = "";
    for(int i = 0; i < file_name.size(); i++)
    {
        if(file_name[i] == ',')
        {
            ans.push_back(now);
            now = "";
            continue;
        }
        now += file_name[i];
    }
    if(now != "")
        ans.push_back(now);
    return ans;
}   

void CsvFile::read()
{
    string new_line;
    file_stream >> new_line;
    // cout << new_line << endl;
    col_name = parse_new_line(new_line);
    while(file_stream >> new_line)
    {
        lines.push_back(parse_new_line(new_line));   
    }
}

vector<Hashes*> CsvFile::input_hashes(int num_seeds)
{
    vector<Hashes*> ans;
    for(int i = 0; i < num_seeds; i++)
    {
        ans.push_back(get_new_hash());
    }
    return ans;
}

vector<Kmers*> CsvFile::input_kmers(int num_seeds)
{
    vector<Kmers*> ans;
    for(int i = 0; i < num_seeds; i++)
    {
        ans.push_back(get_new_kmer());
    }
    return ans;
}

string Sample::get_hash()
{
    return hash_method;
}

string Sample::get_seed_method()
{
    return seed_generator_method;
}

int Sample::get_n()
{
    return n;
}

uint64_t to_int_64(string inp)
{
    stringstream stream_temp;
    stream_temp << inp;
    uint64_t now;
    stream_temp >> now;
    return now;
}

uint32_t to_int_32(string inp)
{
    stringstream stream_temp;
    stream_temp << inp;
    uint32_t now;
    stream_temp >> now;
    return now;
}

string Sample::get_hash(int indx)
{
    string ans = "";
    for(int i = 0; i < n; i++)
    {
        stringstream stream_temp;
        stream_temp << hashes[indx]->hashes[i];
        string now;
        stream_temp >> now;
        ans += now;
    }
    return ans;
}


Sample::~Sample()
{
    for(int i = 0; i < hashes.size(); i++)
    {
        delete hashes[i];
    }
    for(int i = 0; i < kmers.size(); i++)
    {
        delete kmers[i];
    }
}

CsvFile::~CsvFile()
{
    file_stream.close();
}

CsvWriter::~CsvWriter()
{
    writer_csv.close();
}

Hashes* CsvFile::get_new_hash()
{
    string new_line;
    file_stream >> new_line;
    vector<string> parsed_string = parse_new_line(new_line);
    Hashes* new_hash = new Hashes();
    int cnt = 0; 
    for(int i = 0; i < (int)parsed_string.size() - 2; i++)
    {
        if(i % 2 == 1)
            new_hash->hashes[cnt++] = to_int_64(parsed_string[i]);
    }
    new_hash->final_hash = to_int_64(parsed_string[(int)parsed_string.size() - 2]);
    return new_hash;
}

Kmers* CsvFile::get_new_kmer()
{
    string new_line;
    file_stream >> new_line;
    vector<string> parsed_string = parse_new_line(new_line);
    Kmers* new_kmer = new Kmers();
    int cnt = 0; 
    for(int i = 0; i < (int)parsed_string.size() - 2; i++)
    {
        if(i % 2 == 0)
            new_kmer->kmer[cnt++] = to_int_32(parsed_string[i]);
    }
    return new_kmer;
}

void Sample::evaluate_hashes()
{
    cout << "Evaluation started..." << endl;

    hashes = csv_file->input_hashes(number_seeds);

    cout << "Input new hashes seeds" << endl;
  

    unique_hashes = calculate_unique_hashes();
    cout << "Calculate Unique Hashes" << endl;
  
    ehits_hashes.push_back(calculate_ehits_hashes());
    cout << "Calculate ehits hashes" << endl;
    unique_final_hash = calculate_unique_final_hashes();
    ratio_final_hash = (double)unique_final_hash / (double)unique_hashes;
    ehits_final_hash = calculate_ehits_final_hashes();
    for(int i = 0; i < hashes.size(); i++)
        delete hashes[i];
    hashes.clear();
}

void Sample::evaluate_kmers()
{

    kmers = csv_file->input_kmers(number_seeds);

    cout << "Input new kmers seeds" << endl;

    ehits_kmers.push_back(calculate_ehits_kmers(1));
    if(n == 3)
    {
        ehits_kmers.push_back(calculate_ehits_kmers(2));
    }
    cout << "Calculate Ehits Kmers" << endl;
    ehits_distance.push_back(calculate_ehits_distance(0, 1));
    if(n == 3)
    {
        ehits_distance.push_back(calculate_ehits_distance(0, 2));
        ehits_distance.push_back(calculate_ehits_distance(1, 2));
    }
    cout << "Calculate Distance Kmers" << endl;

    unique_kmers.push_back(calculate_unique_kmers(1));
    if(n == 3)
    {
        unique_kmers.push_back(calculate_unique_kmers(2));
    }
    cout << "Calculate unique kmers" << endl;

    conflicts = calculate_conflicts();
    cout << "Calculate Conflicts" << endl;
}


int Sample::calculate_unique_final_hashes()
{
    map<uint64_t, bool> mark_strobe;
    int ans = 0;
    for(int i = 0; i < hashes.size(); i++)
    {
        uint64_t now_strobe = hashes[i]->final_hash;
        if(!mark_strobe[now_strobe])
        {
            mark_strobe[now_strobe] = 1;
            ans++;
        }
    }
    return ans;
}

double Sample::calculate_ehits_hashes()
{
    map<string, int> cnt_strobe;
    uint64_t ans = 0;
    for(int i = 0; i < hashes.size(); i++)
    {
        string now_strobe = get_hash(i);
        cnt_strobe[now_strobe]++;
    }
    for(auto i = cnt_strobe.begin(); i != cnt_strobe.end(); i++)
    {
        ans += (uint64_t)i->second * (uint64_t)i->second;
    }
    int sz = hashes.size();
    return (double)ans / (double)sz;
}


double Sample::calculate_ehits_final_hashes()
{
    map<uint64_t, int> cnt_strobe;
    uint64_t ans = 0;
    for(int i = 0; i < hashes.size(); i++)
    {
        uint64_t now_strobe = hashes[i]->final_hash;
        cnt_strobe[now_strobe]++;
    }
    for(auto i = cnt_strobe.begin(); i != cnt_strobe.end(); i++)
    {
        ans += (uint64_t)i->second * (uint64_t)i->second;
    }
    int sz = hashes.size();
    return (double)ans / (double)sz;
}

int Sample::cal_conf_two(int index1, int index2)
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int conf_now;
        int pos1 = kmers[index1]->kmer[i - 1];
        int pos2 = kmers[index2]->kmer[i - 1];
        if(pos1 < pos2)
            conf_now = pos1 - pos2 + kmer_len;
        else 
            conf_now = pos2 - pos1 + kmer_len;
        if(conf_now > 0)
            ans += conf_now;
    }
    return ans;
}

double Sample::calculate_conflicts()
{
    uint64_t sum = 0;
    for(int i = 0; i < kmers.size(); i++)
    {
        int mx = 0;
        for(int j = i + 1; j < min(i + kmer_len, (int)kmers.size()); j++)
        {
            int conf_now = cal_conf_two(i, j);
            mx = max(mx, conf_now);
        }
        sum += (uint64_t)mx;
    }
    int sz = kmers.size();
    return (double)sum / (double)sz;
}

int Sample::calculate_unique_hashes()
{
    map<string, bool> mark_strobe;
    int ans = 0;
    for(int i = 0; i < hashes.size(); i++)
    {
        string now_strobe = get_hash(i);
        if(!mark_strobe[now_strobe])
        {
            mark_strobe[now_strobe] = 1;
            ans++;
        }
    }
    return ans;
}

int Sample::calculate_unique_kmers(int num_kmer)
{
    vector<bool>cnt_repeat;
    for(int i = 0; i < seq_len; i++)
    {
        cnt_repeat.push_back(0);
    }
    for(int i = 0; i < kmers.size(); i++)
    {
        cnt_repeat[kmers[i]->kmer[num_kmer]] = 1;
    }
    int ans = 0;
    for(int i = 0; i < seq_len; i++)
    {
        ans += cnt_repeat[i];   
    }
    return ans;
}



double Sample::calculate_ehits_distance(int num_kmer1, int num_kmer2)
{
    uint64_t sum = 0;
    vector<int>cnt_repeat;
    for(int i = 0; i < seq_len; i++)
    {
        cnt_repeat.push_back(0);
    }
    for(int i = 0; i < kmers.size(); i++)
    {
        cnt_repeat[kmers[i]->kmer[num_kmer2] - kmers[i]->kmer[num_kmer1]]++;
    }
    for(int i = 0; i < seq_len; i++)
    {
        sum += (uint64_t)cnt_repeat[i] * (uint64_t)cnt_repeat[i];
    }
    int num_seeds = kmers.size();
    return (double)sum / (double)num_seeds;
}

double Sample::calculate_ehits_kmers(int num_kmer)
{
    uint64_t sum = 0;
    vector<int>cnt_repeat;
    std::cout <<"seq len: " << seq_len << std::endl;
    for(int i = 0; i < seq_len; i++)
    {
        cnt_repeat.push_back(0);
    }
    std::cout << "cnt_repeat initialized and it's size is:" << cnt_repeat.size() << std::endl;
    for(int i = 0; i < kmers.size(); i++)
    {
        if (kmers[i]->kmer[num_kmer] >= cnt_repeat.size())
            std::cout << "seeds[i]->get_kmer(num_kmer) = " << kmers[i]->kmer[num_kmer] << std::endl;
        cnt_repeat[kmers[i]->kmer[num_kmer]]++;
    }
    std::cout << "cnt_repeat calculated" << std::endl;
    for(int i = 0; i < seq_len; i++)
    {
        sum += (uint64_t)cnt_repeat[i] * (uint64_t)cnt_repeat[i];
    }
    std::cout << "sum calculated" << std::endl;
    int num_seeds = kmers.size();
    std::cout << "num_seeds calculated" << std::endl;
    return (double)sum / (double)num_seeds;
}

void Sample::add_hash(Hashes* new_hash)
{
    hashes.push_back(new_hash);
}

void Sample::add_kmer(Kmers* new_kmer)
{
    kmers.push_back(new_kmer);
}

Sample::Sample(int inp_id, CsvFile* inp_csv_file)
{
    sample_id = inp_id;
    csv_file = inp_csv_file;
}

void Sample::print()
{
   cout << "Time" << " " << time_execution << " kmer_len: " << kmer_len <<" seq_len: " <<  seq_len << endl;
}

void Sample::init_header(vector< vector<string> > & col_seeds)
{
    time_execution = stoi(col_seeds[0][sample_id - 1]);
    number_seeds =  stoi(col_seeds[1][sample_id - 1]);
    n =  stoi(col_seeds[2][sample_id - 1]);
    kmer_len =  stoi(col_seeds[3][sample_id - 1]);
    w_min = stoi(col_seeds[4][sample_id - 1]);
    w_max = stoi(col_seeds[5][sample_id - 1]);
    mask =  col_seeds[6][sample_id - 1];
    seed_generator_method = col_seeds[7][sample_id - 1];
    hash_method = col_seeds[8][sample_id - 1];
    seq_len = stoi(col_seeds[9][sample_id - 1]);
}

CsvWriter::CsvWriter(string output_path)
{
    writer_csv = ofstream(output_path);
}

vector<string> CsvFile::get_col(int index)
{
    vector<string> ans;
    for(int i = 0; i < lines.size(); i++)
    {
        ans.push_back(lines[i][index]);
    }
    return ans;
}

vector< vector<string> > CsvFile::get_cols(vector<string> needed_cols)
{
    int pnt = 0;
    vector< vector<string> > ans;
    for(int i = 0; i < col_name.size(); i++)
    {
        if(pnt < needed_cols.size() && needed_cols[pnt] == col_name[i])
        {
            ans.push_back(get_col(i));
            pnt++;
        }
    }
    return ans;
}

// vector<Seed*> create_seeds(vector< vector<string> > &col_seeds)
// {
//     vector<Seed*> ans;
//     for(int i = 0; i < col_seeds[0].size(); i++)
//     {
//         Seed* new_seed = new Seed();
//         for(int j = 0; j < col_seeds.size(); j ++)
//         {
//             if(j % 2 == 0)
//                 new_seed->add_kmer(col_seeds[j][i]);
//             else 
//                 new_seed->add_hash(col_seeds[j][i]);
//         }
//         ans.push_back(new_seed);
//     }
//     return ans;
// }

vector<Sample*> build_samples(CsvFile* csv_result, CsvFile* csv_header)
{
    vector<string> needed_cols{"Sample"};
    vector< vector<string> > col_samples = csv_header -> get_cols(needed_cols);
    needed_cols.clear();
    vector<Sample*> ans;
    Sample* new_sample;

    for(int i = 0; i < col_samples[0].size(); i++)
    {
        new_sample = new Sample(i + 1, csv_result);
        ans.push_back(new_sample);
    }

    return ans;
}



string add_suffix(string prefix, char* suffix)
{
    stringstream path_stream;
    path_stream << prefix;
    path_stream << suffix;
    string path = "";
    path_stream >> path;
    return path;
}

void fill_header_samples(vector<Sample*> &samples, CsvFile* csv_header)
{
    vector<string> needed_cols{"TimeExecution","NumberofSeeds","n","kmer_len","w_min"
    ,"w_max","mask","SeedGeneratorMethod","HashMethod", "seq_len"};
    vector< vector<string> > col_seeds = csv_header -> get_cols(needed_cols);
    // cout << col_seeds.size() << "*********" << endl;
    for(int i = 0; i < samples.size(); i++)
    {   
        samples[i]->init_header(col_seeds);
    }   
}

void Sample::write_in_file(CsvWriter* csv_all_sample, bool is_median)
{
    csv_all_sample->write_word(hash_method, 1);
    csv_all_sample->write_word(seed_generator_method, 1);
    csv_all_sample->write_word(time_execution, 1);
    for(int i = 0; i < ehits_kmers.size(); i++)
    {
        csv_all_sample->write_word(ehits_kmers[i], 1);
    }
    for(int i = 0; i < ehits_distance.size(); i++)
    {
        csv_all_sample->write_word(ehits_distance[i], 1);
    }
    for(int i = 0; i < unique_kmers.size(); i++)
    {
        csv_all_sample->write_word(unique_kmers[i], 1);
    }
    csv_all_sample->write_word(unique_hashes, 1);
    csv_all_sample->write_word(conflicts, 1);
    for(int i = 0; i < ehits_hashes.size(); i++)
    {
        csv_all_sample->write_word(ehits_hashes[i], 1);
    }
    csv_all_sample->write_word(unique_final_hash, 1);
    csv_all_sample->write_word(ratio_final_hash, 1);
    csv_all_sample->write_word(ehits_final_hash, 1);
    if(!is_median)
        csv_all_sample->write_word(sample_id, 0);
    csv_all_sample->new_line(); 
}


vector<string> build_name_cols(int num_kmer, bool is_median)
{
    vector<string> name_cols{"HashMethod","RandStrobeMethod", "TimeofExecution"};

    name_cols.push_back("E-hits of strobe2 positions");
    if(num_kmer == 3)
        name_cols.push_back("E-hits of strobe3 postions");
    name_cols.push_back("E-hits of distance between strobe2 and strobe1");
    if(num_kmer == 3)
    {
        name_cols.push_back("E-hits of distance between strobe3 and strobe1");
        name_cols.push_back("E-hits of distance between strobe3 and strobe2");
    }

    name_cols.push_back("Number of unique strobe2 postions");
    if(num_kmer == 3)
    {
        name_cols.push_back("Number of unique strobe3 position");
    }
    name_cols.push_back("Number of unique Strobmers");
    name_cols.push_back("Conflicts");
    name_cols.push_back("E-hits of Strobmers");
    name_cols.push_back("Number of unique final seed hash values");
    name_cols.push_back("Ratio of number of unique final seed hash value to number of unique strobmers");
    name_cols.push_back("E-hits of final seed hash values");
    if(!is_median)
        name_cols.push_back("Sample");
    return name_cols;
}

void CsvWriter::write_row(vector<string> new_row)
{
    for(int i = 0; i < new_row.size(); i++)
    {
        writer_csv << new_row[i];
        if(i != (int)new_row.size() - 1)
            writer_csv << ",";
    }
    writer_csv << endl;
}

void CsvWriter::write_word(string new_word, bool is_comma)
{
    writer_csv << new_word;
    if(is_comma)
    {
        writer_csv << ",";
    }
}

void CsvWriter::write_word(int new_word, bool is_comma)
{
    writer_csv << new_word;
    if(is_comma)
    {
        writer_csv << ",";
    }
}

void CsvWriter::write_word(double new_word, bool is_comma)
{
    writer_csv << new_word;
    if(is_comma)
    {
        writer_csv << ",";
    }
}

void CsvWriter::new_line()
{
    writer_csv << endl;
}

void add_new_num(vector< vector<double> >& all_data, int &pnt, double new_num)
{
    if(all_data.size() <= pnt)
    {
        all_data.push_back(vector<double>{});
    }
    all_data[pnt].push_back(new_num);
    pnt++;
}

void Sample::add_all_data(vector< vector<double> >& all_data)
{
    int pnt = 0;
    add_new_num(all_data, pnt, time_execution);
    for(int i = 0; i < ehits_kmers.size(); i++)
    {
        add_new_num(all_data, pnt, ehits_kmers[i]);
    }
    for(int i = 0; i < ehits_distance.size(); i++)
    {
        add_new_num(all_data, pnt, ehits_distance[i]);
    }
    for(int i = 0; i < unique_kmers.size(); i++)
    {
        add_new_num(all_data, pnt, unique_kmers[i]);
    }
    add_new_num(all_data, pnt, unique_hashes);
    add_new_num(all_data, pnt, conflicts);
    for(int i = 0; i < ehits_hashes.size(); i++)
    {
        add_new_num(all_data, pnt, ehits_hashes[i]);
    }
    add_new_num(all_data, pnt, unique_final_hash);
    add_new_num(all_data, pnt, ratio_final_hash);
    add_new_num(all_data, pnt, ehits_final_hash);
}

void Sample::change_csv_file(CsvFile* csv_result2)
{
    csv_file = csv_result2;
}

double find_median(vector<double>& vec_inp)
{
    sort(vec_inp.begin(), vec_inp.end());
    int sz = vec_inp.size();
    if(sz % 2 == 1)
    {
        return vec_inp[sz / 2];
    }
    else 
        return (double)(vec_inp[sz / 2] + vec_inp[sz / 2 - 1]) / (double)2;
}

int main(int argc, char** argv)
{
    string path_result = add_suffix("BenchMarkResults/Results/", argv[1]);
    string path_header = add_suffix("BenchMarkResults/Headers/", argv[1]);
    string path_output = add_suffix("EvaluationResults/AllSamples/", argv[1]);
    string path_median = add_suffix("EvaluationResults/MedianSamples/", argv[1]);

    CsvFile* csv_result1 = new CsvFile(path_result, 1);
    CsvFile* csv_result2 = new CsvFile(path_result, 1);

    CsvFile* csv_header = new CsvFile(path_header, 0);
    CsvWriter* csv_all_sample = new CsvWriter(path_output);
    CsvWriter* csv_median_sample = new CsvWriter(path_median);

    csv_header->read();

    cout << "Read Header" << endl;

    vector<Sample*> samples = build_samples(csv_result1, csv_header);

    cout << "Build Samples" << endl;

    fill_header_samples(samples, csv_header);
    
    cout << "Filled Header" << endl;

    int num_kmer = samples[0] -> get_n();
    
    vector<string> name_cols = build_name_cols(num_kmer, 0);
    vector<vector<double> > all_data;

    csv_all_sample -> write_row(name_cols);

    cout << "Row name writeen" << endl;

    for(int i = 0; i < samples.size(); i++)
    {
        samples[i] -> evaluate_hashes();
        samples[i] -> change_csv_file(csv_result2);
        samples[i] -> evaluate_kmers();
        samples[i] -> write_in_file(csv_all_sample, 0);
        samples[i] -> add_all_data(all_data);
        cout << "A sample evaluation finished" << endl;
    }
    
    cout << "Evaluation Finished" << endl;
    vector<double>median;
    for(int i = 0; i < all_data.size(); i++)
    {
        median.push_back(find_median(all_data[i]));
    }
    
    name_cols = build_name_cols(num_kmer, 1);
    csv_median_sample -> write_row(name_cols);
    csv_median_sample -> write_word(samples[0]->get_hash(), 1);
    csv_median_sample -> write_word(samples[0]->get_seed_method(), 1);
    for(int i = 0; i < median.size(); i++)
    {
        bool is_comma = 1;
        if(i == (int)median.size() - 1)
            is_comma = 0;
        csv_median_sample -> write_word(median[i], is_comma);
    }

    csv_median_sample->new_line();


    delete csv_result1;
    delete csv_result2;
    delete csv_header;
    delete csv_all_sample;
    delete csv_median_sample;
    for(int i = 0; i < samples.size(); i++)
    {
        delete samples[i];
    }
}