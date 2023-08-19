using namespace std;

struct RequestLine {
    string method;
    string path;
    string httpVersion;
};

class HTTP {
    private:
        string method;
        string path;
        string httpVersion;
        map<string, string> headers;      

    public:
        void setHeaders(map<string, string> _headers) {
            headers = _headers;
        }

        string getHeaders() {
            string headersAsString;
            for (auto each : headers) {
                headersAsString += each.first + ": " + each.second + "\r\n"; 
            }
            return headersAsString;
        }

        void setMethod(string _method) {
            method = _method;
        }

        string getMethod() {
            return method;
        }

        void setPath(string _path) {
            path = _path;
        }

        string getPath() {
            return path;
        }

        void setHttpVersion(string _httpVersion) {
            httpVersion = _httpVersion;
        }

        string getHttpVersion() {
            return httpVersion;
        }
};