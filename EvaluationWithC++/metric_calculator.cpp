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
    cout << line0 << endl;
    while(true)
    {
        
    }
}

int main(int argc, char** argv)
{
    stringstream path_stream, path_stream2, string_to_int;

    path_stream << "../BenchMarkResults/Results/";
    path_stream << argv[1];
    string path = "";
    string path2 = "";
    path_stream >> path;
    path_stream2 << "../BenchMarkResults/Headers/";
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
            int conf_now = find_conf(kmer_pos[i], kmer_pos[j], k);
            mx_now = max(mx_now, conf_now);
        }
        max_conflict.push_back(mx_now);
    }
    
    add_col(max_conflict, "../EvaluationResults/AllSamples/", argv[1]);
}