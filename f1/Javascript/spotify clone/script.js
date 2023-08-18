let songIndex = 0;
let audioElement = new Audio('songs/1.mp3');
let masterPlay = document.getElementById('masterPlay');
let myProgressBar = document.getElementById('myProgressBar');
let gif = document.getElementById('gif');
let songItems = Array.from(document.getElementsByClassName('songItem'));
let songItemsPlay = Array.from(document.getElementsByClassName('songItemPlay'));
let masterSong = document.getElementById('masterSong');

let songs = [
    {songName:'Love Again',filePath:'songs/1.mp3',coverPath:'covers/cover1.jpg'},
    {songName:'Eastside',filePath:'songs/2.mp3',coverPath:'covers/cover2.jpg'},
    {songName:'Calm Down',filePath:'songs/3.mp3',coverPath:'covers/cover3.jfif'},
    {songName:'Whenever Wherever',filePath:'songs/4.mp3',coverPath:'covers/cover4.jfif'},
    {songName:'Snap',filePath:'songs/5.mp3',coverPath:'covers/cover5.jfif'},
    {songName:'Until I Found You',filePath:'songs/6.mp3',coverPath:'covers/cover6.jfif'},
    {songName:'As It Was',filePath:'songs/7.mp3',coverPath:'covers/cover7.jfif'},
    {songName:'Alag Aasmaan',filePath:'songs/8.mp3',coverPath:'covers/cover8.jfif'},
];

// For displaying images and song name in the list 
songItems.forEach((element,i) =>{
    console.log(element,i);
    element.getElementsByTagName("img")[0].src = songs[i].coverPath;
    element.getElementsByTagName("span")[0].innerText = songs[i].songName;
})
// When a song paused, this function changes the pause icon of current song to play icon
const makeAllChange = ()=>{
    songItemsPlay.forEach((e) =>{
        e.classList.remove('fa-pause-circle');
        e.classList.add('fa-play-circle');
    })
}
// It detects which song is playing and pauses and also keep track of continuation of a song
songItemsPlay.forEach((element)=>{
    element.addEventListener('click',(e)=>{
        let currsongIndex = parseInt(e.target.id);
        if(audioElement.paused || audioElement.currentTime <= 0 || currsongIndex != songIndex){
            if(currsongIndex == songIndex)
            audioElement.play();
            else {
                songIndex = currsongIndex;
                audioElement.src = `songs/${songIndex+1}.mp3`;
                audioElement.currentTime = 0;
            }
            makeAllChange();
            e.target.classList.remove('fa-play-circle');
            e.target.classList.add('fa-pause-circle');
            audioElement.play();
            masterPlay.classList.remove('fa-play-circle');
            masterPlay.classList.add('fa-pause-circle');
            masterSong.innerText = songs[songIndex].songName;
            gif.style.opacity = 1;
        }
        else {
            audioElement.pause();
            e.target.classList.add('fa-play-circle');
            e.target.classList.remove('fa-pause-circle');
            masterPlay.classList.add('fa-play-circle');
            masterPlay.classList.remove('fa-pause-circle');
            gif.style.opacity = 0;
        
        }
    })
})
// Manages master play icon
masterPlay.addEventListener('click',()=>{
    if(audioElement.paused || audioElement.currentTime <= 0)
    {
        audioElement.play();
        masterPlay.classList.remove('fa-play-circle');
        masterPlay.classList.add('fa-pause-circle');
        gif.style.opacity = 1;
        masterSong.innerText = songs[songIndex].songName;
        songItemsPlay[songIndex].classList.add('fa-pause-circle');
        songItemsPlay[songIndex].classList.remove('fa-play-circle');
    }
    else {
        audioElement.pause();
        masterPlay.classList.remove('fa-pause-circle');
        masterPlay.classList.add('fa-play-circle');
        gif.style.opacity = 0;
        songItemsPlay[songIndex].classList.remove('fa-pause-circle');
        songItemsPlay[songIndex].classList.add('fa-play-circle');
        
    }
})
// Keeps track of progress bar of a song
audioElement.addEventListener('timeupdate',()=>{
    progress = parseInt((audioElement.currentTime/audioElement.duration)*100);
    myProgressBar.value = progress;
    if(progress == 100){
        document.getElementById('next').click();
    }

})
// Enable us to seek along the trackbar
myProgressBar.addEventListener('change',()=>{
    audioElement.currentTime = myProgressBar.value*audioElement.duration/100;
})
// Enables previous click icon
document.getElementById('previous').addEventListener('click',(e)=>{
    songItemsPlay[songIndex].classList.remove('fa-pause-circle');
    songItemsPlay[songIndex].classList.add('fa-play-circle');
    songIndex = (songIndex-1+songs.length)%songs.length;
    audioElement.src = `songs/${songIndex+1}.mp3`;
    audioElement.play();
    audioElement.currentTime = 0;
    masterSong.innerText = songs[songIndex].songName;
    songItemsPlay[songIndex].classList.add('fa-pause-circle');
    songItemsPlay[songIndex].classList.remove('fa-play-circle');
    gif.style.opacity = 1;
    
})
// Enables next click icon  
document.getElementById('next').addEventListener('click',(e)=>{
    songItemsPlay[songIndex].classList.remove('fa-pause-circle');
    songItemsPlay[songIndex].classList.add('fa-play-circle');
    songIndex = (songIndex+1)%songs.length;
    audioElement.src = `songs/${songIndex+1}.mp3`;
    audioElement.play();
    audioElement.currentTime = 0;
    masterSong.innerText = songs[songIndex].songName;
    songItemsPlay[songIndex].classList.add('fa-pause-circle');
    songItemsPlay[songIndex].classList.remove('fa-play-circle');
    gif.style.opacity = 1;
});

