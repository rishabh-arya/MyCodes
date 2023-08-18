let all_char = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0']
let len = 16
let p1El = document.getElementById("p1")
let p2El = document.getElementById("p2")
let p3El = document.getElementById("p3")
let p4El = document.getElementById("p4")

function random_password()
{
    let password = ""
    for(let i = 0;i<len;i++)
    password += all_char[Math.floor(Math.random()*(all_char.length))]
    return password

}
function generate_passwords(){
    p1El.textContent = random_password()
    p2El.textContent = random_password()
    p3El.textContent = random_password()
    p4El.textContent = random_password()
}

