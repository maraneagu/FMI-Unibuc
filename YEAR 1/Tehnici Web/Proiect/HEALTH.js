
function myButton() {

    // ACCESAREA BUTONULUI
      var button = document.getElementById("button");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
      var moreText = document.getElementById("more");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
      var buttonText = document.getElementById("buttontext");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
        document.body.style.backgroundColor = "black";
        // TEXTUL SE RESTRÂNGE
        button.style.display = "inline";
        // TEXTUL DE PE BUTON SE SCHIMBĂ
        buttonText.innerHTML = "● ● ●"; 
        // TEXTUL SUPLIMENTAR DEVINE "NONE"
         moreText.style.display = "none";
      }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
        document.body.style.backgroundColor = "red";
        // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
      }
  }

  function myButton2() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button2");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more2");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext2");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
        document.body.style.backgroundColor = "black";    
        // TEXTUL SE RESTRÂNGE
        button.style.display = "inline";
        // TEXTUL DE PE BUTON SE SCHIMBĂ
        buttonText.innerHTML = "● ● ●"; 
        // TEXTUL SUPLIMENTAR DEVINE "NONE"
         moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {  
        document.body.style.backgroundColor = "orange";
        // TEXTUL SE RESTRÂNGE
        // TEXTUL NU MAI ESTE RESTRÂNS
        button.style.display = "none";
        // TEXTUL DE PE BUTON SE SCHIMBĂ
        buttonText.innerHTML = "✌️"; 
        // TEXTUL SUPLIMENTAR APARE
        moreText.style.display = "inline";
    }
}

function myButton3() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button3");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more3");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext3");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black"; 
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "yellow"; 
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton4() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button4");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more4");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext4");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "green";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton5() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button5");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more5");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext5");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "rgb(1,60,56)";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton6() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button6");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more6");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext6");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "rgb(178, 202, 241)";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton7() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button7");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more7");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext7");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "blue";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton8() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button8");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more8");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext8");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "rgb(22, 3, 98)";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton9() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button9");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more9");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext9");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "purple";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton10() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button10");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more10");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext10");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "violet";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton11() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button11");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more11");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext11");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "pink";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}

function myButton12() {

    // ACCESAREA BUTONULUI
    var button = document.getElementById("button12");

    // ACCESAREA TEXTULUI SUPLIMENTAR, CARE APARE DUPĂ APĂSAREA BUTONULUI
    var moreText = document.getElementById("more12");

    // TEXTUL CARE APARE PE BUTON ÎN FUNCȚIA DE STAREA SA
    var buttonText = document.getElementById("buttontext12");

    // DACĂ BUTONUL ESTE "NONE" => A FOST APĂSAT DEJA => NE ÎNTOARCEM LA STAREA INIȚIALĂ
    if (button.style.display === "none") 
    {
            document.body.style.backgroundColor = "black";
            // TEXTUL SE RESTRÂNGE
            button.style.display = "inline";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "● ● ●"; 
            // TEXTUL SUPLIMENTAR DEVINE "NONE"
            moreText.style.display = "none";
    }
    // DACĂ BUTONUL NU ESTE "NONE" => NU A FOST APĂSAT DEJA
    else 
    {
            document.body.style.backgroundColor = "white";
            // TEXTUL NU MAI ESTE RESTRÂNS
            button.style.display = "none";
            // TEXTUL DE PE BUTON SE SCHIMBĂ
            buttonText.innerHTML = "✌️"; 
            // TEXTUL SUPLIMENTAR APARE
            moreText.style.display = "inline";
    }
}




