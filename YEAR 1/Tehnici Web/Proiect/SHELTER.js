	var slideIndex = 1;
	showSlides(slideIndex); 
	showSlides2(slideIndex);
	showSlides3(slideIndex);
	showSlides4(slideIndex); 
    showSlides5(slideIndex); 
    showSlides6(slideIndex);
	showSlides7(slideIndex); 
    showSlides8(slideIndex);

	function plusSlides(n) 
	{
		showSlides(slideIndex += n);
	}
	function plusSlides2(n) 
	{
		showSlides2(slideIndex += n);
	}
	function plusSlides3(n) 
	{
		showSlides3(slideIndex += n);
	}
	function plusSlides4(n) 
    {
        showSlides4(slideIndex += n);
    }
	function plusSlides5(n) 
    {
        showSlides5(slideIndex += n);
    }
	function plusSlides6(n) 
    {
        showSlides6(slideIndex += n);
    }
	function plusSlides7(n) 
    {
        showSlides7(slideIndex += n);
    }
	function plusSlides8(n) 
    {
        showSlides8(slideIndex += n);
    }


	function currentSlide(n) 
	{
		showSlides(slideIndex = n);
	}
	function currentSlide2(n)
	{
		showSlides2(slideIndex = n);
	}
	function currentSlide3(n) 
	{
		showSlides3(slideIndex = n);
	}
	function currentSlide4(n) 
    {
        showSlides4(slideIndex = n);
    }
	function currentSlide5(n) 
    {
        showSlides5(slideIndex = n);
    }
	function currentSlide6(n) 
    {
        showSlides6(slideIndex = n);
    }
	function currentSlide7(n) 
    {
        showSlides7(slideIndex = n);
    }
	function currentSlide8(n) 
    {
        showSlides8(slideIndex = n);
    }
	
	function showSlides(n) {
  		var i;
		
		// ACCESAREA SLIDE-URILOR
  		var slides = document.getElementsByClassName("mySlides");

		// ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
  		var dots = document.getElementsByClassName("dot");

		// AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
  		if (n > slides.length) 
		{
			slideIndex = 1;
		}
		
		// AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
  		if (n < 1) {
			slideIndex = slides.length;
		}

		// TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
  		for (i = 0; i < slides.length; i++) 
		{
			slides[i].style.display = "none";
		}

		// TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
		for (i = 0; i < dots.length; i++) 
		{
			dots[i].className = dots[i].className.replace(" active", "");
		}

		// IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
  		slides[slideIndex-1].style.display = "block"; 

		// BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
		dots[slideIndex-1].className += " active";
	}

	function showSlides2(n) {
  		var i;
		
		// ACCESAREA SLIDE-URILOR
  		var slides = document.getElementsByClassName("mySlides2");

		// ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
  		var dots = document.getElementsByClassName("dot2");

		// AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
  		if (n > slides.length) 
		{
			slideIndex = 1
		}
		
		// AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
  		if (n < 1) {
			slideIndex = slides.length
		}

		// TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
  		for (i = 0; i < slides.length; i++) 
		{
			slides[i].style.display = "none";
		}

		// TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
		for (i = 0; i < dots.length; i++) 
		{
			dots[i].className = dots[i].className.replace(" active", "");
		}

		// IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
  		slides[slideIndex-1].style.display = "block"; 

		// BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
		dots[slideIndex-1].className += " active";
	}

	function showSlides3(n) {
  		var i;
		
		// ACCESAREA SLIDE-URILOR
  		var slides = document.getElementsByClassName("mySlides3");

		// ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
  		var dots = document.getElementsByClassName("dot3");

		// AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
  		if (n > slides.length) 
		{
			slideIndex = 1
		}
		
		// AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
  		if (n < 1) {
			slideIndex = slides.length
		}

		// TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
  		for (i = 0; i < slides.length; i++) 
		{
			slides[i].style.display = "none";
		}

		// TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
		for (i = 0; i < dots.length; i++) 
		{
			dots[i].className = dots[i].className.replace(" active", "");
		}

		// IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
  		slides[slideIndex-1].style.display = "block"; 

		// BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
		dots[slideIndex-1].className += " active";
	}

    function showSlides4(n) {
        var i;
      
        // ACCESAREA SLIDE-URILOR
        var slides = document.getElementsByClassName("mySlides4");

        // ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
        var dots = document.getElementsByClassName("dot4");

        // AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
        if (n > slides.length) 
        {
            slideIndex = 1
        }
      
        // AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
        if (n < 1) {
            slideIndex = slides.length
        }

        // TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
        for (i = 0; i < slides.length; i++) 
        {
            slides[i].style.display = "none";
        }

        // TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
        for (i = 0; i < dots.length; i++) 
        {
            dots[i].className = dots[i].className.replace(" active", "");
        }

        // IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
        slides[slideIndex-1].style.display = "block"; 

        // BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
        dots[slideIndex-1].className += " active";
    }

    function showSlides5(n) {
        var i;
      
        // ACCESAREA SLIDE-URILOR
        var slides = document.getElementsByClassName("mySlides5");

        // ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
        var dots = document.getElementsByClassName("dot5");

        // AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
        if (n > slides.length) 
        {
            slideIndex = 1
        }
      
        // AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
        if (n < 1) 
        {
          slideIndex = slides.length
        }

        // TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
        for (i = 0; i < slides.length; i++) 
        {
            slides[i].style.display = "none";
        }

        // TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
        for (i = 0; i < dots.length; i++) 
        {
            dots[i].className = dots[i].className.replace(" active", "");
        }

        // IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
        slides[slideIndex-1].style.display = "block"; 

        // BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
        dots[slideIndex-1].className += " active";
    }

    function showSlides6(n) {
        var i;
      
        // ACCESAREA SLIDE-URILOR
        var slides = document.getElementsByClassName("mySlides6");

        // ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
        var dots = document.getElementsByClassName("dot6");

        // AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
        if (n > slides.length) 
        {
            slideIndex = 1
        }
      
        // AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
        if (n < 1) 
        {
          slideIndex = slides.length
        }

        // TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
        for (i = 0; i < slides.length; i++) 
        {
            slides[i].style.display = "none";
        }

        // TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
        for (i = 0; i < dots.length; i++) 
        {
            dots[i].className = dots[i].className.replace(" active", "");
        }

        // IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
        slides[slideIndex-1].style.display = "block"; 

        // BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
        dots[slideIndex-1].className += " active";
    }

    function showSlides7(n) {
        var i;
      
        // ACCESAREA SLIDE-URILOR
        var slides = document.getElementsByClassName("mySlides7");

        // ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
        var dots = document.getElementsByClassName("dot7");

        // AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
        if (n > slides.length) 
        {
            slideIndex = 1
        }
      
        // AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
        if (n < 1) 
        {
          slideIndex = slides.length
        }

        // TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
        for (i = 0; i < slides.length; i++) 
        {
            slides[i].style.display = "none";
        }

        // TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
        for (i = 0; i < dots.length; i++) 
        {
            dots[i].className = dots[i].className.replace(" active", "");
        }

        // IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
        slides[slideIndex-1].style.display = "block"; 

        // BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
        dots[slideIndex-1].className += " active";
    }

    function showSlides8(n) {
        var i;
      
        // ACCESAREA SLIDE-URILOR
        var slides = document.getElementsByClassName("mySlides8");

        // ACCESAREA BUTOANELOR DE DEPLASARE PE SLIDE-URI
        var dots = document.getElementsByClassName("dot8");

        // AM AJUNS LA CAPĂT => NE ÎNTOARCEM LA ÎNCEPUT
        if (n > slides.length) 
        {
            slideIndex = 1
        }
      
        // AM AJUNS LA ÎNCEPUT => NE ÎNTOARCEM LA CAPĂT
        if (n < 1) 
        {
          slideIndex = slides.length
        }

        // TOATE SLIDE-URILE AU DISPLAY "NONE" => TRANZIȚIE DE IMAGINI, ALTFEL SE SUPRAPUN
        for (i = 0; i < slides.length; i++) 
        {
            slides[i].style.display = "none";
        }

        // TOATE BUTOANELE DEVIN DIN ACTIVE, INACTIVE => CULOAREA DEVINE GRI
        for (i = 0; i < dots.length; i++) 
        {
            dots[i].className = dots[i].className.replace(" active", "");
        }

        // IMAGINEA ACCESATĂ DEVINE "BLOCK"/VIZIBILĂ
        slides[slideIndex-1].style.display = "block"; 

        // BUTONUL ACCESAT DEVINE ACTIV => CULOAREA DEVINE ROȘIE
        dots[slideIndex-1].className += " active";
    }

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
				// TEXTUL NU MAI ESTE RESTRÂNS
				button.style.display = "none";
				// TEXTUL DE PE BUTON SE SCHIMBĂ
				buttonText.innerHTML = "✌️"; 
				// TEXTUL SUPLIMENTAR APARE
				moreText.style.display = "inline";
		}
	}