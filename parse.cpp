#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <boost/algorithm/string.hpp>
#include "headers/types.h"

using namespace std;
using namespace boost::algorithm;


vector<string> split(char c, string text) {
    string s;  
    stringstream ss(text);

    vector<string> textVector;

    while (getline(ss, s, c)) {
        trim(s);
        textVector.push_back(s);
    }
    return textVector;
}

RequestLine requestLineParse(string content) {
    string requestLineString = content.substr(0, content.find('\n'));  
    vector<string> requestLineParsed;
    requestLineParsed = split(' ', requestLineString);

    struct RequestLine requestLine;
    requestLine.method = requestLineParsed[0];
    requestLine.path = requestLineParsed[1];
    requestLine.httpVersion = requestLineParsed[2];
    
    return requestLine;
}

bool isHeader(string line) {
    if (!line.find(':')) {
        return false; 
    }
    return true;
}

map<string, string> getHeaders() {
    map<string, string> headers;
    vector<string> splitted;

    if (isHeader(":")) {
        splitted = split(':', ":");
    }

    return headers;
}

string getFileContent(string filename, map<string, string> *headers) {
    ifstream file(filename);
    string text;
    string request_as_string;

    vector<string> splitted;

    while (getline(file, text)) {
        text += "\r\n";
        request_as_string += text;
        if (isHeader(text)) {
           splitted = split(':', text);
           for (int i = 0; i < splitted.size(); i++) {
                cout << splitted[i] << endl;
           }
        //    cout << splitted[1] << endl;
        //    cout << headers << endl;
        //    getHeaders();
        }
    }

    return request_as_string;
}

int main() {
    map<string, string> headers;
    string content = getFileContent("request.txt", &headers);

    RequestLine requestLine = requestLineParse(content);
    // map<string, string> headers = getHeaders(content);

    return 0;
}