const checkbox = document.querySelector('input[type="checkbox"]');
const messageElement = document.getElementById('message');

function checkStateAndUpdateToggle() {
  const url = 'https://blynk.cloud/external/api/get?token=3yj65_OKC42XbMAsbzoHicMcTb8iiXOo&v2';

  const xhr = new XMLHttpRequest();
  xhr.open('GET', url, true);
  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4 && xhr.status === 200) {
      const state = xhr.responseText.trim();

      // Update toggle switch based on the state
      checkbox.checked = state === '1';

      // Update message based on the state
      if (state === '1') {
        messageElement.textContent = 'Light 2 now is ON';
      } else {
        messageElement.textContent = 'Light 2 is now OFF';
      }
    }
  };
  xhr.send();
}

function toggleButtonState() {
  const currentState = checkbox.checked ? '1' : '0';
  const url = `https://blynk.cloud/external/api/update?token=3yj65_OKC42XbMAsbzoHicMcTb8iiXOo&v2=${currentState}`;

  const xhr = new XMLHttpRequest();
  xhr.open('GET', url, true);
  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4 && xhr.status === 200) {
      console.log('Toggle button state changed successfully.');

      // Update message based on the new state
      if (currentState === '1') {
        messageElement.textContent = 'Light is on';
      } else {
        messageElement.textContent = '';
      }
    }
  };
  xhr.send();
}

// Call the function initially
checkStateAndUpdateToggle();

// Check the state and update toggle switch every 1 second
setInterval(checkStateAndUpdateToggle, 1000);

// Add event listener to the checkbox for manual state changes
checkbox.addEventListener('change', toggleButtonState);
