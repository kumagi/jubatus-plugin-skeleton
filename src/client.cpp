#include <jubatus/client/classifier_client.hpp>

#include <iostream>
#include <fstream>

#define CONFIG "converter_config.json"
#define ALGORITHM "PA"
#define NAME "plugin_test"
#define HOST "localhost"
#define PORT 9199
#define TIMEOUT 10

using namespace std;

int main() {
    ifstream ifc(CONFIG);
    stringstream ss;
    ss << ifc.rdbuf();

    jubatus::client::classifier c(HOST, PORT, TIMEOUT);
    jubatus::config_data conf;
    conf.method = ALGORITHM;
    conf.config = ss.str();

    c.set_config(NAME, conf);

    jubatus::datum d;
    d.string_values.push_back(make_pair("data", "The quick brown fox jumps over the lazy dog."));
    vector<pair<string, jubatus::datum> > v;
    v.push_back(make_pair("label1", d));

    c.train(NAME, v);

    return 0;
}
