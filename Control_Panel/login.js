document.getElementById("login-form").addEventListener("submit", function (e) {
    e.preventDefault();
    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;

    // Replace with your own authentication logic.
    // You should check credentials on the server in a production environment.
    if (username === "millatsakib" && password === "backDoor") {
        // Set the login status in local storage.
        localStorage.setItem("loggedIn", "true");
        // Redirect to the control panel page.
        window.location.href = "index.html";
    } else {
        alert("Login failed. Please check your credentials.");
    }
});

// Check if the user is already logged in.
if (localStorage.getItem("loggedIn") === "true") {
    window.location.href = "index.html";
}