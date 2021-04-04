const allowedHostnames: Set<string> = new Set([
    "mangadex.org",
    "nhentai.net",
    "imgur.com",
    "readmanhwa.com",
    // Toonily redirection doesn't work manually, so I'll address it later
    // "toonily.com"
]);
const baseURL: string = "https://guya.moe/proxy/";

const input: HTMLInputElement = (<HTMLInputElement>document.querySelector('#inputField'));
const processedText: HTMLInputElement = (<HTMLInputElement>document.querySelector('#processedText'));

input.addEventListener('change', genURL);

function genURL() {
    // Primary portion of the URL
    let primary: string;
    if(input.value.slice(0, 7) == "http://") {
        // Remove "http://" from the provided URL
        primary = input.value.replace("http://", "");
    } else if(input.value.substr(0, 8) == "https://") {
        // Remove "https://" from the provided URL
        primary = input.value.replace("https://", "");
    }

    if(!allowedHostnames.has(primary.slice(0, primary.indexOf('/'))))
        console.log("ERROR: That URL is not supported!");

    // Get a vector of parts of the URL
    let parts: Array<string> = primary.split('/');
    let result: string;
    // Create redirect URL's based on the hostname
    if(parts[0] == "mangadex.org") {
        // Append hostname and code
        result = baseURL + "mangadex/" + parts[2] + "/";
    } else if(parts[0] == "nhentai.net") {
        // Append hostname and code
        result = baseURL + "nhentai/" + parts[2] + "/";
    } else if(parts[0] == "imgur.com") {
        // Append hostname, code, and chapter/page number, as Imgur links aren't considered links to a series, but a single chapter
        result = baseURL + "imgur/" + parts[2] + "/1/1/";
    } else if(parts[0] == "readmanhwa.com") {
        // Append hostname and title
        result = baseURL + "readmanhwa/" + parts[3] + "/";
    }

    // Set the output field to the result
    processedText.value = result;
}

