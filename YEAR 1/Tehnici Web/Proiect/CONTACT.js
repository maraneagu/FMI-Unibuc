function validateForm() {
    let p = document.forms["myForm"]["fname"].value;
    let n = document.forms["myForm"]["lname"].value;

    let name = /^[a-zA-Z0-9-]*$/;

    if(p == "") {
        alert("Prenumele trebuie completat!");
        return false;
    }

    if(p.match(name)) {
        alert("Prenume valid!");
    }
    else {
        alert("Prenume invalid!");
        return false;
    }

    if(n == "") {
        alert("Numele trebuie completat!");
        return false;
    }

    if(n.match(name)) {
        alert("Nume valid!");
    }
    else {
        alert("Nume invalid!");
        return false;
    }

    localStorage.setItem("fname", p);
    localStorage.setItem("lname", n);

    alert("Multumim de feedback " + localStorage.getItem("fname") + " " + localStorage.getItem("lname") + "!");
    return true;
}