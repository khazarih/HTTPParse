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
    int index = (int)line.find(':');
    if (index < 2) {
        return false;
    }
    return true;
}

vector<string> getHeader(string input) {
    vector<string> header;
    size_t colonPos = input.find(':');

    string key = input.substr(0, colonPos);
    string value = input.substr(colonPos + 1);

    trim(key);
    trim(value);

    header.push_back(key);
    header.push_back(value);

    return header;
}

string getFileContent(string filename, map<string, string> *headers) {
    ifstream file(filename);
    string text;
    string request_as_string;

    vector<string> splitted;
    vector<string> header;

    while (getline(file, text)) {
        text += "\r\n";
        request_as_string += text;
        if (isHeader(text)) {
            header = getHeader(text);
            cout << header[0] << endl;
            cout << header[1] << endl;
        }
    }

    return request_as_string;
}

int main() {
    map<string, string> headers;
    string content = getFileContent("request.txt", &headers);

    RequestLine requestLine = requestLineParse(content);

    return 0;
}