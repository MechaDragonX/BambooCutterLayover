const input: Element = document.querySelector('#inputField');
const processedText: Element = document.querySelector('#processedText');

input.addEventListener('change', processText);

function processText() {
    // @ts-ignore
    processedText.value = input.value;
}

