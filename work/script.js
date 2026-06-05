const colorBtn = document.querySelector('#colorButton');
const hoverBtn = document.querySelector('#hoverButton');

const hero = document.querySelector('.hero');

colorBtn.addEventListener('click', function () {
    hero.style.backgroundColor = 'white';
    console.log("Color button clicked");
});

hoverBtn.addEventListener('mouseover', function(){
    hoverBtn.style.backgroundColor = 'green'
    console.log(("hover button click"))
})

hoverBtn.addEventListener('mouseout', function(){
    hoverBtn.style.backgroundColor =''
    console.log(("hover button out"))
})

const countBtn = document.querySelector("#countButton")
const clicksLabel = document.querySelector("#clicks")

let noOfclicks = 0;

countBtn.addEventListener('click', function(){
    noOfclicks++;
    clicksLabel.textContent  = "NO of click:" + noOfclicks;
})



const themeBtn = document.querySelector("#themeButton");

themeBtn.addEventListener("click", function () {
    document.body.classList.toggle("light-mode");

    if(document.body.classList.contains("light-mode")){
        themeBtn.textContent = "☀️ Dark Mode";
    }
    else{
        themeBtn.textContent = "🌙 Light Mode";
    }
});

const topBtn = document.querySelector("#topBtn");

topBtn.addEventListener("click", function(){
    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });
});