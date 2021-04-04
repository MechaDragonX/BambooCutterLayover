var input = document.querySelector('#inputField');
var processedText = document.querySelector('#processedText');

input.addEventListener('change', processText);

function processText() {
    processedText.value = input.value;
}
