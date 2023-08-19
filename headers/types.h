using namespace std;

struct RequestLine {
    string method;
    string path;
    string httpVersion;
};

class HTTP {
    public:
        string method;
        string path;
        string httpVersion;

        map<string, string> headers;      

        string getHeaders() {
            string headersAsString;
            for (auto each : headers) {
                headersAsString += each.first + ": " + each.second + "\r\n"; 
            }
            return headersAsString;
        }
};