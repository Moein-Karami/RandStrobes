#include<bits/stdc++.h>

using namespace std;

vector<int> find_pos_kmer(string new_seed)
{
    int count = 0;
    vector<int> ans;
    int now = 0;
    for(int i = 0; i < new_seed.size(); i++)
    {
        if(new_seed[i] == ',')
        {
            if(count % 2 == 0)
            {
                ans.push_back(now);
                now = 0;
            }
            count++;
            continue;
        }
        if(count % 2 == 1)
            continue;
        now = now * 10 + (new_seed[i] - '0');
    }   
    ans.push_back(now);
    return ans;
}

string find_in_csv(string line_csv, int ind)
{
    int cnt = 0;
    string ans = "";
    for(int i = 0; i < line_csv.size(); i++)
    {
        if(line_csv[i] == ',')
        {
            cnt++;
            if(cnt == ind)
            {
                return ans;
            }
            continue;
        }
        if(cnt == ind - 1)
        {
            ans += line_csv[i];
        }
    }
    return ans;
}

int find_conf(vector<int>&pos1, vector<int>&pos2, int k)
{
    int ans = 0;
    // cout << pos1.back() << endl;
    for(int i = 0; i < pos1.size() - 1; i++)
    {
        int conf_now;
        if(pos1[i] < pos2[i])
            conf_now = pos1[i] - pos2[i] + k;
        else 
            conf_now = pos2[i] - pos1[i] + k;
        // cout << conf_now << endl;
        if(conf_now > 0)
            ans += conf_now;
    }
    return ans;
}

void add_col(vector<int> &new_col, string path, char* suf_path)
{
    stringstream path_stream;
    string new_line;
    path_stream << path;
    path_stream << suf_path;
    path_stream >> path;
    vector<string>line;
    ifstream read_file(path);
    int cnt = 0;
    string line0 = "";
    while(read_file >> new_line)
    {
        if(line0 == "")
            line0 = new_line;
        line.push_back(new_line);
    }
    // cout << line0 << endl;
    int cnt_line = 1;
    string ans_line0 = "";
    while(true)
    {
        string now_col  = find_in_csv(line0, cnt_line++);
        string tmp = "\"Sample\"";
        if(now_col == tmp)
        {
            ans_line0 += "\"Conflicts\",\"Sample\"\n";
            break;
        }
        ans_line0 += now_col;
        ans_line0 += ",";
    }
    vector<string> ans_line;
    ans_line.push_back(ans_line0);
    string now = "";
    for(int i = 1; i < line.size(); i++)
    {
        // cout << line[i] << endl;
        now = "";
        for(int j = 1; j <= cnt_line - 2; j++)
        {
            now += find_in_csv(line[i], j);
            now += ",";
        }
        stringstream int_to_str;
        string str_new_col;
        int_to_str << new_col[i];
        int_to_str >> str_new_col;
        now += str_new_col;
        now += ",";
        now += find_in_csv(line[i], cnt_line -1);
        now += "\n";
        ans_line.push_back(now);
    }
    ofstream write_file(path);
    for(int i = 0; i < ans_line.size(); i++)
    {
        write_file << ans_line[i];
    }
}

void add_col_double(double new_val, string path, char* suf_path)
{
    stringstream path_stream;
    string new_line;
    path_stream << path;
    path_stream << suf_path;
    path_stream >> path;
    vector<string>line;
    ifstream read_file(path);
    int cnt = 0;
    string line0 = "";
    while(read_file >> new_line)
    {
        if(line0 == "")
            line0 = new_line;
        line.push_back(new_line);
    }
    // cout << line0 << endl;
    int cnt_line = 1;
    string ans_line0 = "";
    while(true)
    {
        string now_col  = find_in_csv(line0, cnt_line++);
        string tmp = "\"Sample\"";
        if(now_col == tmp)
        {
            ans_line0 += "\"Conflicts\"\n";
            break;
        }
        ans_line0 += now_col;
        ans_line0 += ",";
    }
    vector<string> ans_line;
    ans_line.push_back(ans_line0);
    string now = "";
    for(int i = 1; i < line.size(); i++)
    {
        // cout << line[i] << endl;
        now = "";
        for(int j = 1; j <= cnt_line - 2; j++)
        {
            now += find_in_csv(line[i], j);
            now += ",";
        }
        stringstream double_to_str;
        string str_new_col;
        double_to_str << new_val;
        double_to_str >> str_new_col;
        now += str_new_col;
        now += "\n";
        ans_line.push_back(now);
    }
    ofstream write_file(path);
    for(int i = 0; i < ans_line.size(); i++)
    {
        write_file << ans_line[i];
    }
}


double find_median(vector<int> &vec_input)
{
    sort(vec_input.begin(), vec_input.end());
    int end = vec_input.size();
    if(end % 2 == 1)
    {
        return vec_input[(end - 1) / 2];
    }
    else 
    {
        return (double)((double)vec_input[end / 2] + (double)vec_input[end / 2 - 1]) / 2;
    }
}

double find_avg(vector<int> &vec_input)
{
    double sum = 0;
    for(int i = 0; i < vec_input.size(); i++)
    {
        sum += (double)vec_input[i];
    }
    int size_vec = vec_input.size();
    return (double)sum / (double)size_vec;
}




int main(int argc, char** argv)
{
    stringstream path_stream, path_stream2, string_to_int;

    path_stream << "BenchMarkResults/Results/";
    path_stream << argv[1];
    string path = "";
    string path2 = "";
    path_stream >> path;
    path_stream2 << "BenchMarkResults/Headers/";
    path_stream2 << argv[1];
    path_stream2 >> path2;

    string line_now;

    ifstream result_reader(path);
    ifstream header_reader(path2);

    header_reader >> line_now;
    header_reader >> line_now;

    int k;

    string_to_int << find_in_csv(line_now, 4);
    string_to_int >> k;

    string new_seed;
    vector<vector<int> > kmer_pos;
    int tmp = 0;
    while(result_reader >> new_seed)
    {
        tmp++;
        if(tmp != 1)
            kmer_pos.push_back(find_pos_kmer(new_seed));
        else 
            continue;
    }
    vector<int>max_conflict;
    for(int i = 0; i < kmer_pos.size(); i++)
    {
        int end_check = min((int)kmer_pos.size(), i + k);
        int mx_now = 0;
        for(int j = i + 1; j < end_check; j++)
        {
            if(kmer_pos[i].back() != kmer_pos[j].back())
                break;
            int conf_now = find_conf(kmer_pos[i], kmer_pos[j], k);
            mx_now = max(mx_now, conf_now);
        }
        max_conflict.push_back(mx_now);
    }
    vector<int>samples;
    for(int i = 0; i < kmer_pos.size(); i++)
    {
        samples.push_back(kmer_pos[i].back());
    }
    
    add_col(max_conflict, "EvaluationResults/AllSamples/", argv[1]);
    double median = find_median(max_conflict);
    double avg = find_avg(max_conflict);
    add_col_double(avg, "EvaluationResults/MedianSamples/", argv[1]);
}