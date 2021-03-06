#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

static const unordered_set<string> ALLOWED_HOSTNAMES {
    "mangadex.org",
    "nhentai.net",
    "imgur.com",
    "readmanhwa.com",
    // Toonily redirection doesn't work manually, so I'll address it later
    // "toonily.com"
};

int main(int argc, char** argv) {
    
}
