const checkboxes = document.querySelectorAll('input[type="checkbox"]');
const messageElements = document.querySelectorAll('.message');

function checkStateAndUpdateToggle() {
  const urls = [
    'https://blynk.cloud/external/api/get?token=iFGIF3ytEx3ZtBDM3jjbA6JXEAW6Rdm5&v0',
    'https://blynk.cloud/external/api/get?token=iFGIF3ytEx3ZtBDM3jjbA6JXEAW6Rdm5&v1',
    'https://blynk.cloud/external/api/get?token=iFGIF3ytEx3ZtBDM3jjbA6JXEAW6Rdm5&v2',
    'https://blynk.cloud/external/api/get?token=iFGIF3ytEx3ZtBDM3jjbA6JXEAW6Rdm5&v3'
  ];

  urls.forEach((url, index) => {
    const xhr = new XMLHttpRequest();
    xhr.open('GET', url, true);
    xhr.onreadystatechange = function () {
      if (xhr.readyState === 4 && xhr.status === 200) {
        const state = xhr.responseText.trim();

        // Update toggle switch based on the state
        checkboxes[index].checked = state === '1';

        // Update message based on the state

      }
    };
    xhr.send();
  });
}

function toggleButtonState(event) {
  const checkbox = event.target;
  const currentState = checkbox.checked ? '1' : '0';
  const index = Array.from(checkboxes).indexOf(checkbox);
  const url = 'https://blynk.cloud/external/api/update?token=iFGIF3ytEx3ZtBDM3jjbA6JXEAW6Rdm5&v' + index + '=' + currentState;

  const xhr = new XMLHttpRequest();
  xhr.open('GET', url, true);
  xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
      console.log('Toggle button ' + (index + 1) + ' state changed successfully.');


    }
  };
  xhr.send();
}

// Call the function initially
checkStateAndUpdateToggle();

// Check the state and update toggle switches every 1 second
setInterval(checkStateAndUpdateToggle, 2000);

// Add event listener to each checkbox for manual state changes
checkboxes.forEach((checkbox, index) => {
  checkbox.addEventListener('change', toggleButtonState);
});
