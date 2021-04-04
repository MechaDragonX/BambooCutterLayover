const input: HTMLElement = document.querySelector('#inputField');
const processedText: HTMLElement = document.querySelector('#processedText');

input.addEventListener('change', processText);

function processText() {
    //@ts-ignore
    processedText.value = input.value;
}

