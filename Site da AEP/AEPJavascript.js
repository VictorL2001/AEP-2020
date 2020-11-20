function applyTheme (theme) {
	document.getElementById("Tema").className = theme;  /* Coloque no body para começar a mudar o tema */
	localStorage.setItem ("theme", theme);	
}

function applyDayTheme () {					/* Função para aplicar o tema dia */
	applyTheme("day");
}

function applyNightTheme() { 				/* Função para aplicar o tema noite */
	applyTheme("night");
}

function addButtonLestenrs () {
document.getElementById("Daymode").addEventListener("click", applyDayTheme);   /* Ao clicar, ativa a função applyDayTheme */
document.getElementById("Nightmode").addEventListener("click", applyNightTheme);	/* Ao clicar, ativa a função applyNightTheme */
}

function initiate(){
	if(typeof(localStorage)===undefined)									/* Da erro se o browser não suportar */
		alert("the application can not be executed properly in this browser");
	else{
		if(localStorage.getItem("theme")===null)			/* O site é Day time de padrão */
			applyDayTheme();
		else
			applyTheme(localStorage.getItem("theme"));	
	}
	addButtonLestenrs();
}
initiate();