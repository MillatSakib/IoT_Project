function checkDeviceStatus() {
    // Make an HTTP GET request to the API link
    fetch("https://blynk.cloud/external/api/isHardwareConnected?token=3yj65_OKC42XbMAsbzoHicMcTb8iiXOo")
      .then(response => response.json())
      .then(data => {
        // Check if the response is "true"
        if (data === true) {
          // Update the message and text color for online status
          const statusElement = document.getElementById("status");
          statusElement.textContent = "Device is online!";
          statusElement.classList.remove("offline");
          statusElement.classList.add("online");
        } else {
          // Update the message and text color for offline status
          const statusElement = document.getElementById("status");
          statusElement.textContent = "Device is offline!";
          statusElement.classList.remove("online");
          statusElement.classList.add("offline");
        }
      })
      .catch(error => {
        // Handle any errors that may occur during the request
        console.error("An error occurred:", error);
      });
  }
  
  // Call the function immediately to check the device status
  checkDeviceStatus();
  
  // Set an interval to call the function every 30 seconds
  setInterval(checkDeviceStatus, 30000);
  