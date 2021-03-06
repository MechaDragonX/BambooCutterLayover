#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// A unordered set of all allowed hostnames
static const unordered_set<string> ALLOWED_HOSTNAMES {
    "mangadex.org",
    "nhentai.net",
    "imgur.com",
    "readmanhwa.com",
    // Toonily redirection doesn't work manually, so I'll address it later
    // "toonily.com"
};
// Base string to attach the parts of the redirect URL
static const string baseURL = "https://guya.moe/proxy/";

vector<string> splitStringByDelimiter(string input, char delimiter) {
    vector<string> result = {};
    size_t pos = 0;
    string token;
    while((pos = input.find(delimiter)) != string::npos) {
        // Make the token the current portion
        token = input.substr(0, pos);
        // Remove blank matches
        if(token != "") {
            result.push_back(token);
        }
        // Remove everything looked at so far
        input.erase(0, pos + 1);
    }
    result.push_back(input);
    return result;
}
string genURL(string arg) {
    // Remove "https://" from the argument
    string primary = arg.erase(0, 8);
    // Check to see if the hostname is supported
    if(ALLOWED_HOSTNAMES.find(arg.substr(0, arg.find('/'))) == ALLOWED_HOSTNAMES.end()) {
        return "That URL is not supported!";
    }

    // Get a vector of parts of the URL
    vector<string> parts = splitStringByDelimiter(arg, '/');
    // Create redirect URL's based on the hostname
    if(parts[0] == "mangadex.org") {
        // Append hostname and code
        return baseURL + "mangadex/" + parts[2] + "/";
    } else if(parts[0] == "nhentai.net") {
        // Append hostname and code
        return baseURL + "nhentai/" + parts[2] + "/";
    } else if(parts[0] == "imgur.com") {
        // Append hostname, code, and chapter/page number, as Imgur links aren't considered links to a series, but a single chapter
        return baseURL + "imgur/" + parts[2] + "/1/1/";
    } else if(parts[0] == "readmanhwa.com") {
        // Append hostname and title
        return baseURL + "readmanhwa/" + parts[3] + "/";
    }

    return "";
}

int main(int argc, char** argv) {
    cout << genURL(argv[1]) << endl;
}
