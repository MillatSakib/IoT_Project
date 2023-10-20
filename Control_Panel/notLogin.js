
// Check if the user is not logged in.
if (localStorage.getItem("loggedIn") !== "true") {
    window.location.href = "login.html";
}

