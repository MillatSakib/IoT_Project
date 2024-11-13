function checkDeviceStatus() {
  // Make an HTTP GET request to the API link
  fetch("https://blynk.cloud/external/api/isHardwareConnected?token=iFGIF3ytEx3ZtBDM3jjbA6JXEAW6Rdm5")
    .then(response => response.json())
    .then(data => {
      // Check if the response is "true"
      if (data === true) {
        // Update the message and text color for online status
        const statusElement = document.getElementById("status");
        statusElement.textContent = "Controller Device is online!";
        statusElement.classList.remove("offline", "error");
        statusElement.classList.add("online");
      } else {
        // Update the message and text color for offline status
        const statusElement = document.getElementById("status");
        statusElement.textContent = "Controller Device is offline!";
        statusElement.classList.remove("online", "error");
        statusElement.classList.add("offline");
      }
    })
    .catch(error => {
      // Handle any errors that may occur during the request
      const statusElement = document.getElementById("status");
      statusElement.textContent = "Oops! You are not connected to the internet.";
      statusElement.classList.remove("online", "offline");
      statusElement.classList.add("error");
      console.error("An error occurred:", error);
    });
}

// Call the function immediately to check the device status
checkDeviceStatus();

// Set an interval to call the function every 50 seconds
setInterval(checkDeviceStatus, 10000);
