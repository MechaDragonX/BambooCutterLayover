#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// A unordered set of all allowed hostnames
static const std::unordered_set<std::string> ALLOWED_HOSTNAMES {
    "mangadex.org",
    "nhentai.net",
    "imgur.com",
    "readmanhwa.com",
    // Toonily redirection doesn't work manually, so I'll address it later
    // "toonily.com"
};
// A unordered map of all logged URL's
static std::unordered_map<std::string, std::string> LOGGED_URLS {};
// Base string to attach the parts of the redirect URL
static const std::string baseURL = "https://guya.moe/proxy/";


/*
    Parameters: Reference to an input string, and a character to split by 
    Returns: A vector<string> that contains all the parts of the string
    Description: Takes a string, splits it by a delimiter character, and return a vector with all the parts of the string
*/
std::vector<std::string> splitStringByDelimiter(std::string& input, char delimiter) {
    std::vector<std::string> result = {};
    size_t pos = 0;
    std::string token;
    // Loop until the end of the string
    while((pos = input.find(delimiter)) != std::string::npos) {
        // Make the token the current portion
        token = input.substr(0, pos);
        // Remove blank matches
        if(token != "") {
            result.push_back(token);
        }
        // Remove everything looked at so far
        input.erase(0, pos + 1);
    }
    // Append the remaing bits to the vector
    result.push_back(input);
    return result;
}
/*
    Parameters: Reference to an input stream object pointing to the log file
    Returns: Nothing
    Description: Read the log file and populate the LOGGED_URLS map with its data
*/
void populateLoggedURLS(std::ifstream& inStream) {
    std::string line;
    std::vector<std::string> parts;

    // While the the stream still has lines in the file to look at
    while(!inStream.eof()) {
        getline(inStream, line);
        // If the current line isn't blank...
        if(line != "") {
            // Get the parts of the current line: original URL and proxy URL
            parts = splitStringByDelimiter(line, ' ');
            // Add them to the logged URL's map
            LOGGED_URLS.insert({ parts[0], parts[1] });
        } else {
            // There's always a new line at the end of the file, so there's nothing to see if the current line is blank
            break;
        }
    }
    
    // Close the stream
    inStream.close();
}
/*
    Parameters: Reference to a string
    Returns: A proxy URL
    Description: Creates a guya.moe proxy URL from the given URL to an external comic site
*/
std::string genURL(std::string arg) {
    if(arg.substr(0, 7) == "http://") {
        // Remove "http://" from the argument
        std::string primary = arg.erase(0, 7);
    } else if(arg.substr(0, 8) == "https://") {
        // Remove "https://" from the argument
        std::string primary = arg.erase(0, 8);
    }

    // Check to see if the hostname is supported
    if(ALLOWED_HOSTNAMES.find(arg.substr(0, arg.find('/'))) == ALLOWED_HOSTNAMES.end()) {
        std::cout << "ERROR: That URL is not supported!" << std::endl;
        exit(1);
    }

    // Get a vector of parts of the URL
    std::vector<std::string> parts = splitStringByDelimiter(arg, '/');
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
    if(argc > 2) {
        std::cout << "ERROR: That's too many arguments! You only need one argument!" << std::endl;
        return 1;
    }
    
    std::ofstream outStream;
    std::ifstream inStream("log.txt");

    // If the log file already exists...
    if(inStream.good()) {
        // Read the log file and populate the LOGGED_URLS map with its data
        populateLoggedURLS(inStream);
    }
    // Open the log file for appending
    outStream.open("log.txt", std::ios::app);

    // If the logged URL's map contains the passed URL...
    if(LOGGED_URLS.find(argv[1]) != LOGGED_URLS.end()) {
        // Simply return the value of that key from the map
        std::cout << LOGGED_URLS.at(argv[1]) << std::endl;

        // Close stream and return exit code 0
        outStream.close();
        return 0;
    }

    // This code will only be accessed if the passed URL does not exist in the logged URL's map
    // Generate a proxy URL from teh given URL
    std::string proxyUrl = genURL(argv[1]);
    // Append the given URL and the proxy URL to the log file
    outStream << argv[1] << " " << proxyUrl << "\n";
    // Write the proxy URL to the console for the user to put into the web browser
    std::cout << proxyUrl << std::endl;

    // Close stream and return exit code 0
    outStream.close();
    return 0;
}
