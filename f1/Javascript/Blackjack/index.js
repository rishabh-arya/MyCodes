let cards = []
let sum = 0
let cardEl = document.getElementById("card-el")
let sumEl = document.getElementById("sum-el")
let message = ""
let messageEl = document.getElementById("message-el")
let isAlive 
let hasBlackJack
let playerEl = document.getElementById("player-el")
let player = {
    name : "Ardy",
    chips : 200
}
function get_random_card()
{
    let r = Math.floor(Math.random()*13) + 1
    if(r > 10)
    return 10
    else if(r === 1)
    return 11
    else 
    return r
}

function renderCards()
{
    cardEl.textContent = "Cards : "
    for(let i = 0;i<cards.length;i++)
    cardEl.textContent += cards[i] + " "

    sumEl.textContent = "Sum : " + sum
    if(sum <= 20)
    message = "Do you want to draw another card ?"
    else if(sum === 21)
    {
        message = "You've got a Blackjack!"
        hasBlackJack = true
    }
    else 
    {
        message = "You're out of the game!"
        isAlive = false
    }
    messageEl.textContent = message
}
function start_game() {
    isAlive = true
    let firstCard = get_random_card()
    let secondCard = get_random_card()
    cards = [firstCard,secondCard]
    sum = firstCard + secondCard
    renderCards()
}
playerEl.textContent = player.name + " :  $" + player.chips
function new_card()
{
    if(isAlive){
    let c = get_random_card()
    sum += c
    cards.push(c)
    renderCards()
    }
}