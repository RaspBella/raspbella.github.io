var button = document.getElementById("fish_button");
var audio = document.getElementById("fish_audio");

button.addEventListener("click", () => {
    button.classList.add("pressed");

    audio.volume = 0.2;
    audio.currentTime = 0;
    audio.play();

    var delay = 2000;

    setTimeout(() => {
	button.classList.remove("pressed");
    }, delay);
});
