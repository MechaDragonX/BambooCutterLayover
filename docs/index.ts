const input: HTMLInputElement = (<HTMLInputElement>document.querySelector('#inputField'));
const processedText: HTMLInputElement = (<HTMLInputElement>document.querySelector('#processedText'));

input.addEventListener('change', processText);

function processText() {
    processedText.value = input.value;
}

