// document.getElementById("count-el").innerText = 5
let res = 0
let saveEl = document.getElementById("save-el")
function increment(){
    res++
    document.getElementById("count-el").innerText = res
}

function save(){
    saveEl.textContent += res + " - "
    res = 0
    document.getElementById("count-el").innerText = res
}